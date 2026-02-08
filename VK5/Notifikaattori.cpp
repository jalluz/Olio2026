#include "Notifikaattori.h"
#include <iostream>

// Konstruktori
Notifikaattori::Notifikaattori() : head(nullptr) {
    std::cout << "Luodaan notifikaattori" << std::endl;
}

void Notifikaattori::lisaa(Seuraaja* seuraaja) {
    std::cout << "Notifikaattori lisaa seuraajan " << seuraaja->getNimi() << std::endl;
    seuraaja->next = head;
    head = seuraaja;
}
void Notifikaattori::poista(Seuraaja* seuraaja) {
    std::cout << "Notifikaattori poistaa seuraajan " << seuraaja->getNimi() << std::endl;

    Seuraaja* prev = nullptr;
    Seuraaja* curr = head;

    while (curr != nullptr) {
        if (curr == seuraaja) {
            if (prev != nullptr) {
                prev->next = curr->next;
            } else {
                head = curr->next;
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Tulosta kaikki seuraajat
void Notifikaattori::tulosta() {
    std::cout << "Notifikaattorin seuraajat:" << std::endl;

    Seuraaja* curr = head;
    while (curr != nullptr) {
        std::cout << "Seuraaja " << curr->getNimi() << std::endl;
        curr = curr->next;
    }
}

// Lähetä viesti kaikille
void Notifikaattori::postita(const std::string& viesti) {
    std::cout << "Notifikaattori postaa viestin " << viesti << std::endl;

    Seuraaja* curr = head;
    while (curr != nullptr) {
        curr->paivitys(viesti);
        curr = curr->next;
    }
}
