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

    Artist(string nume, int varsta): anAparitie(1953)
    {
        this->nume = nume;
        this->varsta = varsta;
        this->avereEuro = 25.6;
        this->nrGenuriMuzicale = 0;
        this->genuriMuzicale = nullptr;
        totalArtisti++;
    }

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
   
    ~Artist() 
    {
        delete[] genuriMuzicale;
        totalArtisti--;
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

    const int getAnAparitie() const {
        return anAparitie;
    }

    static int getTotalArtisti() {
        return totalArtisti;
    }

    string getNume() const {
        return nume;
    }

    int getVarsta() const {
        return varsta;
    }

    float getAvereEuro() const {
        return avereEuro;
    }

    int getNrGenuriMuzicale() const {
        return nrGenuriMuzicale;
    }

    string* getGenuriMuzicale() const {
        return this->genuriMuzicale;
    }

    void setNume(const string& newNume) {
        nume = newNume;
    }

    void setVarsta(int newVarsta) {
        varsta = newVarsta;
    }

    void setAvereEuro(float newAvereEuro) {
        this->avereEuro = newAvereEuro;
    }

    void setNrGenuriMuzicale(int newNrGenuriMuzicale) {
        this->nrGenuriMuzicale = newNrGenuriMuzicale;
    }

    void setGenuriMuzicale(const string* newGenuriMuzicale) {
        if (this->genuriMuzicale != NULL) {
            delete[] this->genuriMuzicale;
        }
        this->genuriMuzicale = new string[this->nrGenuriMuzicale];
        for (int i = 0; i < this->nrGenuriMuzicale; ++i) {
            this->genuriMuzicale[i] = newGenuriMuzicale[i];
        }
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

    Album() : anLansare(1982), nume("Thriller"), nrMelodii(0), pret(15.99), numeMelodii(nullptr)
    {
        

    }

    Album(string nume, float pret): anLansare(1980)
    {
        this->nume = nume;
        this->nrMelodii = 3;
        this->pret = pret;
        this->numeMelodii = new string[this->nrMelodii]{ "HellsBells", "ShootToThrill", "BackInBlack" };
    }

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
    
    ~Album() 
    {
        delete[] numeMelodii;
    }

    const int getAnLansare() const {
        return anLansare;
    }

    static int getTVA() {
        return TVA;
    }

    string getNume() const {
        return nume;
    }

    int getNrMelodii() const {
        return nrMelodii;
    }

    float getPret() const {
        return pret;
    }

    string* getNumeMelodii() const {
        return numeMelodii;
    }

    static void setTVA(int newTVA) {
        TVA = newTVA;
    }

    void setNume(const string& newNume) {
        nume = newNume;
    }

    void setNrMelodii(int newNrMelodii) {
        nrMelodii = newNrMelodii;
    }

    void setPret(float newPret) {
        pret = newPret;
    }

    void setNumeMelodii(const string* newNumeMelodii) {
        if (this->numeMelodii != NULL)
        {
            delete[] this->numeMelodii;
        }
        numeMelodii = new string[nrMelodii];
        for (int i = 0; i < nrMelodii; ++i) {
            numeMelodii[i] = newNumeMelodii[i];
        }
    }

    void afisare()
    {
        cout << "Nume album: " << this->nume << "\nAn lansare: " << this->anLansare << "\nNumar melodii: " << this->nrMelodii << "\nPret: " << this->pret << " RON\nMelodii: ";
        for (int i = 0; i < this->nrMelodii; ++i) {
            cout << numeMelodii[i] << " ";
        }
        cout << "\n\n";
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

    Melodie() : durata(4.0)
    {
        this->nume = "Hello";
        this->numeArtist = "Adele";
        this->nrVersuri = 2;
        this->versuri = new std::string[this->nrVersuri]{ "VersulNr1", "VersulNr2" };
        nrTotalMelodii++;
    }

    Melodie(float durata, string nume) : durata(durata)
    {
        this->nume = nume;
        this->numeArtist = "Adele";
        this->nrVersuri = 4;
        this->versuri = new std::string[this->nrVersuri]{ "Close enough to start a war", "All that I have is on the floor", "God only knows what we're fighting for", "All that I say, you always say more"};

        nrTotalMelodii++;
    }

    Melodie(float durata, string nume, string numeArtist, int nrVersuri, string* versuriArray): durata(durata), nume(nume), numeArtist(numeArtist), nrVersuri(nrVersuri), versuri(new string[nrVersuri])
    {
        for (int i = 0; i < nrVersuri; ++i) 
        {
            this->versuri[i] = versuriArray[i];
        }
        nrTotalMelodii++;
    }

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
    
    ~Melodie() 
    {
        delete[] versuri;
        nrTotalMelodii--;
    }

    float getDurata() const {
        return durata;
    }

    static int getNrTotalMelodii() {
        return nrTotalMelodii;
    }

    string getNume() const {
        return nume;
    }

    string getNumeArtist() const {
        return numeArtist;
    }

    int getNrVersuri() const {
        return nrVersuri;
    }

    string* getVersuri() const {
        return versuri;
    }

    void setNume(const string& newNume) {
        nume = newNume;
    }

    void setNumeArtist(const string& newNumeArtist) {
        numeArtist = newNumeArtist;
    }

    void setNrVersuri(int newNrVersuri) {
        nrVersuri = newNrVersuri;
    }

    void setVersuri(const string* newVersuri) {
        if (this->versuri != NULL)
        {
            delete[] this->versuri;
        }
        versuri = new string[nrVersuri];
        for (int i = 0; i < nrVersuri; ++i) {
            versuri[i] = newVersuri[i];
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
};
int Melodie::nrTotalMelodii = 0;


int main() 
{

    string adeleGenuriMuzicale[] = { "Pop", "Rock" };
    Artist adele("Adele", 35, 220.53, 2, adeleGenuriMuzicale, 2006);
    Artist elvis("Elvis Presley", 40);
    Artist artistCult;
    Artist copyAdele;
    copyAdele = adele;

    adele.afisare();
    elvis.afisare();
    artistCult.afisare();
    cout << "Copy constructor:\n";
    copyAdele.afisare();

    cout << "Total artisti: " << Artist::getTotalArtisti() << endl << endl;


    Artist artistGetSet;

    artistGetSet.setNume("Freddie Mercury");
    artistGetSet.setVarsta(45);
    artistGetSet.setAvereEuro(100.5);
    artistGetSet.setNrGenuriMuzicale(2);
    artistGetSet.setGenuriMuzicale(adeleGenuriMuzicale);

    cout << "Nume artist: " << artistGetSet.getNume() << endl;
    cout << "Varsta: " << artistGetSet.getVarsta() << endl;
    cout << "An aparitie: " << artistGetSet.getAnAparitie() << endl;
    cout << "Avere: " << artistGetSet.getAvereEuro() << "M euro" << endl;
    cout << "Nr genuri muzicale: " << artistGetSet.getNrGenuriMuzicale() << endl;
    cout << "Genuri muzicale: " << artistGetSet.getGenuriMuzicale() << endl;

    cout << "\nArtist prin get-eri si sett-eri:\n";
    artistGetSet.afisare();



    string numeMelodii[] = { "SpeakToMe", "Breathe(InTheAir)", "BrainDamage" };

    Album albumulUnu;

    Album albumulDoi("Back in Black", 29.99);

    Album albumulTrei("The Dark Side of the Moon", 3, 39.99, numeMelodii);

    Album copyAlbumUnu;
    copyAlbumUnu = albumulUnu;

    albumulUnu.afisare();
    albumulDoi.afisare();
    albumulTrei.afisare();
    cout << "Copy constructor:\n";
    copyAlbumUnu.afisare();

    cout << "TVA: " << Album::getTVA() << "%" << endl;


    Album albumGetSet;

    albumGetSet.setNume("To the future");
    albumGetSet.setNrMelodii(10);
    albumGetSet.setPret(25.99);
    albumGetSet.setNrMelodii(3);
    albumGetSet.setNumeMelodii(numeMelodii);


    cout << "Nume album: " << albumGetSet.getNume() << endl;
    cout << "An lansare: " << albumGetSet.getAnLansare() << endl;
    cout << "Pret: " << albumGetSet.getPret() << " RON" << endl;
    cout << "Nr. melodii: " << albumGetSet.getNrMelodii() << endl;
    cout << "Melodii: " << albumGetSet.getNumeMelodii() << endl;

    cout << "\nAlbum prin get-eri si sett-eri:\n";
    albumGetSet.afisare();



    string versuriArray[] = { "I'm Mr. Originality", "Come my way, come and see", "Let me be your fantasy" };

    Melodie melodieImplicita;

    Melodie melodieCuDurataNume(4.10, "TurningTables");

    Melodie mrOriginality(3.20,  "MrOriginality", "Simplu", 3, versuriArray);
    Melodie copyMelodieImplicita;
    copyMelodieImplicita = melodieImplicita;

    melodieImplicita.afisare();
    melodieCuDurataNume.afisare();
    mrOriginality.afisare();
    cout << "Copy constructor:\n";
    copyMelodieImplicita.afisare();

    cout << "Total Melodii: " << Melodie::getNrTotalMelodii() << endl;

    Melodie melodieGetSet;

    melodieGetSet.setNume("Rolling in the Deep");
    melodieGetSet.setNumeArtist("Adele Adkins");
    melodieGetSet.setNrVersuri(3);
    melodieGetSet.setVersuri(versuriArray);

    cout << "Nume melodie: " << melodieGetSet.getNume() << endl;
    cout << "Nume artist: " << melodieGetSet.getNumeArtist() << endl;
    cout << "Durata: " << melodieGetSet.getDurata() << " minute" << endl;
    cout << "Nr. versuri: " << melodieGetSet.getNrVersuri() << endl;
    cout << "Versuri: " << melodieGetSet.getVersuri() << endl;

    cout << "\nMelodie prin get-eri si sett-eri:\n";
    melodieGetSet.afisare();



    return 0;
}
