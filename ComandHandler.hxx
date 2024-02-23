#include <iostream>
#include <string>
#include <vector>

class CommandHandler
{
public:
    CommandHandler() {};

    CommandHandler (int theCommandNumber) : myCommandsNumber (theCommandNumber) {};

    void PrintCommands();

    void AddCommand (const std::string& theCommand);

private:
    size_t myCommandsNumber;
    int myNestedBlocks = 0;
    std::vector<std::string> myCommands;
};
