#include <iostream>
#include <iomanip>
#include <cmath>
#include <numbers>
#include "shared_types.h"

int main() {
    // Вхідні дані: інтегруємо sin(x) на відрізку [0, pi], n = 1000, точне значення = 2.0
    auto data = std::make_shared<const InputData>(InputData{
        [](double x) { return std::sin(x); },
        0.0,
        std::numbers::pi,
        1000,
        2.0
    });

    std::cout << "================ NUMERICAL INTEGRATION ================" << std::endl;
    std::cout << std::fixed << std::setprecision(8);

    // --- Виклик алгоритму Студента А (Метод Сімпсона) ---
    auto resultA = calculateA(data);
    auto [valA, errA, evalsA, timeA] = *resultA; // Structured Bindings (C++20)

    std::cout << "\n[Student A] Simpson's Rule:" << std::endl;
    std::cout << "  Calculated Value: " << valA << std::endl;
    std::cout << "  Absolute Error:   " << errA << std::endl;
    std::cout << "  Function calls:   " << evalsA << std::endl;
    std::cout << "  Execution Time:   " << timeA << " microseconds" << std::endl;

    return 0;
}