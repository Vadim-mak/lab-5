#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(const T& element) {
        elements.push_back(element);
    }

    T pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::pop(): пустой стек");
        }
        T elem = elements.back();
        elements.pop_back();
        return elem;
    }

    T top() const {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::top(): пустой стек");
        }
        return elements.back();
    }

    bool empty() const {
        return elements.empty();
    }
};

int main() {
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    while (!intStack.empty()) {
        std::cout << intStack.top() << std::endl;
        intStack.pop();
    }

    return 0;
}
