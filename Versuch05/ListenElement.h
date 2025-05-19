//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#ifndef _LISTENELEMENT_H_
#define _LISTENELEMENT_H_

#include "Student.h"

class ListenElement
{
private:
	Student data;
	ListenElement *next;
	ListenElement *prev; // Hinzufügen eines Zeigers auf das vorherige Element

public:
	ListenElement(Student pData, ListenElement *pNext, ListenElement *prev = nullptr);

	void setData(Student pData);
	void setNext(ListenElement *pNext);
	void setPrev(ListenElement *pPrev); // Methode zum Setzen des Zeigers auf das vorherige Element hinzufügen

	Student getData() const;

	ListenElement* getNext() const;
	ListenElement* getPrev() const; // Hinzufügen einer Methode zum Abrufen eines Zeigers auf das vorherige Element.
};

#endif
