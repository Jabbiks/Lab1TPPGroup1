#include "shared_types.h"

// Початкова заглушка Студента А для першого коміту
std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data) {
    return std::make_unique<Result>(Result{
        0.0, // integral_value
        0.0, // error
        0,   // function_evaluations
        0.0  // execution_time_mcs
    });
}