
//
// Created by norse on 17-4-19.
//
#include <rc_serial/rcserial.h>
#include <rc_globalVarable/rc_global_serial.h>
#include <rc_log/rclog.h>
#ifdef __linux__
#include <fcntl.h>
#include <termios.h>
#include <zconf.h>
#include <string>
#include <iostream>

RC::SERIAL_FLAGS RC::Serial::recive(char *buffer) {
    SERIAL_FLAGS empty;
    if (this->isOpend()) {
//        char recv_buf[RC_MAX_RECIVE_BUFFER_SIZE] = {'\0'};
//        std::string text;
//        while(){
//        }
//        std::cout<<text;
        if (read(this->device_point, buffer, 64) > 0) {
//            write(STDOUT_FILENO,ch,BUFFER_SIZE);
//            return RC::STRING::serial_encode(recv_buf);
        }
    }
    return empty;
}

int RC::Serial::send(std::string str) {
    char p='a';
    int wr_num = write(this->device_point,str.c_str() , str.length());
    if(wr_num)return 1;
    return 0;

}

int RC::STRING::serial_search_find(const char *chr_1, const char *chr_2) {
    int num_chr_1 = 0, num_chr_2 = 0;
    for (int i = 0; i < RC_SEARCH_SIZE; i++) {
        num_chr_1 += (int) chr_1[i];
        num_chr_2 += (int) chr_2[i];
    }
    return num_chr_1 - num_chr_2;
}
bool RC::Serial::isOpend() {
    return (this->device_point!=-1? true: false);
}

int RC::Serial::openSerial(char *device) {
    this->device_point=open(device,O_RDWR|O_NOCTTY|O_NDELAY);//O_NDELAY
    struct termios st;
    char ch[RC_MAX_RECIVE_BUFFER_SIZE];
    if (this->device_point < 0) {
        RC::LOG::logError(RC_STRING_USB_OPEN_ERROR);
        return -1;
    }
    RC::LOG::logSuccess(RC_SREING_USB_OPEN_SUCCESS);
//    st.c_iflag = 1;
//    st.c_oflag = 0;
//    st.c_cflag = 0;
//    CS8 | CREAD | CLOCAL;
//    cfsetospeed(&st, B9600);
//    int set_config=tcsetattr(this->device_point, TCSANOW, &st);
//    if(set_config)RC::LOG::logError("SetSpeedError");
}

int RC::Serial::release() {
    if (this->device_point) {
        tcflush(this->device_point, TCIOFLUSH);
        close(this->device_point);
    }
}

RC::SERIAL_FLAGS RC::STRING::serial_encode(char *data) {
    SERIAL_FLAGS empty;
    char search[RC_SEARCH_SIZE] = RC_SUB_BIT;
    int search_flag = -1;
    int top_c = 0;
    int head_flag = 0;
    for (int i = 0; i < RC_MAX_RECIVE_BUFFER_SIZE; i++) {
        char find[RC_SEARCH_SIZE] = {'\0'};
        for (int count_c = 0; count_c < RC_SEARCH_SIZE; count_c++) {
            find[count_c] = data[top_c + count_c];
        }
        if (top_c == 0 && STRING::serial_search_find(find, search) == 0) {
            head_flag = 1;
        }
        if (head_flag == 0)
            return empty;
        top_c++;
        if (STRING::serial_search_find(find, search) == 0) {
            search_flag += 1;
        }
        if (search_flag == 1)break;
    }
    char buffer_from_serial[top_c] = {'0'};
    for (int i = 0; i < top_c + 1; i++) {
        buffer_from_serial[i] = data[i];
    }
    if (head_flag == 1 && search_flag == 1) {
        SERIAL_FLAGS data_map;
        std::string GPS_E;
        std::string GPS_N;
        std::string GPS_M;
        std::string GPS_KM;
        std::string GPS_TEMPERTURE;
        std::string GPS_TEMPERTURE_HUMIDDITY;
        int GPS_E_flag=0;
        int GPS_N_flag=0;
        int GPS_M_flag=0;
        int GPS_KM_flag=0;
        int GPS_TEMPERTURE_flag=0;
        int GPS_TEMPERTURE_HUMIDDITY_flag=0;
        for(int i=0;i<top_c;i++){
            if(buffer_from_serial[i]=='E'){
                int str_top=i;
                int count=0;
                while(buffer_from_serial[str_top]!='\n'){
                    str_top--;
                    count++;
                }
                for(int gps_find=1;gps_find<count+1;gps_find++){
                    char c=buffer_from_serial[str_top+gps_find];
                    GPS_E+=c;
                }
                GPS_E_flag=1;
            }
            if(buffer_from_serial[i]=='N'){
                int str_top=i;
                int count=0;
                while(buffer_from_serial[str_top]!=' '){
                    str_top--;
                    count++;
                }
                for(int gps_find=1;gps_find<count+1;gps_find++){
                    char c=buffer_from_serial[str_top+gps_find];
                    GPS_N+=c;
                }
                GPS_N_flag=1;
            }
            if(GPS_M_flag==0&&buffer_from_serial[i]=='m'){
                int str_top=i;
                int count=0;
                while(buffer_from_serial[str_top]!=' '){
                    str_top--;
                    count++;
                }
                for(int gps_find=1;gps_find<count+1;gps_find++){
                    char c=buffer_from_serial[str_top+gps_find];
                    GPS_M+=c;
                }
                GPS_M_flag=1;
            }
            if(buffer_from_serial[i]=='h'){
                int str_top=i;
                int count=0;
                while(buffer_from_serial[str_top]!=' '){
                    str_top--;
                    count++;
                }
                for(int gps_find=1;gps_find<count+1;gps_find++){
                    char c=buffer_from_serial[str_top+gps_find];
                    GPS_KM+=c;
                }
                GPS_KM_flag=1;
            }
            if(buffer_from_serial[i]=='%'){
                int str_top=i;
                int count=0;
                while(buffer_from_serial[str_top]!=' '){
                    str_top--;
                    count++;
                }
                for(int gps_find=1;gps_find<count+1;gps_find++){
                    char c=buffer_from_serial[str_top+gps_find];
                    GPS_TEMPERTURE+=c;
                }
                GPS_TEMPERTURE_flag=1;
            }
            if(buffer_from_serial[i]=='C'){
                int str_top=i;
                int count=0;
                while(buffer_from_serial[str_top]!=' '){
                    str_top--;
                    count++;
                }
                for(int gps_find=1;gps_find<count+1;gps_find++){
                    char c=buffer_from_serial[str_top+gps_find];
                    GPS_TEMPERTURE_HUMIDDITY+=c;
                }
                GPS_TEMPERTURE_HUMIDDITY_flag=1;
            }
        }
        if( GPS_E_flag==1&&
            GPS_N_flag==1&&
            GPS_M_flag==1&&
            GPS_KM_flag==1&&
            GPS_TEMPERTURE_flag==1&&
            GPS_TEMPERTURE_HUMIDDITY_flag==1){
            data_map.insert(SERIAL_FLAG("E",GPS_E));
            data_map.insert(SERIAL_FLAG("N",GPS_N));
            data_map.insert(SERIAL_FLAG("M",GPS_E));
            data_map.insert(SERIAL_FLAG("KM",GPS_KM));
            data_map.insert(SERIAL_FLAG("TEMPERTURE",GPS_TEMPERTURE));
            data_map.insert(SERIAL_FLAG("TEMPERTURE_HUMIDDITY",GPS_TEMPERTURE_HUMIDDITY));

            return data_map;
        }
    }
    return empty;
}
#endif