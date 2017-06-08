#include "tlistacom.h"

TListaNodo* TListaNodo::getAnterior()
{
    return this->anterior;
}
//getter del siguiente
TListaNodo* TListaNodo::getSiguiente()
{
    return this->siguiente;
}
//getter del complejo
TComplejo TListaNodo::getE()
{
    return this->e;
}
TListaNodo::TListaNodo():e()
{
    this->anterior=NULL;
    this->siguiente=NULL;
}
void TListaNodo::Copia(const TListaNodo& miNodo)
{
    this->e=miNodo.e;
	this->anterior=NULL;
	this->siguiente=NULL;
}
TListaNodo::TListaNodo(const TListaNodo& n)
{
    this->Copia(n);
}

TListaNodo::~TListaNodo()
{
    if(this!=NULL)
    {
        this->siguiente=NULL;
        this->anterior=NULL;
    }
}

TListaNodo& TListaNodo::operator=(const TListaNodo& nod)
{
    if(this != &nod)
    {
        (*this).~TListaNodo();
        Copia(nod);
    }
    return *this;
}

// Constructor por defecto
TListaPos::TListaPos()
{
    this->pos = NULL;
}
// Constructor de copia
TListaPos::TListaPos (const TListaPos& lista)
{
    this->Copia(lista);
}
TListaPos::TListaPos(TListaNodo* nodo)
{
    this->pos=nodo;
}
// Destructor
TListaPos::~TListaPos ()
{
    if(this != NULL)
    {
        this->pos=NULL;
    }
}
// Sobrecarga del operador asignación
TListaPos& TListaPos::operator=(const TListaPos& pos)
{
    if(this != &pos)
    {
        (*this).~TListaPos();
        this->Copia(pos);
    }
    return *this;
}
// Sobrecarga del operador igualdad
bool TListaPos::operator==(const TListaPos& pos)
{
    if(this->pos == pos.pos)
    {
        return true;
    }
    return false;
}
// Sobrecarga del operador desigualdad
bool TListaPos::operator!=(const TListaPos& pos)
{
    return !((*this)==pos);
}
// Devuelve la posición anterior
TListaPos TListaPos::Anterior()const
{
    if(this->pos==NULL)
    {
        return TListaPos();
    }
    TListaPos pos = TListaPos(this->pos->anterior);
    return pos;
}
// Devuelve la posición siguiente
TListaPos TListaPos::Siguiente()const
{
    if(this->pos==NULL)
    {
        return TListaPos();
    }
    TListaPos pos = TListaPos(this->pos->getSiguiente());
    return pos;
}
// Devuelve TRUE si la posición no apunta a una lista, FALSE en caso contrario
bool TListaPos::EsVacia() const
{
    if(this->pos==NULL)
	{
		return true;
	}
    return false;
}
//copia
void TListaPos::Copia(const TListaPos& pos)
{
    this->pos = pos.pos;
}
/*
    Empieza la clase
    TListaCom
*/
/*
----------------------------------------
----------------------------------------
----------------------------------------
----------------------------------------
*/
// Constructor por defecto
TListaCom::TListaCom()
{
    this->primero=NULL;
    this->ultimo=NULL;
}
// Constructor de copia
TListaCom::TListaCom(const TListaCom& lista)
{
    this->primero=NULL;
    this->ultimo=NULL;
    this->Copia(lista);// depende de Copia
}
// Destructor
TListaCom::~TListaCom()
{
    if(this!=NULL)
    {
        TListaPos pos = TListaPos(this->primero);
        TListaNodo *aux;
        while(pos.pos!=NULL)
        {
            aux=pos.pos;
            pos=pos.Siguiente();
            delete aux;
        }
        this->primero=NULL;
        this->ultimo=NULL;
    }
}
void TListaCom::Copia(const TListaCom& lista)
{
    //depende de Insertar
    TListaPos posicion = TListaPos(lista.primero);
    while(posicion.pos != NULL)
    {
        TComplejo com = posicion.pos->getE();
        this->InsertarD(com,this->ultimo);
        posicion.pos=posicion.Siguiente().pos;
    }
}
// Sobrecarga del operador asignación
TListaCom& TListaCom::operator=(const TListaCom& lista)
{
    if(this != &lista)
    {
        (*this).~TListaCom();
        this->Copia(lista);
    }
    return *this;
}
//Sobrecarga del operador igualdad
bool TListaCom::operator==(TListaCom& lista)
{
    if(this->Longitud()!=lista.Longitud())
    {
        return false;
    }
    TListaPos miPos = TListaPos(this->primero);
    TListaPos suPos = TListaPos(lista.primero);
    //recorro la lista
    while(miPos.pos!=NULL)
    {
        //si mi complejo  es distinto de su complejo 
        if(miPos.pos->getE() != suPos.pos->getE())
        {
            return false;
        }
        miPos.pos = miPos.Siguiente().pos;
        suPos.pos = suPos.Siguiente().pos;
    }
    return true;
}
//Sobrecarga del operador desigualdad
bool TListaCom::operator!=(TListaCom& lista)
{
    return !((*this)==lista); 
}
// Devuelve true si la lista está vacía, false en caso contrario
bool TListaCom::EsVacia()const
{
    if(this->primero==NULL)
    {
        return true;
    }
    return false;
}
// Devuelve true si el elemento está en la lista, false en caso contrario
bool TListaCom::Buscar(const TComplejo& com)
{
    TListaPos miPos = TListaPos(this->primero);
    //recorro la lista
    while(miPos.pos!=NULL)
    {
        //si mi complejo  es igual de su complejo 
        if(miPos.pos->getE() == com)
        {
            return true;
        }
        miPos.pos = miPos.Siguiente().pos;
    }
    return false;    
}
// Inserta el elemento en la cabeza de la lista
bool TListaCom::InsCabeza(const TComplejo& complejo)
{
    TListaNodo* nodo = new TListaNodo();
    nodo->e=complejo;
    TListaNodo *aux = new TListaNodo();
    aux=this->primero;
    if(&nodo==NULL)
    {
        return false;
    }else
    {
        //si el primero es vacio el primero y ultimo apuntan al nodo
        //sino reapuntamos todos los punteros   
        if(this->primero!=NULL)
        {
            //el anterior del primer nodo apuntará a mi nodo
            this->primero->anterior=nodo;
            //mi  nodo se convierte en el primero
            this->primero=nodo;
            //el siguiente de mi nodo será el nodo que antes era el primero
            nodo->siguiente=aux;
        }else
        {
            this->primero = nodo;
            this->ultimo = nodo;
        }
        return true;     
    }
}
// Devuelve la longitud de la lista
int TListaCom::Longitud() const
{
    if(this->primero==NULL)
    {
        return 0;
    }
    TListaPos pos = TListaPos(this->primero);
    int a = 0;
    while(pos.pos != NULL)
    {
        a++;
        pos=pos.Siguiente();
    }
    return a;
}
// Inserta el elemento a la izquierda de la posición indicada
bool TListaCom::InsertarI(const TComplejo& e,const TListaPos& posi)
{
    if(posi.EsVacia())
    {
        return false;
    }
    TListaNodo* nodo = new TListaNodo();
    nodo->e=e;
    if(nodo!=NULL)
    {
        if(posi.pos!=NULL)
        {
        //si la posición que me pasan apunta al primer nodo
        if(this->primero == posi.pos)
        {
            //hago que mi primer nodo me apunte como su anterior
            this->primero->anterior=nodo;
            //apunto al siguiente nodo 
            nodo->siguiente=this->primero;
            //cambio el puntero del primero y hago que me apunte a mi
            this->primero=nodo;
        }else
        {
            //consigo la posicion del nodo anterior 
            TListaPos aux = posi.Anterior();
            //hago que el nodo anterior me apunte como su siguiente
            aux.pos->siguiente = nodo;
            //hago que el nodo del que me pasarón la pos me apunte como su anterior
            posi.pos->anterior= nodo;
        }
        return true;
        //la lista esta vacia
        }else
        {
            this->primero= nodo;
            this->ultimo= nodo;
            return true;
        }
    }else
    {
        return false;
    }
}
// Inserta el elemento a la derecha de la posición indicada
bool TListaCom::InsertarD(const TComplejo& e,const TListaPos& pos)
{
    TListaNodo* nodo = new TListaNodo();
    nodo->e=e;
    if(nodo!=NULL)
    {
        if(this->primero!=NULL)
        {
            //si la posicion que me han pasado es la ultima pos de la lista
            if(this->ultimo == pos.pos)
            {
                //hago que el ultimo nodo me apunte como su siguiente
                pos.pos->siguiente=nodo;
                //apunto al ultimo nodo como mi anterior
                nodo->anterior=this->ultimo;
                //hago que mi nodo sea el ultimo nodo
                this->ultimo=nodo;
            }else
            {
                //hago que el siguiente nodo me apute como su nodo anterior
                pos.pos->siguiente->anterior=nodo;
                //apunto como mi siguiente el nodo siguiente
                nodo->siguiente=pos.pos->siguiente;
                //apunto como mi anterior al nodo que apunta la pos
                nodo->anterior=pos.pos;
                //hago que el nodo que apunta la posicion me apunte como su siguiente
                pos.pos->siguiente=nodo;
            }
            return true;
        //si la lista esta vacia
        }else
        {
            this->primero=nodo;
            this->ultimo=nodo;
            return true;
        }
    }else
    {
        return false;
    }
}
// Busca y borra la primera ocurrencia del elemento
bool TListaCom::Borrar(const TComplejo& e)
{
    if(this->Longitud()!=0)
    {
        TListaPos pos = TListaPos(this->primero);
        while(pos.pos!=NULL)
        {
            //si el elemento que contiene el nodo es igual al elemento que nos han pasado
            if(pos.pos->getE()==e)
            {
                //si la posicion es la primera
                if(this->primero==pos.pos)
                {
                    //hago que el anterior del sigiente nodo sea NULL
                    pos.pos->siguiente->anterior = NULL;
                    //apunto como primero al siguiente nodo
                    this->primero = pos.pos->siguiente;
                    //destruyo el nodo
                    (*pos.pos).~TListaNodo();

                //si la posicion es la ultima
                }else if(this->ultimo==pos.pos)
                {
                    //hago que el siguiente del nodo anterior apunte a NULL
                    pos.pos->anterior->siguiente=NULL;
                    //apunto como ultimo al nodo anterior
                    this->ultimo=pos.pos->anterior;
                    //destruyo el nodo
                    (*pos.pos).~TListaNodo();
                }else
                {
                    //hago que el siguiente del anterior apunte a mi siguiente
                    pos.pos->anterior->siguiente=pos.pos->siguiente;
                    //hago que el anterior del siguiente apunte a mi anterior
                    pos.pos->siguiente->anterior=pos.pos->anterior;
                    //destruyo el nodo 
                    (*pos.pos).~TListaNodo();
                }
                return true;
            }else
            {
                pos=pos.Siguiente();
            }
        }
        return false;
    }else
    {
        return false;
    }
}
// Busca y borra todas las ocurrencias del elemento
bool TListaCom::BorrarTodos(const TComplejo& e)
{
    if(this->Longitud()!=0)
    {
        TListaPos pos = TListaPos(this->primero);
        TListaNodo* aux = new TListaNodo();
        while(pos.pos!=NULL)
        {
            //si el elemento que contiene el nodo es igual al elemento que nos han pasado
            if(pos.pos->getE()==e)
            {
                //si la posicion es la primera
                if(this->primero==pos.pos)
                {
                    //si la lista tiene mas elementos
                    if(pos.pos->siguiente!=NULL)
                    {
                        //hago que el anterior del sigiente nodo sea NULL
                        pos.pos->siguiente->anterior = NULL;
                        //apunto como primero al siguiente nodo
                        this->primero = pos.pos->siguiente;
                        //asigno el auxiliar
                        aux = pos.Siguiente().pos;
                        //destruyo el nodo
                        (*pos.pos).~TListaNodo();
                    }else
                    {
                        //destruyo el nodo
                        (*pos.pos).~TListaNodo();
                        this->primero=NULL;
                        this->ultimo=NULL;
                    }


                //si la posicion es la ultima
                }else if(this->ultimo==pos.pos)
                {
                    //hago que el siguiente del nodo anterior apunte a NULL
                    pos.pos->anterior->siguiente=NULL;
                    //apunto como ultimo al nodo anterior
                    this->ultimo=pos.pos->anterior;
                    //asigno el auxiliar
                    aux = pos.Siguiente().pos;
                    //destruyo el nodo
                    (*pos.pos).~TListaNodo();
                }else
                {
                    //hago que el siguiente del anterior apunte a mi siguiente
                    pos.pos->anterior->siguiente=pos.pos->siguiente;
                    //hago que el anterior del siguiente apunte a mi anterior
                    pos.pos->siguiente->anterior=pos.pos->anterior;
                    //asigno el auxiliar
                    aux = pos.Siguiente().pos;
                    //destruyo el nodo 
                    (*pos.pos).~TListaNodo();
                }
                //hago que la posicion actual pase a ser aux
                pos.pos= aux;
            }else
            {
                pos=pos.Siguiente();
            }
        }
        return true;
    }else
    {
        return false;
    }
}
// Borra el elemento que ocupa la posición indicada
bool TListaCom::Borrar(const TListaPos& pos)
{
    if(pos.EsVacia())
    {
        return false;
    }
    if(this->Longitud()!=0)
    {
        //si la posicion es la primera
        if(this->primero==pos.pos)
        {
            //si hay mas nodos en la lista
            if(pos.pos->siguiente!=NULL)
            {
                //hago que el anterior del sigiente nodo sea NULL
                pos.pos->siguiente->anterior = NULL;
                //apunto como primero al siguiente nodo
                this->primero = pos.pos->siguiente;
            }else
            {
                this->primero = NULL;
                this->ultimo = NULL;
            }
            //destruyo el nodo
            (*pos.pos).~TListaNodo();

        //si la posicion es la ultima
        }else if(this->ultimo==pos.pos)
        {
            //hago que el siguiente del nodo anterior apunte a NULL
            pos.pos->anterior->siguiente=NULL;
            //apunto como ultimo al nodo anterior
            this->ultimo=pos.pos->anterior;
            //destruyo el nodo
            (*pos.pos).~TListaNodo();
        }else
        {
            //hago que el siguiente del anterior apunte a mi siguiente
            pos.pos->anterior->siguiente=pos.pos->siguiente;
            //hago que el anterior del siguiente apunte a mi anterior
            pos.pos->siguiente->anterior=pos.pos->anterior;
            //destruyo el nodo 
            (*pos.pos).~TListaNodo();
        }
        return true;
    }else
    {
        return false;
    }
}
// Obtiene el elemento que ocupa la posición indicada
TComplejo TListaCom::Obtener(const TListaPos& pos)const
{
    if(pos.EsVacia())
    {
        return  TComplejo();
    }
    return pos.pos->getE();
}
// Devuelve la primera posición en la lista
TListaPos TListaCom::Primera()const
{
    TListaPos pos = TListaPos(this->primero);
    return pos;
}
// Devuelve la última posición en la lista
TListaPos TListaCom::Ultima()const
{
    TListaPos pos = TListaPos(this->ultimo);
    return pos;
}
// Sobrecarga del operador suma
TListaCom TListaCom::operator+(const TListaCom& lista)
{
    TListaCom* aux = new TListaCom();
    TListaPos miPos = TListaPos(this->primero);
    TListaPos suPos = TListaPos(lista.primero);
    while(miPos.pos!=NULL)
    {
        aux->InsertarD(miPos.pos->getE(),aux->ultimo);
        miPos=miPos.Siguiente();
    }
     while(suPos.pos!=NULL)
    {
        aux->InsertarD(suPos.pos->getE(),aux->ultimo);
        suPos=suPos.Siguiente(); 
    }
    return (*aux);
}
// Sobrecarga del operador resta
TListaCom TListaCom::operator-(const TListaCom& lista)
{
    TListaNodo *aux0;
    TListaCom* resultado = new TListaCom(*this);
    if(lista.EsVacia()==false)
    { 
        aux0=lista.primero;
        while(aux0!=NULL)
        {
            resultado->BorrarTodos(aux0->e);
            aux0=aux0->siguiente;
        }
    }
    return (*resultado);
}
// Sobrecarga del operador salida
ostream& operator<<(ostream& os,const  TListaCom& p)
{
	TListaPos pos0;
	os<<"{";
    pos0 = p.Primera();
    while(!pos0.EsVacia())
	{
		if(!(pos0==p.Ultima()))
		{
			os<<p.Obtener(pos0);
			os<<" ";
		}else
		{
			os<<p.Obtener(pos0);
		}
        pos0=pos0.Siguiente();
	}
	os<<"}";
	return os;
}