#include "ComandHandler.hxx"
#include "Logger.hxx"
#include "OutputHandler.hxx"
#include <ctime>


void CommandHandler::PrintCommands()
{
    if (myCommands.size() == 0) {
        return;
    }
    OutputHandler::GlobalInstance()->Output ("bulk: ");

    for (auto anIt = myCommands.cbegin(); anIt != myCommands.cend(); ++anIt) {
        OutputHandler::GlobalInstance()->Output (*anIt);
        if (anIt != --myCommands.cend()) {
            OutputHandler::GlobalInstance()->Output (", ");
        }
    }
    OutputHandler::GlobalInstance()->Output ("\n");
    myCommands.clear();
}

void CommandHandler::AddCommand (const std::string& theCommand)
{
    if (theCommand == "{") {
        if (myNestedBlocks == 0) {
            PrintCommands();
            myCommands.clear();
        }
        myNestedBlocks++;
        return;
    }
    else if (theCommand == "}") {
        myNestedBlocks--;
        if (myNestedBlocks == 0) {
            PrintCommands();
        }
        return;
    }
    else if (theCommand == "}" && myNestedBlocks == 0) {
        OutputHandler::GlobalInstance()->Output ("Invalid block \n");
        return;
    }

    myCommands.push_back (theCommand);
    if ((myCommands.size() == myCommandsNumber) && myNestedBlocks == 0) {
        PrintCommands();
    }
}