﻿#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;
#define LUNGIME_VECTOR 3
#define LUNGIME_MATRICE_LINIE 2
#define LUNGIME_MATRICE_COLOANA 3

class casaDeDiscuri 
{
protected:
    int anInfiintare;
    string nume;

public:
    //constructorul default
    casaDeDiscuri()
    {
        this->anInfiintare = 2003;
        this->nume = "Global Records";
    }

    //functii virtuale
    virtual void publicTinta() const = 0; // Metoda virtuala pura pentru afisarea publicului tinta al unui artist
    virtual void promovare() const = 0; // Metoda virtuala pura pentru promovarea casei de discuri

    ~casaDeDiscuri() 
    {
    }

};

class magazinMuzical
{
protected:
    int anInfiintare;
    string nume;

public:
    magazinMuzical()
    {
        this->anInfiintare = 2010;
        this->nume = "Bombonica muzicala";
    }

    virtual void afiseazaInformatii() = 0;

    virtual void vinde() = 0;

    virtual void recomanda() = 0;

    ~magazinMuzical()
    {

    }

};

class Artist: public casaDeDiscuri
{
private:
    const int anAparitie;
    static int totalArtisti;
    string nume;
    int varsta;
    float avereEuro;
    int nrGenuriMuzicale;
    string* genuriMuzicale;
public:
    //Constructorul default
    Artist() : anAparitie(1776)
    {
        this->nume = "Wolfgang Amadeus Mozart";
        this->varsta = 35;
        this->avereEuro = 0.5;
        this->nrGenuriMuzicale = 2;
        this->genuriMuzicale = new string[this->nrGenuriMuzicale];
        for (int i = 0; i < this->nrGenuriMuzicale; ++i)
        {
            this->genuriMuzicale[i] = "Gen " + to_string(i + 1);
        }
        totalArtisti++;
    }
    //Constructorul cu toti parametrii
    Artist(string nume, int varsta, float avereEuro, int nrGenuriMuzicale, string* genuriMuzicale, int anAparitie) : anAparitie(anAparitie)
    {
        this->nume = nume;
        this->varsta = varsta;
        this->avereEuro = avereEuro;
        this->nrGenuriMuzicale = nrGenuriMuzicale;
        this->genuriMuzicale = new string[this->nrGenuriMuzicale];
        for (int i = 0; i < this->nrGenuriMuzicale; ++i)
        {
            this->genuriMuzicale[i] = genuriMuzicale[i];
        }
        totalArtisti++;
    }
    //Constructorul cu 2 parametrii
    Artist(string nume, int varsta) : anAparitie(1953)
    {
        this->nume = nume;
        this->varsta = varsta;
        this->avereEuro = 25.6;
        this->nrGenuriMuzicale = 0;
        this->genuriMuzicale = nullptr;
        totalArtisti++;
    }
    //Constructorul de copiere
    Artist& operator=(const Artist& artist)
    {
        if (this != &artist)
        {
            this->nume = artist.nume;
            this->varsta = artist.varsta;
            this->avereEuro = artist.avereEuro;
            this->nrGenuriMuzicale = artist.nrGenuriMuzicale;
            if (this->genuriMuzicale != NULL) {
                delete[]this->genuriMuzicale;
            }

            this->genuriMuzicale = new string[this->nrGenuriMuzicale];
            for (int i = 0; i < this->nrGenuriMuzicale; i++)
            {
                this->genuriMuzicale[i] = artist.genuriMuzicale[i];
            }
        }
        return *this;
    }
    friend ostream& operator<<(ostream& os, const Artist& artist);
    friend bool operator>(Artist& artist1, Artist& artist2);
    friend istream& operator>>(istream& input, Artist& artist);
    static int getTotalArtisti()
    {
        return totalArtisti;
    }
    int getAnAparitie()
    {
        return this->anAparitie;
    }
    string getNume() const
    {
        return this->nume;
    }
    int getVarsta() const
    {
        return this->varsta;
    }
    float getAvereEuro()
    {
        return this->avereEuro;
    }
    int getNrGenuriMuzicale()
    {
        return this->nrGenuriMuzicale;
    }
    string* getGenuriMuzicale()
    {
        return this->genuriMuzicale;
    }
    //Setteri
    static void setTotalArtisti(int _totalAristi)
    {
        if (_totalAristi >= 0)
        {
            totalArtisti = _totalAristi;
        }
    }
    void setNume(string _nume)
    {
        if (_nume != "" || _nume != " ")
        {
            this->nume = _nume;
        }
    }
    void getVarsta(int _varsta)
    {
        if (_varsta > 0)
        {
            this->varsta = _varsta;
        }
    }
    void setAvereEuro(float _avereEuro)
    {
        if (_avereEuro >= 0)
        {
            this->avereEuro = _avereEuro;
        }
    }
    void setNrGenuriMuzicale(int _nrGenuriMuzicale)
    {
        if (_nrGenuriMuzicale > 0)
        {
            this->nrGenuriMuzicale = _nrGenuriMuzicale;
        }
    }
    void setGenuriMuzicale(string* _genuriMuzicale)
    {
        if (_genuriMuzicale != NULL)
        {
            if (this->genuriMuzicale != NULL)
            {
                delete[]this->genuriMuzicale;
            }
            this->genuriMuzicale = new string[nrGenuriMuzicale];
            for (int i = 0; i < nrGenuriMuzicale; i++)
            {
                this->genuriMuzicale[i] = _genuriMuzicale[i];
            }
        }
    }

    //implementarea metodei virtuale din clasa casaDeDiscuri
    void publicTinta() const override {
        if (this->varsta >= 28)
        {
            cout << "Artistul: " << this->nume << " are ca public tinta adultii cu varsta de peste 28 de ani." << endl;
        }
        else if (this->varsta < 18)
        {
            cout << "Artistul: " << this->nume << " are ca public tinta copiii." << endl;
        }
        else
        {
            cout << "Artistul: " << this->nume << " este potrivit intregii familii." << endl;
        }

    }

    void promovare() const override {
        //aflu anul curent
        auto timp_curent = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        struct std::tm timp_info;
        localtime_s(&timp_info, &timp_curent);
        int an_curent = timp_info.tm_year + 1900;

        cout << "Artistul " << this->nume << " este promovat de casa de discuri, avand o avere de " << this->avereEuro << " Euro obtinuta in cei " << (an_curent - this->anAparitie) << " ani de activitate." << endl;
    }

    //Destructor
    ~Artist()
    {
        delete[] genuriMuzicale;
        totalArtisti--;
    }
};
int Artist::totalArtisti = 0;

