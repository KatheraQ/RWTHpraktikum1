//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>

#include "ListenElement.h"
#include "Student.h"

class Liste
{
private:
    ListenElement* front;                                         // Zeiger auf das erste Listenelement
    ListenElement* back;                                         // Zeiger auf das letzte Listenelement

public:
    Liste();                                                     // Konstruktor mit Zeigerinitialisierung
    void pushBack(Student pData);
    void pushFront(Student pData); // Neue Deklaration der Kopfeinfügemethode
    void popFront();
    bool empty();
    Student dataFront();
    void ausgabeVorwaerts() const;
    void ausgabeRueckwaerts() const; // Neue Deklaration der Ausgabemethode für umgekehrte Reihenfolge
    bool loescheDatenelement(unsigned int matNr); // Neue Deklaration der Methode Datenelement löschen

};

#endif /*LISTE_H_*/
