#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H
#include "pankkitili.h"
#include <string>

class Luottotili: public Pankkitili
{
public:
    Luottotili(string omistaja, double luottoRaja);
    bool deposit(double summa) override;
    bool withdraw(double summa) override;

protected:
    double luottoRaja = 0;
};

#endif // LUOTTOTILI_H
