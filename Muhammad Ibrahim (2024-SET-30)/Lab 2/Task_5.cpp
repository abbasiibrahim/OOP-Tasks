#include <iostream>
using namespace std;

class Calculator {
public:
    float num1, num2;

    void add();
    void subtract();
    void multiply();
    void divide();
};

void Calculator::add() {
    cout << "Result: " << num1 + num2 << endl;
}

void Calculator::subtract() {
    cout << "Result: " << num1 - num2 << endl;
}

void Calculator::multiply() {
    cout << "Result: " << num1 * num2 << endl;
}

void Calculator::divide() {
    if (num2 != 0)
        cout << "Result: " << num1 / num2 << endl;
    else
        cout << "Error: Division by zero!" << endl;
}

int main() {
    Calculator c;
    int choice;

    cout << "Enter two numbers: ";
    cin >> c.num1 >> c.num2;

    cout << "\nChoose operation:\n";
    cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
    cin >> choice;

    switch (choice) {
        case 1: c.add(); break;
        case 2: c.subtract(); break;
        case 3: c.multiply(); break;
        case 4: c.divide(); break;
        default: cout << "Invalid choice!";
    }
    return 0;
}