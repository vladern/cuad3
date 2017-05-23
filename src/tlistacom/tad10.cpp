#include <iostream>

using namespace std;

#include "tlistacom.h"

int
main(void)
{
    //Prueba insertar derecha
	TComplejo p(1, 1),q(2,2),r(3,3),s(4,4),t(5,5);
	TListaCom a;

	a.InsCabeza(p);
	a.InsertarD(q,a.Ultima());
	a.InsertarD(r,a.Ultima());
	a.InsertarD(s,a.Ultima());
	a.InsertarD(t,a.Ultima());
	a.InsertarD(p,a.Ultima());
	a.InsertarD(q,a.Ultima());
	a.InsertarD(r,a.Ultima());//8 TCOMPLEJO

	cout << a << endl;
	a.Borrar(r);
	cout << a << endl;
	a.Borrar(r);
	cout << a << endl;
}