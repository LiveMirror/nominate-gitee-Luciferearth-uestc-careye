
//
// Created by norse on 17-4-19.
//
#include <rc_serial/rcserial.h>

#ifdef __linux__
RC::SERIAL_FLAGS RC::Serial::recive(char *buffer,int size) {
    SERIAL_FLAGS empty;
    if (this->isOpend()) {
        if (read(this->device_point, buffer, size) > 0) {
//            return RC::STRING::serial_encode(buffer);
        }
    }
    return empty;
}

int RC::Serial::send(std::string str) {
    int wr_num = write(this->device_point,str.c_str() , str.length());
    if(wr_num)return 1;
    return 0;

}

int RC::Serial::send(long comm) {
    char commond=(char)comm;
    int wr_num = write(this->device_point,&commond, 100);
    if(wr_num)return 1;
    return 0;

}




bool RC::Serial::isOpend() {
    return (this->device_point!=RC_SERIAL_ERROR? true: false);
}

int RC::Serial::openSerial(char *device) {
    this->device_point=open(device,O_RDWR|O_NOCTTY|O_NDELAY);//O_NDELAY
    struct termios st;
    char ch[RC_SERIAL_MAX_RECIVE_BUFFER_SIZE];
    if (this->device_point < 0) {
        RC::LOG::logError(RC_SERIAL_STRING_USB_OPEN_ERROR);
        return -1;
    }
    RC::LOG::logSuccess(RC_SERIAL_SREING_USB_OPEN_SUCCESS);
}

int RC::Serial::release() {
    if (this->device_point) {
        tcflush(this->device_point, TCIOFLUSH);
        close(this->device_point);
    }
}


#endif // __linux__
