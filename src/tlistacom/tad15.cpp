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
	TListaCom e;
	TListaPos p, q;

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

	cout << a << endl;
	a.Borrar(TComplejo(1, 1));
	cout << a << endl;
	a.Borrar(TComplejo(2, 2));
	cout << a << endl;
	a.Borrar(TComplejo(4, 4));
	cout << a << endl;
	a.Borrar(TComplejo(5, 5));
	cout << a << endl;

	cout << b << endl;
	b.Borrar(TComplejo(5, 5));
	cout << b << endl;
	b.Borrar(TComplejo(1, 1));
	cout << b << endl;
	b.Borrar(TComplejo(3, 3));
	cout << b << endl;

	p = c.Primera();
	q = c.Ultima();

	cout << c << endl;
	c.Borrar(p);
	cout << c << endl;
	c.Borrar(q);
	cout << c << endl;

	p = c.Primera();
	q = c.Ultima();

	c.Borrar(p);
	cout << c << endl;
	c.Borrar(q);
	cout << c << endl;

	if (a.Borrar(TComplejo(10, 10))) {
		cout << "INCORRECTO" << endl;
	} else {
		cout << "CORRECTO" << endl;
	}
	if (e.Borrar(TComplejo(10, 10))) {
		cout << "INCORRECTO" << endl;
	} else {
		cout << "CORRECTO" << endl;
	}
	p = a.Primera();
	if (a.Borrar(p)) {
		cout << "CORRECTO" << endl;
	} else {
		cout << "INCORRECTO" << endl;
	}
	q = a.Ultima();
	if (a.Borrar(q)) {
		cout << "CORRECTO" << endl;
	} else {
		cout << "INCORRECTO" << endl;
	}
	a.InsCabeza(TComplejo());
	p = a.Primera();
	if (a.Borrar(p)) {
		cout << "CORRECTO" << endl;
	} else {
		cout << "INCORRECTO" << endl;
	}
}