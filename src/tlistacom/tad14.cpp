#include <iostream>

using namespace std;

#include "tlistacom.h"

int
main(void)
{
    TListaCom a;
	TListaPos p, q;

	a.InsCabeza(TComplejo(1, 1));
	a.InsertarI(TComplejo(2, 2),a.Primera());
	a.InsertarI(TComplejo(3, 3),a.Primera());

	p = a.Primera();
	q = a.Ultima();
	cout << a.Obtener(p) << endl;
	cout << a.Obtener(q) << endl;
}