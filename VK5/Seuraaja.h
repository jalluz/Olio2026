#ifndef SEURAAJA_H
#define SEURAAJA_H

#include <string>

class Seuraaja {
private:
    std::string nimi;

public:
    Seuraaja* next;  // Osoitin seuraavaan


    Seuraaja(const std::string& n);

    std::string getNimi() const;

    void paivitys(const std::string& viesti);
};

#endif
