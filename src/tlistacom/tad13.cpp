#include <iostream>

using namespace std;

#include "tlistacom.h"

int
main(void)
{
	TListaCom a;

		a.InsCabeza(TComplejo());
		a.InsertarD(TComplejo(1, 1),a.Ultima());
		a.InsertarD(TComplejo(2, 2),a.Ultima());
		a.InsertarD(TComplejo(3, 3),a.Ultima());
		a.InsertarD(TComplejo(4, 4),a.Ultima());
		a.InsertarD(TComplejo(5, 5),a.Ultima());

		if (a.Buscar(TComplejo())) {
			cout << "CORRECTO" << endl;
		} else {
			cout << "INCORRECTO" << endl;
		}
		if (a.Buscar(TComplejo(1, 1))) {
			cout << "CORRECTO" << endl;
		} else {
			cout << "INCORRECTO" << endl;
		}
		if (a.Buscar(TComplejo(2, 2))) {
			cout << "CORRECTO" << endl;
		} else {
			cout << "INCORRECTO" << endl;
		}

		if (a.Buscar(TComplejo(3, 3))) {
			cout << "CORRECTO" << endl;
		} else {
			cout << "INCORRECTO" << endl;
		}

		if (a.Buscar(TComplejo(4, 4))) {
			cout << "CORRECTO" << endl;
		} else {
			cout << "INCORRECTO" << endl;
		}

		if (a.Buscar(TComplejo(5, 5))) {
			cout << "CORRECTO" << endl;
		} else {
			cout << "INCORRECTO" << endl;
		}
		if (a.Buscar(TComplejo(6, 6))) {
			cout << "INCORRECTO" << endl;
		} else {
			cout << "CORRECTO" << endl;
		}
}