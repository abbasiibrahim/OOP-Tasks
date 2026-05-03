#include<iostream>
using namespace std;
class Voter{
    public:
    string name;
    int age;

    void getData();
    bool isEligible();
};
 void Voter::getData(){
    cout<<"Enter Name :";
    cin>>name;
    cout<<"Enter age :";
    cin>>age;
 }
  bool Voter::isEligible(){
    if(age>=18)
    return true;
    else 
    return false;
  }

  int main(){
    Voter v;
    v.getData();

    if (v.isEligible())
        cout<<"You are Eligible for casting vote"<<endl;
    else
        cout<<"You are not Eligible for casting vote";

        return 0;
  }

// #include <iostream>
// using namespace std;

// class Voter
// {
// public:
//     int age;

//     void getAge();
//     bool isEligible();   // ✅ function declaration
// };

// void Voter::getAge()
// {
//     cout << "Enter Age: ";
//     cin >> age;
// }

// bool Voter::isEligible()
// {
//     return age >= 18;
// }

// int main()
// {
//     Voter v;

//     v.getAge();

//     if (v.isEligible())
//         cout << "Eligible to vote";
//     else
//         cout << "Not eligible to vote";

//     return 0;
// }
