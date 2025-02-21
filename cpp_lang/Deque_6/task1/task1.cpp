#include "MyDeque.h"
#include <iostream>
#include <string>

bool isPalindrome(const std::string& str) {
    Deque dq;

    // Заполняем дек символами строки
    for (char ch : str) {
        if (std::isalpha(ch)) { // Игнорируем пробелы и символы
            dq.pushBack(std::tolower(ch));
        }
    }

    // Сравниваем символы с двух концов
    while (dq.getSize() > 1) {
        if (dq.getFront() != dq.getBack()) {
            return false;
        }
        dq.popFront();
        dq.popBack();
    }
    return true;
}

int main() {
    std::string input;
    std::cout << "Enter smth ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "This IS a Polyndrome\n";
    } else {
        std::cout << "This is NOT a Polyndrome.\n";
    }
    
    return 0;
}
