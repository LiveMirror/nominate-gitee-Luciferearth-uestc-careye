//
// Created by PulsarV on 18-5-11.
//
#include <rc_serial/rcserial.h>
#include <zconf.h>
#include <iostream>

using namespace RC;

int main() {
    Serial sr;
    sr.openSerial((char*)"/dev/ttyUSB0");
    int counter=0;
    if (sr.isOpend()) {
        while (true) {
            std::string p="aaaaaaaaaaaaaaaaaaaaaa";
            if(counter>1){
                p="bbbbbbbbbbbbbbbbbbbbbbb";
                counter=0;
            }
            sr.send(p);
            char buffer[64] = {'\0'};
            sr.recive(buffer);
            sleep(1);
            std::cout << buffer << std::endl;
            counter+=1;
        }

    }
    return 0;
}

