#include<iostream>
using namespace std;

class Rectangle{
    private:
    int length;
    int width;

    public:
    void setDimension();
    int area();
    int perimeter();
};

// Now we define functions outside the class
void Rectangle::setDimension(){
    cout<<"Enter length of Rectangle: ";
    cin>>length;
    cout<<"Enter width of Rectangle: ";
    cin>>width;
}
int Rectangle::area(){
    return length*width;
}
int Rectangle::perimeter(){
    return 2* (length+width);
}

int main(){
    Rectangle r;
    
    r.setDimension();

    cout<<"Area = "<<r.area()<<endl;
    cout<<"Perimeter = "<<r.perimeter()<<endl;

    return 0;
}