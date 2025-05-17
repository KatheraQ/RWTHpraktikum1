//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * @brief Subtracts another vector from this vector and returns the result.
 */
Vektor Vektor::sub(const Vektor& input) const
{
    return Vektor(x - input.x, y - input.y, z - input.z);
}

/**
 * @brief Calculates the length of the vector.
 */
double Vektor::laenge() const
{
    return std::sqrt(x * x + y * y + z * z);
}

/**
 * @brief Calculates the scalar product of this vector and another vector.
 */
double Vektor::skalarProd(const Vektor& input) const
{
    return x * input.x + y * input.y + z * input.z;
}

/**
 * @brief Calculates the angle between this vector and another vector in radians.
 */
double Vektor::winkel(const Vektor& input) const
{
    return std::acos(skalarProd(input) / (laenge() * input.laenge()));
}

/**
 * @brief Rotates the vector around the Z-axis by a given angle in radians.
 */
void Vektor::rotiereUmZ(const double rad)
{
    double newX = x * std::cos(rad) - y * std::sin(rad);
    double newY = x * std::sin(rad) + y * std::cos(rad);
    x = newX;
    y = newY;
}
