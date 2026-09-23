#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ================= VEHICLE =================

class Vehicle {
protected:
    string model;
    double dailyRate;
    bool available;

public:
    Vehicle(string m, double rate) {
        model = m;
        dailyRate = rate;
        available = true;
    }

    virtual ~Vehicle() {}

    string getModel() {
        return model;
    }

    bool isAvailable() {
        return available;
    }

    void setAvailable(bool status) {
        available = status;
    }

    // Virtual function for polymorphism
    virtual double calculateCost(int days) {
        return dailyRate * days;
    }

    virtual string getType() {
        return "Vehicle";
    }
};


// ================= CAR =================

class Car : public Vehicle {
private:
    int seats;

public:
    Car(string m, double rate, int s)
        : Vehicle(m, rate) {
        seats = s;
    }

    string getType() override {
        return "Car";
    }
};


// ================= MOTORBIKE =================

class Motorbike : public Vehicle {
private:
    int engineCC;

public:
    Motorbike(string m, double rate, int cc)
        : Vehicle(m, rate) {
        engineCC = cc;
    }

    string getType() override {
        return "Motorbike";
    }

    double calculateCost(int days) override {

        double cost = dailyRate * days;

        // 10% discount for more than 7 days
        if (days > 7) {
            cost = cost * 0.90;
        }

        return cost;
    }
};


// ================= TRUCK =================

class Truck : public Vehicle {
private:
    double payload;

public:
    Truck(string m, double rate, double p)
        : Vehicle(m, rate) {
        payload = p;
    }

    string getType() override {
        return "Truck";
    }

    double calculateCost(int days) override {

        double cost = dailyRate * days;

        // 20% surcharge
        cost = cost * 1.20;

        return cost;
    }
};


// ================= CUSTOMER =================

class Customer {
private:
    int id;
    string name;

public:
    Customer(int i, string n) {
        id = i;
        name = n;
    }

    int getID() {
        return id;
    }

    string getName() {
        return name;
    }
};


// ================= RENTAL =================

class Rental {
private:
    Customer* customer;
    Vehicle* vehicle;
    int days;
    double cost;
    bool active;

public:
    Rental(Customer* c, Vehicle* v, int d) {

        customer = c;
        vehicle = v;
        days = d;

        // Polymorphism
        cost = vehicle->calculateCost(days);

        active = true;

        vehicle->setAvailable(false);
    }

    void returnVehicle() {
        active = false;
        vehicle->setAvailable(true);
    }

    bool isActive() {
        return active;
    }

    void display() {

        cout << "Customer: " << customer->getName() << endl;
        cout << "Vehicle: " << vehicle->getModel() << endl;
        cout << "Days: " << days << endl;
        cout << "Cost: $" << cost << endl;
        cout << "Status: "
             << (active ? "Active" : "Closed") << endl;
    }

    Vehicle* getVehicle() {
        return vehicle;
    }
};


// ================= RENTAL SYSTEM =================

class RentalSystem {
private:
    vector<Vehicle*> vehicles;
    vector<Customer*> customers;
    vector<Rental*> rentals;

public:

    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }

    void addCustomer(Customer* customer) {
        customers.push_back(customer);
    }

    void rentVehicle(Customer* customer,
                     Vehicle* vehicle,
                     int days) {

        if (!vehicle->isAvailable()) {
            cout << "Vehicle is already rented.\n";
            return;
        }

        Rental* rental =
            new Rental(customer, vehicle, days);

        rentals.push_back(rental);

        cout << "\nRental successful!\n";
    }

    void returnVehicle(Vehicle* vehicle) {

        for (Rental* rental : rentals) {

            if (rental->isActive() &&
                rental->getVehicle() == vehicle) {

                rental->returnVehicle();

                cout << "\nVehicle returned successfully.\n";
                return;
            }
        }

        cout << "\nNo active rental found.\n";
    }

    void summary() {

        int available = 0;
        int rented = 0;

        cout << "\n========== ACTIVE RENTALS ==========\n";

        for (Rental* rental : rentals) {

            if (rental->isActive()) {
                rental->display();
                cout << "--------------------------\n";
            }
        }

        for (Vehicle* vehicle : vehicles) {

            if (vehicle->isAvailable())
                available++;
            else
                rented++;
        }

        cout << "\n========== VEHICLE STATUS ==========\n";
        cout << "Available Vehicles: "
             << available << endl;

        cout << "Rented Vehicles: "
             << rented << endl;
    }
};


// ================= MAIN =================

int main() {

    RentalSystem system;

    // Add 3 vehicles
    Vehicle* car =
        new Car("Toyota Corolla", 50, 5);

    Vehicle* motorbike =
        new Motorbike("Honda 150", 30, 150);

    Vehicle* truck =
        new Truck("Isuzu Truck", 100, 5);

    system.addVehicle(car);
    system.addVehicle(motorbike);
    system.addVehicle(truck);


    // Register 2 customers
    Customer* customer1 =
        new Customer(101, "Ali");

    Customer* customer2 =
        new Customer(102, "Ahmed");

    system.addCustomer(customer1);
    system.addCustomer(customer2);


    // Process rental 1
    system.rentVehicle(
        customer1,
        car,
        3
    );


    // Process rental 2
    system.rentVehicle(
        customer2,
        truck,
        5
    );


    // Return one vehicle
    system.returnVehicle(car);


    // Print summary
    system.summary();


    return 0;
}