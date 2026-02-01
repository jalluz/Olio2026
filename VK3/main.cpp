#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Chef class
class Chef {
protected:
    string chefName;

public:
    Chef(string name);
    ~Chef();
    string getName();
    int makeSalad(int ingredients);
    int makeSoup(int ingredients);
};

// Chef method
Chef::Chef(string name) {
    chefName = name;
    cout << "Chef " << chefName << "konstruktori" << endl;
}

Chef::~Chef() {
    cout << "Chef " << chefName << "destruktori" << endl;
}

string Chef::getName() {
    return chefName;
}

int Chef::makeSalad(int ingredients) {
    int portions = ingredients / 5;
    cout << "Chef " << chefName << " with " << ingredients << " items can make salad " << portions << " portions" << endl;
    return portions;
}

int Chef::makeSoup(int ingredients) {
    int portions = ingredients / 3;
    cout << "Chef " << chefName << " with " << ingredients << " items can make soup " << portions << " portions" << endl;
    return portions;
}

// ItalianChef class
class ItalianChef : public Chef {
private:
    string password;
    int flour;
    int water;
    int makePizza(int flour, int water);

public:
    ItalianChef(string name);
    ~ItalianChef();
    bool askSecret(string pwd, int flour, int water);
};

// ItalianChef method
ItalianChef::ItalianChef(string name) : Chef(name) {
    password = "pizza";
    flour = 0;
    water = 0;
    cout << "ItalianChef " << chefName << "konstruktori" << endl;
}

ItalianChef::~ItalianChef() {
    cout << "ItalianChef " << chefName << "destruktori" << endl;
}

bool ItalianChef::askSecret(string pwd, int flour, int water) {
    if (pwd.compare(password) == 0) {
        this->flour = flour;
        this->water = water;
        cout << "Password ok!" << endl;
        makePizza(flour, water);
        return true;
    } else {
        cout << "Wrong password!" << endl;
        return false;
    }
}

int ItalianChef::makePizza(int flour, int water) {
    int pizzas = min(flour, water) / 5;
    cout << "ItalianChef " << chefName << " with " << flour << " flour and " << water << " water can make " << pizzas << " pizzas" << endl;
    return pizzas;
}


int main() {
    // Test Chef
    cout << " Testing Chef " << endl;
    Chef chef("Gordon");
    cout << "Chef name: " << chef.getName() << endl;
    chef.makeSalad(15);
    chef.makeSoup(9);

    cout << endl << " Testing ItalianChef " << endl;
    ItalianChef italianChef("Anthony");
    cout << "Chef name: " << italianChef.getName() << endl;
    italianChef.makeSalad(15);
    italianChef.makeSoup(9);

    cout << endl << " Testing Pizza with wrong password " << endl;
    italianChef.askSecret("wrong", 25, 30);

    cout << endl << " Testing Pizza with correct password " << endl;
    italianChef.askSecret("pizza", 25, 30);

    cout << endl << " Destructors will be called " << endl;
    return 0;
}
