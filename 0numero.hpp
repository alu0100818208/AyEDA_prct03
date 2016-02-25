#pragma once
#include <iostream>
#include <istream>
#include <ostream>
using namespace std;

class numero_t {	//Clase base para todos los tipos de número
public:

  virtual ostream& toStream(ostream& sout) const = 0;// Escribe un Numero al flujo sout
  virtual istream& fromStream(istream& sin) = 0;// Lee un Numero desde flujo sin
  
  //SOBRECARGA DE OPERADOR DE SALIDA
  //friend ostream& operator<<(ostream&,const numero_t&);
};