#include <rc_main/main.h>
#include <rc_move/rcmove.h>
#include <fcntl.h>
#include <zconf.h>

int main() {
    RC::RobotCarMove robot;
    robot.init(RC_CAMERA_DEVICE,RC_SEERIAL_DEVICE);
    robot.start();
    return 0;
}


