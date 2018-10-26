//
// Created by PulsarV on 18-5-10.
//

#ifndef ROBOCAR_RCSERIAL_H
#define ROBOCAR_RCSERIAL_H

#include <map>
#include <string>
#include <rc_log/rclog.h>
#include <fcntl.h>
#include <iostream>
#include <rc_globalVarable/rc_global_serial.h>
#include <rc_serial/imu_device/JY901.h>

#ifdef __linux__

#include <stdio.h>   /*标准输入输出的定义*/
#include <errno.h>  /*错误号定义*/
#include <sys/stat.h>
#include <fcntl.h>  /*文件控制定义*/
#include <termios.h>    /*PPSIX 终端控制定义*/
#include <stdlib.h> /*标准函数库定义*/
#include <sys/types.h>
#include <unistd.h> /*UNIX 标准函数定义*/
#include <termios.h>
#include <zconf.h>
#include <linux/serial.h>

#else

#endif
namespace RC {
    int set_serial(int fd, int nSpeed, int nBits, char nEvent, int nStop);
    typedef std::map<std::string, std::string> SERIAL_FLAGS;
    typedef std::pair<std::string, std::string> SERIAL_FLAG;
//    struct termios {
//        tcflag_t c_iflag;//输入选项
//        tcflag_t c_oflag; //输出选项
//        tcflag_t c_cflag; //控制选项
//        tcflag_t c_lflag; //行选项
//        cc_t c_cc[NCCS]; //控制字符
//    };

    class Serial {
    public:
#ifdef __linux__

        int openSerial(char *device);

        int send(std::string str);

        int send(long comm);

        int recive(char *buffer, int size);

        bool isOpend();

        int release();

    private:
        int device_point;
        char *device;
    };

#else

#endif

}
#endif //ROBOCAR_RCSERIAL_H
