#include <iostream>
#include <vector>
#include <ctime>  // for getting current time
#include "LogServices.h"

void LogServices::addLog(std::string userName, std::string floorName, bool accessGranted) {
    // get current time
    time_t now = time(0);
    std::string currentTime = ctime(&now); // store the current time

    // remove newline that ctime adds at the end 
    currentTime.erase(currentTime.length() - 1);

    LogEntry entry;
    entry.userName = userName;
    entry.floorName = floorName;
    entry.time = currentTime;
    entry.accessGranted = accessGranted;

    logs.push_back(entry); // add to memory list
}

std::vector<LogEntry> LogServices::getLogs() {
    return logs;
}

std::vector<LogEntry> LogServices::getLogsByFloor(std::string floorName) {
    std::vector<LogEntry> floorLogs;

    for (LogEntry entry : logs) {
        if (entry.floorName == floorName) {
            floorLogs.push_back(entry);
        }
    }

    return floorLogs;
}