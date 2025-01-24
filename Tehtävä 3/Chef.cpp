#include "Chef.h"
#include <iostream>

Chef::Chef(string name) : chefName(name)
{
    cout << "Chef " << chefName << " konstruktori" << endl;
}

Chef::~Chef()
{
    cout << "Chef " << chefName << " destruktori" << endl;
}

string Chef::getName()
{
    return chefName;
}

int Chef::makeSalad(int items)
{
    int portions = items / 5;
    cout << "Chef " << chefName << " with " << items << " items can make salad " << portions << " portions" << endl;
    return portions;
}

int Chef::makeSoup(int items)
{
    int portions = items / 3;
    cout << "Chef " << chefName << " with " << items << " items can make soup " << portions << " portions\n" << endl;
    return portions;
}

ItalianChef::ItalianChef(string name) : Chef(name), flour(0), water(0)
{
    cout << "ItalianChef " << chefName << " konstruktori" << endl;
}

ItalianChef::~ItalianChef()
{
    cout << "ItalianChef " << chefName << " destruktori" << endl;
}

bool ItalianChef::askSecret(string pass, int flourAmount, int waterAmount)
{
    if (pass == password)
    {
        int ogFlour = flourAmount;
        int ogWater = waterAmount;

        flour = flourAmount;
        water = waterAmount;

        cout << "\nPassword ok!" << endl;

        int pizzas = makepizza();

        cout << "ItalianChef " << chefName << " with " << ogFlour << " flour and " << ogWater << " water can make " << pizzas << " pizzas\n" << endl;
        return true;
    }
    else
    {
        cout << "\nIncorrect password!\n" << endl;
        return false;
    }
}

int ItalianChef::makepizza()
{
    if (flour > 0 && water > 0)
    {
        int pizzas = min(flour / 5, water / 5);
        flour -= pizzas * 5;
        water -= pizzas * 5;
        return pizzas;
    }
    else
    {
        return 0;
    }
}
