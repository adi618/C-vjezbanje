#include "pch.h"



using namespace std;
//kenin kod
struct Cvor {

    string imePrezime;
    int prosjek;
    //  Unutar strukture cvor pored ostalih clanova imamo
    //  i pokazivac na samu strukturu cvor
    //  Ovaj pokazivac ce nam sluziti da uvezemo
    //  clanove strukture u listu
    Cvor* veza;


    Cvor()      // Ovo je funkcija koja se pokrene kad se napravi objekt klase cvor, ovo sam stavio zato sto sam u 
    {           // visual studiu dobijao neke errore, i na internetu nasao rjesenje, mada mi nije u potpunosti jasno zasto sve mora
        imePrezime = "";        // da bude inicijalizirano
        prosjek = 0;
        veza = nullptr;
    }
};


int main() {

    Cvor* prethodni = nullptr, * temp = nullptr, * temp1;

    Cvor* head = nullptr;

    while (true) {
        string student;
        cout << "\n\tUnesite ime studenta: ";
        getline(cin, student);
        if (student == "")
            break;

        int prosjek;
        cout << "\tUnesite prosjek ucenika: ";
        cin >> prosjek;

        cin.ignore();

        Cvor* novoUneseni = new Cvor;

        novoUneseni->imePrezime = student;
        novoUneseni->prosjek = prosjek;

        novoUneseni->veza = nullptr;

        if (head == nullptr) {
            head = novoUneseni;
        }
        else {
            Cvor* i = head;
            bool nesta = true;
            for (i; i != 0; prethodni = i, i = i->veza) {
                temp = i;
                if ((i->prosjek < novoUneseni->prosjek) && (i == head)) {
                    head = novoUneseni;
                    novoUneseni->veza = i;
                    nesta = false;
                    break;
                }

                else if (i->prosjek < novoUneseni->prosjek) {
                    novoUneseni->veza = i;
                    prethodni->veza = novoUneseni;
                    nesta = false;
                    break;
                }
            }
            if (nesta) {
                novoUneseni->veza = i;
                prethodni->veza = novoUneseni;
            }
        }
    }

    cout << "----------------------------------------------\n";

    for (Cvor* i = head; i != 0; i = i->veza) {
        cout << "\t" << i->imePrezime;
        cout << "\t" << i->prosjek << endl;
    }
    cout << "----------------------------------------------\n";
    getchar();
    return 0;
}