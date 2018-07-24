//
// Created by PulsarV on 18-5-10.
//

#ifndef ROBOCAR_RCLOG_H
#define ROBOCAR_RCLOG_H

#include <string>
namespace RC{
    namespace LOG{
        int printlog(char *logType,std::string str);
        int printlog(char *logType,char *str);
        int logSuccess(char *str);
        int logError(char *str);
        int logInfo(char *str);
        int logDebug(char *str);
    }
}
#endif //ROBOCAR_RCLOG_H
