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

#ifdef __linux__

#include <termios.h>
#include <zconf.h>

#else

#endif
namespace RC {
    typedef std::map<std::string, std::string> SERIAL_FLAGS;
    typedef std::pair<std::string, std::string> SERIAL_FLAG;

    class Serial {
    public:
#ifdef __linux__

        int openSerial(char *device);

        int send(std::string str);

        int send(long comm);

        SERIAL_FLAGS recive(char *buffer, int size);

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
