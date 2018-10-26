//
// Created by PulsarV on 18-5-10.
//

#ifndef ROBOCAR_RC_GLOBAL_SERIAL_H
#define ROBOCAR_RC_GLOBAL_SERIAL_H

#include "rc_global.h"
#include "rc_global_wheel.h"
//Usb COM recive buffer size
#define RC_SERIAL_MAX_SEND_BUFFER_SIZE 64
//encode search size
#define RC_SERIAL_SEARCH_SIZE 2
#define RC_SERIAL_SUB_BIT {'\r','\n'}
//USB serial open state output
#define RC_SERIAL_STRING_USB_OPEN_ERROR (char*)"Cant open USB COM"
#define RC_SERIAL_SREING_USB_OPEN_SUCCESS (char*)"Open USB serial"
#define RC_SERIAL_ERROR -1
#define RC_SERIAL_MAX_RECIVE_BUFFER_SIZE 64
//JY901 COMMMOND
#define GYRO_COMMOND_ERROE "Commond Error or no commond default to set to once"
#define GYRO_0D1HZ 1
#define GYRO_0D5HZ 2
#define GYRO_1HZ 3
#define GYRO_2HZ 4
#define GYRO_5HZ 5
#define GYRO_10HZ 6
#define GYRO_20HZ 7
#define GYRO_50HZ 8
#define GYRO_100HZ 9
#define GYRO_200HZ 10
#define GYRO_ONCE 11
#define GYRO_CLOSE 12

#define GYRO_SERIAL_BACK_SPEED_0D1HZ 0xffaa030100
#define GYRO_SERIAL_BACK_SPEED_0D5HZ 0xffaa030200
#define GYRO_SERIAL_BACK_SPEED_1HZ 0xffaa030300
#define GYRO_SERIAL_BACK_SPEED_2HZ 0xffaa030400
#define GYRO_SERIAL_BACK_SPEED_5HZ 0xffaa030500
#define GYRO_SERIAL_BACK_SPEED_10HZ 0xffaa030600
#define GYRO_SERIAL_BACK_SPEED_20HZ 0xffaa030700
#define GYRO_SERIAL_BACK_SPEED_50HZ 0xffaa030800
#define GYRO_SERIAL_BACK_SPEED_100HZ 0xffaa030900
#define GYRO_SERIAL_BACK_SPEED_ONCE 0xffaa030a00
#define GYRO_SERIAL_BACK_SPEED_200HZ 0xffaa030b00
#define GYRO_SERIAL_BACK_SPEED_CLOSE 0xffaa030c00

#endif //ROBOCAR_RC_GLOBAL_SERIAL_H
















