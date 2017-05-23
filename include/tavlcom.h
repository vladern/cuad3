#ifndef TABBCOM_H__
#define TABBCOM_H__
#include "tcomplejo.h"
#include "tvectorcom.h"
#include <algorithm>

class TNodoABB;
class TABBCom
{
        friend class TNodoABB;
        // Puntero al nodo
        TNodoABB *nodo;
        // AUXILIAR : Devuelve el recorrido en inorden
        void InordenAux(TVectorCom &, int &);
        // AUXILIAR : Devuelve el recorrido en preorden
        void PreordenAux(TVectorCom &, int &);
        // AUXILIAR : Devuelve el recorrido en postorden
        void PostordenAux(TVectorCom &, int &);
        void NivelesnAux(TVectorCom &, int &);
    public:
        //copia
        void Copia(const TABBCom&);
        // Constructor por defecto
        TABBCom();
        // Constructor de copia
        TABBCom(const TABBCom&);
        // Destructor
        ~TABBCom();
        // Sobrecarga del operador asignación
        TABBCom & operator=(const TABBCom &);
        //--------------------Metodos-----------------------
        //--------------------------------------------------
        //--------------------------------------------------
        //--------------------------------------------------
        // Sobrecarga del operador igualdad
        bool operator==(TABBCom&);
        // Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
        bool EsVacio()const;
        // Inserta el elemento en el árbol
        bool Insertar(TComplejo &);
        //min
        TComplejo maxi();
        //Borrar aux
        TABBCom BorrarAux(const TComplejo& com);
        // Borra el elemento en el árbol
        bool Borrar(const TComplejo &);
        // Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
        bool Buscar(const TComplejo &);
        // Devuelve el elemento en la raíz del árbol
        TComplejo Raiz();
        // Devuelve la altura del árbol (la altura de un árbol vacío es 0)
        int Altura()const;
        // Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
        int Nodos();
        //devuelve true es un nodo hoja
        bool EsHoja();
        // Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
        int NodosHoja();
        // Devuelve el recorrido en inorden
        TVectorCom Inorden();
        // Devuelve el recorrido en preorden
        TVectorCom Preorden();
        // Devuelve el recorrido en postorden
        TVectorCom Postorden();
        // Devuelve el recorrido en niveles
        TVectorCom Niveles();
        // Sobrecarga del operador salida
        friend ostream & operator<<(ostream &, TABBCom &);
};
class TNodoABB{
friend class TABBCom;
private:
	// El elemento del nodo
	TComplejo item;
	// Subárbol izquierdo y derecho
	TABBCom iz, de;
public:
	// Constructor por defecto
	TNodoABB ();

	// Constructor de copia
	TNodoABB (TNodoABB &);

	// Sobrecarga del operador asignación
	TNodoABB & operator=( TNodoABB &);

	// destructor de la clase
	virtual ~TNodoABB();
};
#endif