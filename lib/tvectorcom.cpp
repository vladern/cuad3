#include"tvectorcom.h"

TVectorCom::TVectorCom():error()
{
    this->tamano=0;
    this->c=NULL;
}
TVectorCom::TVectorCom(const int a):error()
{
    if(a<0)
    {
        this->tamano=0;
        this->c=NULL;
    }else
    {
        this->tamano=a;
		this->c = new TComplejo[a];
    }
}
//constructor de copia
TVectorCom::TVectorCom(const TVectorCom& vec)
{
	this->Copia(vec);
}
TVectorCom::~TVectorCom()//falta por hacer
{
	this->tamano=0;
	for(int i=0;i<this->Tamano();i++)
	{
		delete[] this->c;
	}

}
//Copia el objeto en profundidad
void TVectorCom::Copia(const TVectorCom& vec)
{
	this->tamano=vec.Tamano();
	this->c = new TComplejo[this->tamano];
	for(int i=0;i<this->Tamano();i++)
	{
		this->c[i]=vec.c[i];
	}
}
//sobrecarga del operador de asignacion
TVectorCom& TVectorCom::operator=(const TVectorCom& vec)
{
    if(this != &vec)
    {
        //lo destruyo
        (*this).~TVectorCom();
        // y lo copio
        this->Copia(vec);
    }
    return *this;
}
//sobrecarga del operador de igualdad
bool TVectorCom::operator==(const TVectorCom& vec)
{
	if(vec.Tamano()!=this->Tamano())
	{
		return false;
	}
	for(int i=0;i<this->Tamano();i++)
	{
		if(this->c[i]!=vec[i])
		{
			return false;
		}
	}
	return true;
}
//sobrecarga del operador de desigualdad
bool TVectorCom::operator!=(const TVectorCom& vec)
{
	return !((*this)==vec);
}
//sobrecarga del operador de [] de izquierda
TComplejo& TVectorCom::operator[](const int num)
{
	if(num>=1 && num<=this->Tamano())
	{
		return this->c[num-1];
	}
	this->error.clear();
	return this->error;
}

//sobrecarga del operador de [] de derecha
TComplejo TVectorCom::operator[](const int num)const
{
	if(num>=1 && num<=this->Tamano())
	{
		TComplejo nuevo = this->c[num-1];
		return nuevo;
	}
	TComplejo nuevo;
	nuevo = this->error;
	return nuevo;
}
//devuelve el tamaño del vector
int TVectorCom::Tamano()const
{
	return this->tamano;
}
//numero de TComplojos no vacios
int TVectorCom::Ocupadas()const
{
  int cont = 0;
  if(this->c== NULL )
	  return cont;
  for(int i=0;i<this->Tamano();i++)
  {
	 if(!this->c[i].EsVacio())
	 {
		 cont++;
	 }
  }
  return cont;
}
bool TVectorCom::ExisteCom(const TComplejo& com)
{
	if(this->c==NULL)
		return false;
	for(int i=0;i<this->Tamano();i++)
	{
		if(this->c[i]==com)
			return true;
	}
	return false;
}
// Mostrar por pantalla los elementos TComplejo del vector con PARTE REAL O POSTERIOR al argumento
void TVectorCom::MostrarComplejos(double re)
{
		int cont=0;
		cout<<"[";
		for(int i=0;i<this->Tamano();i++)
		{
			if(cont==0 and this->c[i].Re()>=re)
			{
				cout<<this->c[i]; cont++;
			}else if(this->c[i].Re()>=re)
			{
				cout<<","<<this->c[i];
			}
		}
		cout<<"]";

}
// REDIMENSIONAR el vector de TComplejo
bool TVectorCom::Redimensionar(const int n) //mucho mas complejo que eso hay que recorer y destruir cada uno de los objetos si es necesario
{
	bool devolver =false;
	TComplejo *auxiliar;

	if( n>0 and n!=this->Tamano())
	{
		auxiliar = new TComplejo[n];
		this->tamano=n;
		for(int i=0;i<n;i++)
		{
			auxiliar[i]=this->c[i];
		}
		delete[] this->c;
			
		devolver=true;
	}
	return devolver;
}
// Sobrecarga del operador salida
ostream & operator<<(ostream& os,const TVectorCom& vector) //mirar y comprobar que este todo bien
{
		os<<"[";
		for(int i=0;i<vector.Tamano();i++)
		{
			os<<"("<<i+1<<")"<<" ";
			os<< vector.c[i];
			if(i<vector.Tamano() - 1)
			{
				os<<", ";
			}
		}
		os<<"]";
}

