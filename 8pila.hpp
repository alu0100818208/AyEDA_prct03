#include "0nodo.hpp"
#include <cstdlib>
#include "0numero.hpp"

//DEFINICION DE LA CLASE
template <class T2>
class pila {

    mynodo<T2>* front;
    mynodo<T2>* rear;
    unsigned int tam;
  
  public:
    pila(void);
    ~pila(void);
    
    void push(T2 elemento);
    T2 pop(void);
    void insertar_vacio(T2 elemento);
   
    bool empty(void);
    void escribir(void);
    std::ostream& imprime_ptr_numero(std::ostream& os);
    
};

//IMPLEMENTACION DE LAS FUNCIONES DE LA CLASE
template <class T2>
pila<T2>::pila(void):
front(NULL),
rear(NULL),
tam(0)
{}

template <class T2>
pila<T2>::~pila(void) {

  mynodo<T2>* aux = front;
  while(front!=NULL) {
  
    front = front->get_next();
    delete aux;
    aux=front;
    
  }
  
}  

template <class T2>
bool pila<T2>::empty(void) {

  return(front == NULL ? true : false);
  
}

template <class T2>
void pila<T2>::insertar_vacio(T2 elemento) {
  
    try
    {
      mynodo<T2>* dummy = new mynodo<T2>(elemento); 
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

template <class T2>
void pila<T2>::push(T2 elemento) {

  if(empty()) {
    
    insertar_vacio(elemento);
    
  } else {
    
     try
    {
      mynodo<T2>* dummy = new mynodo<T2>(elemento); 
      
	if(front == rear) {
      
	  dummy->set_next(rear);
	  front = dummy;
    
	} else {
    
	  dummy->set_next(front);
	  front = dummy;
	}
      tam++;
     }
      catch(std::bad_alloc& ba)
    {
      std::cerr << ba.what() << std::endl;
      exit(1);
    }
  }
    
}

template <class T2>
T2 pila<T2>::pop(void) {

  if(empty()) {
    
    std::cout << "La pila ya está completamente vacia" << std::endl;
    
  } else  {
    
	if(front==rear) {
	  mynodo<T2>* aux = front;
	  front = NULL;
	  rear = NULL;
	  tam--;
	  return (aux->get_dato());
    
	} else {
  
	  mynodo<T2>* aux=front;
	  front = front->get_next();
	  tam--;
	  return (aux->get_dato());
    
	}
  }
  
}

template <class T2>
void pila<T2>::escribir(void) {
  
  
  mynodo<T2>* aux = front;
  
  while(aux != NULL) {
  
    std::cout << aux->get_dato() << " ";
    aux= aux->get_next();
  }
  
  std::cout << std::endl;
  
  //std::cout << tam << std::endl;
}

template <>
std::ostream& pila<numero_t*>::imprime_ptr_numero(std::ostream& os)
{
  mynodo<numero_t*>* aux = front;
  
  while(aux != NULL) {
  
    aux->get_dato()->toStream(os);
    cout<< " ";
    aux= aux->get_next();
  }
  
}

