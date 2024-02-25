#include "OutputHandler.hxx"
#include "Logger.hxx"

OutputHandler* OutputHandler::GlobalInstance()
{
    static OutputHandler aHandler;
    return &aHandler;
}

void OutputHandler::Output (const std::string& theMessage) const
{
    std::cout << theMessage;
    Logger::GetLogger()->Log (theMessage);

}