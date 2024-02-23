#include "Logger.hxx"
#include <fstream>

using namespace std;

ofstream Logger::myLogFile;
bool Logger::myInitialised = false;
string Logger::myFileName = "Log.log";

Logger* Logger::GetLogger()
{
    static Logger aLogger;
    if (!myInitialised) {
        myInitialised = true;
        myLogFile.open (myFileName, ios::out | ios::app);
    }
    return &aLogger;
}

void Logger::Log (const std::string& theMessage) const
{
    myLogFile << theMessage;
}