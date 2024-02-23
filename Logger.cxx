#include "Logger.hxx"
#include <fstream>
#include <chrono>
#include <ctime>
#include <sstream>

using namespace std;

ofstream Logger::myLogFile;
bool Logger::myInitialised = false;
string Logger::myFileName = "bulk";

Logger* Logger::GetLogger()
{
    static Logger aLogger;
    if (!myInitialised) {
        myInitialised = true;
        InitFileName();
        myLogFile.open (myFileName, ios::out | ios::app);
    }
    return &aLogger;
}

void Logger::Log (const std::string& theMessage) const
{
    myLogFile << theMessage;
}

void Logger::InitFileName()
{
    auto aCurrentTime = std::chrono::system_clock::now();
    auto aTimeStamp = std::chrono::system_clock::to_time_t (aCurrentTime);
    std::stringstream aTime;
    aTime << aTimeStamp;
    myFileName = myFileName + aTime.str() + ".log";
}