#include <rc_main/main.h>


int main(int argc,char **argv) {
    RC::LOG::logInfo(RC_STRING_SYSTEM_START);
    int CAMERA_DEVICE=RC_CAMERA_DEVICE;
    char *SEERIAL_DEVICE=RC_SERIAL_DEVICE;
    for(int i=0;i<argc;i+=1){
        std::string commond=argv[i];
        if(commond=="-index")
            if(argv[i+1])
                CAMERA_DEVICE=atoi(argv[i+1]);
        if(commond=="-serial")
            if(argv[i+1])
                SEERIAL_DEVICE=argv[i+1];
        if(commond=="-help"){
            std::cout<<RC_COMMOND_HELP_INFO;
            return 0;
        }
    }
    RC::RobotCarMove robot;
    robot.init(CAMERA_DEVICE,SEERIAL_DEVICE);
    robot.start();
    return 0;
}


