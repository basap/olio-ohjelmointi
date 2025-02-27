/* Olio-ohjelmointi, tehtävä 8
 * Tekijä: Kimi Sarkkila TVT24SPO */

#include "shakkikello.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    shakkikello w;
    w.show();
    return a.exec();
}
