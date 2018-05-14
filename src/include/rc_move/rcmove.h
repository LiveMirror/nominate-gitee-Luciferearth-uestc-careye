//
// Created by PulsarV on 18-5-9.
//

#ifndef ROBOCAR_RCMOVE_H
#define ROBOCAR_RCMOVE_H

#include <rc_cv/rcCV.h>
#include <rc_log/rclog.h>
#include <rc_serial/rcserial.h>
#include <rc_globalVarable/rc_global_wheel.h>
namespace RC {
    class RobotCarMove {
    public:
        int camera_id = -1;
        RC::Serial *serial_device;

        int init(int camera_id, char *device);

        int start();

        void wheel_1_forward(double trangle);

        void wheel_1_backward(double trangle);

        void wheel_2_forward(double trangle);

        void wheel_2_backward(double trangle);

        void wheel_3_forward(double trangle);

        void wheel_3_backward(double trangle);

        void wheel_go_forward();

        void wheel_go_backward();

        void wheel_CW();//顺时针
        void wheel_AC();//逆时针
    };
}


#endif //ROBOCAR_RCMOVE_H
