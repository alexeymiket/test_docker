/* 
./program --help
./program --input data.txt --operation mean
./program --input data.txt --operation variance
./program --input data.txt --operation standard_deviation
*/

/**
* @file main.cpp
* @brief Основная программа для статистических вычислений
* @author Alexey Miket
* @date 2025-05-23
* 
* @details Программа принимает входной файл с числами и выполняет
*          указанную статистическую операцию (среднее, дисперсия,
*          стандартное отклонение).
*/

#include <iostream> 
#include <fstream>
#include <vector> 
#include <string> 
#include <cstdlib> // Для функций C, таких как exit                                                      
#include "mylib.h"
 
/**
* @brief Выводит справочную информацию о программе
*/

void print_help() {
    std::cout << "Использование: program --input <файл> --operation <операция>\n"; 
    std::cout << "Операции:\n";
    std::cout << "  mean                Вычисление среднего\n"; 
    std::cout << "  variance            Вычисление дисперсии\n"; 
    std::cout << "  standard_deviation  Вычисление среднеквадратичного отклонения\n"; 
    std::cout << "Ключ --help для отображения этой справки.\n"; 
}

/**
* @brief Читает числа из файла
* @param filename Имя входного файла
* @return Вектор прочитанных чисел
* 
* @details Функция читает числа из файла, ограничивая максимальное количество 100 числами.
*          Если происходит ошибка чтения, выводит сообщение об ошибке.
*/

std::vector<double> read_numbers_from_file(const std::string& filename) {
    std::vector<double> numbers; 
    std::ifstream infile(filename); // Открываем файл для чтения

    if (!infile.is_open()) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    double number; // Переменная для временного хранения числа
    while (infile >> number) { // Читаем числа из файла
        if (numbers.size() < 100) { 
            numbers.push_back(number); // Добавляем число в вектор
        } else {
            std::cerr << "Превышено максимальное количество чисел (100).\n"; 
            break; 
        }
    }

    if (infile.fail() && !infile.eof()) { // Проверяем, произошла ли ошибка чтения
        std::cerr << "Ошибка чтения файла.\n"; 
    }

    return numbers; // Возвращаем вектор чисел
}

/**
* @brief Точка входа в программу
* @return Код завершения программы (EXIT_SUCCESS или EXIT_FAILURE)
* 
* @details Обрабатывает аргументы командной строки, читает числа из файла
*          и выполняет указанную статистическую операцию.
* 
* @note Доступные аргументы:
*       --input <файл>        Указание входного файла
*       --operation <операция> Выбор операции
*       --help                Вывод справки
*/

int main(int argc, char* argv[]) {
    if (argc < 5) { // Проверяем, достаточно ли аргументов
        std::cerr << "Недостаточно аргументов.\n"; 
        print_help(); 
        exit(0);
    }

    std::string input_file; // Переменная для хранения имени входного файла
    std::string operation; // Переменная для хранения операции

    // Обработка аргументов командной строки
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "--input") { // Если аргумент --input
            if (i + 1 < argc) { // Проверяем, есть ли следующее значение
                input_file = argv[i + 1]; // Сохраняем имя файла
                i++; // Пропускаем следующее значение
            } else {
                std::cerr << "Не указано имя файла.\n"; 
                return EXIT_FAILURE; 
            }
        } else if (std::string(argv[i]) == "--operation") { // Если аргумент --operation
            if (i + 1 < argc) { // Проверяем, есть ли следующее значение
                operation = argv[i + 1]; // Сохраняем операцию
                i++; // Пропускаем следующее значение
            } else {
                std::cerr << "Не указана операция.\n"; 
                return EXIT_FAILURE;
            }
        } else if (std::string(argv[i]) == "--help") { // Если аргумент --help
            print_help(); 
            exit(0);
        }
    }

    // Чтение чисел из файла
    std::vector<double> numbers = read_numbers_from_file(input_file);

    // Выполнение указанной операции
    try {
        if (operation == "mean") { 
            std::cout << "Среднее: " << Statistics::mean(numbers) << std::endl; 
        } else if (operation == "variance") { 
            std::cout << "Дисперсия: " << Statistics::variance(numbers) << std::endl; 
        } else if (operation == "standard_deviation") { 
            std::cout << "Среднеквадратичное отклонение: " 
                    << Statistics::standard_deviation(numbers) << std::endl; 
        } else {
            std::cerr << "Неизвестная операция: " << operation << std::endl; 
            print_help(); 
            return EXIT_FAILURE; 
        }
    } catch (const std::invalid_argument &e) { 
        std::cerr << "Ошибка: " << e.what() << std::endl; 
        return EXIT_FAILURE; 
    }

    return EXIT_SUCCESS; 
}