/**
* \file aghMatrix.cpp
* \author Kamil Dawidów & Beata Gie³baga
* \date 15.5.2014
* \brief Definicje metod specjalizowanych klasy aghMatrix
*/
// ------------------------------------------------------

#include <iostream>
#include <string>
// -----------------------------------------------------------------------------

#include "aghInclude.h"
// -----------------------------------------------------------------------------

using namespace std;
// -----------------------------------------------------------------------------

template <>
void aghMatrix<char>::setItems(int r, int c, ...)
{
    this->free();
    this->alloc(r, c);

    va_list listOfValues;
    va_start(listOfValues, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            mat[i][j] = va_arg(listOfValues, int);
        }
    }
    va_end(listOfValues);
}
// -----------------------------------------------------------------------------

template <>
aghMatrix<char> aghMatrix<char>::operator+ (aghMatrix<char> const & orig)
{
    if (this->getRows() != orig.getRows() || this->getCols() != orig.getCols())
    {
        throw aghException(2, "Incompatible matrices' sizes, cannot sum", __FILE__, __LINE__);
    }
    else
    {
        int val1;
        int val2;
        aghMatrix<char> result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                val1 = conversion(this->get(i, j));
                val2 = conversion(orig.get(i, j));
                if (val1 > 25 || val1 < 0 || val2 > 25 || val2 < 0)
                {
                    throw aghException(4, "There are not only small letters in the matrix", __FILE__, __LINE__);
                }
                val1 += val2;
                val1 = val1 % 26;

                result.setItem(i, j, conversion(val1));
            }
        }
        return result;
    }
}
// -----------------------------------------------------------------------------

template <>
aghMatrix<char> aghMatrix<char>::operator* (aghMatrix<char> const & right)
{
    if (cols != right.getRows())
    {
        throw aghException(2, "Incompatible matrices' sizes, cannot sum", __FILE__, __LINE__);
    }
    else
    {
        int r = rows; //ilosc wierszy macierzy wyniku
        int c = right.getCols(); //ilosc kolumn macierzy wyniku
        int val;
        aghMatrix<char> result(r, c);
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                val = 0;
                for (int k = 0; k < cols; ++k)
                {
                    val += conversion(this->get(i, k)) * conversion(right.get(k, j));
                }
                val = val % 26;
                result.setItem(i, j, conversion(val));
            }
        }
        return result;
    }
}
// -----------------------------------------------------------------------------

template<>
void aghMatrix<char*>::free(void)
{
    if (!is_free)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                delete[] mat[i][j];
            }
            delete[] mat[i];
        }

        delete[] mat;

        mat = nullptr;
        is_free = true;
        rows = 0;
        cols = 0;
    }
}
// -----------------------------------------------------------------------------

template <>
aghMatrix<char*>::aghMatrix(int r, int c)
{
    this->alloc(r, c);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            mat[i][j] = nullptr;
        }
    }
}
// -----------------------------------------------------------------------------

template <>
aghMatrix<char*>::aghMatrix(aghMatrix<char*> const& pattern)
{
    this->alloc(pattern.getRows(), pattern.getCols());
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (pattern.get(i, j) == nullptr)
                mat[i][j] = nullptr;
            else
            {
                mat[i][j] = new char[strlen(pattern.get(i, j)) + 1];
                strcpy(mat[i][j], pattern.get(i, j));
            }
        }
    }
}
// -----------------------------------------------------------------------------

template <>
aghMatrix<char*>::~aghMatrix()
{
    this->free();
}
// -----------------------------------------------------------------------------

template <>
void aghMatrix<char*>::setItem(int r, int c, char* val)
{
    if (r < 0 || r >= rows || c < 0 || c >= cols)
        throw aghException(1, "Index out of range", __FILE__, __LINE__);
    delete[] mat[r][c];
    if (val == nullptr)
        mat[r][c] = nullptr;
    else
    {
        mat[r][c] = new char[strlen(val) + 1];
        strcpy(mat[r][c], val);
    }
}
// -----------------------------------------------------------------------------

template <>
void aghMatrix<char*>::setItems(char** tab)
{
   for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            delete [] mat[i][j];
            if (*tab == nullptr)
                mat[i][j] = nullptr;
            else
            {
                mat[i][j] = new char[strlen(*tab) + 1];
                strcpy(mat[i][j], *tab);
            }
            ++tab;
        }
    }
}
// -----------------------------------------------------------------------------

template <>
void aghMatrix<char*>::setItems(int r, int c, ...)
{
    if (r < 0 || c < 0)
        throw aghException(0, "Index out of range", __FILE__, __LINE__);

    this->free();
    this->alloc(r, c);

    va_list listOfValues;
    va_start(listOfValues, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            mat[i][j] = new char[strlen(va_arg(listOfValues, char*)) + 1];
        }
    }

    va_start(listOfValues, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            strcpy(mat[i][j], va_arg(listOfValues, char*));
        }
    }

    va_end(listOfValues);
}
// -----------------------------------------------------------------------------

template<>
const aghMatrix<char*>& aghMatrix<char*>::operator= (const aghMatrix<char*>& right)
{
    if (*this != right)
    {
        this->free();

        this->alloc(right.getRows(), right.getCols()); 
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (right.get(i, j) == nullptr)
                    mat[i][j] = nullptr;
                else
                {
                    mat[i][j] = new char[strlen(right.get(i, j)) + 1];
                    strcpy(mat[i][j], right.get(i, j));
                }
            }
        }
    }
    return *this;
}
// -----------------------------------------------------------------------------

template <>
aghMatrix<char*> aghMatrix<char*>::operator+ (aghMatrix<char*> const & right)
{
    if (rows != right.getRows() || cols != right.getCols())
    {
        throw aghException(4, "Incompatible matrices' sizes, cannot sum", __FILE__, __LINE__);
    }

    aghMatrix<char*> result(rows, cols);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            result.setItem(i, j, sumOfString(mat[i][j], right.get(i, j)));
        }
    }
    return result;
}
// -----------------------------------------------------------------------------

template<>
aghMatrix<char*> aghMatrix<char*>::operator* (aghMatrix<char*> const & right)
{
    if (cols != right.getRows())
    {
        throw aghException(2, "Incompatible matrices' sizes, cannot multiply", __FILE__, __LINE__);
    }

    aghMatrix<char*> result(rows, right.getCols());

    int r = rows; //iloœæ wierszy macierzy wyniku
    int c = right.getCols(); //iloœæ kolumn macierzy wyniku

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            for (int k = 0; k < cols; ++k)
                result.setItem(i, j,
                sumOfString(result.get(i, j),
                multOfString(mat[i][k], right.get(k, j))));
        }
    }
    return result;
}
// -----------------------------------------------------------------------------

template <>
bool aghMatrix<char*>::operator== (const aghMatrix<char*>& right)
{
    if (rows != right.getRows() || cols != right.getCols())
        return false;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (mat[i][j] == nullptr || right.get(i, j) == nullptr)
            {
                if (mat[i][j] == nullptr && right.get(i, j) == nullptr)
                    continue;
                else
                    return false;
            }
            if (strcmp(mat[i][j], right.get(i, j)) != 0)
                return false;
        }
    }
    return true;
}
// -----------------------------------------------------------------------------

template <>
bool aghMatrix<char*>::operator!= (const aghMatrix<char*>& right)
{
    return !(this->operator==(right));
}
// -----------------------------------------------------------------------------