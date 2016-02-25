#include "3racional.hpp"
#include "cmath"



//En los constructores cada numero racional se expresa en su forma mínima, dividiendo tanto numerador como denominador por el maximo común divisor
racional::racional(void):
numerador(1),
denominador(2)
{}

racional::racional(entero dio, entero dir):
numerador(dio),
denominador(dir),
mcd(m_d())
{
  try
  {
    if(!denominador.get_numero()) throw 1;
    if(!denominador.get_numero()&&!numerador.get_numero()) throw 'a';
    
    mcd = m_d();
    numerador = numerador/mcd;
    denominador = denominador/mcd;
  } 
  catch(int a)
  {
    cerr << "***ERROR***\nEl numerador o el denominador no pueden ser 0." << endl;
    cout << "Introduzca un nuevo valor para el racional: " << endl;
    fromStream(cin);
    mcd = m_d();
    denominador = denominador/mcd;
    numerador = numerador/mcd;
  }
   catch(char b)
   {
     string b;
      cerr << "***ERROR, SE HA INTRODUCIDO LA INDETERMINACION 0/0***\n." << endl;
      cout << "Introduzca un nuevo valor para el racional: " << endl;
      fromStream(cin);
      mcd = m_d();
      denominador = denominador/mcd;
      numerador = numerador/mcd;
   }
}

racional::racional(int dio, int dir):
numerador(entero(dio)),
denominador(entero(dir)),
mcd(m_d())
{
  try
  {
    if(!denominador.get_numero()) throw 1;
    if(!denominador.get_numero()&&!numerador.get_numero()) throw 'a';
    
    mcd = m_d();
    numerador = numerador/mcd;
    denominador = denominador/mcd;
  } 
  catch(int a)
  {
    cerr << "***ERROR***\nEl numerador o el denominador no pueden ser 0." << endl;
    cout << "Introduzca un nuevo valor para el racional: " << endl;
    fromStream(cin);
    mcd = m_d();
    denominador = denominador/mcd;
    numerador = numerador/mcd;
  }
   catch(char b)
   {
     string b;
      cerr << "***ERROR, SE HA INTRODUCIDO LA INDETERMINACION 0/0***\n." << endl;
      cout << "Introduzca un nuevo valor para el racional: " << endl;
      fromStream(cin);
      mcd = m_d();
      denominador = denominador/mcd;
      numerador = numerador/mcd;
   }
}

racional::racional(const racional& n) 
{
  *this = n;
}

racional::~racional(void){}

entero racional::get_numerador(void) const
{
  return numerador;
}

entero racional::get_denominador(void) const
{
  return denominador;
}

racional& racional::operator=(const racional& a)
{
  numerador = a.get_numerador();
  denominador = a.get_denominador();
  mcd=a.m_d();
  
  return *this;
}

racional& racional::operator=(const string a)
{
  try
  {
    size_t found = a.find("_");
  
    string b,c;
    b.resize(found);
    c.resize((a.size() - found)-1);
    for(unsigned int i=0;i<found;i++) {
  
    b[i] = a[i];
    }
    for(unsigned int j=0;j<c.size();j++) {
  
      c[j] = a[j+1+found];
    }
  
    numerador = atoi(b.c_str());
    denominador = atoi(c.c_str());
  
      if(!denominador.get_numero()||!numerador.get_numero()) throw 1; //si alguno es 0 se vuelve a introducir el numero
      if(!denominador.get_numero()&&!numerador.get_numero()) throw 'a'; //si es  0_0 existe una indeterminación por lo que hay que cambiar el numero
      
      mcd = m_d();
      numerador = numerador/mcd;
      denominador = denominador/mcd;
      return *this;
   } 
   catch(int a)
   {
      string b;
      cerr << "***ERROR***\nEl numerador o el denominador no pueden ser 0." << endl;
      cout << "Introduzca un nuevo valor para el racional: " << endl;
      fromStream(cin);
      mcd = m_d();
      denominador = denominador/mcd;
      numerador = numerador/mcd;
      return *this;
      
   }
   catch(char b)
   {
     string b;
      cerr << "***ERROR, SE HA INTRODUCIDO LA INDETERMINACION 0/0***\n." << endl;
      cout << "Introduzca un nuevo valor para el racional: " << endl;
      fromStream(cin);
      mcd = m_d();
      denominador = denominador/mcd;
      numerador = numerador/mcd;
      return *this;
   }
  
}

