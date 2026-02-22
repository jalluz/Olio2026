#include <iostream>
#include <string>
using namespace std;

class Pankkitili
{
protected:
    string omistaja;
    double saldo;

public:
    Pankkitili(string nimi) : omistaja(nimi), saldo(0) {}

    virtual bool deposit(double amount)
    {
        if (amount < 0) return false;
        saldo += amount;
        return true;
    }

    virtual bool withdraw(double amount)
    {
        if (amount < 0 || amount > saldo) return false;
        saldo -= amount;
        return true;
    }

    double getBalance() const
    {
        return saldo;
    }

    string getOmistaja() const
    {
        return omistaja;
    }
};

class Luottotili : public Pankkitili
{
private:
    double luottoRaja;

public:
    Luottotili(string nimi, double raja)
        : Pankkitili(nimi), luottoRaja(raja)
    {
        saldo = 0;
    }

    bool withdraw(double amount) override
    {
        if (amount < 0) return false;
        // Saldo menee negatiiviseksi mutta ei alle -luottoRaja
        if (saldo - amount < -luottoRaja) return false;
        saldo -= amount;
        return true;
    }

    bool deposit(double amount) override
    {
        if (amount < 0) return false;
        // Luottotilin saldo ei saa olla yli 0
        if (saldo + amount > 0) return false;
        saldo += amount;
        return true;
    }

    double getLuottoRaja() const
    {
        return luottoRaja;
    }
};

class Asiakas
{
private:
    string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;

public:
    Asiakas(string n, double raja)
        : nimi(n), kayttotili(n), luottotili(n, raja) {}

    string getNimi() const
    {
        return nimi;
    }

    void showSaldo()
    {
        cout << nimi << endl;
        cout << "Kayttotilin saldo " << kayttotili.getBalance() << endl;
        cout << "Luottotilin saldo " << luottotili.getBalance() << endl;
    }

    bool talletus(double amount)
    {
        return kayttotili.deposit(amount);
    }

    bool nosto(double amount)
    {
        return kayttotili.withdraw(amount);
    }

    bool luotonMaksu(double amount)
    {
        return luottotili.deposit(amount);
    }

    bool luotonNosto(double amount)
    {
        return luottotili.withdraw(amount);
    }

    bool tiliSiirto(double summa, Asiakas& toinen)
    {
        if (summa < 0) return false;

        // Nostetaan ensin omalta tililtä
        if (!kayttotili.withdraw(summa))
            return false;

        // Talletetaan toiselle
        if (!toinen.kayttotili.deposit(summa))
        {
            // Jos talletus epäonnistui, palautetaan rahat
            kayttotili.deposit(summa);
            return false;
        }

        return true;
    }

    double getKayttotilinSaldo() const
    {
        return kayttotili.getBalance();
    }

    double getLuottotilinSaldo() const
    {
        return luottotili.getBalance();
    }

    double getLuottoRaja() const
    {
        return luottotili.getLuottoRaja();
    }
};

int main()
{
    // Luodaan Aapeli
    Asiakas aapeli("Aapeli", 1000);
    cout << "Pankkitili luotu " << aapeli.getNimi() << ":lle" << endl;
    cout << "Luottotili luotu " << aapeli.getNimi() << ":lle, luottoraja "
         << aapeli.getLuottoRaja() << endl;
    cout << "Asiakkuus luotu " << aapeli.getNimi() << endl;
    aapeli.showSaldo();

    cout << endl;

    // Tehdään talletuksia ja nostoja
    aapeli.talletus(250);
    cout << "Pankkitili: talletus 250 tehty" << endl;

    aapeli.luotonNosto(150);
    cout << "Luottotili: nosto 150 tehty, luottoa jaljella "
         << (aapeli.getLuottoRaja() + aapeli.getLuottotilinSaldo()) << endl;

    aapeli.showSaldo();

    cout << endl;

    // Luodaan Bertta
    Asiakas bertta("Bertta", 1000);
    cout << "Pankkitili luotu " << bertta.getNimi() << ":lle" << endl;
    cout << "Pankkitili luotu " << bertta.getNimi() << ":lle" << endl;
    cout << "Luottotili luotu " << bertta.getNimi() << ":lle, luottoraja "
         << bertta.getLuottoRaja() << endl;
    cout << "Asiakkuus luotu " << bertta.getNimi() << endl;
    bertta.showSaldo();

    cout << endl;

    // Siirto
    aapeli.showSaldo();

    cout << "Pankkitili: " << aapeli.getNimi() << " siirtaa 50 "
         << bertta.getNimi() << ":lle" << endl;

    aapeli.tiliSiirto(50, bertta);

    cout << aapeli.getNimi() << " Pankkitili: nosto 50 tehty" << endl;
    cout << bertta.getNimi() << " Pankkitili: talletus 50 tehty" << endl;

    bertta.showSaldo();

    return 0;
}