class ArtistColaborator : public Artist, public casaDeDiscuri
{
protected:
    string* colaborareMelodii;
    string* colaborareArtisti;
    int nrArtistiColaborare;
    int nrMelodiiColaborare;

public:
    ArtistColaborator() :Artist("Sia", 37)
    {
        this->nrArtistiColaborare = 2;
        this->nrMelodiiColaborare = 2;
        colaborareMelodii = new string[this->nrMelodiiColaborare]{ "Cheap Thrills", "Genius" };
        colaborareArtisti = new string[this->nrArtistiColaborare]{ "Sean Paul", "Zayn" };
    }

    ArtistColaborator(int _nrMelodiiColaborare, string* _colaborareMelodii, int _nrArtistiColaborare, string* _colaborareArtisti) : Artist("Drake", 47), colaborareMelodii(nullptr), colaborareArtisti(nullptr)
    {
        this->nrArtistiColaborare = _nrArtistiColaborare;
        this->nrMelodiiColaborare = _nrMelodiiColaborare;
        if ((this->nrArtistiColaborare > 0) && (this->nrMelodiiColaborare > 0))
        {
            this->colaborareMelodii = new string[this->nrMelodiiColaborare];
            this->colaborareArtisti = new string[this->nrArtistiColaborare];

            for (int i = 0; i < this->nrMelodiiColaborare; i++)
            {
                this->colaborareMelodii[i] = _colaborareMelodii[i];
            }

            for (int i = 0; i < this->nrArtistiColaborare; i++)
            {
                this->colaborareArtisti[i] = _colaborareArtisti[i];
            }
        }
    }

    ArtistColaborator& operator=(const ArtistColaborator& a1)
    {
        if (this != &a1)
        {
            this->nrArtistiColaborare = a1.nrArtistiColaborare;
            this->nrMelodiiColaborare = a1.nrMelodiiColaborare;
            if ((this->nrArtistiColaborare > 0) && (this->nrMelodiiColaborare > 0))
            {
                this->colaborareMelodii = new string[this->nrMelodiiColaborare];
                this->colaborareArtisti = new string[this->nrArtistiColaborare];

                for (int i = 0; i < this->nrMelodiiColaborare; i++)
                {
                    this->colaborareMelodii[i] = a1.colaborareMelodii[i];
                }

                for (int i = 0; i < this->nrArtistiColaborare; i++)
                {
                    this->colaborareArtisti[i] = a1.colaborareArtisti[i];
                }
            }
            return *this;
        }

    }


    friend ostream& operator<<(ostream& print, ArtistColaborator& a1)
    {
        print << "Nume artist: " << a1.getNume() << "\n" << "Varsta: " << a1.getVarsta() << "\nAn aparitie: " << a1.getAnAparitie() << "\nAvere:" << a1.getAvereEuro() << "M euro\nGenuri muzicale: ";
        for (int i = 0; i < a1.getNrGenuriMuzicale(); i++)
        {
            print << a1.getGenuriMuzicale()[i] << " ";
        }
        print << "\nNr artisti colaborare: " << a1.nrArtistiColaborare << "\nArtisti: ";
        for (int i = 0; i < a1.nrArtistiColaborare; i++)
        {
            print << a1.colaborareArtisti[i] << " ";
        }
        print << "\nMelodii colaborare: ";
        for (int i = 0; i < a1.nrMelodiiColaborare; i++)
        {
            print << a1.colaborareMelodii[i] << " ";
        }
        print << "\n";
        return print;
    }



    //Setteri
    void setNrArtistiColaborare(int nr)
    {
        this->nrArtistiColaborare = nr;
    }
    void setNrMelodiiColaborare(int nr)
    {
        this->nrMelodiiColaborare = nr;
    }
    void setColaborareMelodii(string* melodii)
    {
        this->colaborareMelodii = melodii;
    }
    void setColaborareArtisti(string* artisti)
    {
        this->colaborareArtisti = artisti;
    }

    //Getteri
    int getNrArtistiColaborare()
    {
        return this->nrArtistiColaborare;
    }
    int getNrMelodiiColaborare()
    {
        return this->nrMelodiiColaborare;
    }
    string* getColaborareMelodii()
    {
        return this->colaborareMelodii;
    }
    string* getColaborareArtisti()
    {
        return this->colaborareArtisti;
    }

    //implementarea metodei virtuale din clasa casaDeDiscuri
    void publicTinta() const override
    {
        if (this->getVarsta() >= 28)
        {
            cout << "Artistul " << this->getNume() << " are ca public tinta adultii cu varsta de peste 28 de ani, colaborand cu ";
            for (int i = 0; i < this->nrArtistiColaborare - 1; i++)
            {
                cout << this->colaborareArtisti[i] << ",";
            }
            cout << this->colaborareArtisti[this->nrArtistiColaborare - 1] << "." << endl;
        }
        else if (this->getVarsta() < 18)
        {
            cout << "Artistul: " << this->getNume() << " are ca public tinta copiii, colaborand cu ";
            for (int i = 0; i < this->nrArtistiColaborare - 1; i++)
            {
                cout << this->colaborareArtisti[i] << ",";
            }
            cout << this->colaborareArtisti[this->nrArtistiColaborare - 1] << "." << endl;
        }
        else
        {
            cout << "Artistul: " << this->getNume() << " este potrivit intregii familii, colaborand cu ";
            for (int i = 0; i < this->nrArtistiColaborare - 1; i++)
            {
                cout << this->colaborareArtisti[i] << ",";
            }
            cout << this->colaborareArtisti[this->nrArtistiColaborare - 1] << "." << endl;
        }
    }

    void promovare() const override
    {

        cout << "Artistul " << this->getNume() << " este promovat de casa de discuri, avand un numar de " << this->nrArtistiColaborare << " artisti cu care a colaborat." << endl;
    }

    ~ArtistColaborator()
    {
        delete[] this->colaborareArtisti;
        delete[] this->colaborareMelodii;
    }
};

class Melodie;

