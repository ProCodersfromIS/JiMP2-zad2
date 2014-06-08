/**
* \file dod_funkcje.h
* \author Kamil Dawidów & Beata Gie³baga
* \date 15.5.2014
* \brief Deklaracje funkcji pomocniczych
*/
// ------------------------------------------------------

#ifndef DOD_FUNKCJE_H
#define DOD_FUNKCJE_H

/// \brief Funkcja zwraca wartoœæ int zmiennej char, a=0, b=1, etc.
///
/// \param right - zmienna typu char
int conversion(char right);

/// \brief Funkcja zwraca zmienn¹ typu char po konwersji z int, 0=a, 1=b; itd.
///
/// \param right - zmienna typu char
char conversion(int right);

/// \brief Funkcja zwraca sumê dwóch tablic znaków
///
/// \param A - pierwsza tablica
/// \param B - druga tablica
/// \return - suma dwóch argumentów
char* sumOfString(char* A, char* B);

/// \brief Funkcja zwraca iloczyn dwóch tablic znaków
///
/// \param A - pierwsza tablica
/// \param B - druga tablica
/// \return - iloczyn dwóch argumentów
char* multOfString(char* A, char* B);

#endif