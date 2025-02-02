#ifndef ASIAKAS_H
#define ASIAKAS_H
#include "luottotili.h"
#include "pankkitili.h"
#include <string>

class Asiakas
{
public:
    Asiakas(string nimi, double luottoRaja);
    string getNimi();
    void showSaldo();
    bool talletus(double summa);
    bool nosto(double summa);
    bool luotonMaksu(double summa);
    bool luotonNosto(double summa);
    bool tiliSiirto(double summa, Asiakas &vastaanottaja);

private:
    string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;
};

#endif // ASIAKAS_H
