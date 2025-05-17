/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 1.2: Strukturen
// Author: Boxin Wang
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

struct Person {
	std::string sNachname;
	std::string sVorname;
	int iGeburtsjahr;
	int iAlter;
};

int main() {
	Person nBenutzer;
	//Datei eingeben lassen
	std::cout << "Bitte geben Sie Ihren Nachnamen ein: ";
	std::cin >> nBenutzer.sNachname;
	std::cout << "Bitte geben Sie Ihren Vornamen ein: ";
	std::cin >> nBenutzer.sVorname;
	std::cout << "Bitte geben Sie Ihr Geburtsjahr ein: ";
	std::cin >> nBenutzer.iGeburtsjahr;
	std::cout << "Bitte geben Sie Ihr Alter ein: ";
	std::cin >> nBenutzer.iAlter;

	// Inhalt ausgeben
	std::cout << "\nBenutzerinformationen:\n";
	std::cout << "Nachname: " << nBenutzer.sNachname << std::endl;
	std::cout << "Vorname: " << nBenutzer.sVorname << std::endl;
	std::cout << "Geburtsjahr: " << nBenutzer.iGeburtsjahr << std::endl;
	std::cout << "Alter: " << nBenutzer.iAlter << std::endl;

	// Elemente in nKopieEinzeln kopieren
	Person nKopieEinzeln;
	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;

	// die gesamte Struktur in nKopieGesamt kopieren
	Person nKopieGesamt = nBenutzer;

	// Ergebnisse ausgeben
	std::cout << "\nKopie (Elemente einzeln):\n";
	std::cout << "Nachname: " << nKopieEinzeln.sNachname << std::endl;
	std::cout << "Vorname: " << nKopieEinzeln.sVorname << std::endl;
	std::cout << "Geburtsjahr: " << nKopieEinzeln.iGeburtsjahr << std::endl;
	std::cout << "Alter: " << nKopieEinzeln.iAlter << std::endl;

	std::cout << "\nKopie (Gesamte Struktur):\n";
	std::cout << "Nachname: " << nKopieGesamt.sNachname << std::endl;
	std::cout << "Vorname: " << nKopieGesamt.sVorname << std::endl;
	std::cout << "Geburtsjahr: " << nKopieGesamt.iGeburtsjahr << std::endl;
	std::cout << "Alter: " << nKopieGesamt.iAlter << std::endl;
	return 0;

}
