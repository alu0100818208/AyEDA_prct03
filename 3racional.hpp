#pragma once
#include <iostream>
#include "2entero.hpp"
#include <cstring>
#include <string>
#include <cstdlib>
#include "0numero.hpp"

//Definición de la clase racional

class racional:public numero_t {

private:
  entero numerador;
  entero denominador;
  entero mcd;
     
public:
  
  racional(void);//constructor por defecto
  racional(entero num, entero den);//constructor de asignación
  racional(const racional& n);//constructor de copia
  racional(int dio, int dir);//constructor de asignación
  ~racional(void);//destructor
  
  entero get_numerador(void) const;
  entero get_denominador(void) const;
  entero m_d(void) const;//máximo común divisor
  
  //HERENCIA DE LA CLASE numero
  virtual ostream& toStream(ostream& sout) const;  // Escribe un Numero al flujo sout
  virtual istream& fromStream(istream& sin);// Lee un Numero desde flujo sin
  
  //SOBRECARGA DE OPERADORES
  racional& operator=(const racional&);
  racional& operator=(const string cad);
  
  //aritméticos
  friend racional operator+(const racional&, const racional&);
  friend racional operator-(const racional&, const racional&);
  friend racional operator*(const racional&, const racional&);
  friend racional operator/(const racional&, const racional&);
  
  //comparación
  friend bool operator==(const racional&, const racional&);
  friend bool operator!=(const racional&, const racional&);
  friend bool operator<(const racional&, const racional&);
  friend bool operator>(const racional&, const racional&);
  friend bool operator<=(const racional&, const racional&);
  friend bool operator>=(const racional&, const racional&);
  
  //Entrada-Salida
  friend ostream& operator<<(ostream&, const racional&);
  friend istream& operator>>(istream&, const racional&);
  
};