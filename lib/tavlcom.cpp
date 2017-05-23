#include "tavlcom.h"
#include <queue>
TNodoAVL::TNodoAVL():item(),iz(),de()
{

}
TNodoAVL::TNodoAVL(TNodoAVL &nodo):item(nodo.item),iz(nodo.iz),de(nodo.de)
{
    this->fe=nodo.fe;
}
TNodoAVL::~TNodoAVL()
{

}
/*
*
*--------------------AVLComplejo----------------------
*
*/
// Constructor por defecto
TAVLCom::TAVLCom()
{
    this->nodo=NULL;
}
// Constructor de copia
TAVLCom::TAVLCom(const TAVLCom& arbol)
{
    this->nodo=NULL;
    this->Copia(arbol);
}
// Destructor
TAVLCom::~TAVLCom()
{
    if(this!=NULL)
    {
        delete nodo;
        this->nodo=NULL;
    }
}
// Sobrecarga del operador asignación
TAVLCom& TAVLCom::operator=(const TAVLCom& arbol)
{
    if(this != &arbol)
    {
        (*this).~TAVLCom();
        Copia(arbol);
    }
    return(*this);
}
//copia
void TAVLCom::Copia(const TAVLCom& arbol)
{
    if(!arbol.EsVacio())
    {
        //nodo auxiliar
        TNodoAVL * aux = new TNodoAVL();
        aux->item = arbol.nodo->item;
        this->nodo=aux;
        //Recursivamente para todos los demas subarboles
        this->nodo->iz.Copia(arbol.nodo->iz);
        this->nodo->de.Copia(arbol.nodo->de);
        //Termino con la recursion y me voy a tomarme unas cervezas :)
    }else
    {
        this->nodo=NULL;
    }
}
// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
bool TAVLCom::EsVacio() const
{
    if(this->nodo==NULL)
    {
        return true;
    }else
    {
        return false;
    }
}
// Rotación simple a la derecha(PP)
/*
             [P]
            /   \
          [Q]   [C]
         /   \   
      [A]     [B]
*/
void TAVLCom::RSD()
{
    TNodoAVL* P = this->nodo;
    TNodoAVL* Q = this->nodo->iz.nodo;
    TNodoAVL* B = Q->de.nodo;
    if(this->nodo->iz.nodo->fe==0)
    {
        Q->fe=1;
        P->fe=-1;
    }else
    {
        Q->fe=0;
        P->fe=0;
    }
    //1.Pasamos el subárbol derecho del nodo Q como subárbol izquierdo de P.
    P->iz.nodo = B;
    //2.El árbol P pasa a ser el subárbol derecho del nodo Q.
    Q->de.nodo = P;
    /*3.Ahora, el nodo Q pasa a tomar la posición del nodo P, es decir,
     hacemos que la entrada al árbol sea el nodo Q, en lugar del nodo P.
     Previamente, P puede que fuese un árbol completo o un subárbol de otro nodo de menor altura.
     */
     this->nodo=Q;
}
// Rotación doble a la derecha(PP)
void TAVLCom::RDD()
{
 
}
// Rotación simple a la izquierda(Podemos)
/*
             [P]
            /   \
          [A]   [Q]   
               /   \   
            [B]     [C]
*/
void TAVLCom::RSI()
{
    TNodoAVL* P = this->nodo;
    TNodoAVL* Q = this->nodo->de.nodo;
    TNodoAVL* B = Q->iz.nodo;

    /*
    1.Pasamos el subárbol izquierdo del nodo Q como subárbol derecho de P.
    Esto mantiene el árbol como ABB, ya que todos los valores a la izquierda
    de Q siguen estando a la derecha de P.
    */
    P->de.nodo = B;
    /*2.El árbol P pasa a ser el subárbol izquierdo del nodo Q.*/
    Q->iz.nodo = P;
    /*
    3.Ahora, el nodo Q pasa a tomar la posición del nodo P,
    es decir, hacemos que la entrada al árbol sea el nodo Q,
    en lugar del nodo P. Previamente, P puede que fuese un árbol
    completo o un subárbol de otro nodo de menor altura.
    */
    this->nodo=Q;
    //actualizo el factor de equilibrio
    Q->fe=0;
    P->fe=0;
}
// Rotación doble a la izquierda(Podemos)
void TAVLCom::RII()
{

}
// Equilibrar árbol AVL partiendo de un nodo
void TAVLCom::Equilibrar()
{

}
// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
int TAVLCom::Nodos()
{
    
    if(this->EsVacio())
    {
        return 0;
    }
    else
	{
		int total= 1 + this->nodo->de.Nodos() + this->nodo->iz.Nodos();
		return total;
	}
}
//Inorde auxiliar
void TAVLCom::InordenAux(TVectorCom &v,int &posicion)
{
	if(this->nodo!=NULL)
	{
        //itero recursivamente por el subarbol izquierdo
		this->nodo->iz.InordenAux(v,posicion);
        //inserto la raiz en el vector
		v[posicion]=this->nodo->item;
        posicion++;
        //itero recursivamente por el subarbol derecho
        this->nodo->de.InordenAux(v,posicion);
		
	}
}
void TAVLCom::PreordenAux(TVectorCom &v,int &posicion)
{
	if(this->nodo!=NULL)
	{
        //inserto la raiz en el vector
		v[posicion]=this->nodo->item;
        posicion++;
        //itero recursivamente por el subarbol izquierdo
		this->nodo->iz.PreordenAux(v,posicion);
        //itero recursivamente por el subarbol derecho
        this->nodo->de.PreordenAux(v,posicion);
		
	}
}
void TAVLCom::PostordenAux(TVectorCom &v,int &posicion)
{
	if(this->nodo!=NULL)
	{
        //itero recursivamente por el subarbol izquierdo
		this->nodo->iz.PostordenAux(v,posicion);
        //itero recursivamente por el subarbol derecho
        this->nodo->de.PostordenAux(v,posicion);
        //inserto la raiz en el vector
        posicion++;
		v[posicion]=this->nodo->item;	
	}
}
// Devuelve el recorrido en inorden
TVectorCom TAVLCom::Inorden()
{
    if(!this->EsVacio())
    {
        //creo el vector con el numero de nodos que tiene el arbol
        TVectorCom vec = TVectorCom(this->Nodos()); //esto no tiene ni puto sentido joder :( si hago lo mismo pero en Nodos() no funciona
        int pos = 1;
        //llamo a la función recursiva para llenar el vector
        this->InordenAux(vec,pos);
        return vec;
    }else
    {
        TVectorCom vec;
        return vec;
    }
}
TVectorCom TAVLCom::Preorden()
{
    if(!this->EsVacio())
    {
        //creo el vector con el numero de nodos que tiene el arbol
        TVectorCom vec = TVectorCom(this->Nodos());
        int pos = 1;
        //llamo a la función recursiva para llenar el vector
        this->PreordenAux(vec,pos);
        return vec;
    }else
    {
        TVectorCom vec;
        return vec;
    }
}
TVectorCom TAVLCom::Postorden()
{
    if(!this->EsVacio())
    {
        //creo el vector con el numero de nodos que tiene el arbol
        TVectorCom vec = TVectorCom(this->Nodos());
        int pos = 1;
        //llamo a la función recursiva para llenar el vector
        this->PostordenAux(vec,pos);
        return vec;
    }else
    {
        TVectorCom vec;
        return vec;
    }
}
// Devuelve el recorrido en niveles
TVectorCom TAVLCom::Niveles()
{
         
    //cola de abb s
    queue<TAVLCom> c;
    //una arbol abb
    TAVLCom aux;
    int pos=1;
    //vector
    TVectorCom vec(this->Nodos());
    //si el arbol esta vacio devuelvo un vector vacio
    if(this->nodo==NULL)
    {
        return vec;
    }
    // encolar en c
    c.push((*this));
    // mientras la cola no es vacia
    while(!c.empty())
    {
        //auxiliar es igual a lo que haya en la cola
        aux = c.front();
        vec[pos]=aux.nodo->item;
        //desencolar
        c.pop();
        //si el subarbol de la izquierda no es vacio se inserta en cabeza el subarbol izquierdo
        if(!aux.nodo->iz.EsVacio())
            c.push(aux.nodo->iz);
        //si el subarbol de la derecha no es vacio se inserta en cabeza el subarbol derecho
        if(!aux.nodo->de.EsVacio())
            c.push(aux.nodo->de);
        //se aumenta la posición
        pos++;
    }
    return vec;
}
// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
int TAVLCom::Altura()const
{
    if(this->EsVacio())
    {
        return 0;
    }else
    {
        return 1 + max(this->nodo->iz.Altura(),this->nodo->de.Altura());
    }
}
// Sobrecarga del operador igualdad
bool TAVLCom::operator==(TAVLCom& arbol)
{
    for(int i=1;i<=arbol.Inorden().Tamano();i++)
    {
        if(!this->Buscar(arbol.Inorden()[i]))
        {
            return false;
        }
        return true;
    }
    return false;
}
bool TAVLCom::operator!=(TAVLCom& arbol)
{
    return(!((*this)==arbol));
}
// Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
bool TAVLCom::Buscar(const TComplejo& com)
{
    if(this->EsVacio())
    {
        return false;
    }
    //si el modulo de la raiz es mayor que el modulo de num. complejo
    if(this->nodo->item.Mod()>com.Mod())
    {
        return this->nodo->iz.Buscar(com);
    }else if(this->nodo->item.Mod()<com.Mod())
    {
        return this->nodo->de.Buscar(com);
    }else
    {
        return true;
    }
}
// Inserta el elemento en el árbol
bool TAVLCom::Insertar(TComplejo& com)
{
    //Compruebo que el complejo no este ya insertado
    if(!this->Buscar(com))
    {
        //si el arbol esta vacio iserto el primer elemento
        if(this->EsVacio())
        {
            TNodoAVL* aux = new TNodoAVL();
            aux->item=com;
            this->nodo=aux;
            return true;
        }
        //si la raiz es mayor que el complejo busco en el subarbol izquierdo
        if(this->nodo->item.Mod()>com.Mod())
        {
            return this->nodo->iz.Insertar(com);
        //si la raiz es menor que el complejo busco en el subarbol derecho
        }else
        {
            return this->nodo->de.Insertar(com);
        }
    }
    return false;
}
//min
TComplejo TAVLCom::maxi()
{
    //si esvacio(i) entonces
    if(this->nodo->de.EsVacio())
    {
        //min( enraizar( i, x, d ) ) = x
        return this->nodo->item;
    //si no min( enraizar( i, x, d ) ) = min( i ) fsi
    }else
    {
        return this->nodo->de.maxi();
    }
}
//auxiliar de borrar
TAVLCom TAVLCom::BorrarAux(const TComplejo& com)
{
    //borrar( crea_arbin( ), x ) = crea_arbin()
    if(this->EsVacio())
    {
        return TAVLCom();
    }
    //si ( y < x ) entonces
    if(com.Mod() < this->nodo->item.Mod())
    {
        //borrar( enraizar( i, x, d ), y ) = enraizar( borrar( i, y ), x, d )
        this->nodo->iz = this->nodo->iz.BorrarAux(com);
        return(*this);
    //sino si ( y > x ) entonces
    }else if( com.Mod() > this->nodo->item.Mod())
    {
        //borrar(enraizar( i, x, d ), y ) = enraizar( i, x, borrar( d, y )) fsi
        this->nodo->de = this->nodo->de.BorrarAux(com);
        return (*this);
    }
    //si(y==x) y esvacio(d) entonces
    if(this->nodo->item.Mod()==com.Mod() && this->nodo->de.EsVacio())
    {
        //borrar( enraizar( i, x, d ), y ) = i fsi
        return this->nodo->iz;
    }
    //si ( y==x ) y esvacio( i ) entonces
    if(this->nodo->item.Mod()==com.Mod() && this->nodo->iz.EsVacio())
    {
        //borrar( enraizar( i, x, d ), y ) = d fsi
        return this->nodo->de;
    }
    //si (y==x) y no esvacio(d) y no esvacio(i) entonces
    if(this->nodo->item.Mod()==com.Mod() && (!this->nodo->de.EsVacio()) && (!this->nodo->iz.EsVacio()))
    {
        //sustituyo por el mayor de la izquierda
        this->nodo->item = this->nodo->iz.maxi();
        this->nodo->iz = this->nodo->iz.BorrarAux(this->nodo->iz.maxi());
        return (*this);
    }
}
// Borra el elemento en el árbol
bool TAVLCom::Borrar(const TComplejo& com)
{
    if(this->EsVacio())
    {
        return false;
    }else if(!this->Buscar(com))
    {
        return false;
    }
    (*this)=this->BorrarAux(com);
    return true;
}
// Devuelve el elemento en la raíz del árbol
TComplejo TAVLCom::Raiz()
{
    if(this->EsVacio())
    {
        TComplejo co;
        return co;
    }
    return this->nodo->item;
}
//devuelve true si es hoja
bool TAVLCom::EsHoja()
{
    if(this->nodo==NULL)
        return true;
	if(this->nodo->iz.nodo == NULL and this->nodo->de.nodo == NULL)
	{
		return true;
	}else
	{
		return false;
	}
}
// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
int TAVLCom::NodosHoja()
{
    if(this->EsVacio())
        return 0;
    if(this->EsHoja())
    {
        return 1;
    }
    int total = this->nodo->iz.NodosHoja()+this->nodo->de.NodosHoja();
    return (total);
}
ostream& operator<<(ostream& os, TAVLCom& com)
{
    os<<com.Niveles();
    return os;
}