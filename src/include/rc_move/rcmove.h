//
// Created by PulsarV on 18-5-9.
//

#ifndef ROBOCAR_RCMOVE_H
#define ROBOCAR_RCMOVE_H

#include <rc_cv/rcCV.h>
#include <rc_serial/rcserial.h>

namespace RC {
    class RobotCarMove {
    public:
        int camera_id = -1;
        RC::Serial *serial_device;

        int init(int camera_id, char *device);

        int start();
    };
    namespace WHEEL {
        void wheel_1_forward(RC::Serial *serial, double trangle);

        void wheel_1_backward(RC::Serial *serial, double trangle);

        void wheel_2_forward(RC::Serial *serial, double trangle);

        void wheel_2_backward(RC::Serial *serial, double trangle);

        void wheel_3_forward(RC::Serial *serial, double trangle);

        void wheel_3_backward(RC::Serial *serial, double trangle);

        void wheel_go_forward(RC::Serial *serial);

        void wheel_go_backward(RC::Serial *serial);

        void wheel_CW(RC::Serial *serial);//顺时针
        void wheel_AC(RC::Serial *serial);//逆时针
    }
}


#endif //ROBOCAR_RCMOVE_H
