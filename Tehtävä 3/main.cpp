/* Olio-ohjelmointi, tehtävä 3
 * Tekijä: Kimi Sarkkila TVT24SPO */

#include "Chef.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string chefName = "Gordon";         // Kokin nimi
    string italianChefName = "Mario";   // Italialaisen kokin nimi

    // Luodaan kokin olio
    Chef chef(chefName);

    // Kysytään salaattiainesten määrää, tehdään salaattia niin paljon kuin mahdollista
    int saladItems;
    cout << "\nCount of salad items: ";
    cin >> saladItems;
    chef.makeSalad(saladItems);

    // Kysytään keittoainesten määrää, tehdään keittoa niin paljon kuin mahdollista
    int soupItems;
    cout << "\nCount of soup items: ";
    cin >> soupItems;
    chef.makeSoup(soupItems);

    // Luodaan italialaisen kokin olio
    ItalianChef italianChef(italianChefName);

    // Kysytään käyttäjältä salasana ja pizza-ainesten määrät
    string password;
    int flour, water;

    cout << "\nPassword for Italian chef: ";
    cin >> password;

    cout << "How much flour? ";
    cin >> flour;

    cout << "How much water? ";
    cin >> water;

    // Valmistetaan pizzaa
    italianChef.askSecret(password, flour, water);
    return 0;
}
