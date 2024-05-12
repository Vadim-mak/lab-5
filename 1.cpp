#include <iostream>
#include <list>
#include <string>
#include <exception>

// Определение класса исключения
class VectException : public std::exception {
public:
    const char* what() const throw() {
        return "Ошибка вектора";
    }
};

// Шаблонный класс Vect
template <typename T>
class Vect {
private:
    std::list<T> data;

public:
    // Добавление элемента в вектор
    void push(T value) {
        data.push_back(value);
    }

    // Получение элемента по индексу
    T get(int index) {
        if (index < 0 || index >= data.size()) {
            throw VectException();
        }
        auto it = data.begin();
        std::advance(it, index);
        return *it;
    }

    // Вывод всех элементов вектора
    void print() {
        for (auto& value : data) {
            std::cout << value << std::endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    try {
        // Инстанцирование шаблона для int
        Vect<int> intVect;
        intVect.push(1);
        intVect.push(2);
        std::cout << "intVect:" << std::endl;
        intVect.print();

        // Инстанцирование шаблона для double
        Vect<double> doubleVect;
        doubleVect.push(1.1);
        doubleVect.push(2.2);
        std::cout << "\ndoubleVect:" << std::endl;
        doubleVect.print();

        // Инстанцирование шаблона для std::string
        Vect<std::string> stringVect;
        stringVect.push("one");
        stringVect.push("two");
        std::cout << "\nstringVect:" << std::endl;
        stringVect.print();

        // Пример вызова исключения
        std::cout << "\nПопытка доступа к несуществующему элементу:" << std::endl;
        intVect.get(10);
    }
    catch (VectException& e) {
        std::cout << "Исключение: " << e.what() << std::endl;
    }

    return 0;
}
