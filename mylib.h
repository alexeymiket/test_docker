/**
* @file mylib.h
* @brief Заголовочный файл библиотеки статистических вычислений
* @author Alexey Miket
* @date 2025-05-23
* 
* @details Этот файл содержит объявление класса Statistics для выполнения
*          базовых статистических вычислений над массивом чисел.
*/

#ifndef MYLIB_H // Проверяем, определен ли MYLIB_H
#define MYLIB_H // Если не определен, определяем MYLIB_H

#include <vector>

/**
* @class Statistics
* @brief Класс для выполнения статистических вычислений
* 
* @details Класс предоставляет статические методы для вычисления основных
*          статистических показателей: среднего значения, дисперсии и
*          стандартного отклонения.
*/

class Statistics {
public:

    /**
    * @brief Вычисляет среднее арифметическое значение
    * @param numbers Вектор чисел для вычислений
    * @return Среднее значение
    */

    static double mean(const std::vector<double>& numbers);

    /**
    * @brief Вычисляет дисперсию
    * @param numbers Вектор чисел для вычислений
    * @return Значение дисперсии
    */

    static double variance(const std::vector<double>& numbers);
 
    /**
    * @brief Вычисляет стандартное отклонение
    * @param numbers Вектор чисел для вычислений
    * @return Значение стандартного отклонения
    */

     static double standard_deviation(const std::vector<double>& numbers);
};

#endif