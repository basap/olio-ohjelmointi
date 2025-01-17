#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Game::Game(int maxNumber) :
    maxNumber(maxNumber),
    playerGuess(-1),
    numOfGuesses(0)
{
    srand(time(NULL));
    randomNumber = (rand() % maxNumber) + 1;
}

Game::~Game()
{

}

void Game::play()
{
    while (playerGuess != randomNumber) {
        cout << "Arvauksesi? " << endl;
        cin >> playerGuess;
        numOfGuesses++;

        if (playerGuess < randomNumber) {
            cout << "Luku on isompi." << endl;
        } else if (playerGuess > randomNumber) {
            cout << "Luku on pienempi." << endl;
        }
    }
}

void Game::printGameResult() const
{
    cout << "Oikein!" << endl;
    cout << "Teit " << numOfGuesses << " arvausta ennen oikeaa vastausta." << endl;
}

