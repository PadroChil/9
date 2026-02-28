#include <utility>
#include <iostream>
#include <string>
#include <type_traits>
#include <Windows.h>

// Тестовая шаблонная функция, использующая perfect forwarding, as_const и declval
template <typename T>
void process(T&& arg) 
{
    // as_const просто возвращает const-ссылку на аргумент
    auto& const_arg = std::as_const(arg);
    std::cout << "Передано значение: " << const_arg << "\n";

    // declval позволяет получить тип объекта без его создания
    using TType = decltype(std::declval<T>());
    // Демонстрируем тип T через declval()
    std::cout << "Тип T по declval: " << typeid(TType).name() << "\n";
}

// Главная функция
int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // --- Работа с pair ---
    // Создание пары с помощью make_pair (автоматическое определение типов)
    auto p = std::make_pair(42, std::string("Ответ"));
    std::cout << "pair: " << p.first << ", " << p.second << "\n";

    // --- Обмен значений с помощью swap ---
    int a = 10, b = 20;
    std::cout << "До swap: a = " << a << ", b = " << b << "\n";
    std::swap(a, b);  // обмен значений a и b
    std::cout << "После swap: a = " << a << ", b = " << b << "\n";

    // --- Обмен с помощью exchange ---
    std::string s = "старое";  // исходное значение
    // exchange заменяет значение s на "новое" и возвращает старое
    auto old_value = std::exchange(s, "новое");
    std::cout << "Exchange: старое было '" << old_value << "', теперь s = '" << s << "'\n";

    // --- Перемещение ресурсов с помощью move ---
    // Изначальный объект
    std::string str1 = "Перемещаемое";
    // str2 получает ресурсы str1, str1 становится пустым
    std::string str2 = std::move(str1);
    std::cout << "После move: str2 = '" << str2 << "', str1 = '" << str1 << "' (пустой)\n";

    // --- Использование as_const ---
    const std::string s_const = "константа";
    auto& ref_const = std::as_const(s_const);  // Получаем const-ссылку
    std::cout << "Использование as_const: " << ref_const << "\n";

    // --- Использование declval ---
    // Определение типа возвращаемого значения size()
    using SizeType = decltype(std::declval<std::string>().size());
    std::cout << "Тип, возвращаемый size(): " << typeid(SizeType).name() << "\n";

    // --- Передача аргумента через perfect forwarding ---
    process(std::string("Переданное значение"));

    return 0;
}