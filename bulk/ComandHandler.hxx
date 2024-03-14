#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Observer.hxx"

#if defined _WIN64 || defined _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__((visibility("default")))
#endif

class CommandHandler : public Observable
{
public:
    EXPORT CommandHandler() {};

    EXPORT CommandHandler (int theCommandNumber) : myCommandsNumber (theCommandNumber) {};

    EXPORT void PrintCommands();

    EXPORT void AddCommand (const std::string& theCommand);

    EXPORT void Subscribe (Observer* theObs) override;

    EXPORT void Notify (const std::string& theStr) const;

private:
    size_t myCommandsNumber;
    int myNestedBlocks = 0;
    std::vector<std::string> myCommands;
    std::vector<Observer*> mySubscribers;
};
