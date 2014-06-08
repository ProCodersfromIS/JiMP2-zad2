/**
* \file dod_funkcje.h
* \author Kamil Dawid�w & Beata Gie�baga
* \date 15.5.2014
* \brief Deklaracje funkcji pomocniczych
*/
// ------------------------------------------------------

#ifndef DOD_FUNKCJE_H
#define DOD_FUNKCJE_H

/// \brief Funkcja zwraca warto�� int zmiennej char, a=0, b=1, etc.
///
/// \param right - zmienna typu char
int conversion(char right);

/// \brief Funkcja zwraca zmienn� typu char po konwersji z int, 0=a, 1=b; itd.
///
/// \param right - zmienna typu char
char conversion(int right);

/// \brief Funkcja zwraca sum� dw�ch tablic znak�w
///
/// \param A - pierwsza tablica
/// \param B - druga tablica
/// \return - suma dw�ch argument�w
char* sumOfString(char* A, char* B);

/// \brief Funkcja zwraca iloczyn dw�ch tablic znak�w
///
/// \param A - pierwsza tablica
/// \param B - druga tablica
/// \return - iloczyn dw�ch argument�w
char* multOfString(char* A, char* B);

#endif