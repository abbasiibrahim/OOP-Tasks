#include <iostream>
using namespace std;

class Calculator
{
public:
    double add(double a, double b)
    {
        return a + b;
    }

    double multiply(double a, double b)
    {
        return a * b;
    }
};

class Student
{
private:
    string name;
    Calculator *calculator;

public:
    Student(string n, Calculator *calc)
    {
        name = n;
        calculator = calc;
    }

    void performAddition(double a, double b)
    {
        double result = calculator->add(a, b);
        cout << name << " get Addition Result: " << result << endl;
    }

    void performMultiplication(double a, double b)
    {
        double result = calculator->multiply(a, b);
        cout << name << " get Multiplication Result: " << result << endl;
    }
};

int main()
{
    Calculator sharedCalculator;

    Student s1("Ali", &sharedCalculator);
    Student s2("hammad", &sharedCalculator);

    s1.performAddition(10, 5);
    s2.performMultiplication(3, 7);

    return 0;
}
