#include <iostream>
#include <string>

class Seuraaja {
private:
    std::string nimi;

public:
    Seuraaja* next;

    // Konstruktori
    Seuraaja(const std::string& n) : nimi(n), next(nullptr) {
        std::cout << "Luodaan seuraaja " << nimi << std::endl;
    }


    std::string getNimi() const {
        return nimi;
    }


    void paivitys(const std::string& viesti) {
        std::cout << "Seuraaja " << nimi << " sai viestin " << viesti << std::endl;
    }
};

// notifikaattori
class Notifikaattori {
private:
    Seuraaja* head;

public:
    // Konstruktori
    Notifikaattori() : head(nullptr) {
        std::cout << "Luodaan notifikaattori" << std::endl;
    }

    void lisaa(Seuraaja* seuraaja) {
        std::cout << "Notifikaattori lisaa seuraajan " << seuraaja->getNimi() << std::endl;

        seuraaja->next = head;
        head = seuraaja;
    }

    void poista(Seuraaja* seuraaja) {
        std::cout << "Notifikaattori poistaa seuraajan " << seuraaja->getNimi() << std::endl;

        Seuraaja* prev = nullptr;
        Seuraaja* curr = head;

        while (curr != nullptr) {
            if (curr == seuraaja) {  // osoitin vertailu
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

    void tulosta() {
        std::cout << "Notifikaattorin seuraajat:" << std::endl;

        Seuraaja* curr = head;
        while (curr != nullptr) {
            std::cout << "Seuraaja " << curr->getNimi() << std::endl;
            curr = curr->next;
        }
    }

    // lähetä viesti kaikille
    void postita(const std::string& viesti) {
        std::cout << "Notifikaattori postaa viestin " << viesti << std::endl;

        Seuraaja* curr = head;
        while (curr != nullptr) {
            curr->paivitys(viesti);
            curr = curr->next;
        }
    }
};

int main() {

    Notifikaattori n;


    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");


    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);

    n.tulosta();

    n.postita("Tama on viesti 1");


    n.poista(&b);

    n.postita("Tama on viesti 2");
    return 0;
}
