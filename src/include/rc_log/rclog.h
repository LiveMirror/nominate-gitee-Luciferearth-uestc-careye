//
// Created by PulsarV on 18-5-10.
//

#ifndef ROBOCAR_RCLOG_H
#define ROBOCAR_RCLOG_H

#include <string>
namespace RC{
    namespace LOG{
        void printlog(char *logType,std::string str);
        void printlog(char *logType,char *str);
        void logSuccess(char *str);
        void logError(char *str);
        void logInfo(char *str);
    }
}
#endif //ROBOCAR_RCLOG_H
