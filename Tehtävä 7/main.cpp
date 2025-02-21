/* Olio-ohjelmointi, tehtävä 7
 * Tekijä: Kimi Sarkkila TVT24SPO */

#include "laskin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Laskin w;
    w.show();
    return a.exec();
}
