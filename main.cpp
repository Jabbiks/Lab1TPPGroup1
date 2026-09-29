#include <iostream>
#include <memory>
#include <cmath>
#include <iomanip>
#include "shared_types.h"

int main() {
    // 1. Створюємо спільні вхідні дані для розрахунку інтеграла sin(x) від 0 до PI
    // Точне аналітичне значення інтеграла sin(x) на [0, PI] дорівнює 2.0
    auto data = std::make_shared<const InputData>(InputData{
        .f = [](double x) { return std::sin(x); },
        .a = 0.0,
        .b = 3.14159265358979323846,
        .n = 1000,
        .exact_value = 2.0
    });

    std::cout << "=== Numerical Integration (Lab 1) ===" << std::endl;

    // 2. Виклик алгоритму Студента Б (метод трапецій)
    auto resultB = calculateB(data);

    // 3. Розпакування всіх 4 полів через Structured Bindings (вимога C++20)
    auto [valB, errB, callsB, timeB] = *resultB;

    // 4. Виведення результатів роботи вашого методу
    std::cout << "\n[Student B - Trapezoidal Method]:" << std::endl;
    std::cout << "Calculated value: " << std::fixed << std::setprecision(8) << valB << std::endl;
    std::cout << "Absolute error:   " << errB << std::endl;
    std::cout << "Function calls:   " << callsB << std::endl;
    std::cout << "Execution time:   " << timeB << " microseconds" << std::endl;

    return 0;
}