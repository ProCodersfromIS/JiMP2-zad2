/**
* \file aghMatrix.h
* \author Kamil Dawid�w & Beata Gie�baga
* \date 15.5.2014
* \brief Szablon klasy aghMatrix, zadanie numer 2 na JiMP2, IS2014
*/
// ------------------------------------------------------

#ifndef AGHMATRIX_H
#define AGHMATRIX_H
// ---------------------

using namespace std;
// -----------------------

/**
* \class aghMatrix
* \author Kamil Dawid�w & Beata Gie�baga
* \date 15.5.2014
* \brief Szablon klasy aghMatrix opisuj�cy obiekt - macierz
*/
template <class T>
class aghMatrix 
{
private:
	int rows; ///< liczba wierszy macierzy
	int cols; ///< liczba kolumn macierzy
	T** mat; ///< wska�nik do tablicy tablic warto�ci macierzy
    bool is_free = true; ///< true je�li pami�� jest zaalokowana, false gdy zwolniona

    /// \brief Metoda przydziela pami�� dla macierzy
    ///
    /// \param r - nowa ilo�� wierszy macierzy
    /// \param c - nowa ilo�� kolumn
    void alloc(int r, int c);

    /// \brief Metoda zwalnia przydzielon� pami�� dla macierzy
    void free();

public:
	/// \brief Konstruktor bezparametrowy klasy
	aghMatrix();

	/// \brief Konstruktor parametrowy klasy
	///
	/// \param r - ilo�� kolumnn macierzy
	/// \param c - ilo�� wierszy macierzy
	aghMatrix(int r, int c);

	/// \brief Konstruktor kopiuj�cy klasy
	///
	/// \param orig - referencja do obiektu macierzystego - wzorca
    aghMatrix(const aghMatrix<T>& orig);

	/// \brief Destruktor klasy
	~aghMatrix();

	/// \brief Metoda zwraca ilo�� wierszy macierzy
	int getRows() const;

	/// \brief Metoda zwraca ilo�� kolumn macierzy
	int getCols() const;

	/// \brief Metoda zwraca ��dany element macierzy
	///
	/// \param r - indeks wiersza elementu
	/// \param c - indeks kolumny elementu
	/// \return - warto�� ��danego elementu
	T get(int r, int c) const;

	/// \brief Metoda wy�wietla macierz
	void show() const;

	/// \brief Metoda przypisuje warto�� konkretnemu elementowi macierzy
	///
	/// \param r - indeks wiersza elementu
	/// \param c - indeks kolumny elementu
	/// \param val - warto�� elementu, kt�ra zostanie mu przypisana
	void setItem(int r, int c, T val);

	/// \brief Metoda przypisuje macierzy kolejne warto�ci przekazane w tablicy
	///
	/// \param tab - wska�nik do pocz�tku tablicy z kt�rej pobierane s� wsp�czynniki
	void setItems(T* tab);

	/// \brief Metoda ta zmienia wielko�� macierzy i wpisuje w ni� nowe warto�ci
	///
	/// \param r - ilo�� wierszy macierzy
	/// \param c - ilo�� kolumn macierzy
	/// \param ... - rightumenty, kt�re s� wpisywane w macierz
	void setItems(int r, int c, ...);

	/// \brief Prze�adowanie operatora przypisania "="
	///
	/// \param orig - referencja do obiektu macierzystego - wzorca
    const aghMatrix & operator= (const aghMatrix<T> & orig);

	/// \brief Prze�adowanie operatora dodawania "+", pozwala dodawa� obiekty do siebie
	/// 
	/// \param right - referencja do drugiego sk�adnika dodawania
	/// \return - obiekt, kt�ry jest wynikiem dodawania
    aghMatrix operator+ (const aghMatrix<T> & right);

	/// \brief Prze�adowanie operatora mno�enia "*"
	///
	/// \param right - referencja do drugiego czynnika mno�enia
	/// \return - obiekt, kt�ry jest wynikiem mno�enia
    aghMatrix operator* (const aghMatrix<T> & right);

	/// \brief Prze�adowanie operatora por�wnania "=="
	///
	/// \param right - referencja do drugiego rightumentu operacji por�wnania
    bool operator== (const aghMatrix<T>& right);

	/// \brief Prze�adowanie operatora por�wnania "!="
	///
	/// \param right - referencja do drugiego rightumentu operacji por�wnania
    bool operator!= (const aghMatrix<T>& right);

	/// \brief Prze�adowanie operatora "()", pozwala odnie�� si� do konkretnego elementu macierzy
	///
	/// \param r - indeks wiersza elementu
	/// \param c - indeks kolumny elementu
	/// \return - warto�� ��dane elementu
	T& operator() (int r, int c);
};
// ---------------------------------------------------------------------

// Deklaracje metod specjalizowanych
// ---------------------------------------

