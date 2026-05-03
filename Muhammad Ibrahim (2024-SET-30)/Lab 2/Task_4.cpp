#include<iostream>
using namespace std;

class Temperature{
    public:
    float celsius;

    float convertTemp(){
        return (celsius * 9/5)+32;
    }
    void displayTemp(){
        cout<<"Temperature in fahrenheit :"<<convertTemp()<<endl;
    }
};
int main(){
    Temperature t;
    cout<<"Enter Temperature in Celsius :";
    cin>>t.celsius;

    t.displayTemp();
    return 0;
}