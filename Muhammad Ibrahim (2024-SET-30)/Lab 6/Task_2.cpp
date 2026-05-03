#include <iostream>
#include <string>
using namespace std;

class Product
{
protected:
    string name;
    double price;

public:
    Product(string n, double p)
    {
        name = n;
        price = p;
    }

    void display()
    {
        cout << "Name    : " << name << endl;
        cout << "Price   : PKR" << price << endl;
    }
};

class Electronics : public Product
{
private:
    int warrantyYears;

public:
    Electronics(string n, double p, int wy) : Product(n, p)
    {
        warrantyYears = wy;
    }

    void display()
    {
        Product::display();
        cout << "Warranty: " << warrantyYears << " years" << endl;
    }
};

int main()
{
    Electronics item("Samsung Galaxy", 678.67, 2);
    item.display();
    return 0;
}