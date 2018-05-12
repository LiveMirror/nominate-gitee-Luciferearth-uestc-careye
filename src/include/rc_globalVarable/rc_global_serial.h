//
// Created by PulsarV on 18-5-10.
//

#ifndef ROBOCAR_RC_GLOBAL_SERIAL_H
#define ROBOCAR_RC_GLOBAL_SERIAL_H

#include "rc_global.h"
#include "rc_global_wheel.h"
//Usb COM recive buffer size
#define RC_SERIAL_MAX_RECIVE_BUFFER_SIZE 64
#define RC_SERIAL_MAX_SEND_BUFFER_SIZE 64
//encode search size
#define RC_SERIAL_SEARCH_SIZE 2

#define RC_SERIAL_SUB_BIT {'\r','\n'}
//USB serial open state output
#define RC_SERIAL_STRING_USB_OPEN_ERROR (char*)"Cant open USB COM"
#define RC_SERIAL_SREING_USB_OPEN_SUCCESS (char*)"Open USB serial"
#define RC_SERIAL_ERROR -1

#endif //ROBOCAR_RC_GLOBAL_SERIAL_H
