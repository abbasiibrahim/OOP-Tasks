#include <iostream>
using namespace std;

struct Student
{
    string first_Name;
    string last_Name;
    int roll_Number;
    float marks;

    void displayStudentInfo()
    {
        cout << "Full Name: " << first_Name << " " << last_Name << endl;
        cout << "Roll Number: " << roll_Number << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main()
{
    Student s1;
    s1.first_Name = "Muhammad";
    s1.last_Name = "Ibrahim";
    s1.roll_Number = 30;
    s1.marks = 90;    
    s1.displayStudentInfo();
    return 0;
}
