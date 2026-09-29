#include <iostream>
#include <memory>
#include <cmath>
#include <iomanip>
#include "shared_types.h"

int main() {
    // 1. Єдиний спільний екземпляр вхідних даних для обох студентів
    auto data = std::make_shared<const InputData>(InputData{
        .f = [](double x) { return std::sin(x); },
        .a = 0.0,
        .b = 3.14159265358979323846,
        .n = 1000,
        .exact_value = 2.0
    });

    std::cout << "=== Numerical Integration Comparison (Lab 1) ===" << std::endl;

    // 2. Виклик алгоритму Студента А (метод Сімпсона)
    auto resultA = calculateA(data);
    auto [valA, errA, callsA, timeA] = *resultA; // Structured bindings

    // 3. Виклик алгоритму Студента Б (метод трапецій)
    auto resultB = calculateB(data);
    auto [valB, errB, callsB, timeB] = *resultB; // Structured bindings

    // 4. Виведення результатів
    std::cout << std::fixed << std::setprecision(8);
    std::cout << "\n[Student A - Simpson Method]:" << std::endl;
    std::cout << "Value:           " << valA << std::endl;
    std::cout << "Absolute error:  " << errA << std::endl;
    std::cout << "Function calls:  " << callsA << std::endl;
    std::cout << "Execution time:  " << timeA << " microseconds" << std::endl;

    std::cout << "\n[Student B - Trapezoidal Method]:" << std::endl;
    std::cout << "Value:           " << valB << std::endl;
    std::cout << "Absolute error:  " << errB << std::endl;
    std::cout << "Function calls:  " << callsB << std::endl;
    std::cout << "Execution time:  " << timeB << " microseconds" << std::endl;

    // 5. Безпосереднє порівняння двох методів
    std::cout << "\n=== Methods Comparison ===" << std::endl;
    std::cout << "Difference (|A - B|): " << std::abs(valA - valB) << std::endl;
    if (errA < errB) {
        std::cout << "Simpson method was more accurate." << std::endl;
    } else {
        std::cout << "Trapezoidal method was more accurate." << std::endl;
    }

    return 0;
}