/* Olio-ohjelmointi, viikko 4
 * Tekijä: Kimi Sarkkila TVT24SPO */

#include "asiakas.h"
#include <iostream>
using namespace std;

int main() {
    string nimi1 = "Aapeli";    // Asiakas 1
    double luottoraja1 = 1000;  // Asiakas 1:n luottoraja
    double luotonSiirto1 = 250; // Siirretään asiakas 1:n pankkitilille luottotililtä

    string nimi2 = "Bertta";    // Asiakas 2
    double luottoraja2 = 1000;  // Asiakas 1:n luottoraja

    double tilisiirtoSumma = 50;    // Asiakas 1 siirtää tämän summan Asiakas 2:lle

    // Ensimmäisen asiakkaan luonti ja alkusaldot
    Asiakas asiakas1(nimi1, luottoraja1);
    asiakas1.showSaldo();

    // Nostetaan annettu summa luottotililtä käyttötilille
    asiakas1.talletus(luotonSiirto1);
    asiakas1.luotonNosto(luotonSiirto1);
    asiakas1.showSaldo();

    // Toisen asiakkaan luonti ja alkusaldot
    Asiakas asiakas2(nimi2, luottoraja2);
    asiakas2.showSaldo();

    // Ensimmäisen asiakkaan päivitetyt saldot
    cout << "\n" << nimi1 << endl;
    asiakas1.showSaldo();

    // Tilisiirto 1. asiakkaalta 2. asiakkaalle
    asiakas1.tiliSiirto(tilisiirtoSumma, asiakas2);

    // Toisen asiakkaan päivitetyt saldot
    cout << "\n" << nimi2 << endl;
    asiakas2.showSaldo();

    return 0;
}
