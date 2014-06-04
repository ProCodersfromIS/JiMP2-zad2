/**
* \file aghComplex.cpp
* \author Kamil Dawidów & Beata Gie³baga
* \date 15.5.2014
* \brief Definicje metod klasy aghComplex, zadanie numer 2 na JiMP2, IS2014
*/
// ----------------------------------------------------------------------

#include <iostream>
// ----------------------------------------------------------------------

#include "aghComplex.h"
// ----------------------------------------------------------------------

using namespace std;
// ----------------------------------------------------------------------

aghComplex::aghComplex()
{
    Re = 0;
    Im = 0;
}
// ----------------------------------------------------------------------

aghComplex::aghComplex(double _Re, double _Im)
{
    Re = _Re;
    Im = _Im;
}
// ----------------------------------------------------------------------

aghComplex::aghComplex(double val)
{
    Re = val;
    Im = val;
}
// ----------------------------------------------------------------------
aghComplex::aghComplex(const aghComplex& orig)
{
    Re = orig.getRe();
    Im = orig.getIm();
}
// ----------------------------------------------------------------------

aghComplex::~aghComplex()
{
}
// ----------------------------------------------------------------------

double aghComplex::getRe() const
{
    return Re;
}
// ----------------------------------------------------------------------

double aghComplex::getIm() const
{
    return Im;
}
// ----------------------------------------------------------------------

void aghComplex::setRe(double _Re)
{
    Re = _Re;
}
// ----------------------------------------------------------------------

void aghComplex::setIm(double _Im)
{
    Im = _Im;
}
// ----------------------------------------------------------------------

void aghComplex::operator=(aghComplex orig)
{
    Re = orig.getRe();
    Im = orig.getIm();
}
// ----------------------------------------------------------------------

void aghComplex::operator=(double val)
{
    Re = val;
    Im = val;
}
// ----------------------------------------------------------------------


aghComplex aghComplex::operator+(aghComplex orig)
{
    aghComplex result;
    result.setRe(Re + orig.getRe());
    result.setIm(Im + orig.getIm());
    return result;
}
// ----------------------------------------------------------------------

aghComplex aghComplex::operator*(aghComplex orig)
{
    aghComplex result;
    result.setRe(Re * orig.getRe() - Im * orig.getIm());
    result.setIm(Im * orig.getRe() + Re * orig.getIm());
    return result;
}
// ----------------------------------------------------------------------

bool aghComplex::operator==(aghComplex orig)
{
    bool result = true;
    if (Re != orig.getRe() || Im != orig.getIm())
        result = false;
    return result;
}
// ----------------------------------------------------------------------

bool aghComplex::operator!=(aghComplex orig)
{
    bool result = true;
    if (Re == orig.getRe() || Im == orig.getIm())
        result = false;
    return result;
}
// ----------------------------------------------------------------------

ostream& operator<<(ostream& output, const aghComplex arg)
{
    output << "Re(" << arg.getRe() << ")+Im(" << arg.getIm() << ")";
    return output;
}
// --------------------------------------------------------------------