/* Olio-ohjelmointi, viikko 5
 * Tekijä: Kimi Sarkkila TVT24SPO */

#include "notifikaattori.h"
#include "seuraaja.h"
using namespace std;

int main()
{
    Notifikaattori n;

    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);
    n.tulosta();

    n.postita("Tama on viesti 1");

    n.poista(&b);

    n.postita("Tama on viesti 2");

    return 0;
}
