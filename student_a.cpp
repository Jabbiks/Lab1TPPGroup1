#include "shared_types.h"
#include <chrono>
#include <cmath>
#include <stdexcept>

std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data) {
    if (!data) {
        throw std::invalid_argument("InputData pointer is null");
    }
    if (data->n <= 0) {
        throw std::invalid_argument("Number of intervals (n) must be positive");
    }
    if (data->n % 2 != 0) {
        throw std::invalid_argument("Simpson's method requires an even number of intervals (n)");
    }

    // Замір початкового часу
    auto start_time = std::chrono::high_resolution_clock::now();

    double h = (data->b - data->a) / data->n;
    double sum = data->f(data->a) + data->f(data->b);
    int evals_count = 2; // f(a) та f(b)

    for (int i = 1; i < data->n; ++i) {
        double x = data->a + i * h;
        if (i % 2 == 1) {
            sum += 4.0 * data->f(x);
        } else {
            sum += 2.0 * data->f(x);
        }
        evals_count++;
    }

    double integral = (h / 3.0) * sum;

    // Замір кінцевого часу
    auto end_time = std::chrono::high_resolution_clock::now();
    double elapsed_mcs = std::chrono::duration<double, std::micro>(end_time - start_time).count();

    // Абсолютна похибка
    double err = std::abs(integral - data->exact_value);

    // Повернення результату через unique_ptr
    return std::make_unique<Result>(Result{
        integral,
        err,
        evals_count,
        elapsed_mcs
    });
}