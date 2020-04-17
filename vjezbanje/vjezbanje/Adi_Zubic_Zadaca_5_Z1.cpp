#include "pch.h"

//Napisite funkciju “IzdvojiRijec” sa dva parametra, od kojih je prvi tipa “string”, a drugi tipa
//“int”.Prvi parametar predstavlja neku recenicu, a drugi parametar redni broj riječi unutar te
//recenice.Funkcija treba da izdvoji tu rijec iz recenice i da vrati kao rezultat tako izdvojenu rijec.
//Na primjer, ukoliko je kao prvi parametar zadan tekst “ Riba ribi grize rep ” a kao drugi
//parametar broj 3, funkcija treba kao rezultat da vrati string “grize”.Ovdje pod pojmom rijec
//podrazumijevamo bilo koji slijed uzastopnih znakova koji nisu razmaci, a ispred kojeg se
//eventualno nalazi razmak(ili nista), i iza kojeg eventualno slijedi razmak(ili nista).Obratite
//paznju da rijeci mogu biti razdvojene sa vise uzastopnih razmaka, kao i da na pocetku i kraju
//teksta moze, ali i ne mora biti razmaka.Ukoliko je drugi parametar manji od 1 ili veci od broja
//rijeci u recenici, funkcija treba baciti izuzetak.Napisanu funkciju demonstrirajte u testnom
//programu u kojem se za recenicu unesenu sa tastature i prirodan broj n ispisuje n - ta rijec te
//recenice(pozivom napisane funkcije).


std::string IzdvojiRijec(std::string recenica, const int& brRijeci)  // brRijeci ne planiram mijenjati pa sam ga poslao kao const reference
{
    if (brRijeci < 1)   // Ukoliko je redni broj trazene rijeci manji od 1, vracamo prazan string. Prazan string oznacava da rijec rednog
        return "";      // broja nije nadjena buduci da se na tom rednom broju ne nalazi rijec unutar unesene recenice.


    std::string temp = "";                  // Deklaracija stringa temp u koji cemo smjestati individualne rijeci
    std::vector<std::string> rijeci;        // te rijeci cemo onda stavljati u vektor 'rijeci', i kada velicina tog vektora bude 
                                            // jednaka broju koji je korisnik unio, ispisacemo zadnju unijetu rijec, koja ce
                                            // ujedno biti i rijec trazenog rednog broja.
                                            // Ukoliko ne dodjemo u situaciju gdje je velicina vektora rijeci jednaka unesenom broju
                                            // onda mozemo zakljuciti da je uneseni broj veci od broja rijeci u recenici
                                            // te vracamo prazan string kao znak da je uneseni broj veci od broja rijeci u recenici

    recenica += " ";    // na recenicu dodajemo razmak, razlog objasnjen ispod funkcije
    for (int i = 0; i < recenica.size(); i++)
    {
        if (recenica[i] != ' ')             // ukoliko karakter rednog broja i nije razmak, taj karakter dodajemo na temp
        {
            temp += recenica[i];
        }
        else if (temp != "")                // u suprotnom, provjeravamo da li je temp prazan. Ako temp nije prazan onda tu rijec
        {                                   // stavljamo na vektor rijeci. Vrlo je vazno da provjerimo da li je temp prazan.
                                            // Prazan temp se moze pojaviti kao rezultat razmaka, a razmak nije rijec te ne zelimo da ga brojimo
            rijeci.push_back(temp);
            temp = "";                      // temp se reseta kada nadjemo razmak (razmak oznacava kraj rijeci), potrebno je resetati
        }                                   // da bi se sljedeca rijec mogla upisati, ukoliko ne resetamo, onda ce se sljedeca rijec
                                            // samo nadodati na prijethodnu (ili prijethodne).

        if (rijeci.size() == brRijeci)          // Ukoliko dodjemo u situaciju gdje je velicina vektora jednaka brRijeci,
        {                                       // onda zadnja rijec vektora mora biti rijec unesenog rednog broja.
            return rijeci[rijeci.size() - 1];   // returnamo tu rijec.
        }
    }

    return "";          // Ukoliko je funkcija dosla do ove linije, mozemo zakljuciti da je uneseni broj veci od broja rijeci u recenici,
                        // te returnamo prazan string kao oznaka za to.
}
// Zelio sam da prvo procitate rad algoritma prije nego sto objasnim zasto sam na recenicu dodao razmak:
// Dodao sam razmak zato sto se rijec ubacuje na vektor jedino kada se nadje razmak.
// Da nisam dodao razmak onda bi unos (" riba ribi grize rep ", 4) radio normalno, zato sto bi se rijec 'rep' dodala na vektor u
// zadnjoj iteraciji.
// Za unos: (" riba ribi grize rep", 4) funkcija bi vratila prazan string, zato sto se rijec 'rep' nikada ne bi dodala na vektor
// buduci da se rijeci jedino dodaju kada se nadje razmak

// Takodjer je vazno napomenuti da ovaj algoritam prepoznaje rijeci kao bilo kakve karaktere koji nisu odvojeni X brojem razmaka,
// ukoliko zelimo ograniciti algoritam da samo trazi rijeci (uzastopna slova i samo slova), tj. da izostavi simbole ili brojeve,
// onda mozemo prvu if kondiciju unutar petlje promjeniti u:
// if (recenica[i] > 64 && recenica[i] < 91) || (recenica[i] > 96 && recenica[i] < 123)


void Adi_Zubic_Zadaca_5_Z1()
{
    std::string recenica;
	int brRijeci;

    std::cout << "\n\n\tMolimo unesite recenicu:\n\t\t";
    getline(std::cin, recenica);        // unos recenice - getline koristimo da razmake korektno unesemo u string

    std::cout << "\n\tMolimo unesite redni broj rijeci:\n\t\t";
    std::cin >> brRijeci;

    std::string rijec = IzdvojiRijec(recenica, brRijeci);   // funkcija vraca rijec rednog broja koji je zapisan u varijabli brRijeci
                                                            // ukoliko se na tom rednom broju ne nalazi rijec, funkcija vraca prazan string
    if (rijec != "")    // dakle, ukoliko string nije prazan ispisujemo rijec tog rednog broja
    {
        std::cout << "\n\tRijec rednog broja " << brRijeci << ": " << rijec;
    }
    else                // a ukoliko je string prazan ispisujemo da se na poziciji unesenog broja ne nalazi rijec.
    {
        std::cout << "\n\tNa rednom broju " << brRijeci << " se ne nalazi rijec unutar unesene recenice.";
    }
}