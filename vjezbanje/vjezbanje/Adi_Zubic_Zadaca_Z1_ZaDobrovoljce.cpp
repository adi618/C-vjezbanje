#include "pch.h"

//Program kojim se vrsi sifriranje podataka postojece datoteke tekst.txt(sadrzi samo velika slova), tako sto
//se svako slovo zamjenjuje narednim ASCII znakom(slovo Z zamjeniti sa A).

void Adi_Zubic_Zadaca_Z1_ZaDobrovoljce()
{
	std::string ulaznaRecenica;
	std::string izlaznaRecenica;
    std::ifstream file("tekst.txt");    // ifstream je otvaranje filea u iz kojeg planiramo samo ucitavati informacije
                                        // i je skraceniza za input, ofstream, je output file stream
    if (file.is_open())                 // dok je fstream samo file stream, preko njeg mozemo i citati i pisati
    {   // provjera da li je file otvoren, ako nije doslo je do greske
        while (getline(file, ulaznaRecenica))
        {
            izlaznaRecenica += ulaznaRecenica + '\n';       // uzimamo svaku liniju iz file-a i stavljamo je u string izlaznaRecenica
        }
        
        for (char& rijec : izlaznaRecenica)     // iteriramo slova recenice i sifriramo ih, u for petlju je proslijedjena rijec po referenci
        {                                       // da nije po referenci, petlja bi samo napravila kopiju rijeci i editovanje te kopije
            if (rijec >= 'A' && rijec <= 'Z')   // ne bi imalo efekta na originalnu poruku
            {
                if (rijec == 'Z')
                    rijec = 'A';
                else
                    rijec++;
            }
        }

        file.close();                       // zatvaramo file
	    std::ofstream file("tekst.txt");    // otvaramo ga u output file stream mode-u, sto brise sav tekst iz file-a
        file << izlaznaRecenica;            // u, sada prazan, file upisujemo nasu sifriranu recenicu
        file.close();                       // zatvaramo file.

        std::cout << "\n\n\tTekst je ucitan i velika slova su sifrirana!\n\n\n";
    }
    else
    {
        std::cout << "\n\n\tTekst.txt nije pronadjen!\n\n\n";
    }
}
