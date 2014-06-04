/**
* \file aghComplex.h
* \author Kamil Dawid�w & Beata Gie�baga 
* \date 15.5.2014
* \brief Deklaracja klasy aghComplex, zadanie numer 2 na JiMP2, IS2014
*/
// ------------------------------------------------------

#ifndef AGHCOMPLEX_H
#define AGHCOMPLEX_H

// -------------------------------------------------------

/**
* \class aghComplex
* \author Kamil Dawid�w & Beata Gie�baga
* \date 15.5.2014
* \brief klasa aghComplex, opisuj�ca liczb� zespolon�
*/
class aghComplex
{
private:
    double Re, Im;
public:
    /// \brief Konstruktor bezparametrowy
	aghComplex();

    /// \brief Konstruktor parametrowy
    ///
    /// \param _Re - cz�� rzeczywista
    /// \param _Im - cz�� urojona
    aghComplex(double _Re, double _Im);

    /// \brief Konstruktor parametrowy przyjmuj�cy jeden argument typu double
    ///
    /// \param val - warto��, kt�r� przyjm� obie cz�ci liczby
    aghComplex(double val);

    /// \brief Konstruktor kopiuj�cy
    ///
    /// \param orig -  wzorzec
    aghComplex(const aghComplex& orig);

    /// \brief Destruktor
	~aghComplex();

    /// \brief Metoda zwraca cz�� rzeczywist� liczby zespolonej
    ///
    /// \return cz�� rzeczywista liczby zespolonej
    double getRe() const;
    
    /// \brief Metoda zwraca cz�� urojon� liczby zespolonej
    ///
    /// \return cz�� urojon� liczby zespolonej
    double getIm() const;

    /// \brief Metoda zmieniaj�ca cz�� rzeczywist� liczby
    ///
    /// \param _Re
    void setRe(double _Re);

    /// \brief Metoda zmieniaj�ca cz�� urojon� liczby
    ///
    /// \param _Im
    void setIm(double _Im);

    /// \brief Prze�adowanie operatora przypisania "=" (aghComplex)
    ///
    /// \param orig - referencja do obiektu wzorca
    void operator= (aghComplex orig);

    /// \brief Prze�adowanie operatora przypisania "=" (double)
    ///
    /// \param val - warto��, kt�r� przyjm� obie cz�ci liczby
    void operator= (double val);

    /// \brief Prze�adowanie operatora dodawania "+"
    ///
    /// \param orig - referencja do drugiego sk�adnika 
    /// \return - obiekt, kt�ry jest wynikiem dodawania
    aghComplex operator+ (aghComplex orig);

    /// \brief Prze�adowanie operatora mno�enia "*"
    ///
    /// \param orig - referencja do drugiego czynnika 
    /// \return - obiekt, kt�ry jest wynikiem mno�enia
    aghComplex operator* (aghComplex orig);

    /// \brief Prze�adowanie operatora por�wnania "=="
    ///
    /// \param orig - referencja do drugiego argumentu operacji por�wnania
    /// \return - wynik por�wnania jako warto�� typu bool
    bool operator== (aghComplex orig);

    /// \brief Prze�adowanie operatora por�wnania "!="
    ///
    /// \param orig - referencja do drugiego argumentu operacji por�wnania
    /// \return - wynik por�wnania jako warto�� typu bool
    bool operator!= (aghComplex orig);

    /// \brief Prze�adowanie operatora "<<"
    ///
    /// \param output - referencja do strumienia
    /// \param arg - referencja do argumentu operacji <<
    friend std::ostream& operator<<(std::ostream& output, const aghComplex &arg);
};

#endif
