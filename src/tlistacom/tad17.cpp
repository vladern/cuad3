#include <iostream>

using namespace std;

#include "tlistacom.h"

int
main(void)
{
	TListaCom a;
	TListaCom b;
	TListaCom c;

	a.InsCabeza(TComplejo(1, 1));
	a.InsertarD(TComplejo(2, 2),a.Ultima());
	b.InsCabeza(TComplejo(1, 1));
	b.InsertarD(TComplejo(2, 2),b.Ultima());
	cout << a - b << endl;
	b.InsertarD(TComplejo(3, 3),b.Ultima());
	b.InsertarD(TComplejo(4, 4),b.Ultima());
	b.InsertarD(TComplejo(5, 5),b.Ultima());
	cout << a - b << endl;
	cout << a - c << endl;
	c.InsCabeza(TComplejo(1, 1));
	c.InsertarD(TComplejo(4, 4),c.Ultima());
	c.InsertarD(TComplejo(5, 5),c.Ultima());
	cout << a - c << endl;
}