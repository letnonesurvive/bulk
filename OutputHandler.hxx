#include <string>
#include <iostream>

class OutputHandler
{
public:
    static OutputHandler* GlobalInstance();
    void Output (const std::string& theMessage) const;

private:
    OutputHandler() {};
    OutputHandler (const OutputHandler&) {};
};