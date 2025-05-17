/**
 * Praktikum Informatik 1 
 * 
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Othello
 */

/**
 * @mainpage Othello
 *
 * Dokumentation des Spiels Othello im Rahmen des Praktikums Informatik 1.
 *
 */

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "othelloKI.h"

/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
	for (int j = 0; j < GROESSE_Y; j++)
	{
		for (int i = 0; i < GROESSE_X; i++)
		{
			spielfeld[j][i] = 0;
		}
	}
	spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
	spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
	spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
	spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}

/**
 * @brief Ausgabe des Spielfelds auf der Konsole
 *
 * Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
 * Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
 *
 *  @param spielfeld  Spielfeld, das ausgeben wird
 */
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
	std::cout << "   | ";

	//Start bei ASCII 65 = A
	for (int i = 65; i < 65 + GROESSE_X; ++i)
		std::cout << ((char) i) << " | ";

	std::cout << std::endl;

	for (int j = 0; j < GROESSE_Y; ++j)
	{
		for (int i = 0; i < GROESSE_X; ++i)
		{
			std::cout << "---+";
		}
		std::cout << "---+" << std::endl;

		std::cout << " " << j + 1 << " |";
		for (int i = 0; i < GROESSE_X; ++i)
		{
			switch (spielfeld[j][i])
			{
			case 0:
				std::cout << "   ";
				break;
			case 1:
				std::cout << " X ";
				break;
			case 2:
				std::cout << " O ";
				break;
			default:
				std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
				std::cout << "Abbruch .... " << std::endl;
				exit(0);
				break;
			}
			std::cout << "|";
		}
		;  //for i
		std::cout << std::endl;
	}  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
	int zaehlerSpieler1 = 0;
	int zaehlerSpieler2 = 0;

	for (int j = 0; j < GROESSE_Y; ++j)
	{
		for (int i = 0; i < GROESSE_X; ++i)
		{
			if (spielfeld[j][i] == 1)
			{
				++zaehlerSpieler1;
			}
			if (spielfeld[j][i] == 2)
			{
				++zaehlerSpieler2;
			}

		}
	}

	if (zaehlerSpieler1 == zaehlerSpieler2)
	{
		return 0;
	}
	if (zaehlerSpieler1 < zaehlerSpieler2)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}

/**
 * @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
 *
 * @param posX Index fuer die Spalte
 * @param posY Index fuer die Zeile
 * @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
 */
bool aufSpielfeld(const int posX, const int posY)
{
	// Hier erfolgt jetzt Ihre Implementierung ...
	if (posX >= 0 && posX < GROESSE_X && posY >= 0 && posY < GROESSE_Y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X],
		const int aktuellerSpieler, const int posX, const int posY)
{
	int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
									   //               if aktuellerSpieler == 2 -> gegner = 1

	if (spielfeld[posY][posX] != 0) // ist das Feld leer?
	{
		return false;
	}

	// Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
	for (int j = -1; j <= 1; j++)
	{
		for (int i = -1; i <= 1; i++)
		{
			if (i == 0 && j == 0)
				continue; // Ueberspringe die Mitte

			int newX = posX + i;
			int newY = posY + j;

			if (newX < 0 || newX >= GROESSE_X || newY < 0 || newY >= GROESSE_Y)
				continue; // Ueberspringe wenn ausserhalb des Spielfelds

			if (spielfeld[newY][newX] == gegner)
			{
				while (true)
				{
					newX += i;
					newY += j;

					if (newX < 0 || newX >= GROESSE_X || newY < 0
							|| newY >= GROESSE_Y)
						break; // Ueberspringe wenn ausserhalb des Spielfelds

					if (spielfeld[newY][newX] == 0)
						break; // Ueberspringe wenn leeres Feld

					if (spielfeld[newY][newX] == aktuellerSpieler)
						return true; // Gueltiger Zug gefunden
				}
			}
		}
	}
	return false;
}

/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X],
		const int aktuellerSpieler, const int posX, const int posY)
{
	int gegner = 3 - aktuellerSpieler;

	spielfeld[posY][posX] = aktuellerSpieler;

	//Alle Richtungen bearbeiten
	for (int j = -1; j <= 1; j++)
	{
		for (int i = -1; i <= 1; i++)
		{
			if (i == 0 && j == 0)
				continue; // Ueberspringe die Mitte

			int newX = posX + i;
			int newY = posY + j;

			if (newX < 0 || newX >= GROESSE_X || newY < 0 || newY >= GROESSE_Y)
				continue; // Ueberspringe wenn ausserhalb des Spielfelds

			if (spielfeld[newY][newX] == gegner)
			{
				bool foundOwnPiece = false;
				while (true)
				{
					newX += i;
					newY += j;

					if (newX < 0 || newX >= GROESSE_X || newY < 0
							|| newY >= GROESSE_Y)
						break; // Ueberspringe wenn ausserhalb des Spielfelds

					if (spielfeld[newY][newX] == 0)
						break; // Ueberspringe wenn leeres Feld

					if (spielfeld[newY][newX] == aktuellerSpieler)
					{
						foundOwnPiece = true;
						break;
					}
				}

				if (foundOwnPiece)
				{
					newX = posX + i;
					newY = posY + j;
					while (spielfeld[newY][newX] == gegner)
					{
						spielfeld[newY][newX] = aktuellerSpieler;
						newX += i;
						newY += j;
					}
				}
			}
		}
	}
}

