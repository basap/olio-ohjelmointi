/* Olio-ohjelmointi, tehtävä 1
 * Tekijä: Kimi Sarkkila TVT24SPO */

#include <iostream>
#include <ctime>

using namespace std;

int game (int maxnum) {
    srand(time(NULL));
    int satluku = rand() % maxnum;
    int arvausMaara = 0;
    int arvaus = 0;

    while (arvaus != satluku) {
        cout << "Arvauksesi? " << endl;
        cin >> arvaus;
        arvausMaara++;
        if (satluku == arvaus) {
            cout << "Oikein!" << endl;
        } else if (arvaus < satluku) {
            cout << "Luku on isompi." << endl;
        } else {
            cout << "Luku on pienempi." << endl;
        }
    }
    return arvausMaara;
}

int main()
{
    int maxnum = 0;
    cout << "Anna pelin maksimiluku: ";
    cin >> maxnum;
    int arvausMaara = game(maxnum);
    cout << "Teit " << arvausMaara << " arvausta ennen oikeaa vastausta." << endl;
    return 0;
}
