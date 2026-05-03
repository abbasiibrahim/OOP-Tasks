#include<iostream>
using namespace std;

class Person{
    private:
    string name;
    int age;

    public:
    void input_person(){
        cout<<"Enter the Name: ";
        cin>>name;
        cout<<"Enter age: ";
        cin>>age;
    }
    void display_person(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};

class Employee:public Person{
    private:
    int employee_id;

    public:
    void input_employee(){
        input_person();
        cout<<"Enter the Employee id: ";
        cin>>employee_id;
    }
    void display_employee(){
        display_person();
        cout<<"Employee id: "<<employee_id<<endl;
    }
};

class Manager: public Employee{
    private:
    string department;
    public:
    void input_manager(){
        input_employee();
        cout<<"ENter Department: ";
        cin>>department;
    }
    void display_manager(){
        display_employee();
        cout<<"Department: "<<department<<endl;
    }
};

int main(){
    Manager m;
    m.input_manager();

    cout<<"\n Manager information \n";
    m.display_manager();

    return 0;
}