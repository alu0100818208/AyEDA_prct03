#pragma once
#include <iostream>
#include <new>          // std::bad_alloc
#include <stdexcept>      // std::out_of_range
#include <cstdlib>
#include "0numero.hpp"

//DEFINICION DE LA CLASE
template <class T>
class myvector {
	
	private:
		T* elemento; //puntero indicador de donde empieza el vector
		unsigned int tam; //tamaño del vector
	
	public:
		myvector (void);
		myvector (unsigned int size);
		myvector (myvector<T>& A);
		~myvector (void); //destructor por defecto
		
		template <class T3>
		friend myvector<T3> operator+(const myvector<T3>&, const myvector<T3>&);
		
		T &operator[](unsigned int i);
		void mostrarVector(void); //método para ver el vector por pantalla
		T cojer_elemento(unsigned int i); //método para seleccionar un elemento del vector
		void dejar_elemento(unsigned int i, T elem); //método para introducir un elemento en el vector
		
		unsigned int tamanio(void) const; //método para que el usuario sepa el tamaño del vector
		
		myvector<T>& operator=(const myvector<T>&);
		
		template <class T2>
		friend std::ostream& operator<<(std::ostream&,myvector<T2>&);
		
		std::ostream& imprime_ptr_numero(std::ostream& os); //Funcion para imprimir en caso de que sea un vector de tipo numero_t*
	};

	
	
	
//IMPLEMENTACION DE LA CLASE
template <class T>
myvector<T>::myvector(void):	//constructor por defecto
tam(0),
elemento(NULL)
{}

template <class T>
myvector<T>::myvector(unsigned int size):
tam(size),
elemento(NULL)
{
  try
  {
    elemento = new T [tam];
    
    for(unsigned int i=0;i<tam;i++)
    {
      elemento[i] = 0;
    }
    
  }catch (std::bad_alloc& ba)
  {
    std::cerr << ba.what() << std::endl;
    exit(1);
  }

	}
	
template <class T>
myvector<T>::myvector(myvector<T>& A): 	//constructor de copia
tam(0),
elemento(NULL)
{
   /* tam = A.tamanio();
    elemento = new T [tam];
    
    unsigned int i;
    for(i=0;i<tam;i++) {
     
      elemento[i] = A[i];
      
    }*/
  *this = A;
  
}

template <class T>
myvector<T>::~myvector(void) {
	
	if (elemento != NULL){
			delete [] elemento;
			elemento = NULL;
		}
	}

template <class T>
void myvector<T>::mostrarVector(void) { //función para mostrar el vector entero
	
	unsigned int i;
	for(i=0;i<tam;i++) {
		
		std::cout << elemento[i] << " ";
	}
	
	std::cout << std::endl;
}

template <class T>
T myvector<T>::cojer_elemento(unsigned int i) {
	
	try{
	  
	  if(i>tam||i<0) throw "out of range";
	  
	  return(elemento[i]);
		
		
	}
	catch(const char* a)
	{
		std::cerr << "Error al obtener el elemento ya que la posición está fuera de rango." << std::endl;
	}
	
}

template <class T>
void myvector<T>::dejar_elemento(unsigned int i, T elem) {
	
	try
	{
		if(i>tam||i<0) throw 'a';
		
		elemento[i] = elem;
	}
	catch(const char a)
	{
		std::cerr << "Error al depositar el elemento ya que la posición está fuera de rango" << std::endl;
		
	}
}

template <class T>
unsigned int myvector<T>::tamanio(void) const {
	
	return (tam);
}

template <>
std::ostream& myvector<numero_t*>::imprime_ptr_numero(std::ostream& os)
{
  
  for(int i = 0; i<tam;i++) {
		
	    if(elemento[i]!=0) 
	    {
	     elemento[i]->toStream(os);
	     cout << " ";
	    }
	    else
	    {
	      os << elemento[i] << " ";
	    }
		
	}

	return os;
  
}


template <class T>
T &myvector<T>::operator[](unsigned int i) {	//operador que sobrecarga para acceder a un elemento del vector

	try{
	  
	  if(i>tam||i<0) throw "out of range";
	  
	  
	  return(elemento[i]);
		
		
	}
	catch(const char* a)
	{
		std::cerr << "Error al obtener el elemento ya que la posición está fuera de rango." << std::endl;
	}
  
}

template <class T>
myvector<T>& myvector<T>::operator=(const myvector<T>& x) {	//operador de asignación

  try
  {
    
  if (tam != x.tamanio()) {
    tam = x.tamanio();
    delete[] elemento;
    elemento = new T[x.tamanio()];
  }
  // pasamos todos los elementos desde 'x'
  for (unsigned int i = 0; i < tam; i++)
    elemento[i] = x[i];

  return *this;
  
  } catch(std::bad_alloc& ba)
  {
    std::cerr << ba.what() << std::endl;
    exit(1);
  }
  
}

//*********IMPLEMENTACION DE FUNCIONES AMIGAS*********
template <class T3>
myvector<T3> operator+(myvector<T3>& A,myvector<T3>& B) {	//operador de suma sorecargado que suma los elementos de dos vectores

  if(A.tamanio() <= B.tamanio()) {
    myvector<T3> C(B);
    unsigned int i;
    for(i =0;i<A.tamanio();i++) {
    
      C.dejar_elemento(i, A[i] + C[i]);
      
    }
    
    return C;
      
   } else {
    
      myvector<T3> C(A);
      unsigned int i;
      for(i =0;i<B.tamanio();i++) {
    
      C.dejar_elemento(i, B[i] + C[i]);
      
      }
      
      return C;
      
    }
    
    
}

template <class T2>
std::ostream& operator<<(std::ostream& os, myvector<T2>& v) {

	for(int i = 0; i<v.tamanio();i++) {
		
		os << v[i] << " ";
		
	}

	return os;
}	