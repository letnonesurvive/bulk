#pragma once

#include <string>
#include <iostream>
#include <ctime>
#include <fstream>
#include <chrono>
#include <sstream>

class Observer
{
public:
    virtual ~Observer() = default;
    virtual void Log (const std::string&) = 0;
};

class Observable 
{
public:
    virtual ~Observable() = default;
    virtual void Subscribe (Observer* obs) = 0;
};

