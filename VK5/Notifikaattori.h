#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H

#include "Seuraaja.h"
#include <string>

class Notifikaattori {
private:
    Seuraaja* head;

public:
    // Konstruktori
    Notifikaattori();

    // Lisää seuraaja
    void lisaa(Seuraaja* seuraaja);

    // Poista seuraaja
    void poista(Seuraaja* seuraaja);

    // Tulosta seuraajat
    void tulosta();

    // Lähetä viesti
    void postita(const std::string& viesti);
};

#endif
