#pragma once
#include <functional>
#include <memory>

// Спільні вхідні дані для розрахунку визначеного інтеграла
struct InputData {
    std::function<double(double)> f; // Підінтегральна функція f(x)
    double a;                       // Ліва межа інтегрування
    double b;                       // Права межа інтегрування
    int n;                          // Кількість розбиттів (має бути парним)
    double exact_value;             // Точне аналітичне значення для підрахунку похибки
};

// Спільна структура результату роботи кожного з алгоритмів
struct Result {
    double integral_value;          // Обчислене значення інтеграла
    double error;                   // Абсолютна похибка
    int function_evaluations;       // Кількість викликів функції f(x)
    double execution_time_mcs;      // Час роботи алгоритму в мікросекундах
};

// Прототипи функцій Студента А та Студента Б
std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);