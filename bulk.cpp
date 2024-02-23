// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CommandHandler
{
public:
    CommandHandler() {};

    CommandHandler (int theCommandHandler) : myCommandsNumber (theCommandHandler) {};

    void PrintCommands()
    {
        if (myCommands.size() == 0) {
            return;
        }
        cout << "bulk: ";
        for (auto anIt = myCommands.cbegin(); anIt != myCommands.cend(); ++anIt) {
            cout << *anIt;
            if (anIt != --myCommands.cend()) {
                cout << ", ";
            }
        }
        cout << endl;
        myCommands.clear();
    }

    void AddCommand (const string& aCommand)
    {
        if (aCommand == "{") {
            if (myNestedBlocks == 0) {
                PrintCommands();
                myCommands.clear();
            }
            myNestedBlocks++;
            return;
        }
        else if (aCommand == "}") {
            myNestedBlocks--;
            if (myNestedBlocks == 0) {
                PrintCommands();
            }
            return;
        }
        else if (aCommand == "}" && myNestedBlocks == 0) {
            cout << "Invalid block" << endl;
            return;
        }

        myCommands.push_back (aCommand);
        if (myCommands.size() == myCommandsNumber && myNestedBlocks == 0) {
            PrintCommands();
        }
    }

private:
    int myCommandsNumber;
    int myNestedBlocks = 0;
    vector<string> myCommands;
};

int main(int argc, char *argv[])
{
    if (argc != 2) {
        return 1;
    }

    int aNumber = atoi (argv[1]);

    vector<string> aCommands;

    string aCommand;

    CommandHandler aHandler (aNumber);

    while (true) {
        cin >> aCommand;
        if (aCommand == "EOF") {
            aHandler.PrintCommands();
            break;
        }
        aHandler.AddCommand (aCommand);
    }

    return 0;
}
