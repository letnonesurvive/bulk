#include "ComandHandler.hxx"
#include "FileLogger.hxx"
#include "ConsoleLogger.hxx"

using namespace std;

int main (int argc, char *argv[])
{
    if (argc != 2) {
        return 1;
    }

    int aNumber = atoi (argv[1]);
    vector<string> aCommands;
    string aCommand;

    CommandHandler aHandler (aNumber);

    ConsoleLogger aConsLog (&aHandler);
    FileLogger aFileLog (&aHandler);

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