entero racional::m_d(void) const //algoritmo de Euclides
{
  entero resto, numerador_aux, resto_aux;
  
  resto = numerador.get_numero()%denominador.get_numero();
  numerador_aux = denominador;
  
  while(resto!=0)
  {
   resto_aux = resto;
   resto = numerador_aux.get_numero()%resto.get_numero();
   numerador_aux = resto_aux;
  }
  
  return numerador_aux;
}

ostream& racional::toStream(ostream& sout) const
{
  numerador.toStream(cout);
  cout << "_";
  denominador.toStream(cout);
  
  return sout;
}

istream& racional::fromStream(istream& sin)
{
  string a;
  sin >> a;
  
  try
  {
    size_t found = a.find("_");
  
    string b,c;
    b.resize(found);
    c.resize((a.size() - found)-1);
    for(unsigned int i=0;i<found;i++) {
  
    b[i] = a[i];
    }
    for(unsigned int j=0;j<c.size();j++) {
  
      c[j] = a[j+1+found];
    }
  
    numerador = atoi(b.c_str());
    denominador = atoi(c.c_str());
  
      if(!denominador.get_numero()||!numerador.get_numero()) throw 1; //si alguno es 0 se vuelve a introducir el numero
      if(!denominador.get_numero()&&!numerador.get_numero()) throw 'a'; //si es  0_0 existe una indeterminación por lo que hay que cambiar el numero
      
      mcd = m_d();
      numerador = numerador/mcd;
      denominador = denominador/mcd;
   } 
   catch(int c)
   {
      string b;
      cerr << "***ERROR***\nEl numerador o el denominador no pueden ser 0." << endl;
      cout << "Introduzca un nuevo valor para el racional: " << endl;
      fromStream(cin);
      mcd = m_d();
      denominador = denominador/mcd;
      numerador = numerador/mcd;    
   }
   catch(char b)
   {
     string b;
      cerr << "***ERROR, SE HA INTRODUCIDO LA INDETERMINACION 0/0***\n." << endl;
      cout << "Introduzca un nuevo valor para el racional: " << endl;
      fromStream(cin);
      mcd = m_d();
      denominador = denominador/mcd;
      numerador = numerador/mcd;
   }
  
  
  return sin;
}

//*************************SOBRECARGA DE OPERADORES "AMIGOS*******************************
//Aritméticos
racional operator+(const racional& a, const racional& b)
{  
  return racional(a.get_numerador()*b.get_denominador() + b.get_numerador()*a.get_denominador(),a.get_denominador()*b.get_denominador());
}

racional operator-(const racional& a, const racional& b)
{ 
  return racional(a.get_numerador()*b.get_denominador() - b.get_numerador()*a.get_denominador(),a.get_denominador()*b.get_denominador());
}

racional operator*(const racional& a, const racional& b)
{ 
  return racional(a.get_numerador()*b.get_numerador(),a.get_denominador()*b.get_denominador());
}

racional operator/(const racional& a, const racional& b)
{
 
  /*try {
    if(!b.get_denominador()) throw b;
    
    return entero(a.get_numero()/b.get_numero());
    } 
  catch(...)
  {
    cout << "***ERROR*** [División por cero]\nEl resultado se igualará a 0 pero correctamente tiende a infinito." << endl;
    return 000;
  }*/
  
  return racional(a.get_numerador()*b.get_denominador(),a.get_denominador()*b.get_numerador());
}

//comparación
bool operator==(const racional& a, const racional& b)
{
  if((a.get_numerador()==b.get_numerador())&&(a.get_denominador()==b.get_denominador())) {
    return true;
  } else {
    return false;
  }
}

bool operator!=(const racional& a, const racional& b)
{
  return(a==b ? false:true);
}

bool operator<(const racional& a, const racional& b)
{
  if(a.get_numerador()==b.get_denominador())
  {
    return(a.get_denominador()<b.get_denominador() ? false:true);
    
  } else {
    
      if((a.get_numerador()*b.get_denominador())<(b.get_numerador()*a.get_denominador())) {
	return true;
      } else {
	return false;
      }
  }
  
}

bool operator>(const racional& a, const racional& b)
{
  if(a!=b) {
    return(a<b ? false:true);
  } else {
    return false;
  }
}

bool operator<=(const racional& a, const racional& b)
{
  return(a>b ? false:true);
}

bool operator>=(const racional& a, const racional& b)
{
  return(a<b ? false:true);
}

//Entrada-Salida
ostream& operator<<(ostream& os, const racional& a)
{
  os << a.get_numerador() << "_" << a.get_denominador();
  return os;
}

istream& operator>>(istream& is, racional& a)
{
  string n;
  is >> n;
  a = n;
  return is;
}