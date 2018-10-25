//
// Created by PulsarV on 18-5-11.
//
#include <rc_serial/rcserial.h>
#ifdef __linux__
#include <zconf.h>
#endif // __linux__
#include <iostream>
#include <cstring>

using namespace RC;

int main() {
#ifdef __linux__
    Serial sr;
    sr.openSerial((char*)"/dev/ttyUSB0");
    int counter=0;
    if (sr.isOpend()) {
        while (true) {
            std::string p="a";
            if(counter>1){
                p="a";
                counter=0;
            }
            sr.send(p);
            char buffer[64] = {'\0'};
            sleep(1);
            if(strlen(buffer)>0){
                std::cout << buffer << std::endl;
            }
            counter+=1;
        }

    }
    return 0;
}
#endif // __linux__

