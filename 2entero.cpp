#include "2entero.hpp"

entero::entero(void):		//Constructor por defecto
numero(0)
{}

entero::entero(int n):
numero(n)
{}

entero::entero(const entero& n)		//Constructor de copia
{
  *this = n;
}

entero::~entero(void){}			//Destructor por defecto

int entero::get_numero(void) const
{
  return numero;
}

entero& entero::operator=(const entero& a)
{
  numero = a.get_numero();
  
  return *this;
}

entero& entero::operator=(const int& n)
{
  numero = n;
  return *this;
}

ostream& entero::toStream(ostream& sout) const
{
  sout << numero;
  
  return sout;
}

istream& entero::fromStream(istream& sin)
{
  sin >> numero;
  
  return sin;
}


//******************************SOBRECARGA DE OPERADORES "AMIGOS"***********************************************
//Aritméticos
entero operator+(const entero& a, const entero& b)
{
  return entero(a.get_numero() + b.get_numero());
}

entero operator-(const entero& a, const entero& b)
{
      return entero(a.get_numero() - b.get_numero());
}

entero operator*(const entero& a, const entero& b)
{
  return entero(a.get_numero() * b.get_numero());
}

entero operator/(const entero& a, const entero& b)
{
  try {
    if(!b.get_numero()) throw b;
    
    return entero(a.get_numero()/b.get_numero());
    } 
  catch(...)
  {
    cout << "***ERROR*** [División por cero]\nEl resultado se igualará a 0 pero correctamente tiende a infinito." << endl;
    return 000;
  }
}

//comparación
bool operator==(const entero& a, const entero& b)
{
  return(a.get_numero()==b.get_numero() ? true:false);
}

bool operator!=(const entero& a, const entero& b)
{
  return(a==b ? false:true);
}

bool operator<(const entero& a, const entero& b)
{
  return(a.get_numero()<b.get_numero() ? true:false);
}

bool operator>(const entero& a, const entero& b)
{
  if(a!=b) {
    return(a<b ? false:true);
  } else {
    return false;
  }
}

bool operator<=(const entero& a, const entero& b)
{
  return(a>b ? false:true);
}

bool operator>=(const entero& a, const entero& b)
{
  return(a<b ? false:true);
}

//Entrada-Salida
ostream& operator<<(ostream& os, const entero& a)
{
  os << a.get_numero();
  return os;
}

istream& operator>>(istream& is, entero& a)
{
  int n;
  is >> n;
  a = entero(n);
  return is;
}
