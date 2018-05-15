#include <rc_main/main.h>

int main(int argc, char **argv) {
    RC::LOG::logInfo(RC_STRING_SYSTEM_START);
    int CAMERA_DEVICE = RC_CAMERA_DEVICE;
    char *CAMERA_VEDIO_FILE = NULL;
    char *SEERIAL_DEVICE = RC_SERIAL_DEVICE;
    for (int i = 0; i < argc; i += 1) {
        std::string commond = argv[i];
        if (commond == RC_PARAM_INDEX)
            if (argv[RC_START_PARAM])
                CAMERA_DEVICE = atoi(argv[RC_START_PARAM]);
        if (commond == RC_PARAM_SERIAL)
            if (argv[RC_START_PARAM])
                SEERIAL_DEVICE = argv[RC_START_PARAM];
        if (commond == RC_PARAM_VIDEO)
            if (argv[RC_START_PARAM])
                CAMERA_VEDIO_FILE = argv[RC_START_PARAM];
        if (commond == RC_PARAM_HELP) {
            std::cout << RC_COMMOND_HELP_INFO;
            return 0;
        }
    }
    RC::RobotCarMove robot;
    if (CAMERA_VEDIO_FILE != NULL)
        robot.init(CAMERA_VEDIO_FILE, SEERIAL_DEVICE);
    else
        robot.init(CAMERA_DEVICE, SEERIAL_DEVICE);
    robot.start();
    return 0;
}


