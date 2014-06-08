/**
* \file aghMatrix.h
* \author Kamil Dawidów & Beata Gie³baga
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
* \author Kamil Dawidów & Beata Gie³baga
* \date 15.5.2014
* \brief Szablon klasy aghMatrix opisuj¹cy obiekt - macierz
*/
template <class T>
class aghMatrix 
{
private:
	int rows; ///< liczba wierszy macierzy
	int cols; ///< liczba kolumn macierzy
	T** mat; ///< wskaŸnik do tablicy tablic wartoœci macierzy
    bool is_free = true; ///< true jeœli pamiêæ jest zaalokowana, false gdy zwolniona

    /// \brief Metoda przydziela pamiêæ dla macierzy
    ///
    /// \param r - nowa iloœæ wierszy macierzy
    /// \param c - nowa iloœæ kolumn
    void alloc(int r, int c);

    /// \brief Metoda zwalnia przydzielon¹ pamiêæ dla macierzy
    void free();

public:
	/// \brief Konstruktor bezparametrowy klasy
	aghMatrix();

	/// \brief Konstruktor parametrowy klasy
	///
	/// \param r - iloœæ kolumnn macierzy
	/// \param c - iloœæ wierszy macierzy
	aghMatrix(int r, int c);

	/// \brief Konstruktor kopiuj¹cy klasy
	///
	/// \param orig - referencja do obiektu macierzystego - wzorca
    aghMatrix(const aghMatrix<T>& orig);

	/// \brief Destruktor klasy
	~aghMatrix();

	/// \brief Metoda zwraca iloœæ wierszy macierzy
	int getRows() const;

	/// \brief Metoda zwraca iloœæ kolumn macierzy
	int getCols() const;

	/// \brief Metoda zwraca ¿¹dany element macierzy
	///
	/// \param r - indeks wiersza elementu
	/// \param c - indeks kolumny elementu
	/// \return - wartoœæ ¿¹danego elementu
	T get(int r, int c) const;

	/// \brief Metoda wyœwietla macierz
	void show() const;

	/// \brief Metoda przypisuje wartoœæ konkretnemu elementowi macierzy
	///
	/// \param r - indeks wiersza elementu
	/// \param c - indeks kolumny elementu
	/// \param val - wartoœæ elementu, która zostanie mu przypisana
	void setItem(int r, int c, T val);

	/// \brief Metoda przypisuje macierzy kolejne wartoœci przekazane w tablicy
	///
	/// \param tab - wskaŸnik do pocz¹tku tablicy z której pobierane s¹ wspó³czynniki
	void setItems(T* tab);

	/// \brief Metoda ta zmienia wielkoœæ macierzy i wpisuje w ni¹ nowe wartoœci
	///
	/// \param r - iloœæ wierszy macierzy
	/// \param c - iloœæ kolumn macierzy
	/// \param ... - rightumenty, które s¹ wpisywane w macierz
	void setItems(int r, int c, ...);

	/// \brief Prze³adowanie operatora przypisania "="
	///
	/// \param orig - referencja do obiektu macierzystego - wzorca
    const aghMatrix & operator= (const aghMatrix<T> & orig);

	/// \brief Prze³adowanie operatora dodawania "+", pozwala dodawaæ obiekty do siebie
	/// 
	/// \param right - referencja do drugiego sk³adnika dodawania
	/// \return - obiekt, który jest wynikiem dodawania
    aghMatrix operator+ (const aghMatrix<T> & right);

	/// \brief Prze³adowanie operatora mno¿enia "*"
	///
	/// \param right - referencja do drugiego czynnika mno¿enia
	/// \return - obiekt, który jest wynikiem mno¿enia
    aghMatrix operator* (const aghMatrix<T> & right);

	/// \brief Prze³adowanie operatora porównania "=="
	///
	/// \param right - referencja do drugiego rightumentu operacji porównania
    bool operator== (const aghMatrix<T>& right);

	/// \brief Prze³adowanie operatora porównania "!="
	///
	/// \param right - referencja do drugiego rightumentu operacji porównania
    bool operator!= (const aghMatrix<T>& right);

	/// \brief Prze³adowanie operatora "()", pozwala odnieœæ siê do konkretnego elementu macierzy
	///
	/// \param r - indeks wiersza elementu
	/// \param c - indeks kolumny elementu
	/// \return - wartoœæ ¿¹dane elementu
	T& operator() (int r, int c);
};
// ---------------------------------------------------------------------

// Deklaracje metod specjalizowanych
// ---------------------------------------

