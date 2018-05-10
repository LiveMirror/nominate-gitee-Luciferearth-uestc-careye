//
// Created by PulsarV on 18-5-10.
//

#include <rc_log/rclog.h>
#include <iostream>
void RC::LOG::printlog(char *logType,char *str) {
    std::cout<<logType<<str<<std::endl;
}
void RC::LOG::printlog(char *logType,std::string str) {
    std::cout<<logType<<str<<std::endl;
}
void RC::LOG::logSuccess(char *str) {
    RC::LOG::printlog("[SUCCESS] ",(char*)str);
}
void RC::LOG::logError(char *str) {
    RC::LOG::printlog("[ERROR] ",(char*)str);
}

void RC::LOG::logInfo(char *str) {
    RC::LOG::printlog("[SUCCESS] ",(char*)str);
}