/// \brief - specjalizowana metoda setItems dla char, pozwalaj�ca zmieni� wpisane warto�ci w macierz
///
/// \param r - ilo�� wierszy macierzy
/// \param c - ilo�� kolumn macierzy
/// \param tab - tablica warto�ci, kt�re s� wpisywane w macierz
template <>
void aghMatrix<char>::setItems(int r, int c, ...);

/// \brief Prze�adowanie operatora specjalizowanego "+" dla typu char.
///	 
/// \details Traktuje on kolejne ma�e litery alfabetu jako kolejne liczby, a=0, b=1, itd.
/// Daje poprawne wyniki w zakresie ma�ych liter.
///
/// \param right - referencja do drugiego sk�adnika dodawania
/// \return - obiekt, kt�ry jest wynikiem dodawania
template <>
aghMatrix<char> aghMatrix<char>::operator+ (aghMatrix<char> const & orig);

/// \brief Prze�adowanie operatora specjalizowanego "*" dla typu char.
///	 
/// \details Traktuje on kolejne ma�e litery alfabetu jako kolejne liczby np. a=0, b=1, itd.
/// Daje poprawne wyniki w zakresie ma�ych liter.
///
/// \param right - referencja do drugiego czynnika mno�enia
/// \return - obiekt, kt�ry jest wynikiem mno�enia
template <>
aghMatrix<char> aghMatrix<char>::operator* (aghMatrix<char> const & orig);

/// \brief Specjalizowany konstruktor kopiuj�cy
///
/// \param orig - obiekt wzorzec
template <>
aghMatrix<char*>::aghMatrix(aghMatrix<char*> const & orig);

/// \brief Specjalizowany destruktor klasy
template <>
aghMatrix<char*>::~aghMatrix();

/// \brief Specjalizowana metoda dla char* pozwalaj�ca zmieni� warto�� konkretnego elementu
///
/// \param r - indeks wiersza
/// \param c - indeks kolumn
/// \param val - wyraz kt�ry zostanie wpisany w podane miejsce w macierzy
template <>
void aghMatrix<char*>::setItem(int r, int c, char* val);

/// \brief Specjalizowana metoda dla char*
///
/// \param tab - wska�nik do tablicy wyraz�w, kt�re zostan� wpisane do macierzy
template <>
void aghMatrix<char*>::setItems(char** tab);

/// \brief - specjalizowana metoda setItems dla char, pozwalaj�ca zmieni� wpisane warto�ci w macierz
///
/// \param r - ilo�� wierszy macierzy
/// \param c - ilo�� kolumn macierzy
/// \param tab - tablica warto�ci, kt�re s� wpisywane w macierz
template <>
void aghMatrix<char*>::setItems(int r, int c, ...);

/// \brief Prze�adowanie operatora przypisania "="
///
/// \param right - referencja do obiektu macierzystego - wzorca
template <>
const aghMatrix<char*>& aghMatrix<char*>::operator= (const aghMatrix<char*>& right);

/// \brief - specjalizowane prze�adowanie operatora por�wnania dla typu char*
///
/// \param right - referencja do obiektu do kt�rego por�wnujemy
template <>
bool aghMatrix<char*>::operator== (const aghMatrix<char*>& right);

/// \brief - specjalizowane prze�adowanie operatora por�wnania dla typu char*
///
/// \param right - referencja do obiektu do kt�rego por�wnujemy
template <>
bool aghMatrix<char*>::operator!= (const aghMatrix<char*>& right);

/// \brief Prze�adowanie operatora specjalizowanego "+" dla typu char*.
///	 
/// \details rightumentami operacji dodawania s� wyrazy, traktowane jako zbiory liter.
/// Wynikiem dodawania s� zbiory liter.
///
/// \param right - referencja do drugiego sk�adnika dodawania
/// \return - obiekt, kt�ry jest wynikiem dodawania
template <>
aghMatrix<char*> aghMatrix<char*>::operator+ (aghMatrix<char*> const & right);

/// \brief Prze�adowanie operatora specjalizowanego "*" dla typu char*.
///	 
/// \details rightumentami operacji dodawania s� wyrazy, traktowane jako zbiory liter.
/// Wynikiem mno�enia jest cz�� wsp�lna obu zbior�w liter.
///
/// \param right - referencja do drugiego czynnika mno�enia
/// \return - obiekt, kt�ry jest wynikiem mno�enia
template<>
aghMatrix<char*> aghMatrix<char*>::operator* (aghMatrix<char*> const & right);

template<>
aghMatrix<char*>::aghMatrix(int r, int c);
// --------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//Definicje metod szablonu klasy aghMatrix
// -----------------------------------------------------------------------------

template <class T>
void aghMatrix<T>::alloc(int r, int c)
{
    if (r < 0 || c < 0)
        throw aghException(0, "Index out of range", __FILE__, __LINE__);
    if (is_free)
    {
        rows = r;
        cols = c;
        mat = new T*[r];
        for (int i = 0; i < rows; ++i)
        {
            mat[i] = new T[cols];
        }
        is_free = false;
    } 
}
// -----------------------------------------------------------------------------

