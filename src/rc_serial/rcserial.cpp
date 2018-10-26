
//
// Created by norse on 17-4-19.
//
#include <rc_serial/rcserial.h>
#include <cstring>

#ifdef __linux__

int RC::Serial::recive(char *buffer, int size) {
    if (this->isOpend()) {
        int nread = read(this->device_point, buffer, sizeof(size));
        if (nread < 0) {
            printf("read data error!!\n");
            return -2;
        }
//        memset(buffer, 0, sizeof(size));
    }
    return -1;
}

int RC::Serial::send(std::string str) {
    const char *commond = str.c_str();
    int wr_num = write(this->device_point,commond , str.length());
    if (wr_num)return 1;
    return 0;

}

int RC::Serial::send(long comm) {
    char *commond = (char*) comm;
    int wr_num = write(this->device_point, &comm, sizeof(comm));
    if (wr_num)return 1;
    return 0;

}

int RC::set_serial(int fd, int nSpeed, int nBits, char nEvent, int nStop) {
    struct termios newttys1, oldttys1; /*保存原有串口配置*/
    if (tcgetattr(fd, &oldttys1) != 0) {
        perror("Setupserial 1");
        return -1;
    }
    bzero(&newttys1, sizeof(newttys1));
    newttys1.c_cflag |= (CLOCAL | CREAD); /*CREAD 开启串行数据接收，CLOCAL并打开本地连接模式*/
    newttys1.c_cflag &= ~CSIZE;/*设置数据位*/
    /*数据位选择*/
    switch (nBits) {
        case 7:
            newttys1.c_cflag |= CS7;
            break;
        case 8:
            newttys1.c_cflag |= CS8;
            break;
    }
    /*设置奇偶校验位*/
    switch (nEvent) {
        case '0': /*奇校验*/
            newttys1.c_cflag |= PARENB;/*开启奇偶校验*/
            newttys1.c_iflag |= (INPCK | ISTRIP);/*INPCK打开输入奇偶校验；ISTRIP去除字符的第八个比特  */
            newttys1.c_cflag |= PARODD;/*启用奇校验(默认为偶校验)*/
            break;
        case 'E':/*偶校验*/
            newttys1.c_cflag |= PARENB; /*开启奇偶校验  */
            newttys1.c_iflag |= (INPCK | ISTRIP);/*打开输入奇偶校验并去除字符第八个比特*/
            newttys1.c_cflag &= ~PARODD;/*启用偶校验*/ break;
        case 'N': /*无奇偶校验*/
            newttys1.c_cflag &= ~PARENB;
            break;
    } /*设置波特率*/
    switch (nSpeed) {
        case 2400:
            cfsetispeed(&newttys1, B2400);
            cfsetospeed(&newttys1, B2400);
            break;
        case 4800:
            cfsetispeed(&newttys1, B4800);
            cfsetospeed(&newttys1, B4800);
            break;
        case 9600:
            cfsetispeed(&newttys1, B9600);
            cfsetospeed(&newttys1, B9600);
            break;
        case 115200:
            cfsetispeed(&newttys1, B115200);
            cfsetospeed(&newttys1, B115200);
            break;
        default:
            cfsetispeed(&newttys1, B9600);
            cfsetospeed(&newttys1, B9600);
            break;
    } /*设置停止位*/
    /*设置停止位；若停止位为1，则清除CSTOPB，若停止位为2，则激活CSTOPB*/
    if (nStop == 1) {
        newttys1.c_cflag &= ~CSTOPB;/*默认为一位停止位； */
    } else if (nStop == 2) {
        newttys1.c_cflag |= CSTOPB;/*CSTOPB表示送两位停止位*/
    }
    /*设置最少字符和等待时间，对于接收字符和等待时间没有特别的要求时*/
    newttys1.c_cc[VTIME] = 0;/*非规范模式读取时的超时时间；*/
    newttys1.c_cc[VMIN] = 0; /*非规范模式读取时的最小字符数*/
    tcflush(fd, TCIFLUSH);/*tcflush清空终端未完成的输入/输出请求及数据；TCIFLUSH表示清空正收到的数据，且不读取出来 */
    /*激活配置使其生效*/
    if ((tcsetattr(fd, TCSANOW, &newttys1)) != 0) {
        perror("com set error");
        return -1;
    }
    return 0;
}

int jy901_data_analyse(char *buff, JY901DATA *gps_data) {
    char *ptr = NULL;
    if (gps_data == NULL) {
        return -1;
    }
    if (strlen(buff) < 10) {
        return -1;
    }
    /*如果buff字符串中包含字符"$GPRMC"则将$GPRMC的地址赋值给ptr*/
    if (NULL == (ptr = strstr(buff, "$GPRMC"))) {
        return -1;
    }
//    sscanf(ptr, "$GPRMC,%d.000,%c,%f,N,%f,E,%f,%f,%d,,,%c*", &(gps_data->time), &(gps_data->pos_state),
//           &(gps_data->latitude), &(gps_data->longitude), &(gps_data->speed), &(gps_data->direction), &(gps_data->date),
//           &(gps_data->mode));
    /*sscanf函数为从字符串输入，上面这句话的意思是将ptr内存单元的值作为输入分别输入到后面的结构体成员*/
    return 0;
}

bool RC::Serial::isOpend() {
    return (this->device_point != RC_SERIAL_ERROR ? true : false);
}

int RC::Serial::openSerial(char *device) {
    this->device_point = open(device, O_RDWR | O_NOCTTY | O_NDELAY);//O_NDELAY
    if (this->device_point < 0) {
        RC::LOG::logError(RC_SERIAL_STRING_USB_OPEN_ERROR);
        return -1;
    }
    RC::LOG::logSuccess(RC_SERIAL_SREING_USB_OPEN_SUCCESS);
    set_serial(this->device_point, 9600, 8, 'O', 1);
}

int RC::Serial::release() {
    if (this->device_point) {
        tcflush(this->device_point, TCIOFLUSH);
        close(this->device_point);
    }
}


#endif // __linux__
