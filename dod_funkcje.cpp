/**
* \file dod_funkcje.cpp
* \author Kamil Dawidów & Beata Gie³baga
* \date 15.5.2014
* \brief Definicje funkcji pomocniczych
*/
// ------------------------------------------------------

#include "dod_funkcje.h"
// ------------------------------------------------------

#include <iostream>
#include <cstring>
// ------------------------------------------------------

using namespace std;
// ------------------------------------------------------

int conversion(char right)
{
    return right - 97;
}
// ------------------------------------------------------

char conversion(int right)
{
    return right + 97;
}
// ------------------------------------------------------

char* sumOfString(char* A, char* B)
{
    int lenA, lenB;
    if (A == nullptr)
        lenA = 0;
    else
        lenA = strlen(A);

    if (B == nullptr)
    {
        lenA = 0;
        if (A == nullptr)
            return nullptr;
    }
    else
        lenB = strlen(B);

    char* helper = new char[lenA + lenB + 1];
    int counter = 0;

    for (int i = 0; i < lenA; ++i)
    {
        if (strrchr(helper, A[i]) == NULL)
        {
            helper[counter] = A[i];
            ++counter;
        }
    }

    for (int i = 0; i < lenB; ++i)
    {
        if (strchr(helper, B[i]) == NULL)
        {
            helper[counter] = B[i];
            ++counter;
        }
    }

    helper[counter] = '\0';

    char* result = new char[counter + 1];
    strcpy(result, helper);

    delete []helper;
    return result;

}
// ------------------------------------------------------

char* multOfString(char* A, char* B)
{
    int lenA, lenB;
    if (A == nullptr)
        lenA = 0;
    else
        lenA = strlen(A);
    if (B == nullptr)
    {
        lenB = 0;
        if (A == nullptr)
            return nullptr;
    }
    else
        lenB = strlen(B);

    int lenOfHelper;
    if (lenA > lenB)
        lenOfHelper = lenA;
    else
        lenOfHelper = lenB;
    char* helper = new char[lenOfHelper + 1];
    int counter = 0;

    for (int i = 0; i < lenA; ++i)
    {
        if (strchr(B, A[i]) != NULL && strchr(helper, A[i]) == NULL)
        {
            helper[counter] = A[i];
            ++counter;
        }
    }

    helper[counter] = '\0';
    char* result = new char[counter + 1];
    strcpy(result, helper);

    delete []helper;
    return result;
}