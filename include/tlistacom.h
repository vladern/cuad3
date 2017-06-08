#ifndef TLISTACOM_H_
#define TLISTACOM_H_
#include "tcomplejo.h"
class TListaNodo
{
    friend class TListaPos;
    friend class TListaCom;
    private:
        // El elemento del nodo
        TComplejo e;
        // El nodo anterior
        TListaNodo *anterior;
        // El nodo siguiente
        TListaNodo *siguiente;
    public:
        //getter del anterior
        TListaNodo* getAnterior();
        //getter del siguiente
        TListaNodo* getSiguiente();
        //getter del complejo
        TComplejo getE();
        // Constructor por defecto
        TListaNodo ();
        // Constructor de copia
        TListaNodo (const TListaNodo &);
        // Destructor
        ~TListaNodo();
        //copia
        void Copia(const TListaNodo &);
        // Sobrecarga del operador asignación
        TListaNodo& operator=(const TListaNodo &);
};
class TListaPos
{
    friend class TListaNodo;
    friend class TListaCom;
    private:   
        // Puntero a un nodo de la lista
        TListaNodo* pos;
    public:
        // Constructor por defecto
        TListaPos ();
        // Constructor de copia
        TListaPos (const TListaPos &);
        // Constructor pasando un puntero a nodo
        TListaPos(TListaNodo *);
        // Destructor
        ~TListaPos ();
        // Sobrecarga del operador asignación
        TListaPos& operator=(const TListaPos &);
        // Sobrecarga del operador igualdad
        bool operator==(const TListaPos &);
        // Sobrecarga del operador desigualdad
        bool operator!=(const TListaPos &);
        // Devuelve la posición anterior
        TListaPos Anterior()const;
        // Devuelve la posición siguiente
        TListaPos Siguiente()const;
        // Devuelve TRUE si la posición no apunta a una lista, FALSE en caso contrario
        bool EsVacia()const;
        //copia
        void Copia(const TListaPos &);

};
class TListaCom
{
    friend class TListaNodo;
    friend class TListaPos;
    private:
        // Primer elemento de la lista
        TListaNodo *primero;
        // Ultimo elemento de la lista
        TListaNodo *ultimo;
    public:
        //get primero
        TListaNodo* getPrimero() const;
        //get ultimo
        TListaNodo* getUltimo() const;
        //copia
        void Copia(const TListaCom&);
        // Constructor por defecto
        TListaCom();
        // Constructor de copia
        TListaCom(const TListaCom &);
        // Destructor
        ~TListaCom();
        // Sobrecarga del operador asignación
        TListaCom & operator=(const TListaCom &);
        //Sobrecarga del operador igualdad
        bool operator==(TListaCom &);
        //Sobrecarga del operador desigualdad
        bool operator!=(TListaCom &);
        // Sobrecarga del operador suma
        TListaCom operator+(const TListaCom &);
        // Sobrecarga del operador resta
        TListaCom operator-(const TListaCom &);
        // Devuelve true si la lista está vacía, false en caso contrario
        bool EsVacia()const;
        // Inserta el elemento en la cabeza de la lista
        bool InsCabeza(const TComplejo &);
        // Inserta el elemento a la izquierda de la posición indicada
        bool InsertarI(const TComplejo &,const TListaPos &);
        // Inserta el elemento a la derecha de la posición indicada
        bool InsertarD(const TComplejo &,const TListaPos &);
        // Busca y borra la primera ocurrencia del elemento
        bool Borrar(const TComplejo &);
        // Busca y borra todas las ocurrencias del elemento
        bool BorrarTodos(const TComplejo &);
        // Borra el elemento que ocupa la posición indicada
        bool Borrar(const TListaPos &);
        // Obtiene el elemento que ocupa la posición indicada
        TComplejo Obtener(const TListaPos &)const;
        // Devuelve true si el elemento está en la lista, false en caso contrario
        bool Buscar(const TComplejo &);
        // Devuelve la longitud de la lista
        int Longitud()const;
        // Devuelve la primera posición en la lista
        TListaPos Primera()const;
        // Devuelve la última posición en la lista
        TListaPos Ultima()const;
        // Sobrecarga del operador salida
        friend ostream & operator<<(ostream &,const  TListaCom &);
};
#endif