#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"
#include "tlistacom.h"
#include "tvectorcom.h"
using namespace std;

int
main(void)
{
  TAVLCom a;

  TComplejo c1(68, 1);
  TComplejo c2(56, 1);
  TComplejo c3(84, 1);
  TComplejo c4(35, 1);
  TComplejo c5(60, 1);
  TComplejo c6(80, 1);
  TComplejo c7(98, 1);
  TComplejo c8(11,1);
  TComplejo c9(55,1);
  TComplejo c10(64,1);
  TComplejo c11(70,1);
  TComplejo c12(82,1);
  TComplejo c13(92,1);
  TComplejo c14(40,1);
  TComplejo c15(83,1);

  a.Insertar(c1);
  a.Insertar(c2);
  a.Insertar(c3);
  a.Insertar(c4);
  a.Insertar(c5);
  a.Insertar(c6);
  a.Insertar(c7);
  a.Insertar(c8);
  a.Insertar(c9);
  a.Insertar(c10);
  a.Insertar(c11);
  a.Insertar(c12);
  a.Insertar(c13);
  a.Insertar(c14);
  a.Insertar(c15);

  TListaCom l1;

  l1.InsCabeza(c7);
  l1.InsCabeza(c5);
  l1.InsCabeza(c13);
  l1.InsCabeza(c12);
  l1.InsCabeza(TComplejo(71,1));
  l1.InsCabeza(c1);
  
  /*Prueva*/

  cout<<a.examen(l1)[0]<<endl;
  cout<<a.examen(l1)[1]<<endl;
  cout<<a.examen(l1)[2]<<endl;
  cout<<a.examen(l1)[3]<<endl;
  cout<<a.examen(l1)[4]<<endl;
  
return 1;

}