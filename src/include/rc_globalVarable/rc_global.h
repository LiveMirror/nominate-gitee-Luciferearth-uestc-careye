//
// Created by PulsarV on 18-5-10.
//

#define RADIAN CV_PI/180.0

#define ROBOCAR_RC_GLOBAL_H
#define TEST 0
#define RC_SERIAL_DEVICE (char*)"/dev/ttyUSB0"
#define RC_CAMERA_DEVICE 0
#define RC_PLAY_BY_CAMERA 0
#define RC_PLAY_BY_VIDEO 1

#ifdef __linux__
#define RC_NULL_POINT nullptr
#endif
#ifdef __win32__
#define RC_NULL_POINTER NULL
#endif
