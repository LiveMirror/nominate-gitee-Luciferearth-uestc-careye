//
// Created by PulsarV on 18-5-9.
//

#ifndef ROBOCAR_MAIN_H
#define ROBOCAR_MAIN_H
#include <iostream>
#include <rc_move/rcmove.h>
#include "rc_param.h"
#include <rc_log/rclog.h>
#include <fcntl.h>
#ifdef __linux__
#include <zconf.h>
#endif // __linux__

#define RC_STRING_SYSTEM_START (char*)"System Start"

#define RC_COMMOND_HELP_INFO "-index [index] Set camera index id\n"\
                             "-serial [com] Set control device serial com\n"\
                             "-help Show help menu\n"\
                             "eg:RoboCar -index 0 -serial '/dev/ttyUSB0'\n"
#endif //ROBOCAR_MAIN_H
