#ifndef PANKKITILI_H
#define PANKKITILI_H
#include <string>

using namespace std;

class Pankkitili
{
public:
    Pankkitili(string omistaja);
    double getBalance();
    virtual bool deposit(double summa);
    virtual bool withdraw(double summa);

protected:
    string omistaja;
    double saldo = 0;
};

#endif // PANKKITILI_H
