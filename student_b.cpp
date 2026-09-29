#include "shared_types.h"
#include <memory>
#include <cmath>
#include <chrono>

std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data) {
    // Фіксація початкового часу для вимірювання швидкодії
    auto start_time = std::chrono::high_resolution_clock::now();

    double a = data->a;
    double b = data->b;
    int n = data->n;
    double h = (b - a) / n;

    // Метод трапецій: h * ((f(a) + f(b)) / 2 + sum(f(x_i)))
    double sum = 0.5 * (data->f(a) + data->f(b));
    int calls = 2; // f(a) та f(b)

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += data->f(x);
        calls++;
    }

    double integral = sum * h;

    // Фіксація кінцевого часу та обчислення тривалості в мікросекундах
    auto end_time = std::chrono::high_resolution_clock::now();
    double elapsed_mcs = std::chrono::duration<double, std::micro>(end_time - start_time).count();

    // Заповнення структури згідно з shared_types.h
    auto result = std::make_unique<Result>();
    result->integral_value = integral;
    result->error = std::abs(integral - data->exact_value);
    result->function_evaluations = calls;
    result->execution_time_mcs = elapsed_mcs;

    return result;
}