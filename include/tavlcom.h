#ifndef TAVLCom_H__
#define TAVLCom_H__
#include "tcomplejo.h"
#include "tlistacom.h"
#include "tvectorcom.h"
#include <algorithm>

class TNodoAVL;
class TAVLCom
{
        friend class TNodoAVL;
        // Puntero al nodo
        TNodoAVL *nodo;
        // AUXILIAR : Devuelve el recorrido en inorden
        void InordenAux(TVectorCom &, int &);
        // AUXILIAR : Devuelve el recorrido en preorden
        void PreordenAux(TVectorCom &, int &);
        // AUXILIAR : Devuelve el recorrido en postorden
        void PostordenAux(TVectorCom &, int &);
        void NivelesnAux(TVectorCom &, int &);
    public:
        //Examen Jun 2016
        int* insertarEnArr(int* arr,int pos,TComplejo com);
        int* recorrerLista(TListaCom l,int* arr,int pos);
        int* examen(const TListaCom&);
        /*-----------------------------
        -------------------------------
        -------------------------------
        -------------------------------
        -------------------------------*/
        //copia
        void Copia(const TAVLCom&);
        // Constructor por defecto
        TAVLCom();
        // Constructor de copia
        TAVLCom(const TAVLCom&);
        // Destructor
        ~TAVLCom();
        // Sobrecarga del operador asignación
        TAVLCom & operator=(const TAVLCom &);
        //--------------------Metodos-----------------------
        //--------------------------------------------------
        //--------------------------------------------------
        //--------------------------------------------------
        // Rotación simple a la derecha(PP) 
        void RSD();
        // Rotación doble a la derecha(PP + Ciudadanos)
        void RDD();
        // Rotación simple a la izquierda(Podemos)
        void RSI();
        // Rotación doble a la izquierda(PSOE + Ciudadanos)
        void RDI();
        // Equilibrar árbol AVL partiendo de un nodo (PSOE + Podemos + Ciudadanos)
        void Equilibrar();
        // ------------------------------------------------ //
        // Sobrecarga del operador igualdad
        bool operator==(TAVLCom&);
        // Sobrecarga del operador de desigualdad
        bool operator!=(TAVLCom&);
        // Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
        bool EsVacio()const;
        // Inserta el elemento en el árbol
        bool Insertar(const TComplejo &);
        //min
        TComplejo maxi();
        //Borrar aux
        TAVLCom BorrarAux(const TComplejo& com);
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
        friend ostream & operator<<(ostream &, TAVLCom &);
};
class TNodoAVL{
friend class TAVLCom;
private:
	// El elemento del nodo
	TComplejo item;
	// Subárbol izquierdo y derecho
	TAVLCom iz, de;
    // Factor de equilibrio
    int fe ;
public:
	// Constructor por defecto
	TNodoAVL ();

	// Constructor de copia
	TNodoAVL (TNodoAVL &);

	// Sobrecarga del operador asignación
	TNodoAVL & operator=( TNodoAVL &);

	// destructor de la clase
	virtual ~TNodoAVL();
};
#endif