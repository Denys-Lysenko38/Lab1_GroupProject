#include "shared_types.h"
#include <memory>
#include "student_b.h"
#include <iostream>

std::unique_ptr<Result> calculateB(
    std::shared_ptr<const InputData> data)
{
    int n = data->x.size();

    double sumX = 0;
    double sumX2 = 0;
    double sumX3 = 0;
    double sumX4 = 0;

    double sumY = 0;
    double sumXY = 0;
    double sumX2Y = 0;

    for (int i = 0; i < n; i++)
    {
        double x = data->x[i];
        double y = data->y[i];

        double x2 = x * x;

        sumX += x;
        sumX2 += x2;
        sumX3 += x2 * x;
        sumX4 += x2 * x2;

        sumY += y;
        sumXY += x * y;
        sumX2Y += x2 * y;
    }

    double A[3][4] =
    {
        { (double)n, sumX,  sumX2, sumY },
        { sumX,      sumX2, sumX3, sumXY },
        { sumX2,     sumX3, sumX4, sumX2Y }
    };

    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            double factor = A[j][i] / A[i][i];

            for (int k = i; k < 4; k++)
            {
                A[j][k] -= factor * A[i][k];
            }
        }
    }

    double a2 = A[2][3] / A[2][2];

    double a1 = (A[1][3] - A[1][2] * a2) / A[1][1];

    double a0 = (A[0][3] - A[0][1] * a1 - A[0][2] * a2)
        / A[0][0];

    auto result = std::make_unique<Result>();

    result->a0 = a0;
    result->a1 = a1;
    result->a2 = a2;

    return result;
}
