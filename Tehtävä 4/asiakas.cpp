#include "asiakas.h"
#include <iostream>
#include <string>

using namespace std;

Asiakas::Asiakas(string nimi, double luottoRaja) : nimi(nimi), kayttotili(nimi), luottotili(nimi, luottoRaja)
{
    cout << "Asiakkuus luotu " << nimi << endl;
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout << "Kayttotilin saldo " << kayttotili.getBalance() << endl;
    cout << "Luottotilin saldo " << luottotili.getBalance() << "\n" << endl;
}

bool Asiakas::talletus(double summa)
{
    return kayttotili.deposit(summa);
}

bool Asiakas::nosto(double summa)
{
    return kayttotili.withdraw(summa);
}

bool Asiakas::luotonMaksu(double summa)
{
    return luottotili.deposit(summa);
}

bool Asiakas::luotonNosto(double summa)
{
    return luottotili.withdraw(summa);
}

bool Asiakas::tiliSiirto(double summa, Asiakas &vastaanottaja)
{
    if (summa <= 0) {
        cout << "Siirrettava summa on oltava yli 0." << endl;
        return false;
    }

    cout << "Pankkitili: " << nimi << " siirtaa " << summa << " " << vastaanottaja.nimi << ":lle" << endl;

    if (!nosto(summa)) {
        cout << "Tililla ei ole riittavasti katetta siirtoon." << endl;
        return false;
    } if (!vastaanottaja.talletus(summa)) {
        cout << "Vastaanottajan tilille ei voida tallettaa tata summaa." << endl;
        return false;
    }
        return true;
}



