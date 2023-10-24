#include <iostream>
#include <string>
using namespace std;

class Artist 
{
public:
    const int anAparitie;
    static int totalArtisti;
    string nume;
    int varsta;
    float avereEuro;
    int nrGenuriMuzicale;
    string* genuriMuzicale;

    Artist() : anAparitie(2010) 
    {
        this->nume = "Adele";
        this->varsta = 30;
        this->avereEuro = 36.04;
        this->nrGenuriMuzicale = 2;
        this->genuriMuzicale = new std::string[this->nrGenuriMuzicale];
        for (int i = 0; i < this->nrGenuriMuzicale; ++i)
        {
            this->genuriMuzicale[i] = "Gen " + to_string(i + 1);
        }
        totalArtisti++;
    }
    Artist(string nume, int varsta, float avereEuro, int nrGenuriMuzicale, string* genuriMuzicale) : anAparitie(2010), nume(nume), varsta(varsta), avereEuro(avereEuro), nrGenuriMuzicale(nrGenuriMuzicale) 
    {
        this->genuriMuzicale = new string[this->nrGenuriMuzicale];
        for (int i = 0; i < this->nrGenuriMuzicale; ++i) 
        {
            this->genuriMuzicale[i] = genuriMuzicale[i];
        }
        totalArtisti++;
    }

    Artist(string nume, int varsta): anAparitie(2010), nume(nume), varsta(varsta), avereEuro(0.0), nrGenuriMuzicale(0), genuriMuzicale(nullptr) 
    {
        totalArtisti++;
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

    static int getTotalArtisti() 
    {
        return totalArtisti;
    }
};

int Artist::totalArtisti = 0;

class Album 
{
public:
    const int anLansare;
    static int TVA;
    string nume;
    int nrMelodii;
    float pret;
    string* numeMelodii;

    Album(): anLansare(2022), nume("DayDreamer"), nrMelodii(0), pret(0.0), numeMelodii(nullptr) 
    {

    }

    Album(string nume, float pret): anLansare(2022), nume(nume), nrMelodii(0), pret(pret), numeMelodii(nullptr) 
    {

    }

    Album(string nume, int nrMelodii, float pret, string* numeMelodii): anLansare(2022), nume(nume), nrMelodii(nrMelodii), pret(pret), numeMelodii(new string[nrMelodii]) 
    {
        for (int i = 0; i < nrMelodii; ++i) 
        {
            this->numeMelodii[i] = numeMelodii[i];
        }
    }

    ~Album() 
    {
        delete[] numeMelodii;
    }

    static int getTVA() 
    {
        return TVA;
    }

    static void setTVA(int newTVA) 
    {
        TVA = newTVA;
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
public:
    const float durata;
    static int nrTotalMelodii;
    string nume;
    string* versuri;

    Melodie() : durata(0.0), nume("Hello"), versuri(nullptr) {
        nrTotalMelodii++;
    }

    Melodie(float durata, string nume): durata(durata), nume(nume), versuri(nullptr) {
        nrTotalMelodii++;
    }

    Melodie(float durata, string nume, int nrVersuri, string* versuriArray): durata(durata), nume(nume), versuri(new string[nrVersuri]) {
        for (int i = 0; i < nrVersuri; ++i) 
        {
            this->versuri[i] = versuriArray[i];
        }
        nrTotalMelodii++;
    }

    ~Melodie() 
    {
        delete[] versuri;
        nrTotalMelodii--;
    }

    static int getNrTotalMelodii() 
    {
        return nrTotalMelodii;
    }

    void afisare()
    {
        cout << "Nume melodie: " << this->nume << "\nDurata: " << this->durata << " minute\nVersuri:\n";
        for (int i = 0; i < sizeof(versuri); ++i) 
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
    Artist adele("Adele", 30, 36.04, 2, adeleGenuriMuzicale);
    Artist elvis("Elvis", 40);
    Artist artistNou("Mozzart", 25, 20.5, 1, new std::string[1]{ "Clasica" });

    adele.afisare();
    elvis.afisare();
    artistNou.afisare();


    cout << "Total artisti: " << Artist::getTotalArtisti() << endl;



    string numeMelodii[] = { "Melodie1", "Melodie2", "Melodie3" };

    // Constructorul cu valori implicite
    Album albumImplicit;

    // Constructorul cu nume și preț
    Album albumCuNumePret("AlbumCuNumePret", 29.99);

    // Constructorul cu toate atributele
    Album albumCompleto("AlbumCompleto", 3, 39.99, numeMelodii);

    // Afișarea informațiilor despre albumele create
    albumImplicit.afisare();
    albumCuNumePret.afisare();
    albumCompleto.afisare();

    // Afișarea TVA-ului
    cout << "TVA: " << Album::getTVA() << "%" << endl;



    string versuriArray[] = { "Vers 1", "Vers 2", "Refren" };

    Melodie melodieImplicita;

    Melodie melodieCuDurataNume(3.2, "TurningTables");

    Melodie melodieCompleta(4.5, "MrOriginality", 3, versuriArray);

    melodieImplicita.afisare();
    melodieCuDurataNume.afisare();
    melodieCompleta.afisare();

    cout << "Total Melodii: " << Melodie::getNrTotalMelodii() << endl;



    return 0;
}
