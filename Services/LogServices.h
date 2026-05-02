#ifndef LOGSERVICES_H
#define LOGSERVICES_H
#include "../Models/LogEntry.h"
#include <vector>


class LogServices {
    public :
    void addLog(std::string userName, std::string floorName, bool accessGranted);
    std::vector<LogEntry> getLogs();
    std::vector<LogEntry> getLogsByFloor(std::string floorName);

    private :
    std::vector<LogEntry> logs;
};

#endif