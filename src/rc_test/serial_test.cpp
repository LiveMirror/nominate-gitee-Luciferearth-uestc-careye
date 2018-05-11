//
// Created by PulsarV on 18-5-11.
//
#include <rc_serial/rcserial.h>
#include <zconf.h>
#include <iostream>

using namespace RC;

int main() {
    Serial sr;
    sr.openSerial("/dev/ttyUSB0");
    if (sr.isOpend()) {
        while (true) {
            if (sr.send("a")) {

            sleep(1);
                char buffer[64]={'\0'};
                sr.recive(buffer);
//                if(buffer[0]=='{')
                    std::cout << buffer << std::endl;
            }
        }
    }
    return 0;
}

