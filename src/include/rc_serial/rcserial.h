//
// Created by PulsarV on 18-5-10.
//

#ifndef ROBOCAR_RCSERIAL_H
#define ROBOCAR_RCSERIAL_H

#include <map>
#include <string>
#ifdef __linux__

#else

#endif
namespace RC{
    typedef std::map<std::string,std::string> SERIAL_FLAGS;
    typedef std::pair<std::string, std::string> SERIAL_FLAG;
    class Serial{
    public:
#ifdef __linux__
        int openSerial(char* device);
        int send(std::string str);////////////////
        SERIAL_FLAGS recive(char *buffer);
        bool isOpend();
        int release();
#else

#endif
    private:
        int device_point;
        char* device;
    };
    namespace STRING {
        int serial_search_find(const char *chr_1, const char *chr_2);
        RC::SERIAL_FLAGS serial_encode(char *data);
    }
}
#endif //ROBOCAR_RCSERIAL_H
