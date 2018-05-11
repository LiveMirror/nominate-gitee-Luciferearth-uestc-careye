//
// Created by PulsarV on 18-5-10.
//

#ifndef ROBOCAR_RC_GLOBAL_SERIAL_H
#define ROBOCAR_RC_GLOBAL_SERIAL_H

#include "rc_global_serial.h"
//Usb COM recive buffer size
#define RC_MAX_RECIVE_BUFFER_SIZE 64
#define RC_MAX_SEND_BUFFER_SIZE 64
//initation bit
#define RC_SUB_BIT {'\r','\n'}
//encode search size
#define RC_SEARCH_SIZE 2
//USB serial open state output
#define RC_STRING_USB_OPEN_ERROR "Cant open USB COM"
#define RC_SREING_USB_OPEN_SUCCESS "Open USB serial"

#endif //ROBOCAR_RC_GLOBAL_SERIAL_H