/**
 * @brief Zaehlt die Anzahl der moeglichen Zuege fuer einen Spieler
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der Spieler, fuer den die Zuege geprueft werden
 * @return Anzahl der moeglichen Zuege
 */
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X],
		const int aktuellerSpieler)
{
	// Hier erfolgt jetzt Ihre Implementierung ...
	int count = 0;
	for (int y = 0; y < GROESSE_Y; y++)
	{
		for (int x = 0; x < GROESSE_X; x++)
		{
			if (zugGueltig(spielfeld, aktuellerSpieler, x, y))
			{
				count++;
			}
		}
	}
	return count;

}

bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X],
		const int aktuellerSpieler)
{
	if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
	{
		return false;
	}

	int posX;
	int posY;
	std::string symbolSpieler;
	if (aktuellerSpieler == 1)
	{
		symbolSpieler = "X";
	}
	else
	{
		symbolSpieler = "O";
	}

	while (true)
	{
		std::string eingabe;
		std::cout << std::endl << "Du bist " << symbolSpieler
				<< ". Dein Zug (z.B. A1, a1): ";
		std::cin >> eingabe;
		posX = (int) eingabe[0] % 32 - 1;
		posY = (int) eingabe[1] - 49;

		if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
		{
			//accept turn;
			break;
		}
		else
		{
			std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
		}
	}

	zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
	std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf "
			<< (char) (posX + 65) << (posY + 1) << std::endl;

	return true;
}

void spielen(const int spielerTyp[2])
{
	int spielfeld[GROESSE_Y][GROESSE_X];

	//Erzeuge Startaufstellung
	initialisiereSpielfeld(spielfeld);

	int aktuellerSpieler = 1;
	zeigeSpielfeld(spielfeld);

	// solange noch Zuege bei einem der beiden Spieler moeglich sind
	//
	// Hier erfolgt jetzt Ihre Implementierung ...
	while (moeglicheZuege(spielfeld, aktuellerSpieler)
			|| moeglicheZuege(spielfeld, 3 - aktuellerSpieler))
	{
		// Aussetzen des Spielers, wenn kein Zug für den Spieler vorhanden ist
		if (moeglicheZuege(spielfeld, aktuellerSpieler))
		{
			std::cout << "Spielzug von SPIELER " << aktuellerSpieler << ": "
					<< std::endl;
			if (spielerTyp[aktuellerSpieler - 1] == MENSCH)
				menschlicherZug(spielfeld, aktuellerSpieler);
			else
				computerZug(spielfeld, aktuellerSpieler);
			zeigeSpielfeld(spielfeld);
		}

		// Spieler wird zum Gegner
		aktuellerSpieler = 3 - aktuellerSpieler;
	}

	switch (gewinner(spielfeld))
	{
	// Hier erfolgt jetzt Ihre Implementierung ...
	case 0:
		std::cout << std::endl << "Spiel endet unentschieden!" << std::endl;
		break;
	case 1:
		std::cout << std::endl << "Spieler 1 (X) gewinnt!" << std::endl;
		break;
	case 2:
		std::cout << std::endl << "Spieler 2 (O) gewinnt!" << std::endl;
		break;
	}
}

int main()
{
	if (TEST == 1)
	{
		bool gesamtErgebnis = ganzenTestAusfuehren();
		if (gesamtErgebnis == true)
		{
			std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
		}
		else
		{
			std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
			exit(1);
		}
		std::cout << std::endl << std::endl;
	}

	// Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
	// implementiert haben (waeren sonst doppelt)
	int spielfeld[GROESSE_Y][GROESSE_X];

	initialisiereSpielfeld(spielfeld);

	zeigeSpielfeld(spielfeld);

	// int spielerTyp[2] = { COMPUTER, COMPUTER };  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
	// spielen(spielerTyp);
	//
	// Hier erfolgt jetzt Ihre Implementierung ...
	// Menue zur Auswahl des Spieltyps
	std::cout << "Willkommen zu Othello!" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "Spielmodus auswaehlen:" << std::endl;
	std::cout << "1. Mensch gegen Mensch" << std::endl;
	std::cout << "2. Mensch gegen Computer" << std::endl;
	std::cout << "3. Computer gegen Computer" << std::endl;
	std::cout << "Eingabe: ";

	int auswahl;
	std::cin >> auswahl;

	int spielerTyp[2];

	switch (auswahl)
	{
	case 1:
		spielerTyp[0] = MENSCH;
		spielerTyp[1] = MENSCH;
		break;
	case 2:
		spielerTyp[0] = MENSCH;
		spielerTyp[1] = COMPUTER;
		break;
	case 3:
		spielerTyp[0] = COMPUTER;
		spielerTyp[1] = COMPUTER;
		break;
	default:
		std::cout << "Ungueltige Auswahl! Standard: Mensch gegen Computer"
				<< std::endl;
		spielerTyp[0] = MENSCH;
		spielerTyp[1] = COMPUTER;
	}

	// Starte Spiel
	spielen(spielerTyp);

	return 0;
}
