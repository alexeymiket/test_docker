/**
* @file mylib.cpp
* @brief Реализация методов класса Statistics
* @author Alexey Miket
* @date 2025-05-23
* 
* @details Этот файл содержит реализацию методов класса Statistics
*          для выполнения статистических вычислений.
*/

#include "mylib.h"
#include <stdexcept> // Для обработки исключений
#include <cmath>     // Для математических функций

/**
* @brief Реализация метода вычисления среднего значения
* @param numbers Вектор чисел для анализа
* @return Среднее арифметическое значение
* @throw std::invalid_argument Если входной вектор пуст
*/

double Statistics::mean(const std::vector<double>& numbers) {
    if (numbers.empty()) { // Проверяем, пуст ли вектор
        throw std::invalid_argument("Список чисел пуст."); 
    }
    double sum = 0.0; 
    for (double num : numbers) { // Проходим по всем числам в векторе
        sum += num;
    }
    return sum / numbers.size(); // Возвращаем среднее значение
}

/**
* @brief Реализация метода вычисления дисперсии
* @param numbers Вектор чисел для анализа
* @return Значение дисперсии
* @throw std::invalid_argument Если входной вектор пуст
*/

double Statistics::variance(const std::vector<double>& numbers) {
    if (numbers.empty()) { // Проверяем, пуст ли вектор
        throw std::invalid_argument("Список чисел пуст."); 
    }
    double avg = mean(numbers); // Вычисляем среднее
    double var_sum = 0.0; // Cумма квадратов отклонений
    for (double num : numbers) { 
        var_sum += (num - avg) * (num - avg); // Считаем квадрат отклонения от среднего
    }
    return var_sum / numbers.size(); // Возвращаем дисперсию
}

/**
* @brief Реализация метода вычисления стандартного отклонения
* @param numbers Вектор чисел для анализа
* @return Значение стандартного отклонения
* @note Стандартное отклонение - это квадратный корень из дисперсии
*/

double Statistics::standard_deviation(const std::vector<double>& numbers) {
    return std::sqrt(variance(numbers)); // Возвращаем квадратный корень из дисперсии
}