/// \brief - specjalizowana metoda setItems dla char, pozwalaj¹ca zmieniæ wpisane wartoœci w macierz
///
/// \param r - iloœæ wierszy macierzy
/// \param c - iloœæ kolumn macierzy
/// \param tab - tablica wartoœci, które s¹ wpisywane w macierz
template <>
void aghMatrix<char>::setItems(int r, int c, ...);

/// \brief Prze³adowanie operatora specjalizowanego "+" dla typu char.
///	 
/// \details Traktuje on kolejne ma³e litery alfabetu jako kolejne liczby, a=0, b=1, itd.
/// Daje poprawne wyniki w zakresie ma³ych liter.
///
/// \param right - referencja do drugiego sk³adnika dodawania
/// \return - obiekt, który jest wynikiem dodawania
template <>
aghMatrix<char> aghMatrix<char>::operator+ (aghMatrix<char> const & orig);

/// \brief Prze³adowanie operatora specjalizowanego "*" dla typu char.
///	 
/// \details Traktuje on kolejne ma³e litery alfabetu jako kolejne liczby np. a=0, b=1, itd.
/// Daje poprawne wyniki w zakresie ma³ych liter.
///
/// \param right - referencja do drugiego czynnika mno¿enia
/// \return - obiekt, który jest wynikiem mno¿enia
template <>
aghMatrix<char> aghMatrix<char>::operator* (aghMatrix<char> const & orig);

/// \brief Specjalizowany konstruktor kopiuj¹cy
///
/// \param orig - obiekt wzorzec
template <>
aghMatrix<char*>::aghMatrix(aghMatrix<char*> const & orig);

/// \brief Specjalizowany destruktor klasy
template <>
aghMatrix<char*>::~aghMatrix();

/// \brief Specjalizowana metoda dla char* pozwalaj¹ca zmieniæ wartoœæ konkretnego elementu
///
/// \param r - indeks wiersza
/// \param c - indeks kolumn
/// \param val - wyraz który zostanie wpisany w podane miejsce w macierzy
template <>
void aghMatrix<char*>::setItem(int r, int c, char* val);

/// \brief Specjalizowana metoda dla char*
///
/// \param tab - wskaŸnik do tablicy wyrazów, które zostan¹ wpisane do macierzy
template <>
void aghMatrix<char*>::setItems(char** tab);

/// \brief - specjalizowana metoda setItems dla char, pozwalaj¹ca zmieniæ wpisane wartoœci w macierz
///
/// \param r - iloœæ wierszy macierzy
/// \param c - iloœæ kolumn macierzy
/// \param tab - tablica wartoœci, które s¹ wpisywane w macierz
template <>
void aghMatrix<char*>::setItems(int r, int c, ...);

/// \brief Prze³adowanie operatora przypisania "="
///
/// \param right - referencja do obiektu macierzystego - wzorca
template <>
const aghMatrix<char*>& aghMatrix<char*>::operator= (const aghMatrix<char*>& right);

/// \brief - specjalizowane prze³adowanie operatora porównania dla typu char*
///
/// \param right - referencja do obiektu do którego porównujemy
template <>
bool aghMatrix<char*>::operator== (const aghMatrix<char*>& right);

/// \brief - specjalizowane prze³adowanie operatora porównania dla typu char*
///
/// \param right - referencja do obiektu do którego porównujemy
template <>
bool aghMatrix<char*>::operator!= (const aghMatrix<char*>& right);

/// \brief Prze³adowanie operatora specjalizowanego "+" dla typu char*.
///	 
/// \details rightumentami operacji dodawania s¹ wyrazy, traktowane jako zbiory liter.
/// Wynikiem dodawania s¹ zbiory liter.
///
/// \param right - referencja do drugiego sk³adnika dodawania
/// \return - obiekt, który jest wynikiem dodawania
template <>
aghMatrix<char*> aghMatrix<char*>::operator+ (aghMatrix<char*> const & right);

/// \brief Prze³adowanie operatora specjalizowanego "*" dla typu char*.
///	 
/// \details rightumentami operacji dodawania s¹ wyrazy, traktowane jako zbiory liter.
/// Wynikiem mno¿enia jest czêœæ wspólna obu zbiorów liter.
///
/// \param right - referencja do drugiego czynnika mno¿enia
/// \return - obiekt, który jest wynikiem mno¿enia
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
    int r = rows; //iloœæ wierszy macierzy wyniku
    int c = right.getCols(); //iloœæ kolumn macierzy wyniku
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
