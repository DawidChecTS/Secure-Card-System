#ifndef LOGENTRY_H
#define LOGENTRY_H

#include <string>

struct LogEntry {
    std::string userName;
    std::string floorName;
    std::string time;
    bool accessGranted;
};


#endif