//
// Created by PulsarV on 18-5-15.
//
#include <rc_serial/rcserial.h>
namespace RC{
    class GyroCommond:public Serial{
    public:
        void setBackContent(char **arg);
        void setBackSpeed(int speed);
        void getContent(char *buffer,int size);
    };
}
