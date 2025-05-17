//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 02
// Author: Boxin Wang
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>

int fibonacci(int n)
{
    int previousFib = 0;//previousFib soll 0 sein, anstatt 1
    int currentFib = 1;
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    for (int i = 2; i <= n; i++)//Variable 1 soll von 2 beginnen, anstatt 0
    {
        int newFib = previousFib + currentFib ;
        previousFib = currentFib ;//previousFib soll den Wert currentFib zuweisen
        currentFib = newFib ;//currentFib soll den Wert newFib zuweisen
    }
    return currentFib ;
}

int main ()
{
    std::cout << " Fibonacci - Zahlen von 0 bis 42:" << std::endl ;
    for (int i = 1; i <= 42 ; i ++)
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl ;//Schneller
    }
    return 0;
}
//Der Maximalwert von Daten vom Typ int beträgt 2.147.483.647, der 47-ten Fibonacci-Zahl > 2.147.483.647
//Die größte mit diesem Programm berechenbare Fibonacci-Zahl ist der 46-ten, 1,836,311,903 < 2.147.483.647
