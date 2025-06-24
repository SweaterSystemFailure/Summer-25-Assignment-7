#include <iostream>
#include <string>

using namespace std;

class Item {
public:
    string name;
    int quantity;

    Item(const string& name = "", int quantity = 0) : name(name), quantity(quantity) {}

    virtual void display() = 0;
};

class Perishable : public Item {
public:
    Perishable(const string& name = "", int quantity = 0) : Item(name, quantity) {}

    void display() override {
        cout << name << " (Perishable), Quantity: " << quantity << endl;
    }
};


class NonPerishable : public Item {
public: 
    NonPerishable(const string& name = "", int quantity = 0) : Item(name, quantity) {}

    void display() override {
        cout << name << " (Non-Perishable), Quantity: " << quantity << endl;
    }
};

int main()
{  
    Item* firstItem = new Perishable("Lettuce", 7);
    Item* secondItem = new NonPerishable("Ketchup", 25);

    firstItem->display();
    secondItem->display();

    delete firstItem;
    delete secondItem;

    return 0;
}