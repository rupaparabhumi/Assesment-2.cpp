#include <iostream>
using namespace std;

int totalAmount = 0;

class FoodItem
{
public:
    string name;
    string type1Name;
    int type1Price;
    string type2Name;
    int type2Price;
    string type3Name;
    int type3Price;

    FoodItem(
        string name_,
        string type1Name_,
        int type1Price_,
        string type2Name_,
        int type2Price_,
        string type3Name_,
        int type3Price_)
    {
        name = name_;
        type1Name = type1Name_;
        type1Price = type1Price_;
        type2Name = type2Name_;
        type2Price = type2Price_;
        type3Name = type3Name_;
        type3Price = type3Price_;
    }
};

class Order
{
public:
    int foodType;
    int quantity;
};

// FoodType and quantity
Order getOrder(FoodItem &food)
{
    int foodType;
    int quantity;
    cout << "\n1. " << food.type1Name << " " << food.type1Price << endl;
    cout << "\n2. " << food.type2Name << " " << food.type2Price << endl;
    cout << "\n3. " << food.type3Name << " " << food.type3Price << endl;
    cout << "\nplease Enter which " << food.name << " you would like to have:";
    cin >> foodType;
    cout << "\nplease Enter Quantity:";
    cin >> quantity;
    cout << "\t\t\t\t----------------your order---------------" << endl;
    if (foodType == 1)
    {
        cout << food.type1Name;
    }
    else if (foodType == 2)
    {
        cout << food.type2Name;
    }
    else if (foodType == 3)
    {
        cout << food.type3Name;
    }

    struct Order r;
    r.foodType = foodType;
    r.quantity = quantity;
    return r;
}

// total amount bill and quantity

void showOrderDetails(FoodItem &food, Order order)
{
    if (order.foodType == 1)
    {
        totalAmount += order.quantity * food.type1Price;
        cout << "\nYour total bill is " << totalAmount;
    }
    else if (order.foodType == 2)
    {
        totalAmount += order.quantity * food.type2Price;
        cout << "\nYour total bill is " << totalAmount;
    }
    else if (order.foodType == 3)
    {
        totalAmount += order.quantity * food.type3Price;
        cout << "\nYour total bill is " << totalAmount;
    }
    else
    {
        cout << "Wrong input";
    }
}

int main()
{
    int Fooditems, choice, choice1, choice2, choice3, choice4, choice5, foodtype, Quantity;
    FoodItem pizza("Pizza", "paneer pizza", 250, "veg pizza", 300, "Margarita pizza", 250);
    FoodItem burger("Burger", "Aalu tikki Burger", 50, "veg Burger", 70, "crunchy veg Burger", 80);
    FoodItem sandwich("Sandwich", "cheese sandwich", 90, "Aalu matar sandwich", 50, "veg Grilled sandwich", 80);
    FoodItem biryani("Biryani", "hyderabadi Biryani", 360, "paneer Tikka Biryani", 400, "kolkata Biryani", 300);
    FoodItem rolls("Rolls", "paneer Rolls", 150, "potato Rolls", 100, "corn Rolls", 70);

    // print name of customer
    char name[10];
    cout << "\t\t\t\t--------------Tops Tech.Fast Food---------" << endl;
    cout << "please Enter your name:";
    cin >> name;
    cout << "Hello," << name << endl;
    cout << "what would you like to order?" << endl;

    // used concept loops and switch case
    while (Fooditems)
    {
        cout << "\n\t\t\t\t------------Menu-----------" << endl;
        cout << "1.pizza" << endl;
        cout << "2.Burgers" << endl;
        cout << "3.Sandwich" << endl;
        cout << "4.Rolls" << endl;
        cout << "5.Biryani" << endl;
        cout << "\nPlease Enter your choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Order pizzaOrder;
            pizzaOrder = getOrder(pizza);
            showOrderDetails(pizza, pizzaOrder);
            break;
        case 2:
            Order burgerOrder;
            burgerOrder = getOrder(burger);
            showOrderDetails(burger, burgerOrder);
            break;
        case 3:
            Order sandwichOrder;
            sandwichOrder = getOrder(sandwich);
            showOrderDetails(sandwich, sandwichOrder);
            break;
        case 4:
            Order biryaniOrder;
            biryaniOrder = getOrder(biryani);
            showOrderDetails(biryani, biryaniOrder);
            break;
        case 5:
            Order RollsOrder;
            RollsOrder = getOrder(rolls);
            showOrderDetails(rolls, RollsOrder);
            break;
        }

        char anything;
        cout << "\nYour order will be delivered in 40 minutes";
        cout << "\nThank you for ordering from Tops Tech Fast Food";
        cout << "\nwould you like to order anything else? Y/N:";
        cin >> anything;
        if (anything == 'Y' || anything == 'y')
        {
            anything;
        }
        else
        {
            break;
        }
    }
    return 0;
}
