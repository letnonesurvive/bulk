#include "Observer.hxx"

class FileLogger : public Observer
{
public:
    FileLogger(Observable* theObservable);

    void Log(const std::string& theStr) override;

    void InitFileName();

private:
    std::ofstream myLogFile;
    bool myInitialised = false;
    std::string myFileName = "bulk";
};