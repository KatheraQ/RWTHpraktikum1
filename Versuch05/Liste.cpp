//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
//Implementierung einer bidirektionalen Einfügung des Endes einer Kettentabelle
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (empty())                                       // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
    	neuesElement->setPrev(back);
        back->setNext(neuesElement);
        back = neuesElement;
    }
}

/**
 * @brief Fügt ein neues Listenelement mit den übergebenen Studentendaten am Anfang der Liste ein.
 *
 * @param pData Die Daten des hinzuzufügenden Studenten.
 */
void Liste::pushFront(Student pData) {
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (empty()) {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
    	neuesElement->setNext(front);
        front->setPrev(neuesElement);
        front = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
//Implementierung der bidirektionalen verketteten Löschung von Tabellenköpfen
void Liste::popFront()
{
	if(empty()){
		return;
	}
    ListenElement* cursor = front;

    if (front == back)                                       // Liste enth�lt nur ein Listenelement
    {
        delete front;                                        // Listenelement l�schen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr);
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */

Student Liste::dataFront() {
    if (!empty()) {
        return front->getData();
    }
    return Student();
}
/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
    	cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const {
    ListenElement* cursor = back;
    while (cursor != nullptr) {
        cursor->getData().ausgabe();
        cursor = cursor->getPrev();
    }
}

/**
 * @brief Löscht das erste gefundene Listenelement mit der angegebenen Matrikelnummer.
 * @param matNr Die zu suchende Matrikelnummer.
 * @return true, wenn ein Element gelöscht wurde, sonst false.
 */
bool Liste::loescheDatenelement(unsigned int matNr) {
    ListenElement* cursor = front;
    while (cursor != nullptr) {
        if (cursor->getData().getMatNr() == matNr) {
            if (cursor == front) {
                popFront();
            } else if (cursor == back) {
                back = cursor->getPrev();
                back->setNext(nullptr);
                delete cursor;
            } else {
                cursor->getPrev()->setNext(cursor->getNext());
                cursor->getNext()->setPrev(cursor->getPrev());
                delete cursor;
            }
            return true;
        }
        cursor = cursor->getNext();
    }
    return false;
}


