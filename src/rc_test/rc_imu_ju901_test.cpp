//
// Created by PulsarV on 18-10-26.
//
#include <rc_serial/rc_gyro_serial.h>

using namespace RC;
#ifdef TEST_S
int main(int argv, char *argc[]) {
    GyroDevice dev;
    dev.openSerial("/dev/ttyUSB0");
    char buffer[16] = {0};
    while (1) {
//        dev.setBackSpeed(GYRO_200HZ);
        usleep(1000);
//        std::cout<<"sss"<<std::endl;
        dev.recive(buffer, 16);
//        dev.send(GYRO_SERIAL_BACK_SPEED_200HZ);
//        dev.getContent(buffer,11);
//        std::string str = buffer;
        if ((int) buffer[0] == 85) {
            for (int i = 0; i < 11; i++) {
                std::cout << std::hex << (int) buffer[i] << " ";
            }
            std::cout << std::endl;
        }
//            if((int)buffer[0]==85 and (int)buffer[1]==81){
//                int sum=0;
//                for (int i=0;i<10;i++){
//                    sum+=(int)buffer[i];
//                }
//                if(sum==buffer[10]){
//                }
//        }
    }
    return 0;
}
#endif

#ifdef TEST_SINGAL
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/signal.h>
#include<fcntl.h>
#include<termios.h>
#include<errno.h>
#include <cstring>

#define FALSE -1
#define TRUE 0
#define flag 1
#define noflag 0
int wait_flag = noflag;
int STOP = 0;
int res;
int speed_arr[] = {B38400, B19200, B9600, B4800, B2400, B1200, B300, B38400, B19200, B9600, B4800, B2400, B1200, B300,};
int name_arr[] = {38400, 19200, 9600, 4800, 2400, 1200, 300, 38400, 19200, 9600, 4800, 2400, 1200, 300,};

void set_speed(int fd, int speed) {
    int i;
    int status;
    struct termios Opt;
    tcgetattr(fd, &Opt);
    for (i = 0; i < sizeof(speed_arr) / sizeof(int); i++) {
        if (speed == name_arr[i]) {
            tcflush(fd, TCIOFLUSH);
            cfsetispeed(&Opt, speed_arr[i]);
            cfsetospeed(&Opt, speed_arr[i]);
            status = tcsetattr(fd, TCSANOW, &Opt);
            if (status != 0) {
                perror("tcsetattr fd1");
                return;
            }
            tcflush(fd, TCIOFLUSH);
        }
    }
}

int set_Parity(int fd, int databits, int stopbits, int parity) {
    struct termios options;
    if (tcgetattr(fd, &options) != 0) {
        perror("SetupSerial 1");
        return (FALSE);
    }
    options.c_cflag &= ~CSIZE;
    switch (databits) {
        case 7:
            options.c_cflag |= CS7;
            break;
        case 8:
            options.c_cflag |= CS8;
            break;
        default:
            fprintf(stderr, "Unsupported data size\n");
            return (FALSE);
    }
    switch (parity) {
        case 'n':
        case 'N':
            options.c_cflag &= ~PARENB; /* Clear parity enable */ options.c_iflag &= ~INPCK; /* Enable parity checking */ break;
        case 'o':
        case 'O':
            options.c_cflag |= (PARODD | PARENB);
            options.c_iflag |= INPCK; /* Disnable parity checking */ break;
        case 'e':
        case 'E':
            options.c_cflag |= PARENB; /* Enable parity */ options.c_cflag &= ~PARODD;
            options.c_iflag |= INPCK; /* Disnable parity checking */ break;
        case 'S':
        case 's': /*as no parity */ options.c_cflag &= ~PARENB;
            options.c_cflag &= ~CSTOPB;
            break;
        default:
            fprintf(stderr, "Unsupported parity\n");
            return (FALSE);
    }
    switch (stopbits) {
        case 1:
            options.c_cflag &= ~CSTOPB;
            break;
        case 2:
            options.c_cflag |= CSTOPB;
            break;
        default:
            fprintf(stderr, "Unsupported stop bits\n");
            return (FALSE);
    } /* Set input parity option */ if (parity != 'n') options.c_iflag |= INPCK;
    tcflush(fd, TCIFLUSH);
    options.c_cc[VTIME] = 150;
    options.c_cc[VMIN] = 0; /* Update the options and do it NOW */ if (tcsetattr(fd, TCSANOW, &options) != 0) {
        perror("SetupSerial 3");
        return (FALSE);
    }
    return (TRUE);
}

void signal_handler_IO(int status) {
    printf("received SIGIO signale.\n");
    wait_flag = noflag;
}

