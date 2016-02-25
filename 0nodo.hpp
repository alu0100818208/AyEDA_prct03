#pragma once
#include <iostream>
using namespace std;

//DESCRIPCION DE LA CLASE NODO
template <class T1>
class mynodo {
  
    T1 dato; //elemento que tiene el nodo
    mynodo<T1>* next; //puntero al siguiente nodo
  
  public:
    mynodo(T1 ele); //constructor que añade un elemento
    mynodo(void); //constructor por defecto
    ~mynodo(void); //destructor por defecto
   
    void set_dato(T1 ele); //metodo para cambiar el elemento
    T1 get_dato(void); //método para saber el valor del elemento del nodo
    mynodo<T1>* get_next(void); // método para obtener el siguiente nodo
    void set_next(mynodo<T1>* inx); //método para determinar el siguiente nodo
};


//IMPLEMENTACION DE LA CLASE
template <class T1>		
mynodo<T1>::mynodo(T1 ele):		//Constructor por defecto
dato(ele),
next(NULL)
{}

template <class T1>
mynodo<T1>::~mynodo(void) {}		//Destructor por defecto

template <class T1>
void mynodo<T1>::set_dato(T1 ele) {	//Función para asignarle un valor al nodo
  dato=ele;
}

template <class T1>
T1 mynodo<T1>::get_dato(void) { 	//Función para obtener el valor del nodo
  return(dato);
}

template <class T1>
mynodo<T1>* mynodo<T1>::get_next(void) {	//Función para obtener el elemento adyacente al nodo
  return(next);
}

template <class T1>
void mynodo<T1>::set_next(mynodo* A) {		//Función para determinar el elemento adyacente al nodo
  next = A;
}
