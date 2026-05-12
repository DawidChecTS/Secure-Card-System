#include <iostream>
#include <vector>
#include <ctime>  // for getting the current time
#include "LogServices.h"

// a method to add a log entry to the in-memory list of logs
void LogServices::addLog(std::string userName, std::string floorName, bool accessGranted) {
    // get current time
    time_t now = time(0);
    std::string currentTime = ctime(&now); // store the current time

    // removing the newline that ctime adds at the end 
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

// a method to filter logs by floor name and return the matching entries
std::vector<LogEntry> LogServices::getLogsByFloor(std::string floorName) {
    std::vector<LogEntry> floorLogs;
    
    // iterate through all logs and add those that match the floor name to the floorLogs vector
    for (LogEntry entry : logs) {
        if (entry.floorName == floorName) {
            floorLogs.push_back(entry);
        }
    }

    return floorLogs;
}