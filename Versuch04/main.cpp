//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"
#define X 0.01
#define ROTATERAD 0.00000001*PI
#define PI 3.14159265
int main()
{

	Vektor vector1(1, 0, 0);
	Vektor vector2(0, 1, 0);

	vector1.ausgabe();
	vector2.ausgabe();

	//Vektor, der den Menshcen beschreibt, der auf der hohen Plattform steht
	Vektor const mensch(0, (1.70 + 555.70) / 1000 + 6371, 0);

	//Vektor, der die Erde beschreibt
	Vektor erde(0, 6371, 0);

	//Vektor(erde)-Vektor(mensch)= ein Vektor, der die Augen -> ein Punkt an der Erde beschreiben
	Vektor augenVektor = erde.sub(mensch);

	int anzahlSchritte =0;
	while (augenVektor.skalarProd(erde) >= X
			|| augenVektor.skalarProd(erde) <= -1 * X)
	{
		// Rotation des Erdvektors mit einem konstanten Faktor,
		erde.rotiereUmZ(ROTATERAD);
		augenVektor = erde.sub(mensch);
		anzahlSchritte++;
	}

	std::cout << std::fixed;
	std::cout << std::setprecision(4);
	std::cout << "Sie können " << augenVektor.laenge() << " Km weit sehen" << std::endl;
	std::cout << "Sie sind " << 557.4 << " Meter hoch." << std::endl;
	std::cout << "Der Winkel beträgt " << mensch.winkel(erde) << " Grad." << std::endl;
	std::cout << "Anzahl Schritte: " << anzahlSchritte << std::endl;

	return 0;

}
