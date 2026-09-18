#include <vector>
#include "student_b.h"
#include "student_a.h"
#include <tuple>
#include <iostream>

int main() {
    
    auto data = std::make_shared<InputData>();

    data->x = { 1, 2, 3, 4, 5 };
    data->y = { 2.1, 4.2, 5.8, 8.1, 9.9 };

    std::unique_ptr<Result> resultA = calculateA(data);
    auto [valueA1, valueA2] = std::move(*resultA);

    std::cout << valueA1;
    std::cout << "\n";
    std::cout << valueA2;
    std::cout << "\n";

    return 0;

}