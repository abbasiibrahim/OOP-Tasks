#include<iostream>
#include<string>
using namespace std;

class Product{
    private:
    string name;
    double price = 0;
    int quantity = 0;

    public:
    void setName(string n){
        if(n==""){
            cout<<"Error! Name cannot be empty.";
        }
        else{
            name = n;
        }
    }
    void setPrice(double p){
        if(p <= 0){
            cout<<"Error! Price must be greater than 0."<<endl;
        }
        else{
            price = p;
        }
    }
    void setQuantity(int q){
        if(q<0){
            cout<<"Error! Quantity cannot be in negative."<<endl;
        }
        else{
            quantity = q;
        }
    }
    string getName(){
        return name;
    }
    double getPrice(){
        return price;
    }
    int getQuantity(){
        return quantity;
    }
};
int main(){
    Product p;

    //using invalid values
    // p.setName("");
    // p.setPrice(-30);
    // p.setQuantity(-3);

    // using valid values
    p.setName("Book");
    p.setPrice(1500);
    p.setQuantity(4);


    cout<<"\nProduct: "<<p.getName()<<endl;
    cout<<"Pkr: "<<p.getPrice()<<endl;
    cout<<"Quantity: "<<p.getQuantity()<<endl;

    return 0;
}
