#include <rc_main/main.h>
#include <rc_move/rcmove.h>

int main() {
    RC::RobotCarMove robot;
    robot.init(1,"/");
    robot.start();
    return 0;
}


