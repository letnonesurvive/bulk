#include <iostream>
#include <string>
#include <vector>

#ifdef _WIN32 || _WIN64
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__((visibility("default")))
#endif

class CommandHandler
{
public:
    EXPORT CommandHandler() {};

    EXPORT CommandHandler (int theCommandNumber) : myCommandsNumber (theCommandNumber) {};

    EXPORT void PrintCommands();

    EXPORT void AddCommand (const std::string& theCommand);

private:
    size_t myCommandsNumber;
    int myNestedBlocks = 0;
    std::vector<std::string> myCommands;
};
