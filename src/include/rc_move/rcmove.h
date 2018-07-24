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
        int init(int camera_id, char *device,char *mapping);

        int init(char *video, char *device,char *mapping);

        int start();

        void command(char com);

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
    private:
        int camera_id = -1;
        RC::Serial *serial_device;
        char *video = NULL;
        int type = 0;
        char *mapping=NULL;
        bool AutoMove=false;
        int init_serial_device(char *device);
    };
}


#endif //ROBOCAR_RCMOVE_H
