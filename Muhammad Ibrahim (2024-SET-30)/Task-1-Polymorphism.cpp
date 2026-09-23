#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double area()
    {
        return 0;
    }
};
class Rectangle : public Shape
{
public:
    double length, width;

    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }

    double area()override
    {
        return length * width;
    }
};

class Circle : public Shape
{
public:
    double radius;

    Circle(double r)
    {
        radius = r;
    }

    double area()override 
    {
        return 3.14 * radius * radius;
    }
};

int main()
{
    Shape *s;

    Rectangle r(10, 5);
    Circle c(7);

    s = &r;
    cout << "Rectangle Area: " << s->area() << endl;

    s = &c;
    cout << "Circle Area: " << s->area() << endl;

    return 0;
}