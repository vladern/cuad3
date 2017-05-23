#include <iostream>

using namespace std;

#include "tlistacom.h"

int
main(void)
{
	TComplejo p(1, 1), q(2, 2), r(3, 3);
	TListaCom a;

	cout << a.Longitud() << endl;
	a.InsCabeza(p);
	cout << a.Longitud() << endl;
	a.InsertarD(q,a.Ultima());
	cout << a.Longitud() << endl;
	a.InsertarD(r,a.Ultima());
	cout << a.Longitud() << endl;
}