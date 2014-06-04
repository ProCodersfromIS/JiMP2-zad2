/**
* \file aghComplex.h
* \author Kamil Dawidów & Beata Gie³baga 
* \date 15.5.2014
* \brief Deklaracja klasy aghComplex, zadanie numer 2 na JiMP2, IS2014
*/
// ------------------------------------------------------

#ifndef AGHCOMPLEX_H
#define AGHCOMPLEX_H

// -------------------------------------------------------

/**
* \class aghComplex
* \author Kamil Dawidów & Beata Gie³baga
* \date 15.5.2014
* \brief klasa aghComplex, opisuj¹ca liczbê zespolon¹
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
    /// \param _Re - czêœæ rzeczywista
    /// \param _Im - czêœæ urojona
    aghComplex(double _Re, double _Im);

    /// \brief Konstruktor parametrowy przyjmuj¹cy jeden argument typu double
    ///
    /// \param val - wartoœæ, któr¹ przyjm¹ obie czêœci liczby
    aghComplex(double val);

    /// \brief Konstruktor kopiuj¹cy
    ///
    /// \param orig -  wzorzec
    aghComplex(const aghComplex& orig);

    /// \brief Destruktor
	~aghComplex();

    /// \brief Metoda zwraca czêœæ rzeczywist¹ liczby zespolonej
    ///
    /// \return czêœæ rzeczywista liczby zespolonej
    double getRe() const;
    
    /// \brief Metoda zwraca czêœæ urojon¹ liczby zespolonej
    ///
    /// \return czêœæ urojon¹ liczby zespolonej
    double getIm() const;

    /// \brief Metoda zmieniaj¹ca czêœæ rzeczywist¹ liczby
    ///
    /// \param _Re
    void setRe(double _Re);

    /// \brief Metoda zmieniaj¹ca czêœæ urojon¹ liczby
    ///
    /// \param _Im
    void setIm(double _Im);

    /// \brief Prze³adowanie operatora przypisania "=" (aghComplex)
    ///
    /// \param orig - referencja do obiektu wzorca
    void operator= (aghComplex orig);

    /// \brief Prze³adowanie operatora przypisania "=" (double)
    ///
    /// \param val - wartoœæ, któr¹ przyjm¹ obie czêœci liczby
    void operator= (double val);

    /// \brief Prze³adowanie operatora dodawania "+"
    ///
    /// \param orig - referencja do drugiego sk³adnika 
    /// \return - obiekt, który jest wynikiem dodawania
    aghComplex operator+ (aghComplex orig);

    /// \brief Prze³adowanie operatora mno¿enia "*"
    ///
    /// \param orig - referencja do drugiego czynnika 
    /// \return - obiekt, który jest wynikiem mno¿enia
    aghComplex operator* (aghComplex orig);

    /// \brief Prze³adowanie operatora porównania "=="
    ///
    /// \param orig - referencja do drugiego argumentu operacji porównania
    /// \return - wynik porównania jako wartoœæ typu bool
    bool operator== (aghComplex orig);

    /// \brief Prze³adowanie operatora porównania "!="
    ///
    /// \param orig - referencja do drugiego argumentu operacji porównania
    /// \return - wynik porównania jako wartoœæ typu bool
    bool operator!= (aghComplex orig);

    /// \brief Prze³adowanie operatora "<<"
    ///
    /// \param output - referencja do strumienia
    /// \param arg - referencja do argumentu operacji <<
    friend std::ostream& operator<<(std::ostream& output, const aghComplex &arg);
};

#endif
