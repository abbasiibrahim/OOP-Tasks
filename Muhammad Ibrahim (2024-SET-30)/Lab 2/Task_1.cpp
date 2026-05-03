#include<iostream>
using namespace std;

class Student{
    private:
    string name;
    int rollNumber;
    float marks;

 public:
    void getData(){
        cout<<"Enter Student Name: ";
        cin>>name;
        cout<<"Enter roll number; ";
        cin>>rollNumber;
        cout<<"Enter Marks: ";
        cin>>marks;
    }
    void displayData(){
        cout<<"\nStudent Information"<<endl;
        cout<<"Name :"<<name<<endl;
        cout<<"Roll Number :"<<rollNumber<<endl;
        cout<<"Marks :"<<marks;
    }
};
int main(){
    Student s1;
     
    s1.getData();
    s1.displayData();

    return 0;
}