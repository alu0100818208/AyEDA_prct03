#pragma once
#include "0numero.hpp"


//Definición de la clase natural


class natural:public numero_t {

private:
  unsigned int numero;
     
public:
  
  natural(void);//constructor por defecto
  natural(int n);//constructor de asignación
  natural(const natural& n);//constructor de asignación
  ~natural(void);//destructor
  
  unsigned int get_numero(void) const;
  virtual ostream& toStream(ostream& sout) const;  // Escribe un Numero al flujo sout
  virtual istream& fromStream(istream& sin);// Lee un Numero desde flujo sin
  
  //SOBRECARGA DE OPERADORES
  natural& operator=(const natural&);
  natural& operator=(const int& n);
  
  //aritméticos
  friend natural operator+(const natural&, const natural&);
  friend natural operator-(const natural&, const natural&);
  friend natural operator*(const natural&, const natural&);
  friend natural operator/(const natural&, const natural&);
  
  //comparación
  friend bool operator==(const natural&, const natural&);
  friend bool operator!=(const natural&, const natural&);
  friend bool operator<(const natural&, const natural&);
  friend bool operator>(const natural&, const natural&);
  friend bool operator<=(const natural&, const natural&);
  friend bool operator>=(const natural&, const natural&);
  
  //Entrada-Salida
  friend ostream& operator<<(ostream&, const natural&);
  friend istream& operator>>(istream&, const natural&);
  
};

