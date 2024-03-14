#include "ConsoleLogger.hxx"

ConsoleLogger::ConsoleLogger(Observable* theObservable)
{
	theObservable->Subscribe(this);
}

void ConsoleLogger::Log(const std::string& theStr)
{
	std::cout << theStr;
}