int main() {
    printf("This program updates last time at %s %s\n", __TIME__, __DATE__);
    printf("STDIO COM1\n");
    int fd;
    struct sigaction saio;
    fd = open("/dev/ttyUSB0", O_RDWR);
    if (fd == -1) { perror("serialport error\n"); }
    else {
        printf("open ");
        printf("%s", ttyname(fd));
        printf(" succesfully\n");
    }
    saio.sa_handler = signal_handler_IO;
    sigemptyset(&saio.sa_mask);
    saio.sa_flags = 0;
    saio.sa_restorer = NULL;
    sigaction(SIGIO, &saio,
              NULL); //allow the process to receive SIGIO
    fcntl(fd, F_SETOWN,
          getpid()); //make the file descriptor asynchronous
    fcntl(fd, F_SETFL, FASYNC);
    set_speed(fd, 9600);
    if (set_Parity(fd, 8, 1, 'N') == FALSE) {
        printf("Set Parity Error\n");
        exit(0);
    }
    char buf[254]={0};
    while (STOP == 0) {
        usleep(100000); /* after receving SIGIO ,wait_flag = FALSE,input is availabe and can be read */
        if (wait_flag == 0) {
            memset(buf, 0, sizeof(buf));
            res = read(fd, buf, 254);
            if ((int) buf[0] == 85) {
                for (int i = 0; i < 254; i++) {
                    std::cout << std::hex << (int) buf[i] << " ";
                }
                std::cout << std::endl;
            }
//            printf("nread=%d,%s\n", res,buf);
//            if (res ==1)
//             STOP = 1; /*stop loop if only a CR was input */
            wait_flag = flag; /*wait for new input */
        }
    }
    close(fd);
    return 0;
}
#endif
#define TEST_IO_SELECT
#ifdef TEST_IO_SELECT

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/signal.h>
#include<fcntl.h>
#include<termios.h>
#include<errno.h>
#include <cstring>
#include <vector>

#define FALSE -1
#define TRUE 0
#define flag 1
#define noflag 0
int wait_flag = noflag;
int STOP = 0;
int res;
int speed_arr[] = {B38400, B19200, B9600, B4800, B2400, B1200, B300, B38400, B19200, B9600, B4800, B2400, B1200, B300,};
int name_arr[] = {38400, 19200, 9600, 4800, 2400, 1200, 300, 38400, 19200, 9600, 4800, 2400, 1200, 300,};

struct STime stcTime;
struct SAcc stcAcc;
struct SGyro stcGyro;
struct SAngle stcAngle;
struct SMag stcMag;
struct SDStatus stcDStatus;
struct SPress stcPress;
struct SLonLat stcLonLat;
struct SGPSV stcGPSV;

void set_speed(int fd, int speed) {
    int i;
    int status;
    struct termios Opt;
    tcgetattr(fd, &Opt);
    for (i = 0; i < sizeof(speed_arr) / sizeof(int); i++) {
        if (speed == name_arr[i]) {
            tcflush(fd, TCIOFLUSH);
            cfsetispeed(&Opt, speed_arr[i]);
            cfsetospeed(&Opt, speed_arr[i]);
            status = tcsetattr(fd, TCSANOW, &Opt);
            if (status != 0) {
                perror("tcsetattr fd1");
                return;
            }
            tcflush(fd, TCIOFLUSH);
        }
    }
}

int set_Parity(int fd, int databits, int stopbits, int parity) {
    struct termios options;
    if (tcgetattr(fd, &options) != 0) {
        perror("SetupSerial 1");
        return (FALSE);
    }
    options.c_cflag &= ~CSIZE;
    switch (databits) {
        case 7:
            options.c_cflag |= CS7;
            break;
        case 8:
            options.c_cflag |= CS8;
            break;
        default:
            fprintf(stderr, "Unsupported data size\n");
            return (FALSE);
    }
    switch (parity) {
        case 'n':
        case 'N':
            options.c_cflag &= ~PARENB; /* Clear parity enable */ options.c_iflag &= ~INPCK; /* Enable parity checking */ break;
        case 'o':
        case 'O':
            options.c_cflag |= (PARODD | PARENB);
            options.c_iflag |= INPCK; /* Disnable parity checking */ break;
        case 'e':
        case 'E':
            options.c_cflag |= PARENB; /* Enable parity */ options.c_cflag &= ~PARODD;
            options.c_iflag |= INPCK; /* Disnable parity checking */ break;
        case 'S':
        case 's': /*as no parity */ options.c_cflag &= ~PARENB;
            options.c_cflag &= ~CSTOPB;
            break;
        default:
            fprintf(stderr, "Unsupported parity\n");
            return (FALSE);
    }
    switch (stopbits) {
        case 1:
            options.c_cflag &= ~CSTOPB;
            break;
        case 2:
            options.c_cflag |= CSTOPB;
            break;
        default:
            fprintf(stderr, "Unsupported stop bits\n");
            return (FALSE);
    } /* Set input parity option */
    if (parity != 'n') options.c_iflag |= INPCK;
    tcflush(fd, TCIFLUSH);
    options.c_cc[VTIME] = 150;
    options.c_cc[VMIN] = 0; /* Update the options and do it NOW */ if (tcsetattr(fd, TCSANOW, &options) != 0) {
        perror("SetupSerial 3");
        return (FALSE);
    }
    return (TRUE);
}

