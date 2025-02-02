#include "pankkitili.h"
#include <iostream>
using namespace std;

Pankkitili::Pankkitili(string omistaja) : omistaja(omistaja), saldo(0)
{
    cout << "Pankkitili luotu " << omistaja << ":lle" << endl;
}

double Pankkitili::getBalance()
{
    return saldo;
}

bool Pankkitili::deposit(double summa)
{
    if (summa <= 0) {
        return false;
    }
    else {
        saldo += summa;
        cout << omistaja << " Pankkitili: talletus " << summa << " tehty" << endl;
        return true;
    }
}

bool Pankkitili::withdraw(double summa)
{
    if (summa <= 0 || summa > saldo) {
        return false;
    }
    else {
        saldo -= summa;
        cout << omistaja << " Pankkitili: nosto " << summa << " tehty" << endl;
        return true;
    }
}
