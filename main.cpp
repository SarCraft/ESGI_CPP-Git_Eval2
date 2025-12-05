// Jeu devine le nombre
// nombre aléatoire entre 1 et 100
// utilisateur a 10 essais pour deviner le nombre
// dit si c'est < > ou =

#include <iostream>
// Lib permettant de générer des nombres aléatoires
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int maxAttempts = 10;
    const int minNumber = 1;
    const int maxNumber = 100;

    // Générer un nombre aléatoire entre minNumber et maxNumber
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % (maxNumber - minNumber + 1) + minNumber;

    cout << "Bienvenue au jeu de devine le nombre!" << endl;
    cout << "J'ai choisi un nombre entre " << minNumber << " et " << maxNumber << "." << endl;
    cout << "Vous avez " << maxAttempts << " essais pour le deviner." << endl;

    int userGuess;
    for (int attempt = 1; attempt <= maxAttempts; ++attempt) {
        cout << "Essai " << attempt << ": Entrez votre devinette: ";
        cin >> userGuess;

        // Vérifier si l'entrée est invalide
        if (cin.fail()) {
            cout << "Erreur: Veuillez entrer un nombre valide!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            // ne pas compter cette tentative
            --attempt;
            continue;
        }

        if (userGuess < secretNumber) {
            cout << "C'est plus grand!" << endl;
        } else if (userGuess > secretNumber) {
            cout << "C'est plus petit!" << endl;
        } else {
            cout << "Félicitations! Vous avez deviné le nombre " << secretNumber << " en " << attempt << " essais!" << endl;
            return 0;
        }
    }

    cout << "Désolé, vous avez utilisé tous vos essais. Le nombre était " << secretNumber << "." << endl;
    return 0;
}