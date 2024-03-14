#include "FileLogger.hxx"

FileLogger::FileLogger(Observable* theObservable)
{
    if (!myInitialised) {
        theObservable->Subscribe(this);
        myInitialised = true;
        InitFileName();
        myLogFile.open(myFileName, std::ios::out | std::ios::app);
    }
}

void FileLogger::Log(const std::string& theStr)
{
    myLogFile << theStr;
}

void FileLogger::InitFileName()
{
    auto aCurrentTime = std::chrono::system_clock::now();
    auto aTimeStamp = std::chrono::system_clock::to_time_t(aCurrentTime);
    std::stringstream aTime;
    aTime << aTimeStamp;
    myFileName = myFileName + aTime.str() + ".log";
}