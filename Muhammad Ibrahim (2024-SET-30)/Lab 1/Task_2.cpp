#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string first_Name;
    string last_Name;
    int roll_Number;
    float marks;

    void displayStudentInfo()
    {
        cout << "\nFull Name: " << first_Name << " " << last_Name << endl;
        cout << "Roll Number: " << roll_Number << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    // here we use array of structures.
    Student students[n];

    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter details for student " << i + 1 << endl;

        cout << "First Name: ";
        cin >> students[i].first_Name;

        cout << "Last Name: ";
        cin >> students[i].last_Name;

        cout << "Roll Number: ";
        cin >> students[i].roll_Number;

        cout << "Marks: ";
        cin >> students[i].marks;
    }

 
    for(int i = 0; i < n; i++)
    {
        students[i].displayStudentInfo();
    }

    return 0;
}