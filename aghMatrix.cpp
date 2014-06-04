/**
* \file aghMatrix.cpp
* \author Kamil Dawidów & Beata Gie³baga
* \date 15.5.2014
* \brief Definicje metod specjalizowanych klasy aghMatrix
*/
// ------------------------------------------------------

#include <iostream>
// -----------------------------------------------------------------------------

#include "aghMatrix.h"
#include "dod_funkcje.h"
#include "aghException.h"
// -----------------------------------------------------------------------------

using namespace std;
// -----------------------------------------------------------------------------

template <>
void aghMatrix<char*>::free()
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
        delete[]mat;
        mat = nullptr;
        is_free = true;
        rows = 0;
        cols = 0;
    }
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
aghMatrix<char> aghMatrix<char>::operator* (aghMatrix<char> const & arg)
{
    if (cols != arg.getRows())
    {
        throw aghException(2, "Incompatible matrices' sizes, cannot sum", __FILE__, __LINE__);
    }
    else
    {
        int r = rows; //ilosc wierszy macierzy wyniku
        int c = arg.getCols(); //ilosc kolumn macierzy wyniku
        int val;
        aghMatrix<char> result(r, c);
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                val = 0;
                for (int k = 0; k < cols; ++k)
                {
                    val += conversion(this->get(i, k)) * conversion(arg.get(k, j));
                }
                val = val % 26;
                result.setItem(i, j, conversion(val));
            }
        }
        return result;
    }
}
// -----------------------------------------------------------------------------

template <>
aghMatrix<char*> aghMatrix<char*>::operator+ (aghMatrix<char*> const & orig)
{
    aghMatrix<char*> result = orig;
    return result;
}
// -----------------------------------------------------------------------------

template<>
aghMatrix<char*> aghMatrix<char*>::operator* (aghMatrix<char*> const & orig)
{
    aghMatrix<char*> result = orig;
    return result;
}
// -----------------------------------------------------------------------------

template <>
aghMatrix<char*>::aghMatrix(aghMatrix<char*> const& pattern)
{

}
// -----------------------------------------------------------------------------

template <>
aghMatrix<char*>::aghMatrix(int r, int c)
{

}
// -----------------------------------------------------------------------------

template <>
void aghMatrix<char*>::setItem(int r, int c, char* val)
{

}
// -----------------------------------------------------------------------------

template <>
void aghMatrix<char*>::setItems(char** tab)
{

}
// -----------------------------------------------------------------------------

template <>
void aghMatrix<char*>::setItems(int r, int c, ...)
{

}
// -----------------------------------------------------------------------------

template <>
bool aghMatrix<char*>::operator== (const aghMatrix<char*>& arg)
{
    bool result = true;
    return result;
}
// -----------------------------------------------------------------------------

template <>
bool aghMatrix<char*>::operator!= (const aghMatrix<char*>& arg)
{
    bool result = false;
    return result;
}
// -----------------------------------------------------------------------------