#include "luottotili.h"
#include <iostream>
#include <string>

Luottotili::Luottotili(string omistaja, double luottoRaja) : Pankkitili(omistaja), luottoRaja()
{
    saldo = luottoRaja;
    cout << "Luottotili luotu " << omistaja << ":lle, luottoraja " << luottoRaja << endl;
}

bool Luottotili::deposit(double summa)
{
    if (summa <= 0) {
        return false;
    }
    else if (saldo + summa > 0) {
        return false;
    }
    else {
        saldo += summa;
        cout << "Luottotili: velanmaksu " << summa << " tehty" << endl;
        return true;
    }
}

bool Luottotili::withdraw(double summa)
{
    if (summa <= 0) {
        return false;
    }
    else if (saldo - summa < luottoRaja) {
        return false;
    }
    else {
        saldo -= summa;
        cout << "Luottotili: nosto " << summa << " tehty, luottoa jaljella " << saldo << endl;
        return true;
    }
}


