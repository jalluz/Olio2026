#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

// Funktio, joka pyörittää arvauspeliä ja palauttaa arvausten määrän
int game(int maxnum) {
    int secret = rand() % maxnum + 1;  // etsittävä luku
    int guess = 0;                     // pelaajan arvaus
    int attempts = 0;                  // arvausten määrä

    while (guess != secret) {
        std::cout << "Syota arvaus (1-"<< maxnum << "): ";

        if (!(std::cin >> guess)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Virheellinen syote! Anna kokonaisluku.\n";
            continue;
        }

        attempts++;

        if (guess < secret) {
            std::cout << "Liian pieni\n";
        } else if (guess > secret) {
            std::cout << "Liian suuri\n";
        } else {
            std::cout << "Oikein\n";
        }
    }

    return attempts;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // satunnaisuus alustetaan

    int maxnum = 40;
    int result = game(maxnum);

    std::cout << "Arvauksia yhteensa: " << result << "\n";
    return 0;
}
