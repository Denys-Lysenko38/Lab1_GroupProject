#include "student_a.h"
#include <memory>

std::unique_ptr<Result> calculateA(
    std::shared_ptr<const InputData> data)
{
    int n = data->x.size();

    double sumX = 0;
    double sumY = 0;
    double sumXY = 0;
    double sumX2 = 0;

    for (int i = 0; i < n; i++)
    {
        sumX += data->x[i];
        sumY += data->y[i];
        sumXY += data->x[i] * data->y[i];
        sumX2 += data->x[i] * data->x[i];
    }

    auto result = std::make_unique<Result>();

    result->a1 = (n * sumXY - sumX * sumY) /
        (n * sumX2 - sumX * sumX);

    result->a0 = (sumY - result->a1 * sumX) / n;

    return result;
}