class Album : public magazinMuzical
{
private:
    const int anLansare;
    static int TVA;
    string nume;
    int nrMelodii;
    float pret;
    string* numeMelodii;

public:
    //Constructorul default
    Album() : anLansare(1982), nume("Thriller"), nrMelodii(0), pret(15.99), numeMelodii(nullptr)
    {

    }
    //Constructorul cu 2 parametrii
    Album(string nume, float pret) : anLansare(1980)
    {
        this->nume = nume;
        this->nrMelodii = 3;
        this->pret = pret;
        this->numeMelodii = new string[this->nrMelodii]{ "HellsBells", "ShootToThrill", "BackInBlack" };
    }
    //Constructorul cu toti parametrii
    Album(string nume, int nrMelodii, float pret, string* numeMelodii) : anLansare(2022)
    {
        this->nume = nume;
        this->nrMelodii = nrMelodii;
        this->pret = pret;
        this->numeMelodii = new string[this->nrMelodii];
        for (int i = 0; i < nrMelodii; ++i)
        {
            this->numeMelodii[i] = numeMelodii[i];
        }
    }
    //Constructorul de copiere
    Album& operator=(Album& album)
    {
        if (this != &album)
        {
            this->nume = album.nume;
            this->nrMelodii = album.nrMelodii;
            this->pret = album.pret;
            if (this->numeMelodii != NULL)
            {
                delete[] this->numeMelodii;
            }
            this->numeMelodii = new string[this->nrMelodii];
            for (int i = 0; i < this->nrMelodii; i++)
            {
                this->numeMelodii[i] = album.numeMelodii[i];
            }

        }
        return *this;
    }
    void afisare()
    {
        cout << "Nume album: " << this->nume << "\nAn lansare: " << this->anLansare << "\nNumar melodii: " << this->nrMelodii << "\nPret: " << this->pret << " RON\nMelodii: ";
        for (int i = 0; i < this->nrMelodii; ++i) {
            cout << numeMelodii[i] << " ";
        }
        cout << "\n\n";
    }
    //Getteri
    int getAnLansare()
    {
        return this->anLansare;
    }
    static int getTVA()
    {
        return TVA;
    }
    string getNume()
    {
        return this->nume;
    }
    int getNrMelodii()
    {
        return this->nrMelodii;
    }
    float getPret()
    {
        return this->pret;
    }
    string* getNumeMelodii()
    {
        return this->numeMelodii;
    }
    //Setteri
    static void setTVA(int _TVA)
    {
        if (_TVA >= 0)
        {
            TVA = _TVA;
        }
    }
    void setNume(string _nume)
    {
        if (_nume != "" || _nume != " ")
        {
            this->nume = _nume;
        }
    }
    void setNrMelodii(int _nrMelodii)
    {
        if (_nrMelodii > 0)
        {
            this->nrMelodii = _nrMelodii;
        }
    }
    void setPret(float _pret)
    {
        if (_pret >= 0)
        {
            this->pret = _pret;
        }
    }
    void setNumeMelodii(string* _numeMelodii)
    {
        if (_numeMelodii != NULL)
        {
            if (this->numeMelodii != NULL)
            {
                delete[] this->numeMelodii;
            }
            this->numeMelodii = new string[this->nrMelodii];
            for (int i = 0; i < this->nrMelodii; i++)
            {
                this->numeMelodii[i] = _numeMelodii[i];
            }
        }
    }
    //Friend function
    friend void afisareAlbumMelodii(Album& album, Melodie& melodie);
    friend ostream& operator<<(ostream& os, const Album& album);
    friend bool operator>(Album& album1, Album& album2);
    friend istream& operator>>(istream& input, Album& album);

    //Implementarea functiilor virtuale
    void afiseazaInformatii() override {
        cout << "Album: " << this->nume << "\nAn lansare: " << this->anLansare << endl;
    }

    void vinde() override {
        cout << "Vanzare album: " << this->nume << endl;
    }

    void recomanda() override {
        cout << "Recomandare album: " << this->nume << endl;
    }
    
    //Destructor
    ~Album()
    {
        delete[] numeMelodii;
    }

};
int Album::TVA = 19;

class Melodie: public magazinMuzical 
{
private:

    const float durata;
    static int nrTotalMelodii;
    string nume;
    string numeArtist;
    int nrVersuri;
    string* versuri;
public:
    //Constructorul default
    Melodie() : durata(4.0)
    {
        this->nume = "HellsBells";
        this->numeArtist = "AC/DC";
        this->nrVersuri = 2;
        this->versuri = new std::string[this->nrVersuri]{ "VersulNr1", "VersulNr2" };
        nrTotalMelodii++;
    }
    //Constructorul cu 2 parametrii
    Melodie(float durata, string nume) : durata(durata)
    {
        this->nume = nume;
        this->numeArtist = "Adele";
        this->nrVersuri = 4;
        this->versuri = new std::string[this->nrVersuri]{ "Close enough to start a war", "All that I have is on the floor", "God only knows what we're fighting for", "All that I say, you always say more" };

        nrTotalMelodii++;
    }
    //Constructorul cu toti parametrii
    Melodie(float durata, string nume, string numeArtist, int nrVersuri, string* versuriArray) : durata(durata), nume(nume), numeArtist(numeArtist), nrVersuri(nrVersuri), versuri(new string[nrVersuri])
    {
        for (int i = 0; i < nrVersuri; ++i)
        {
            this->versuri[i] = versuriArray[i];
        }
        nrTotalMelodii++;
    }
    //Constructorul de copiere
    Melodie& operator=(Melodie& melodie)
    {
        if (this != &melodie)
        {
            this->nume = melodie.nume;
            this->numeArtist = melodie.numeArtist;
            this->nrVersuri = melodie.nrVersuri;
            if (this->versuri != NULL)
            {
                delete[] this->versuri;
            }
            this->versuri = new string[this->nrVersuri];
            for (int i = 0; i < this->nrVersuri; i++)
            {
                this->versuri[i] = melodie.versuri[i];
            }
        }
        return *this;
    }
    //Getteri
    float getDurata()
    {
        return this->durata;
    }
    static int getNrTotalMelodii()
    {
        return nrTotalMelodii;
    }
    string getNume()
    {
        return this->nume;
    }
    string getNumeArtist()
    {
        return this->numeArtist;
    }
    int getNrVersuri()
    {
        return this->nrVersuri;
    }
    string* getVersuri()
    {
        return this->versuri;
    }
    //Setteri
    static void setNrtotalMelodii(int _nrTotalMelodii)
    {
        if (_nrTotalMelodii >= 0)
        {
            nrTotalMelodii = _nrTotalMelodii;
        }
    }
    void setNume(string _nume)
    {
        if (_nume != "" || _nume != " ")
        {
            this->nume = _nume;
        }
    }
    void setNumeArtist(string _numeArtist)
    {
        if (_numeArtist != "" || _numeArtist != " ")
        {
            this->numeArtist = _numeArtist;
        }
    }
    void setNrVersuri(int _nrVersuri)
    {
        if (_nrVersuri > 0)
        {
            this->nrVersuri = _nrVersuri;
        }
    }
    void setVersuri(string* _versuri)
    {
        if (_versuri != NULL)
        {
            if (this->versuri != NULL)
            {
                delete[] this->versuri;
            }
            this->versuri = new string[this->nrVersuri];
            for (int i = 0; i < this->nrVersuri; i++)
            {
                this->versuri[i] = _versuri[i];
            }
        }
    }
    void afisare()
    {
        cout << "Nume melodie: " << this->nume << "\nNume artist: " << this->numeArtist << "\nDurata: " << this->durata << " minute\nVersuri:\n";
        for (int i = 0; i < this->nrVersuri; ++i)
        {
            cout << versuri[i] << "\n";
        }
        cout << endl;
    }
    //Friend function
    friend void afisareMelodieArist(Artist& artist, Melodie& melodie);
    friend ostream& operator<<(ostream& os, const Melodie& melodie);
    friend bool operator>(Melodie& melodie1, Melodie& melodie2);
    friend bool operator!=(Melodie& melodie1, Melodie& melodie2);
    friend istream& operator>>(istream& input, Melodie& melodie);
    friend ifstream& operator>>(ifstream& input, Melodie& melodie);

