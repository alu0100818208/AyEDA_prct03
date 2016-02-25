#include "1natural.hpp"
#include <cstdlib>

natural::natural(void):
numero(0)
{}

natural::natural(int n)
{
  try 
  {
 
    if(n<0) //Si el numero es negativo se lanza la excepción
    {
      throw n;
    } else
    {
       numero = n;
    }
    
  }
  catch(int a)
  {
      cout << "\nSe ha intentado introducir un numero natural negativo." << endl;
      numero = 0;
  }
}

natural::natural(const natural& n) 
{
  *this = n;  //copiamos directamente el contenido de la clase a la nueva
}

natural::~natural(void){}

unsigned int natural::get_numero(void) const
{
  return numero;	//retornamos el numero sacado
}

natural& natural::operator=(const natural& a)
{
  numero = a.get_numero();	//le asignamos a numero el numero del natural al que igualamos
  
  return *this;			//retornamos this para que podamos hacer varias igualaciones en a misma linea ej: A = B = C = D
}

natural& natural::operator=(const int& n)
{
  natural a(n);			//creamos un nuevo natural con el numero al que igualamos
  *this = a;			//le asignamos a la clase el nuevo natural para que obtega todo de la misma
  return *this;
}

ostream& natural::toStream(ostream& sout) const		//Función heredada de la clase padre para escribir
{
  sout << numero;
  
  return sout;
}

istream& natural::fromStream(istream& sin)		//Función heredada de la clase padre para leer
  int n;
  sin >> n;
  
  natural a(n);
  *this = a;
  
  return sin;
}

//*********************SOBRECARGA DE OPERADORES "AMIGOS"*************************
//Aritméticos
natural operator+(const natural& a, const natural& b)
{
  return natural(a.get_numero() + b.get_numero());
}

natural operator-(const natural& a, const natural& b)
{
  int a_t = a.get_numero();
  int b_t = b.get_numero();
    
  return natural(a.get_numero() - b.get_numero());
}

natural operator*(const natural& a, const natural& b)
{
  return natural(a.get_numero() * b.get_numero());
}

natural operator/(const natural& a, const natural& b)
{
  try {
    if(!b.get_numero()) throw b;
    
    return natural(a.get_numero()/b.get_numero());
    } 
  catch(...)
  {
    cout << "***ERROR*** [División por cero]\nEl resultado se igualará a 0 pero correctamente tiende a infinito." << endl;
    return 000;
  }
}

//comparación
bool operator==(const natural& a, const natural& b)
{
  return(a.get_numero()==b.get_numero() ? true:false);
}

bool operator!=(const natural& a, const natural& b)
{
  return(a==b ? false:true);
}

bool operator<(const natural& a, const natural& b)
{
  return(a.get_numero()<b.get_numero() ? true:false);
}

bool operator>(const natural& a, const natural& b)
{
  if(a!=b) {
    return(a<b ? false:true);
  } else {
    return false;
  }
}

bool operator<=(const natural& a, const natural& b)
{
  return(a>b ? false:true);
}

bool operator>=(const natural& a, const natural& b)
{
  return(a<b ? false:true);
}

//Entrada-Salida
ostream& operator<<(ostream& os, const natural& a)
{
  os << a.get_numero();
  return os;
}

istream& operator>>(istream& is, natural& a)
{
  unsigned int n;
  is >> n;
  a = natural(n);
  return is;
}