template <class T>
void aghMatrix<T>::free()
{
    if (!is_free)
    {
        for (int i = 0; i < rows; ++i)
            delete[] mat[i];
        delete[] mat;

        mat = nullptr;
        is_free = true;
        rows = 0;
        cols = 0;
    }
}
// -----------------------------------------------------------------------------

template <class T>
aghMatrix<T>::aghMatrix()
{
    rows = 0;
    cols = 0;
    mat = nullptr;
}
// -----------------------------------------------------------------------------

template <class T>
aghMatrix<T>::aghMatrix(int r, int c)
{
    this->alloc(r, c);
}
// -----------------------------------------------------------------------------

template <class T>
aghMatrix<T>::aghMatrix(const aghMatrix<T>& orig)
{
    this->alloc(orig.getRows(), orig.getCols());
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            mat[i][j] = orig.get(i, j);
        }
    }
}
// -----------------------------------------------------------------------------

template <class T>
aghMatrix<T>::~aghMatrix()
{
    this->free();
}
// -----------------------------------------------------------------------------

template <class T>
int aghMatrix<T>::getRows() const
{
    return rows;
}
// -----------------------------------------------------------------------------

template <class T>
int aghMatrix<T>::getCols() const
{
    return cols;
}
// -----------------------------------------------------------------------------

template <class T>
T aghMatrix<T>::get(int r, int c) const
{
    if (r < 0 || r >= rows || c < 0 || c >= cols)
    {
        throw aghException(1, "Index out of range", __FILE__, __LINE__);
    }
    else
    {
        return mat[r][c];
    }
}
// -----------------------------------------------------------------------------

template <class T>
void aghMatrix<T>::show() const
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
            cout << this->get(i, j) << " ";
        cout << endl;
    }
}
// -----------------------------------------------------------------------------

template <class T>
void aghMatrix<T>::setItem(int r, int c, T val)
{
    if (r < 0 || r >= rows || c < 0 || c >= cols)
    {
        throw aghException(1, "Index out of range", __FILE__, __LINE__);
    }
    else
    {
        mat[r][c] = val;
    }
}
// -----------------------------------------------------------------------------

template <class T>
void aghMatrix<T>::setItems(T* tab)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            mat[i][j] = *tab;
            ++tab;
        }
    }
}
// -----------------------------------------------------------------------------

template <class T>
void aghMatrix<T>::setItems(int r, int c, ...)
{
    this->free();
    this->alloc(r, c);

    va_list vl;
    va_start(vl, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            mat[i][j] = va_arg(vl, T);
        }
    }
    va_end(vl);
}
// -----------------------------------------------------------------------------

template <class T>
const aghMatrix<T> & aghMatrix<T>::operator= (const aghMatrix<T> & orig)
{
    if (*this != orig)
    {
        this->free();
        int r = orig.getRows();
        int c = orig.getCols();
        this->alloc(r, c);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                this->setItem(i, j, orig.get(i, j));
            }
        }
    }
    return *this;
}
// -----------------------------------------------------------------------------

template <class T>
aghMatrix<T> aghMatrix<T>::operator+ (const aghMatrix<T> & right)
{
    if (rows != right.getRows() || cols != right.getCols())
    {
        throw aghException(2, "Incompatible matrices' sizes, cannot sum", __FILE__, __LINE__);
    }
    else
    {
        aghMatrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.setItem(i, j, (this->get(i, j) + right.get(i, j)));
            }
        }
        return result;
    }
}
// ----------------------------------------------------------------------------

template <class T>
aghMatrix<T> aghMatrix<T>::operator* (const aghMatrix<T> & right)
{
    int r = rows; //ilo�� wierszy macierzy wyniku
    int c = right.getCols(); //ilo�� kolumn macierzy wyniku
    if (cols != right.getRows())
    {
        throw aghException(2, "Incompatible matrices' sizes, cannot multiply", __FILE__, __LINE__);
    }
    else
    {
        aghMatrix<T> result(r, c);
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                result.setItem(i, j, 0);
                for (int k = 0; k < cols; ++k)
                {
                    result.setItem(i, j, result.get(i, j) + this->get(i, k) * right.get(k, j));
                }
            }
        }
        return result;
    }
}
// ----------------------------------------------------------------------------

template <class T>
bool aghMatrix<T>::operator== (const aghMatrix<T>& right)
{
    if (rows != right.getRows() || cols != right.getCols())
    {
        return false;
    }
    bool result = true;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (this->get(i, j) != right.get(i, j))
            {
                result = false;
            }
        }
    }
    return result;
}
// -----------------------------------------------------------------------------

template <class T>
bool aghMatrix<T>::operator!= (const aghMatrix<T>& right)
{
    
    return !(this->operator==(right));
}
// -----------------------------------------------------------------------------

template <class T>
T& aghMatrix<T>::operator() (int r, int c)
{
    return mat[r][c];
}
// ------------------------------------------------------------------------------

#endif
