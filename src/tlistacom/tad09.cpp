#include <iostream>

using namespace std;

#include "tlistacom.h"

int
main(void)
{
    TComplejo a(11,-7),b(7,-7),c(4,-7),d(2,-7),e(1,-7);
  //lista 1
  TListaCom l1,l2,l3;
  l1.InsertarD(a,l1.Ultima());
  l1.InsertarD(b,l1.Ultima());
  l1.InsertarD(c,l1.Ultima());
  l1.InsertarD(d,l1.Ultima());
  l1.InsertarD(e,l1.Ultima());
  //lista 2
  l2.InsertarD(e,l2.Ultima());
  l2.InsertarD(d,l2.Ultima());
  l2.InsertarD(c,l2.Ultima());
  l2.InsertarD(b,l2.Ultima());
  l2.InsertarD(a,l2.Ultima());   

  l3 = l1+l2;
  cout<<"lc1 = "<<l3<<endl;
}