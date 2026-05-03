#include<iostream>
using namespace std;

class bankAccount{
    private:
    string accountNumber;
    string accountHolder;
    double balance;

    public:
    bankAccount(string aN, string aH, double b){
        accountNumber = aN;
        accountHolder = aH;
        balance = b;
    }
    void accountDetails(){
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Account Holder: "<<accountHolder<<endl;
        cout<<"Bank Balance: "<<balance<<endl;
    }
};
int main(){
    string aN, aH;
    double b;

    cout<<"Enter Account Number: ";
    cin>>aN;
    cout<<"Enter Account Holder Name: ";
    cin>>aH;
    cout<<"Enter Bank Balance: ";
    cin>>b;
    bankAccount acc(aN, aH, b);
    cout<<"\n Account Details: "<<endl;
    acc.accountDetails();

    return 0;
}
