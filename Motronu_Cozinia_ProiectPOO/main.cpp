#include <iostream>
#include <string>
using namespace std;
#define LUNGIME_VECTOR 3
#define LUNGIME_MATRICE_LINIE 2
#define LUNGIME_MATRICE_COLOANA 3

class Artist
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
    string getNume()
    {
        return this->nume;
    }
    int getVarsta()
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
    //Destructor
    ~Artist()
    {
        delete[] genuriMuzicale;
        totalArtisti--;
    }
};
int Artist::totalArtisti = 0;

class Melodie;

class Album
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
    //Destructor
    ~Album()
    {
        delete[] numeMelodii;
    }

};
int Album::TVA = 19;

class Melodie {
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
    //Destructor
    ~Melodie()
    {
        delete[] versuri;
        nrTotalMelodii--;
    }
};
int Melodie::nrTotalMelodii = 0;

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
    print << "Nume melodie: " << melodie.nume << "\nNume artist: " << melodie.numeArtist << "\nDurata: " << melodie.durata << " minute\nVersuri:\n";
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
    print << "Nume artist: " << artist.nume << "\nVarsta: " << artist.varsta << "\nAn aparitie: " << artist.anAparitie << "\nAvere: " << artist.avereEuro << "M euro\nGenuri muzicale: ";
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
    print << "Nume album: " << album.nume << "\nAn lansare: " << album.anLansare << "\nNumar melodii: " << album.nrMelodii << "\nPret: " << album.pret << " RON\nMelodii: ";
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




int main()
{
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
    //afisarea obiectelor din vector
    cout << "Afisarea matricei de tip album:\n\n";
    for (int i = 0; i < LUNGIME_MATRICE_LINIE; i++)
    {
        for (int j = 0; j < LUNGIME_MATRICE_COLOANA; j++)
        {
            cout << matriceAlbume[i][j];
        }
        cout << endl;
    }

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

    return 0;
}