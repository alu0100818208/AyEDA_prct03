#pragma once
#include <iostream>
#include "0numero.hpp"

#define EPSILON 0.000000001

//Definición de la clase real

using namespace std;

class real:public numero_t {

private:
  float numero;
     
public:
  
  real(void);//constructor por defecto
  real(float n);//constructor de asignación
  real(const real& n);//constructor de asignación
  ~real(void);//destructor
  
  float get_numero(void) const;
  virtual ostream& toStream(ostream& sout) const;  // Escribe un Numero al flujo sout
  virtual istream& fromStream(istream& sin);// Lee un Numero desde flujo sin
  
  //SOBRECARGA DE OPERADORES
  real& operator=(const real&);
  real& operator=(const float& n);
  
  //aritméticos
  friend real operator+(const real&, const real&);
  friend real operator-(const real&, const real&);
  friend real operator*(const real&, const real&);
  friend real operator/(const real&, const real&);
  
  //comparación
  friend bool operator==(const real&, const real&);
  friend bool operator!=(const real&, const real&);
  friend bool operator<(const real&, const real&);
  friend bool operator>(const real&, const real&);
  friend bool operator<=(const real&, const real&);
  friend bool operator>=(const real&, const real&);
  
  //Entrada-Salida
  friend ostream& operator<<(ostream&, const real&);
  friend istream& operator>>(istream&, const real&);
  
};
