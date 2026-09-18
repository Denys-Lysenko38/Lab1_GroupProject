#pragma once

#include <vector>

struct InputData
{
    std::vector<double> x;
    std::vector<double> y;
};

struct Result
{
    double a0;
    double a1;
    double a2;
    double error;
};