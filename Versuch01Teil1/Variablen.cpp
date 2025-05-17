//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 1.1: Datentypen und Typumwandlung
// Author: Boxin Wang
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
    int iErste = 0;
    int iZweite = 0;

    // Hier folgt Ihr eigener Code

    //Aufgabe1
    int iSumme, iQuotient;
    std :: cout << "Bitte geben Sie die erste ganze Zahl ein: "<< std :: endl;
    std :: cin >> iErste;
    std :: cout << "Bitte geben Sie die zweite ganze Zahl ein: "<< std :: endl;
    std :: cin >> iZweite;
    iSumme = iErste + iZweite;
    iQuotient = iErste / iZweite;
    std :: cout << "Die Summe der beiden Zahlen ist: " << iSumme << std :: endl;
    std :: cout << "Das Ergebnis der Division ist: " << iQuotient << std :: endl;


    //Aufgabe2
    double dSumme, dQuotient;
    dSumme = static_cast<double>(iErste) + static_cast<double>(iZweite);
    dQuotient = static_cast<double>(iErste) / static_cast<double>(iZweite);
    std :: cout << "Die Summe der beiden Zahlen (als double) ist: " << dSumme <<std :: endl;
    std :: cout << "Das Ergebnis der Division (als double) ist: " << dQuotient << std :: endl;


    //Aufgabe3
    double dSummeCast, dQuotientCast;
    dSummeCast = (double)iErste + (double)iZweite;
    dQuotientCast = (double)iErste / (double)iZweite;
    std :: cout << "Die Summe der beiden Zahlen (nach Type Casting) ist: " << dSummeCast << std :: endl;
    std :: cout << "Das Ergebnis der Division (nach Type Casting) ist: " << dQuotientCast << std :: endl;


    //Aufgabe4
    std :: string sVorname, sNachname, sVornameName, sNameVorname;
    std :: cout << "Bitte geben Sie Ihren Vornamen ein: ";
    std :: cin >> sVorname;
    std :: cout << "Bitte geben Sie Ihren Nachnamen ein: ";
    std :: cin >> sNachname;
    sVornameName = sVorname + " " + sNachname;
    sNameVorname = sNachname + ", " + sVorname;
    std :: cout << "Der Name in der Form 'Vorname Nachname' ist: " << sVornameName << std :: endl;
    std :: cout << "Der Name in der Form 'Nachname, Vorname' ist: " << sNameVorname << std :: endl;


    //Aufgabe5
    // a)
    {
    	int iFeld[2];
    	iFeld[0] = 1;
    	iFeld[1] = 2;
    	std :: cout << iFeld[0] << std :: endl;
    	std :: cout << iFeld[1] << std :: endl;
    }

    // b)
    {
    	int spielFeld[2][3] = { {1, 2, 3}, {4, 5, 6} };
    	    for (int i = 0; i < 2; ++i) {
    	    	for (int j = 0; j < 3; ++j) {
    	    		std :: cout << spielFeld[i][j] << " ";
    	    	}
    	    	std :: cout << std :: endl;
    	    }
    }

    // c)
    {
    	const int iZweite = 1;
    	std :: cout << "Die konstante iZweite: " << iZweite << std :: endl;
    }
    std :: cout << "iZweite: " << iZweite << std :: endl;


    //Aufgabe6
    int asciiWert1 = static_cast<int>(sVorname[0]);
    int asciiWert2 = static_cast<int>(sVorname[1]);
    std :: cout << "Die Zahl des ersten Buchstabens: " << asciiWert1 << std :: endl;
    std :: cout << "Die Zahl des zweiten Buchstabens: " << asciiWert2 << std :: endl;


    //Aufgabe7
    int iName1_p = (int)toupper(sVorname[0]) - (int)('A') + 1;
    int iName2_p = (int)toupper(sVorname[1]) - (int)('A') + 1;

    std::cout << "Position des ersten Buchstabens im Alphabet = " << iName1_p << std::endl;
    std::cout << "Position des zweiten Buchstabens im Alphabet = " << iName2_p << std::endl;

}
