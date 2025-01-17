/* Olio-ohjelmointi, tehtävä 2
 * Tekijä: Kimi Sarkkila TVT24SPO */

#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
    int maxNumber;
    cout << "Anna pelin maksimiluku: ";
    cin >> maxNumber;

    Game game(maxNumber);
    game.play();

    game.printGameResult();

    return 0;
}
