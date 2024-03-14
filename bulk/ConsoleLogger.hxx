#include "Observer.hxx"

class ConsoleLogger : public Observer
{
public:
    ConsoleLogger(Observable* theObservable);

    void Log(const std::string& theStr) override;
};