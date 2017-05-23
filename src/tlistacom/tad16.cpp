#include <iostream>

using namespace std;

#include "tlistacom.h"

int
main(void)
{
	TListaCom a;
	TListaCom b;
	TListaCom c;
	TListaCom d;

	cout << a << endl;
	a.InsCabeza(TComplejo(1, 1));
	cout << a << endl;
	a.InsertarD(TComplejo(2, 2),a.Ultima());
	cout << a << endl;
	a.InsertarD(TComplejo(3, 3),a.Ultima());
	cout << a << endl;
	a.InsertarD(TComplejo(4, 4),a.Ultima());
	cout << a << endl;
	a.InsertarD(TComplejo(5, 5),a.Ultima());
	cout << a << endl;

	cout << b << endl;
	b.InsCabeza(TComplejo(5, 5));
	cout << b << endl;
	b.InsertarD(TComplejo(4, 4),b.Ultima());
	cout << b << endl;
	b.InsertarD(TComplejo(3, 3),b.Ultima());
	cout << b << endl;
	b.InsertarD(TComplejo(2, 2),b.Ultima());
	cout << b << endl;
	b.InsertarD(TComplejo(1, 1),b.Ultima());
	cout << b << endl;

	cout << c << endl;
	c.InsCabeza(TComplejo(3, 3));
	cout << c << endl;
	c.InsertarD(TComplejo(2, 2),c.Ultima());
	cout << c << endl;
	c.InsertarD(TComplejo(4, 4),c.Ultima());
	cout << c << endl;
	c.InsertarD(TComplejo(1, 1),c.Ultima());
	cout << c << endl;
	c.InsertarD(TComplejo(5, 5),c.Ultima());
	cout << c << endl;

	if (d.InsCabeza(TComplejo())) {
		cout << "CORRECTO" << endl;
		cout << c << endl;
	} else {
		cout << "INCORRECTO" << endl;
		cout << c << endl;
	}
	if (d.InsertarD(TComplejo(),d.Ultima())) {
		cout << "CORRECTO" << endl;
		cout << c << endl;

	} else {
		cout << "INCORRECTO" << endl;
		cout << c << endl;
	}
	if (d.InsertarD(TComplejo(1, 1),d.Ultima())) {
		cout << "CORRECTO" << endl;
		cout << c << endl;
	} else {
		cout << "INCORRECTO" << endl;
		cout << c << endl;
	}
	if (d.InsertarD(TComplejo(1, 1),d.Ultima())) {
		cout << "CORRECTO" << endl;
		cout << c << endl;
	} else {
		cout << "INCORRECTO" << endl;
		cout << c << endl;
	}
}