#include <iostream>
#include <string>
using namespace std;

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
    Artist(string nume, int varsta): anAparitie(1953)
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
    void afisare() 
    {
        cout << "Nume artist: " << this->nume << "\nVarsta: " << this->varsta << "\nAn aparitie: " << this->anAparitie << "\nAvere: " << this->avereEuro << "M euro\nGenuri muzicale: ";
        for (int i = 0; i < this->nrGenuriMuzicale; i++) 
        {
            cout << genuriMuzicale[i] << " ";
        }
        cout << "\n\n";
    }
    //Getteri
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
    Album(string nume, float pret): anLansare(1980)
    {
        this->nume = nume;
        this->nrMelodii = 3;
        this->pret = pret;
        this->numeMelodii = new string[this->nrMelodii]{ "HellsBells", "ShootToThrill", "BackInBlack" };
    }
    //Constructorul cu toti parametrii
    Album(string nume, int nrMelodii, float pret, string* numeMelodii): anLansare(2022)
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
        if (_TVA >=0)
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
        this->nume = "Hello";
        this->numeArtist = "Adele";
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
        this->versuri = new std::string[this->nrVersuri]{ "Close enough to start a war", "All that I have is on the floor", "God only knows what we're fighting for", "All that I say, you always say more"};

        nrTotalMelodii++;
    }
    //Constructorul cu toti parametrii
    Melodie(float durata, string nume, string numeArtist, int nrVersuri, string* versuriArray): durata(durata), nume(nume), numeArtist(numeArtist), nrVersuri(nrVersuri), versuri(new string[nrVersuri])
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
        if (_nrTotalMelodii >=0)
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
    //Destructor
    ~Melodie()
    {
        delete[] versuri;
        nrTotalMelodii--;
    }
};
int Melodie::nrTotalMelodii = 0;


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

    adele.afisare();
    elvis.afisare();
    artistCult.afisare();
    cout << "Copy constructor:\n";
    copyAdele.afisare();

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
    string* artistGenres = artistCult.getGenuriMuzicale();
    cout << "Genuri muzicale: ";
    for (int i = 0; i < artistCult.getNrGenuriMuzicale(); i++)
    {
        cout << artistGenres[i] << " ";
    }

    cout << "\n\nTotal artisti: " << Artist::getTotalArtisti() << endl << endl;



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

    albumulUnu.afisare();
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


    //Melodie
    string versuriArray[] = { "I'm Mr. Originality", "Come my way, come and see", "Let me be your fantasy" };
    //Apelarea constructorului default
    Melodie melodieImplicita;

    //Apelarea constructorului cu 2 parametrii
    Melodie melodieCuDurataNume(4.10, "TurningTables");
    //Apelarea constructorului cu toti parametrii
    Melodie mrOriginality(3.20,  "MrOriginality", "Simplu", 3, versuriArray);

    Melodie copyMelodieImplicita;
    //Apelarea constructorului de copiere
    copyMelodieImplicita = melodieImplicita;

    //Getteri si setteri
    Melodie melodieGetSet;
    //Set
    melodieGetSet.setNume("Rolling in the Deep");
    melodieGetSet.setNumeArtist("Adele Adkins");
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

    cout << "\n\nTotal Melodii: " << Melodie::getNrTotalMelodii() << endl;


    return 0;
}
