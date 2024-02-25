#include <string>
#include <ctime>

class Logger
{
public:
    static Logger* GetLogger();
    void Log (const std::string& theMessage) const;
    
private:
    Logger() {};
    Logger (const Logger&) {};
    static void InitFileName();

    static std::ofstream myLogFile;
    static bool myInitialised;
    static std::string myFileName;
};