#include "ComandHandler.hxx"
#include <ctime>


void CommandHandler::PrintCommands()
{
    if (myCommands.size() == 0) {
        return;
    }
    Notify ("bulk: ");

    for (auto anIt = myCommands.cbegin(); anIt != myCommands.cend(); ++anIt) {
        Notify (*anIt);
        if (anIt != --myCommands.cend()) {
            Notify (", ");
        }
    }
    Notify ("\n");
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
        Notify ("Invalid block \n");
        return;
    }

    myCommands.push_back (theCommand);
    if ((myCommands.size() == myCommandsNumber) && myNestedBlocks == 0) {
        PrintCommands();
    }
}

void CommandHandler::Subscribe (Observer* theObs)
{
    mySubscribers.push_back (theObs);
}

void CommandHandler::Notify (const std::string& theStr) const
{
    for (auto aSub : mySubscribers) {
        aSub->Log(theStr);
    }
}