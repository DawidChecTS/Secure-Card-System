#ifndef LOGENTRY_H
#define LOGENTRY_H

#include <string>

// LogEntry struct to represent access logs in the system
struct LogEntry {
    std::string userName;
    std::string floorName;
    std::string time;
    bool accessGranted;
};
#endif