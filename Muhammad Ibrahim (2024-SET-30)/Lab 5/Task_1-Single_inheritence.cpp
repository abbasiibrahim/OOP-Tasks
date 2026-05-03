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
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    void display_person_info(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};

class Student:public Person{
    private:
    int student_id;

    public:
    void input_student(){
        input_person();
        cout<<"Eneter Student ID: ";
        cin>>student_id;
    }
    void display_student_info(){
        display_person_info();
        cout<<"Student ID: "<<student_id<<endl;
    }
};

int main(){
    Student s;
    s.input_student();
    cout<<"\n Student Info  \n";
    s.display_student_info();
    return 0;
}