    //Implementarea metodelor virtuale
    void afiseazaInformatii() override {
        cout << "Melodie: " << this->nume << "\nDurata: " << durata << " secunde" << endl;
    }

    void vinde() override {
        cout << "Vanzare melodie: " << this->nume << endl;
    }

    void recomanda() override {
        cout << "Recomandare melodie: " << this->nume << endl;
    }
    //Destructor
    ~Melodie()
    {
        delete[] versuri;
        nrTotalMelodii--;
    }
};
int Melodie::nrTotalMelodii = 0;

class RemixMelodie : Melodie
{
protected:
    float nouaDurata;
    string numeRemixer;

public:
    RemixMelodie(float _nouaDurata) : Melodie(_nouaDurata, "Snowman")
    {
        this->numeRemixer = "Santa Clause";
        this->nouaDurata = _nouaDurata;
    }
    friend ostream& operator<<(ostream& print, RemixMelodie& r1)
    {
        print << "Nume melodie: " << r1.getNume() << "\nNume artist: " << r1.getNumeArtist() << "\nNume remixer: " << r1.numeRemixer << "\nDurata: " << r1.nouaDurata << " minute\nVersuri:\n";
        for (int i = 0; i < r1.getNrVersuri(); ++i)
        {
            print << r1.getVersuri()[i] << "\n";
        }
        print << endl;
        return print;
    }
    //Setteri
    void setNumeRemixer(string nume)
    {
        this->numeRemixer = nume;
    }
    void setNouaDurata(float durata)
    {
        this->nouaDurata = durata;
    }
    //Getteri
    string getNumeRemixer()
    {
        return this->numeRemixer;
    }
    float getNouaDurata()
    {
        return this->nouaDurata;
    }

    ~RemixMelodie()
    {

    }
};

class Concert
{
private:
    Artist artist;
    string data;
    int participanti;
public:
    Concert()
    {
        this->artist;
        this->data = "15.06.2024";
        this->participanti = 1589324;
    }

    //setteri
    void setArtistConcert(Artist a1)
    {
        this->artist = a1;
    }
    void setData(string data)
    {
        this->data = data;
    }
    void setParticipanti(int participanti)
    {
        this->participanti = participanti;
    }
    //getteri
    Artist getArtist()
    {
        return this->artist;
    }
    string getData()
    {
        return this->data;
    }
    int getParticipanti()
    {
        return this->participanti;
    }

