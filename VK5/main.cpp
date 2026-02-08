#include "Notifikaattori.h"
#include "Seuraaja.h"

int main() {
    Notifikaattori n;

    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);

    // Tulostetaan lista
    n.tulosta();

    // Lähetetään viesti
    n.postita("Tama on viesti 1");

    // Poistetaan seuraaja
    n.poista(&b);

    // Lähetetään toinen viesti
    n.postita("Tama on viesti 2");

    return 0;
}
