#pragma once
#include "0nodo.hpp"
#include <cstdlib>
#include "0numero.hpp"

//DEFINICION DE LA CLASE
template <class U>
class cola {

    mynodo<U>* front;
    mynodo<U>* rear;
    unsigned int tam;
  
  public:
    cola(void);
    ~cola(void);
    
    U pop(void);
    void push(U elemento);
    
    void insertar_vacio(U elemento);
   
    bool empty(void);
    void escribir(void);
    std::ostream& imprime_ptr_numero(std::ostream& os);
};



//IMPLEMENTACIÓN DE LAS FUNCIONES
template <class U>
cola<U>::cola(void):
front(NULL),
rear(NULL),
tam(0)
{}

template <class U>
cola<U>::~cola(void) {

  mynodo<U>* aux = front;
  while(front!=NULL) {
  
    front = front->get_next();
    delete aux;
    aux=front;
    
  }
  
}  

template <class U>
bool cola<U>::empty(void) {

  return(front == NULL ? true : false);
  
}

template <class U>
void cola<U>::insertar_vacio(U elemento) {
  
    try
    {
      mynodo<U>* dummy = new mynodo<U>(elemento);  
      front = dummy;
      rear = dummy;
      tam++;
    } 
      catch(std::bad_alloc& ba)
    {
      std::cerr << ba.what() << std::endl;
      exit(1);
    }
    
}


template <class U>
U cola<U>::pop(void) {

  if(empty()) {
    
    cout << "La cola ya está completamente vacia" << endl;
    
  } else  {
    
	if(front==rear) {
	  mynodo<U>* aux = front;
	  front = NULL;
	  rear = NULL;
	  tam--;
	  return (aux->get_dato());
    
	} else {
  
	  mynodo<U>* aux=front;
	  front = front->get_next();
	  tam--;
	  return (aux->get_dato());
    
	}
  }
  
}

template <class U>
void cola<U>::push(U elemento) {
  
    try
    {
      mynodo<U>* dummy = new mynodo<U>(elemento);  
      if(empty()) {
    
	insertar_vacio(elemento);
  
      } else {
    
	rear->set_next(dummy);
	rear=dummy;
    
      }
      tam++;
    } 
      catch(std::bad_alloc& ba)
    {
      std::cerr << ba.what() << std::endl;
      exit(1);
    }

}

template <class U>
void cola<U>::escribir(void) {
  
  
  mynodo<U>* aux = front;
  
  while(aux != NULL) {
  
    cout << aux->get_dato() << " ";
    aux= aux->get_next();
  }
  
  cout << endl;
  
  //cout << tam << endl;
}

template <>
std::ostream& cola<numero_t*>::imprime_ptr_numero(std::ostream& os)
{
  mynodo<numero_t*>* aux = front;
  
  while(aux != NULL) {
  
    aux->get_dato()->toStream(os);
    cout<< " ";
    aux= aux->get_next();
  }
  
}
