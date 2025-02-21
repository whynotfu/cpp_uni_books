#include "MyStack.h"


bool isValidExpression(const std::string& stroka) {
    Stack proverka;
    for (char ch : stroka) {
        if (ch == '(' || ch == '[' || ch == '{') {
            proverka.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (proverka.isEmpty()) return false;
            char topChar = proverka.peek();
            if (topChar + 1 != ch && topChar + 2 != ch) {
                return false;
            }
            
            proverka.pop();
        }
    }
    return proverka.isEmpty();
}

int main() {
    std::string skobochki;
    std::cout << "Enter the string: ";
    std::cin >> skobochki;
    
    if (isValidExpression(skobochki)) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }
    
    return 0;
}
