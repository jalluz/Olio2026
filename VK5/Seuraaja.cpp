#include "Seuraaja.h"
#include <iostream>

// Konstruktori
Seuraaja::Seuraaja(const std::string& n) : nimi(n), next(nullptr) {
    std::cout << "Luodaan seuraaja " << nimi << std::endl;
}

std::string Seuraaja::getNimi() const {
    return nimi;
}

void Seuraaja::paivitys(const std::string& viesti) {
    std::cout << "Seuraaja " << nimi << " sai viestin " << viesti << std::endl;
}
