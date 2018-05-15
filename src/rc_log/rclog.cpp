//
// Created by PulsarV on 18-5-10.
//

#include <rc_log/rclog.h>
#include <iostream>
int RC::LOG::printlog(char *logType,char *str) {
    std::cout<<logType<<str<<std::endl;
    return 1;
}
int RC::LOG::printlog(char *logType,std::string str) {
    std::cout<<logType<<str<<std::endl;
    return 1;
}
int RC::LOG::logSuccess(char *str) {
    RC::LOG::printlog((char*)"[SUCCESS] ",str);
    return 1;
}
int RC::LOG::logError(char *str) {
    RC::LOG::printlog((char*)"[ERROR] ",str);
    return 0;
}

int RC::LOG::logInfo(char *str) {
    RC::LOG::printlog((char*)"[INFO] ",str);
    return 1;
}
int RC::LOG::logDebug(char *str) {
    RC::LOG::printlog((char*)"[DEBUG] ",str);
    return 1;
}