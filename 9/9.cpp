#include <iostream>
#include <utility> // Для std::pair
#include<Windows.h>

// Функция, которая возвращает пару
std::pair<int, std::string> getPair() {
    return { 42, "ответ" };
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Создаем пару без функции
    std::pair<int, std::string> p1 = { 10, "привет" };
    std::cout << "Пара из main:\n";
    std::cout << "Ключ: " << p1.first << ", Значение: " << p1.second << "\n";

    // Получаем пару из функции
    auto p2 = getPair();
    std::cout << "\nПара из функции:\n";
    std::cout << "Число: " << p2.first << ", Строка: " << p2.second << "\n";

    // Еще одна пара, создадим прямо в коде
    std::pair<int, std::string> p3 = std::make_pair(99, "же");
    std::cout << "\nЕще одна пара:\n";
    std::cout << "Ключ: " << p3.first << ", Значение: " << p3.second << "\n";

    return 0;
}