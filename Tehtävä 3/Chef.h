#ifndef CHEF_H
#define CHEF_H
#include <string>
using namespace std;

class Chef
{
public:
    Chef(string name);
    ~Chef();
    string getName();
    int makeSalad(int);
    int makeSoup(int);

protected:
    string chefName;
};

class ItalianChef: public Chef
{
public:
    ItalianChef(string);
    ~ItalianChef();
    bool askSecret(string, int, int);

private:
    int makepizza();
    string password = "pizza";
    int flour;
    int water;
};

#endif // CHEF_H
