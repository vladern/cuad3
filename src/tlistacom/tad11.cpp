#include <iostream>

using namespace std;

#include "tlistacom.h"

int
main(void)
{
	TComplejo p(1, 1),q(2,2);
	TListaCom a;

	a.InsCabeza(q);
	a.InsertarD(p,a.Ultima());
	a.InsertarD(p,a.Ultima());
	a.InsertarD(p,a.Ultima());
	a.InsertarD(p,a.Ultima());
	a.InsertarD(p,a.Ultima());
	a.InsertarD(p,a.Ultima());
	a.InsertarD(q,a.Ultima());//8 TCOMPLEJO

	a.Borrar(p);

	cout << a << endl;

	a.BorrarTodos(p);

	cout << a << endl;
}