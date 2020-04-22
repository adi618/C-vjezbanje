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
    {
        while (getline(file, ulaznaRecenica))
        {
            izlaznaRecenica += ulaznaRecenica + '\n';       // uzimamo svaku liniju iz file-a i stavljamo je u string izlaznaRecenica
        }
        
        for (auto& rijec : izlaznaRecenica)     // iteriramo slova recenice i sifriramo ih, u for petlju je proslijedjena rijec po referenci
        {                                       // da nije po referenci, petlja bi samo napravila kopiju rijeci i editovanje te kopije
            if (rijec >= 'A' && rijec <= 'Z')   // ne bi imalo efekta na originalnu poruku
                if (rijec == 'Z')
                    rijec = 'A';
                else
                    rijec++;
        }

        file.close();               // zatvaramo file, buduci da smo zavrsili sa ucitavanjem i ne treba nam vise, mogli smo ovo uraditi
        remove("tekst.txt");        // odmah nakon while (getline) petlje.

	    std::ofstream file("tekst.txt");    // pravimo novi file u koji cemo samo pisati, dakle ofstream, pod imenom tekst.txt
        file << izlaznaRecenica;            // sifriranu recenicu spasavamo u njeg
        file.close();                       // zatvaramo ga

        std::cout << "\n\n\tTekst je ucitan i velika slova su sifrirana!\n\n\n";
    }
    else
    {
        std::cout << "\n\n\tTekst.txt nije pronadjen!\n\n\n";
    }
}
