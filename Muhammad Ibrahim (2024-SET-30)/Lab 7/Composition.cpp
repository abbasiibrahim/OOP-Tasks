#include <iostream>
using namespace std;

class Display {
private:
    double lastResult;

public:
    Display() {
        lastResult = 0;
    }

    void show(double result) {
        lastResult = result;
        cout << "Result: " << result << endl;
    }

    double getLastResult() {
        return lastResult;
    }
};

class Calculator {
private:
    Display display;

public:
    void add(double a, double b) {
        double result = a + b;
        display.show(result);
    }

    void multiply(double a, double b) {
        double result = a * b;
        display.show(result);
    }

    void showLastResult() {
        cout << "Last Result: " << display.getLastResult() << endl;
    }
};

int main() {
    Calculator calc;

    calc.add(5, 3);
    calc.multiply(4, 5);
    calc.showLastResult();

    return 0;
}
