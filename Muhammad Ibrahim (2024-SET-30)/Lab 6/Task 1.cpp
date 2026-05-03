#include <iostream>
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
        cout << "Product Name: " << name << endl;
        cout << "Price: PKR" << price << endl;
    }
};

class Electronics : public Product
{
private:
    string warranty;

public:
    Electronics(string n, double p, string w) : Product(n, p)
    {
        warranty = w;
    }

    void display()
    {
        Product::display();
        cout << "Warranty: " << warranty << " Years" << endl;
    }
};

int main()
{
    cout << "Welcome to the Online Shopping System!" << endl;
    Electronics laptop("Laptop", 679.67, "2");

    cout << "Product Details:" << endl;
    laptop.display();
    return 0;
}