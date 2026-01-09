#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time

int main() {
    srand(static_cast<unsigned int>(time(0))); // satunnaissiementäminen
    int number = rand() % 20 + 1; // arvo luku 1–20
    int guess = 0;

    std::cout << "Arvaa luku väliltä 1-20: ";

    while (guess != number) {
        std::cin >> guess;

        if (guess < number) {
            std::cout << "Liian pieni. Yritä uudelleen: ";
        } else if (guess > number) {
            std::cout << "Liian suuri. Yritä uudelleen: ";
        } else {
            std::cout << "Oikein! Onneksi olkoon!\n";
        }
    }

    return 0;
}