    Concert& operator=(Concert& c1)
    {
        if (this != &c1)
        {
            this->artist = c1.artist;
            this->data = c1.data;
            this->participanti = c1.participanti;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& os, const Concert& c1);
    friend istream& operator>>(istream& input, Concert& c1);

    ~Concert()
    {

    }


};

//Functii friend declarate in clase si implementate aici
void afisareMelodieArist(Artist& artist, Melodie& melodie)
{
    if (artist.getNume() == melodie.getNumeArtist())
    {
        cout << "\n\nFriend function:\nArtistul " << artist.getNume() << " a compus melodia " << melodie.getNume() << "." << endl;
    }
}
//Supraincarcarea operatorului << pentru afisarea obiectului de tip Melodie
ostream& operator<<(ostream& print, const Melodie& melodie)
{
    print << melodie.nume << "\n" << melodie.numeArtist << "\n" << melodie.durata << "\n";
    for (int i = 0; i < melodie.nrVersuri; ++i)
    {
        print << melodie.versuri[i] << "\n";
    }
    print << endl;
    return print;
}
//Supraincarcarea operatorului << pentru afisarea obiectului de tip Artist
ostream& operator<<(ostream& print, const Artist& artist)
{
    print << artist.nume << "\n" << artist.varsta << "\n" << artist.anAparitie << "\n" << artist.avereEuro << "\n";
    for (int i = 0; i < artist.nrGenuriMuzicale; i++)
    {
        print << artist.genuriMuzicale[i] << " ";
    }
    print << "\n\n";
    return print;
}
//Supraincarcarea operatorului > pentru compararea varstei a doi artisti
bool operator>(Artist& artist1, Artist& artist2)
{
    if (artist1.varsta > artist2.varsta)
    {
        return 0;
    }
    else
    {
        return 0;
    }

}
//Supraincarcarea operatorului > pentru compararea duratei a doua melodii
bool operator>(Melodie& melodie1, Melodie& melodie2)
{
    if (melodie1.durata > melodie2.durata)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//Supraincarcarea operatorului != pentru compararea numelui artistului
bool operator!=(Melodie& melodie1, Melodie& melodie2)
{
    if (melodie1.numeArtist != melodie2.numeArtist)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void afisareAlbumMelodii(Album& album, Melodie& melodie)
{
    string numeMelodie = melodie.getNume();
    string* melodii = album.getNumeMelodii();
    for (int i = 0; i < album.getNrMelodii(); i++)
    {
        if (numeMelodie == melodii[i])
        {
            cout << "\n\nFriend function:\nMelodia " << numeMelodie << " face parte din albumul " << album.getNume() << "." << endl;
        }
    }
}
//Supraincarcarea operatorului << pentru afisarea obiectului de tip Album
ostream& operator<<(ostream& print, const Album& album)
{
    print << album.nume << "\n" << album.anLansare << "\n" << album.nrMelodii << "\n" << album.pret << "\n";
    for (int i = 0; i < album.nrMelodii; ++i) {
        print << album.numeMelodii[i] << " ";
    }
    print << "\n\n";
    return print;
}
//Supraincarcarea operatorului > pentru compararea numarului de melodiilor din cele 2 albume
bool operator>(Album& album1, Album& album2)
{
    if (album1.nrMelodii > album2.nrMelodii)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//Supraincarcarea operatorului >> pentru citirea unui obict de tip Album
istream& operator>>(istream& input, Album& album)
{
    int _nrMelodii, _anLansare;
    float _pret;
    string _nume;
    string* _numeMelodii;

    cout << "Nume album: "; input >> _nume;
    cout << "Pret: "; input >> _pret;
    cout << "Numar melodii: "; input >> _nrMelodii;
    _numeMelodii = new string[_nrMelodii];

    for (int i = 0; i < _nrMelodii; i++)
    {
        cout << "Melodia " << i + 1 << ": ";
        input >> _numeMelodii[i];
    }

    album.nume = _nume;
    album.pret = _pret;
    album.nrMelodii = _nrMelodii;
    //Dezalocam memoria din heap in caz ca era ceva acolo
    delete[] album.numeMelodii;
    album.numeMelodii = _numeMelodii;

    return input;
}
//Supraincarcarea operatorului >> pentru citirea unui obict de tip Artist
istream& operator>>(istream& input, Artist& artist)
{
    int _varsta, _nrGenuriMuzicale;
    float _avereEuro;
    string _nume;
    string* _genuriMuzicale;

    cout << "Nume artist: "; input >> _nume;
    cout << "Varsta: "; input >> _varsta;
    cout << "Avere(euro): "; input >> _avereEuro;
    cout << "Numar genuri muzicale: "; input >> _nrGenuriMuzicale;
    _genuriMuzicale = new string[_nrGenuriMuzicale];

    for (int i = 0; i < _nrGenuriMuzicale; i++)
    {
        cout << "Genul " << i + 1 << ": ";
        input >> _genuriMuzicale[i];
    }

    artist.nume = _nume;
    artist.varsta = _varsta;
    artist.avereEuro = _avereEuro;
    artist.nrGenuriMuzicale = _nrGenuriMuzicale;
    //Dezalocam memoria din heap in caz ca era ceva acolo
    delete[] artist.genuriMuzicale;
    artist.genuriMuzicale = _genuriMuzicale;

    return input;
}
//Supraincarcarea operatorului >> pentru citirea unui obict de tip Melodie
istream& operator>>(istream& input, Melodie& melodie)
{
    string _nume;
    string _numeArtist;
    int _nrVersuri;
    string* _versuri;
    cout << "Nume melodie: "; input >> _nume;
    cout << "Nume artist: "; input >> _numeArtist;
    cout << "Numar versuri "; input >> _nrVersuri;
    _versuri = new string[_nrVersuri];
    for (int i = 0; i < _nrVersuri; i++)
    {
        cout << "Versul " << (i + 1) << ": ";
        input >> _versuri[i];
    }
    melodie.nume = _nume;
    melodie.numeArtist = _numeArtist;
    melodie.nrVersuri = _nrVersuri;
    //Dezalocam memoria din heap in caz ca era ceva acolo
    delete[] melodie.versuri;
    melodie.versuri = _versuri;
    return input;
}
//Supraincarcarea operatorului >> pentru citirea obiectului de tip Melodie
ifstream& operator>>(ifstream& input, Melodie& melodie)
{
    string _nume;
    string _numeArtist;
    int _nrVersuri;
    string space = " ";
    string* _versuri;
    input >> _nume;
    input >> _numeArtist;
    input >> _nrVersuri;
    _versuri = new string[_nrVersuri];
    for (int i = 0; i < _nrVersuri; i++)
    {
        input >> _versuri[i] >> space;
    }
    melodie.nume = _nume;
    melodie.numeArtist = _numeArtist;
    melodie.nrVersuri = _nrVersuri;
    //Dezalocam memoria din heap in caz ca era ceva acolo
    delete[] melodie.versuri;
    melodie.versuri = _versuri;
    return input;
}
//Supraincarcarea operatorului << pentru afisarea obiectului de tip Concert
ostream& operator<<(ostream& print, const Concert& c1)
{
    print << c1.artist.getNume() << " a avut un concert in data de " << c1.data << " la care au participat " << c1.participanti << " de oameni.\n";
    return print;
}
//Supraincarcarea operatorului << pentru citirea unui obiect de tip Concert
istream& operator>>(istream& input, Concert& c1)
{
    Artist a1;
    string numeArtist;
    string dataConcert;
    int participanti;
    cout << "Nume artist: ";
    input >> numeArtist;
    cout << "Data concert: ";
    input >> dataConcert;
    cout << "Nr participanti: ";
    input >> participanti;
    c1.artist.setNume(numeArtist);
    c1.data = dataConcert;
    c1.participanti = participanti;

    return input;
}
//Afisarea datelor de tip binar din fisierul artisti
void afisareBinaryArtisti()
{
    Artist a1;
    int anAparitie = a1.getAnAparitie();
    int totalArtisti = a1.getTotalArtisti();
    string nume = a1.getNume();
    int varsta = a1.getVarsta();
    float avereEuro = a1.getAvereEuro();
    int nrGenuriMuzicale = a1.getNrGenuriMuzicale();
    int sizeNume = nume.length();
    string* genuriMuzicale = new string[nrGenuriMuzicale];
    for (int i = 0; i < nrGenuriMuzicale; i++)
    {
        genuriMuzicale[i] = a1.getGenuriMuzicale()[i];
    }

    ifstream afisareBinaryArtisti("artisti.bin", ios::binary);

    if (afisareBinaryArtisti.is_open())
    {
        afisareBinaryArtisti.read((char*)&anAparitie, sizeof(int));
        afisareBinaryArtisti.read((char*)&totalArtisti, sizeof(int));
        afisareBinaryArtisti.read((char*)&sizeNume, sizeof(int));

        nume.resize(sizeNume);
        afisareBinaryArtisti.read(&nume[0], sizeNume);

        afisareBinaryArtisti.read((char*)&varsta, sizeof(int));
        afisareBinaryArtisti.read((char*)&avereEuro, sizeof(float));

        for (int i = 0; i < nrGenuriMuzicale; i++)
        {
            int strSize;
            afisareBinaryArtisti.read((char*)&strSize, sizeof(int));
            genuriMuzicale[i].resize(strSize);
            afisareBinaryArtisti.read(&genuriMuzicale[i][0], strSize);
        }

        afisareBinaryArtisti.close();

        cout << "Nume artist: " << nume << "\nVarsta: " << varsta << "\nAn aparitie: " << anAparitie << "\nAvere: " << avereEuro << "M euro\nGenuri muzicale: ";
        for (int i = 0; i < nrGenuriMuzicale; i++)
        {
            cout << genuriMuzicale[i] << " ";
        }
        cout << "\n\n";

        delete[] genuriMuzicale;
    }
    else
    {
        cout << "Nu am putut deschide fisierul binar :(\n";
        delete[] genuriMuzicale;
    }
}
//Citirea datelor de tip binar din fisierul artisti
void citireBinaryArtisti()
{
    Artist a1;
    int anAparitie = a1.getAnAparitie();
    int totalArtisti = a1.getTotalArtisti();
    string nume = a1.getNume();
    int varsta = a1.getVarsta();
    float avereEuro = a1.getAvereEuro();
    int nrGenuriMuzicale = a1.getNrGenuriMuzicale();
    int sizeNume = nume.length();
    string* genuriMuzicale = new string[nrGenuriMuzicale];
    for (int i = 0; i < nrGenuriMuzicale; i++)
    {
        genuriMuzicale[i] = a1.getGenuriMuzicale()[i];
    }

    fstream citireBinaryArtisti("artisti.bin", ios::binary | ios::out);

    if (citireBinaryArtisti.is_open())
    {
        citireBinaryArtisti.write((char*)&anAparitie, sizeof(int));
        citireBinaryArtisti.write((char*)&totalArtisti, sizeof(int));
        citireBinaryArtisti.write((char*)&sizeNume, sizeof(int));
        citireBinaryArtisti.write(&nume[0], sizeNume);

        citireBinaryArtisti.write((char*)&varsta, sizeof(int));
        citireBinaryArtisti.write((char*)&avereEuro, sizeof(float));

        for (int i = 0; i < nrGenuriMuzicale; i++)
        {
            int strSize = genuriMuzicale[i].length();
            citireBinaryArtisti.write((char*)&strSize, sizeof(int));
            citireBinaryArtisti.write(&genuriMuzicale[i][0], strSize);
        }

        citireBinaryArtisti.close();
        delete[] genuriMuzicale;
    }
    else
    {
        cout << "Nu am putut deschide fisierul binar :(\n";
        delete[] genuriMuzicale;
    }
}
//Afisarea datelor de tip binar din fisierul melodii
void afisareBinaryMelodii()
{
    Melodie m1;
    float durata = m1.getDurata();
    int nrTotalMelodii = m1.getNrTotalMelodii();
    string nume = m1.getNume();
    string numeArtist = m1.getNumeArtist();
    int sizeNume = nume.length();
    int nrVersuri = m1.getNrVersuri();
    string* versuri;
    if (nrVersuri > 0)
    {
        versuri = new string[nrVersuri];
        for (int i = 0; i < nrVersuri; i++)
        {
            versuri[i] = m1.getVersuri()[i];
        }
    }
    else
    {
        versuri = NULL;
    }

    ifstream afisareBinaryMelodii("melodii.bin", ios::binary);
    int strSize;
    if (afisareBinaryMelodii.is_open())
    {
        afisareBinaryMelodii.read((char*)&durata, sizeof(float));
        afisareBinaryMelodii.read((char*)&nrTotalMelodii, sizeof(int));
        afisareBinaryMelodii.read((char*)&sizeNume, sizeof(int));

        nume.resize(sizeNume);
        afisareBinaryMelodii.read(&nume[0], sizeNume);

        afisareBinaryMelodii.read((char*)&sizeNume, sizeof(int));
        numeArtist.resize(sizeNume);
        afisareBinaryMelodii.read(&numeArtist[0], sizeNume);

        afisareBinaryMelodii.read((char*)&nrVersuri, sizeof(int));

        for (int i = 0; i < nrVersuri; i++)
        {
           
            afisareBinaryMelodii.read((char*)&strSize, sizeof(int));
            if (strSize > 0)
            {
                versuri[i].resize(strSize);
                afisareBinaryMelodii.read(&versuri[i][0], strSize);
            }
        }

        afisareBinaryMelodii.close();

        cout << "Nume melodie: " << nume << "\nDurata: " << durata << " minutes\nArtist: " << numeArtist
            << "\nTotal melodii: " << nrTotalMelodii << "\nVersuri: ";
        if ((nrVersuri > 0) && (versuri != NULL))
        {
            for (int i = 0; i < nrVersuri; i++)
            {
                cout << versuri[i] << " ";
            }
        }

        delete[] versuri;
    }
    else
    {
        cout << "Nu am putut deschide fisierul :(\n";
        delete[] versuri;
        afisareBinaryMelodii.close();
    }
}
//Citirea datelor de tip binar din fisierul melodii
void citireBinaryMelodii()
{
    Melodie m1;
    float durata = m1.getDurata();
    int nrTotalMelodii = m1.getNrTotalMelodii();
    string nume = m1.getNume();
    string numeArtist = m1.getNumeArtist();
    int nrVersuri = m1.getNrVersuri();
    string* versuri = new string[nrVersuri];
    int sizeNume = nume.length();
    for (int i = 0; i < nrVersuri; i++)
    {
        versuri[i] = m1.getVersuri()[i];
    }
    ofstream citireBinaryMelodii("melodii.bin", ios::binary);

    if (citireBinaryMelodii.is_open())
    {
        citireBinaryMelodii.write((char*)&durata, sizeof(float));
        citireBinaryMelodii.write((char*)&nrTotalMelodii, sizeof(int));
        citireBinaryMelodii.write((char*)&sizeNume, sizeof(int));
        citireBinaryMelodii.write(nume.c_str(), sizeNume);

        int sizeNumeArtist = numeArtist.length();
        citireBinaryMelodii.write((char*)&sizeNumeArtist, sizeof(int));
        citireBinaryMelodii.write(numeArtist.c_str(), sizeNumeArtist);

        citireBinaryMelodii.write((char*)&nrVersuri, sizeof(int));

        for (int i = 0; i < nrVersuri; i++)
        {
            int strSize = versuri[i].length();
            citireBinaryMelodii.write((char*)&strSize, sizeof(int));
            citireBinaryMelodii.write(versuri[i].c_str(), strSize);
        }

        citireBinaryMelodii.close();
    }
    else
    {
        cout << "Nu am putut deschide fisierul :(\n";
    }

    delete[] versuri;
}


int main()
{
    //--------Faza 1-----------------
    //Artist
    string adeleGenuriMuzicale[] = { "Pop", "Rock" };
    //Apelarea constructorului cu toti parametrii
    Artist adele("Adele", 35, 220.53, 2, adeleGenuriMuzicale, 2006);
    //Apelarea constructorului cu 2 parametrii
    Artist elvis("Elvis Presley", 40);
    //Apelarea constructorului default
    Artist artistCult;

    Artist copyAdele;
    //Apelarea constructorului de copiere
    copyAdele = adele;
    //Supraincarcarea operatorului >> pentru a afisa un obiect de tip Artist
    cout << adele;
    cout << elvis;
    cout << artistCult;
    cout << "Copy constructor:\n";
    cout << copyAdele;
    //----------End Faza 1----------------
    
    //--------Faza 2-----------------
    //Getteri si setteri
    Artist artistGetSet;
    //Set
    artistGetSet.setNume("Bruno Mars");
    artistGetSet.setAvereEuro(30.2);
    artistGetSet.setNrGenuriMuzicale(2);
    artistGetSet.setGenuriMuzicale(adeleGenuriMuzicale);

    //Get
    cout << "Artist get & set:" << endl;
    cout << "Nume artist: " << artistGetSet.getNume() << endl;
    cout << "Varsta: " << artistGetSet.getVarsta() << endl;
    cout << "An aparitie: " << artistGetSet.getAnAparitie() << endl;
    cout << "Avere: " << artistGetSet.getAvereEuro() << "M euro" << endl;
    cout << "Nr genuri muzicale: " << artistGetSet.getNrGenuriMuzicale() << endl;
    string* artistGenres = artistGetSet.getGenuriMuzicale();
    cout << "Genuri muzicale: ";
    for (int i = 0; i < artistCult.getNrGenuriMuzicale(); i++)
    {
        cout << artistGenres[i] << " ";
    }
    //--------End Faza 2-----------------
     
    //--------Faza 3-----------------
    //Supraincarcarea operatorului > pentru a compara varsta a doi artisti
    cout << endl << endl;
    if (adele > elvis)
    {
        cout << adele.getNume() << " este mai mare ca " << elvis.getNume() << endl;
    }
    else
    {
        cout << elvis.getNume() << " este mai mare ca " << adele.getNume() << endl;
    }

    //Supraincarcarea operatorului >>
    Artist artistRandom;
    cin >> artistRandom;
    //Afisarea artistului citit de la tastatura
    cout << endl;
    cout << artistRandom;

    cout << "\nTotal artisti: " << Artist::getTotalArtisti() << endl << endl;
    //--------End Faza 3-----------------
    
    //--------Faza 4-----------------
    //Vector artist
    Artist vectorArtisti[LUNGIME_VECTOR];
    cout << "Citirea obiectelor de tip artist:\n";
    for (int i = 0; i < LUNGIME_VECTOR; i++)
    {
        cin >> vectorArtisti[i];
    }
    //afisarea obiectelor din vector
    cout << "Afisarea obiectelor de tip artist:\n";
    for (int i = 0; i < LUNGIME_VECTOR; i++)
    {
        cout << vectorArtisti[i] << endl;
    }
    //--------End Faza 4-----------------
    

    //--------Faza 1-----------------
    //Album
    string numeMelodii[] = { "SpeakToMe", "Breathe(InTheAir)", "BrainDamage" };
    //Apelarea constructorului default
    Album albumulUnu;
    //Apelarea constructorului cu toti parametrii
    Album albumulDoi("Back in Black", 29.99);
    //Apelarea constructorului cu toti parametrii
    Album albumulTrei("The Dark Side of the Moon", 3, 39.99, numeMelodii);

    Album copyAlbumUnu;
    //Apelarea constructorului de copiere
    copyAlbumUnu = albumulUnu;

    //albumulUnu.afisare();
    //Supraincarcarea operatorului >> pentru afisarea unui obiect de tip Album
    cout << albumulUnu;

    albumulDoi.afisare();
    albumulTrei.afisare();
    cout << "Copy constructor:\n";
    copyAlbumUnu.afisare();
    //--------End Faza 1-----------------

    //--------Faza 2-----------------
    //Getteri si setteri
    Album albumGetSet;
    //Set
    albumGetSet.setNume("To the future");
    albumGetSet.setNrMelodii(10);
    albumGetSet.setPret(25.99);
    albumGetSet.setNrMelodii(3);
    albumGetSet.setNumeMelodii(numeMelodii);
    //Get
    cout << "Album get & set:" << endl;
    cout << "Nume album: " << albumGetSet.getNume() << endl;
    cout << "An lansare: " << albumGetSet.getAnLansare() << endl;
    cout << "Pret: " << albumGetSet.getPret() << " RON" << endl;
    cout << "Nr. melodii: " << albumGetSet.getNrMelodii() << endl;
    string* album = albumGetSet.getNumeMelodii();
    cout << "Melodii ";
    for (int i = 0; i < albumGetSet.getNrMelodii(); i++)
    {
        cout << album[i] << " ";
    }

    cout << "\n\nTVA: " << Album::getTVA() << "%" << endl << endl;
    //--------End Faza 2-----------------

    //--------Faza 3-----------------
    //Supraincarcarea operatorului > pentru a compara numarul de melodii din cele doua albume
    if (albumulUnu > albumulTrei)
    {
        cout << "Albumul " << albumulUnu.getNume() << " are mai multe melodii (" << albumulUnu.getNrMelodii() << ") fata de albumul " << albumulTrei.getNume() << " (" << albumulDoi.getNrMelodii() << ") " << endl << endl;
    }
    else
    {
        cout << "Albumul " << albumulUnu.getNume() << " are mai putine melodii (" << albumulUnu.getNrMelodii() << ") fata de albumul " << albumulTrei.getNume() << " (" << albumulDoi.getNrMelodii() << ") " << endl << endl;

    }

    Album readAlbum;
    //Supraincarcarea operatorului >> pentru a citi un obiect de tip Album
    cin >> readAlbum;
    //Afisarea albumului
    cout << endl;
    cout << readAlbum;
    //--------End Faza 3-----------------

    //--------Faza 4-----------------
    //Vector Album
    Album vectorAlbume[LUNGIME_VECTOR];
    cout << "Citirea obiectelor de tip album:\n\n";
    for (int i = 0; i < LUNGIME_VECTOR; i++)
    {
        cin >> vectorAlbume[i];
    }
    //afisarea obiectelor din vector
    cout << "Afisarea obiectelor de tip album:\n\n";
    for (int i = 0; i < LUNGIME_VECTOR; i++)
    {
        cout << vectorAlbume[i] << endl;
    }

    //Matrice Album
    Album matriceAlbume[LUNGIME_MATRICE_LINIE][LUNGIME_MATRICE_COLOANA];
    cout << "Citirea unei matrice de tip album:\n\n";
    for (int i = 0; i < LUNGIME_MATRICE_LINIE; i++)
    {
        for (int j = 0; j < LUNGIME_MATRICE_COLOANA; j++)
        {
            cin >> matriceAlbume[i][j];
        }
    }
    //afisarea obiectelor din martice
    cout << "Afisarea matricei de tip album:\n\n";
    for (int i = 0; i < LUNGIME_MATRICE_LINIE; i++)
    {
        for (int j = 0; j < LUNGIME_MATRICE_COLOANA; j++)
        {
            cout << matriceAlbume[i][j];
        }
        cout << endl;
    }
    //--------End Faza 4-----------------

    //--------Faza 1-----------------
    //Melodie
    string versuriArray[] = { "I'm Mr. Originality", "Come my way, come and see", "Let me be your fantasy" };
    //Apelarea constructorului default
    Melodie melodieImplicita;
    //Supraincarcarea operatorului >> pentru afisarea obictului de tip Melodie
    cout << melodieImplicita;
    //Apelarea constructorului cu 2 parametrii
    Melodie melodieCuDurataNume(4.10, "TurningTables");
    cout << melodieCuDurataNume;
    //Apelarea constructorului cu toti parametrii
    Melodie mrOriginality(3.20, "MrOriginality", "Simplu", 3, versuriArray);
    cout << mrOriginality;
    Melodie copyMelodieImplicita;
    //Apelarea constructorului de copiere
    copyMelodieImplicita = melodieImplicita;
    cout << copyMelodieImplicita;
    //--------End Faza 1-----------------
    
    //--------Faza 2-----------------
    //Getteri si setteri
    Melodie melodieGetSet;
    //Set
    melodieGetSet.setNume("Rolling in the Deep");
    melodieGetSet.setNumeArtist("Adele");
    melodieGetSet.setNrVersuri(3);
    melodieGetSet.setVersuri(versuriArray);
    //Get
    cout << "Melodie get & set:" << endl;
    cout << "Nume melodie: " << melodieGetSet.getNume() << endl;
    cout << "Nume artist: " << melodieGetSet.getNumeArtist() << endl;
    cout << "Durata: " << melodieGetSet.getDurata() << " minute" << endl;
    cout << "Nr. versuri: " << melodieGetSet.getNrVersuri() << endl;
    string* melodie = melodieGetSet.getVersuri();
    cout << "Versuri ";
    for (int i = 0; i < melodieGetSet.getNrVersuri(); i++)
    {
        cout << melodie[i] << "\n";
    }
    afisareMelodieArist(adele, melodieGetSet);
    afisareAlbumMelodii(albumulDoi, melodieImplicita);

    cout << "\n\nTotal Melodii: " << Melodie::getNrTotalMelodii() << endl;
    //--------End Faza 2-----------------

    //--------Faza 3-----------------
    //Supraincarcarea operatorului > pentru a compara durata a doua melodii

    if (melodieCuDurataNume > mrOriginality)
    {
        cout << "\nDurata melodiei " << melodieCuDurataNume.getNume() << "(" << melodieCuDurataNume.getDurata() << " min)" << " este mai mare ca a melodiei " << mrOriginality.getNume() << "(" << mrOriginality.getDurata() << " min)" << endl << endl;
    }
    else
    {
        cout << "\nDurata melodiei " << melodieCuDurataNume.getNume() << "(" << melodieCuDurataNume.getDurata() << " min)" << " este mai mica fata de cea a melodiei " << mrOriginality.getNume() << "(" << mrOriginality.getDurata() << " min)" << endl << endl;

    }
    //Supraincarcarea operatorului > pentru a compara daca doua melodii sunt interpretate de acelasi artist
    if (melodieCuDurataNume != mrOriginality)
    {
        cout << "Melodiile " << melodieCuDurataNume.getNume() << " si " << mrOriginality.getNume() << "sunt interpretate artisti diferiti.\n" << endl;

    }
    else
    {
        cout << "Melodiile " << melodieCuDurataNume.getNume() << " si " << mrOriginality.getNume() << "sunt interpretate de acelasi artist, " << mrOriginality.getNumeArtist() << ".\n" << endl;

    }
    //--------End Faza 3-----------------

    //--------Faza 4-----------------
    //Vector Melodie
    Melodie vectorMelodii[LUNGIME_VECTOR];
    cout << "Citirea obiectelor de tip artist:\n\n";
    for (int i = 0; i < LUNGIME_VECTOR; i++)
    {
        cin >> vectorMelodii[i];
    }
    //afisarea obiectelor din vector
    cout << "Afisarea obiectelor de tip artist:\n\n";
    for (int i = 0; i < LUNGIME_VECTOR; i++)
    {
        cout << vectorMelodii[i] << endl;
    }
    //--------End Faza 4-----------------

    //--------Faza 5-----------------
    Concert c1;
    cin >> c1;
    cout << c1;
    Concert c2;
    c2 = c1;
    //--------End Faza 5-----------------

    //--------Faza 6-----------------
    Artist artist5;
    Melodie melodie5;
    //Afisare artist in fisier text
    ofstream afisareTextArtisti("artisti.txt", ios::out);
    afisareTextArtisti << artist5;
    //Citire artist din fisier text
    ifstream citireTextArtisti("artisti.txt", ios::in);
    //Afisare melodie in fisier text
    ofstream afisareTextMelodii("melodii.txt", ios::out);
    afisareTextMelodii << melodie5;
    //Citire melodie din fisier text
    ifstream citireTextMelodii("melodii.txt", ios::in);

    citireBinaryArtisti();
    afisareBinaryArtisti();

    citireBinaryMelodii();
    afisareBinaryMelodii();

    //--------End Faza 6-----------------

    //--------Faza 7-----------------
    ArtistColaborator ac1;
    cout << ac1;

    int nrArtistiColaborare = 2, nrMelodiiColaborare = 2;
    string* colaborareMelodii = new string[nrMelodiiColaborare];
    string* colaborareArtisti = new string[nrArtistiColaborare];
    for (int i = 0; i < nrMelodiiColaborare; i++)
    {
        colaborareMelodii[i] = "MelodieColab" + to_string(i + 1);
    }
    for (int i = 0; i < nrArtistiColaborare; i++)
    {
        colaborareArtisti[i] = "ArtistColab" + to_string(i + 1);
    }

    ArtistColaborator a2(nrMelodiiColaborare, colaborareMelodii, nrArtistiColaborare, colaborareArtisti);
    cout << a2;

    delete[] colaborareMelodii;
    delete[] colaborareArtisti;

    RemixMelodie r1((float)4.15);
    cout << r1;

    //Upcasting
    ArtistColaborator ac2;
    Artist& a14 = ac2;
    cout << a14;

    //--------End Faza 7-----------------

    //--------Faza 8-----------------
    //Late binding pentru casaDeDiscuri
    Artist* pointerLaArtist;
    pointerLaArtist = new Artist();
    pointerLaArtist->promovare();
    delete pointerLaArtist;

    string* artistiColaborare = new string[2]{ "Irina Rimes", "Randi" };
    string* melodiiColaborare = new string[2]{ "The gate", "Xmas party" };
    pointerLaArtist = new ArtistColaborator(2, melodiiColaborare, 2, artistiColaborare);
    pointerLaArtist->publicTinta();
    delete pointerLaArtist;

    casaDeDiscuri** pointeriC;
    pointeriC = new casaDeDiscuri * [10];
    pointeriC[0] = new ArtistColaborator(2, melodiiColaborare, 2, artistiColaborare);
    pointeriC[1] = new Artist("Party at the disco", 23);
    for (int i = 2; i < 10; i++)
    {
        pointeriC[i] = new Artist();
    }
    //Afisez datele despre artistii setati mai sus
    for (int i = 0; i < 10; i++)
    {
        pointeriC[i]->publicTinta();
        cout << endl;
    }

    //Late binding pentru magazinMuzical
    Album* pointerAlbum;
    pointerAlbum = new Album();
    pointerAlbum->afiseazaInformatii();
    cout << endl;
    delete pointerAlbum;

    string* melodiiDinAlbum = new string[2]{ "SpeakToMe", "Breathe(InTheAir)" };
    pointerAlbum = new Album("UnNumeInspirat", 2, 13.99, melodiiDinAlbum);
    pointerAlbum->afiseazaInformatii();
    cout << endl;
    delete pointerAlbum;

    magazinMuzical** pointeriM;
    pointeriM = new magazinMuzical*[10];
    pointeriM[0] = new Album("TheEndOfTheWorld", 2, 13.99, melodiiDinAlbum);
    pointeriM[1] = new Melodie(2.19, "AliensOnEarth");
    for (int i = 2; i < 10; i++)
    {
        pointeriM[i] = new Album();
    }

    for (int i = 0; i < 10; i++)
    {
        pointeriM[i]->afiseazaInformatii();
        cout << endl;
    }
    //--------End Faza 8-----------------
    return 0;
}