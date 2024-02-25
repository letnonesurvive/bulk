#include "../bulk/ComandHandler.hxx"

#include <string>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

void TestCase(const vector<string>& theCommands)
{
    int aNumber = 3;
   
    CommandHandler aHandler(aNumber);
    for (const auto& aCommand : theCommands) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << aCommand << endl;
        if (aCommand == "EOF") {
            aHandler.PrintCommands();
            break;
        }
        aHandler.AddCommand (aCommand);
    }
}

int main()
{
    vector<string> aTestCommands1 = { "cmd1", "cmd2", "cmd3", "cmd4", "cmd5" , "EOF" };
    TestCase (aTestCommands1);

    cout << endl;
    vector<string> aTestCommands2 = { "cmd1", "cmd2", 
                                     "{", "cmd3", "cmd4" , "}", 
                                     "{", "cmd5" , "cmd6" , "{", "cmd7", "cmd8", "}" ,"cmd9", "}", 
                                     "{", "cmd10", "cmd11", "EOF"};
   
    TestCase (aTestCommands2);

    return 0;
}