void signal_handler_IO(int status) {
    printf("received SIGIO signale.\n");
    wait_flag = noflag;
}

class DATA {
    DATA(char type) {

    }
};

int main() {


    std::vector<DATA> info;
    printf("This program updates last time at %s %s\n", __TIME__, __DATE__);
    printf("STDIO COM1\n");
    int fd;
    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) { perror("serialport error\n"); }
    else {
        printf("open ");
        printf("%s", ttyname(fd));
        printf(" succesfully\n");
    }
    set_speed(fd, 9600);
    if (set_Parity(fd, 8, 1, 'N') == FALSE) {
        printf("Set Parity Error\n");
        exit(0);
    }
    char buf;
    fd_set rd;
    int nread = 0;
    char buffer[5] = {char(0xff), char(0xaa), char(0x03), char(0x04), char(0x00)};
    write(fd, buffer, 5);
    int lock = true;
    std::vector<char> data_st;
    while (1) {
        FD_ZERO(&rd);
        FD_SET(fd, &rd);

        while (FD_ISSET(fd, &rd)) {
            if (select(fd + 1, &rd, NULL, NULL, NULL) < 0) {
                perror("select error\n");
            } else {
                while ((nread = read(fd, &buf, sizeof(buf))) > 0) {
//                    std::cout << std::hex << (int) buf << " ";
                    if (lock && buf != 0x55) {
                        continue;
                    } else {
                        lock= false;
//                        data_st.insert(data_st.begin(), (long) 0x55);
                        data_st.push_back((long) buf);
                        if (data_st.size() == 11) {
                            char t_buf[11];
                            std::vector<char>::iterator it;
                            int i = 0;
                            long sum = 0;
                            for (it = data_st.begin(); it < data_st.end(); it++) {
                                t_buf[i] = *it;
                                sum = (long) *it;
                                i++;
                            }
                            data_st.clear();
                            if (sum == (2 * long(t_buf[11]))) {

                            }
                            switch (t_buf[1]) {
                                case 0x51:
                                    memcpy(&stcAcc, &t_buf[2], 8);
                                    std::cout << "0x51 加速度"
                                              << " ax: " << (float) stcAcc.a[0] / 32768 * 16.0 * 9.8
                                              << " ay: " << (float) stcAcc.a[1] / 32768 * 16.0 * 9.8
                                              << " az: " << (float) stcAcc.a[2] / 32768 * 16.0 * 9.8
                                              << " T: " << (float) (stcAcc.T) / 100
                                              << std::endl;
                                    break;
                                case 0x52:
                                    memcpy(&stcGyro, &t_buf[2], 8);
                                    break;
                                case 0x53:
                                    memcpy(&stcAngle, &t_buf[2], 8);
                                    std::cout << "0x53 角度"
                                              << " agx: " << (float) stcAngle.Angle[0] / 32768 * 180
                                              << " agy: " << (float) stcAngle.Angle[1] / 32768 * 180
                                              << " az: " << (float) stcAngle.Angle[2] / 32768 * 180
                                              << " T: " << (float) (stcAngle.T) / 100
                                              << std::endl;
                                    break;
                                case 0x54:
                                    memcpy(&stcMag, &t_buf[2], 8);
                                    std::cout << "0x54 磁场"
                                            " cx: " << (float)stcMag.h[0] <<
                                              " cy: " << (float)stcMag.h[1] <<
                                              " cz: " << (float)stcMag.h[2] <<
                                              " cT:  " << (float)stcMag.T/100
                                              << std::endl;

                                    break;
                                case 0x55:
                                    memcpy(&stcDStatus, &t_buf[2], 8);
                                    std::cout << "0x55" << std::endl;

                                    break;
                                case 0x56:
                                    memcpy(&stcPress, &t_buf[2], 8);
                                    std::cout << "0x56" << std::endl;
                                    break;
                                case 0x57:
                                    memcpy(&stcLonLat, &t_buf[2], 8);
                                    std::cout << "0x57" << std::endl;
                                    break;
                                case 0x58:
                                    memcpy(&stcGPSV, &t_buf[2], 8);
                                    std::cout << "0x58" << std::endl;
                                    break;
                            }

//                            std::vector<char>::iterator it;
//                            for(it=data_st.begin();it<data_st.end();it++){
//                                std::cout<<std::hex<<(int)*it<<" ";
//                            }
//                            std::cout<<std::endl;
//                            exit(0);
                        }
                    }
                }
            }
        }
        close(fd);
        return 0;
    }
}

#endif
#ifdef TEST_IO_LOOP

#endif
