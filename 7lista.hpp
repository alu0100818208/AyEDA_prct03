#include "0nodo.hpp"
#include <cstdlib>
#include "0numero.hpp"

//DEFINICIÓN DE LA CLASE
template <class T2>
class listilla {

    mynodo<T2>* front;
    mynodo<T2>* rear;
    unsigned int tam;
  
  public:
    listilla(void);
    ~listilla(void);
    
    void insertar_inicio(T2 elemento);
    T2 extraer_inicio(void);
    void insertar_final(T2 elemento);
    T2 extraer_final(void);
    void insertar_vacio(T2 elemento);
   
    bool empty(void);
    void escribir(void);
    std::ostream& imprime_ptr_numero(std::ostream& os);
    void insertar_despues(T2 elemento, unsigned int pos);
    T2 extraer(unsigned int pos);
    void edicion(T2 dato, unsigned int pos);
};


//IMPLEMENTACION DE LAS FUNCIONES
template <class T2>
listilla<T2>::listilla(void):
front(NULL),
rear(NULL),
tam(0)
{}

template <class T2>
listilla<T2>::~listilla(void) {

  mynodo<T2>* aux = front;
  while(front!=NULL) {
  
    front = front->get_next();
    delete aux;
    aux=front;
    
  }
  
}  

template <class T2>
bool listilla<T2>::empty(void) {

  return(front == NULL ? true : false);
  
}

template <class T2>
void listilla<T2>::insertar_vacio(T2 elemento) {
  
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
void listilla<T2>::insertar_inicio(T2 elemento) {

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
T2 listilla<T2>::extraer_inicio(void) {

  if(empty()) {
    
    std::cout << "La lista ya está completamente vacia" << std::endl;
    
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
void listilla<T2>::insertar_final(T2 elemento) {
  
   try
    {
      mynodo<T2>* dummy = new mynodo<T2>(elemento); 
      
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

template <class T2>
T2 listilla<T2>::extraer_final(void) {
  
  if(empty()) {
    
    std::cout << "La lista ya está completamente vacia" << std::endl;
    
  } else {
  
	if(front==rear) {
    
	  mynodo<T2>* aux = front;
	  front = NULL;
	  rear = NULL;
	  tam--;
	  return (aux->get_dato());
    
	} else {
  
	  mynodo<T2>* aux=front;
    
	  while(aux->get_next() != rear) {
    
	    aux=aux->get_next();
      
	  }
    
	  rear = aux;
	  aux = aux->get_next();
	  rear->set_next(NULL);
    
	  tam--;
	  return (aux->get_dato());
    
	 }
  }
  
}

template <class T2>
void listilla<T2>::escribir(void) {
  
  
  mynodo<T2>* aux = front;
  
  while(aux != NULL) {
  
    std::cout << aux->get_dato() << " ";
    aux= aux->get_next();
  }
  
  std::cout << std::endl;
  
  //std::cout << tam << std::endl;
}


template <class T2>
void listilla<T2>::insertar_despues(T2 elemento, unsigned int pos) {
 
  if(pos == 0){
  
    insertar_inicio(elemento);
    
  } else { if(pos==tam-1) {
  
    insertar_final(elemento);
    
    } else { if(pos>tam-1) {
      
      std::cout << "ERROR, la posición solicitada es mayor que el tamaño de la lista" << std::endl;
      std::cout << "Si quiere expandirla por los extremos insete al final o al principio" << std::endl;
      
      } else {
      
	try
	{
	  mynodo<T2>* dummy = new mynodo<T2>(elemento); 
	
	  mynodo<T2>* aux = front;
	  unsigned int i;
	  
	  for(i=1;i<pos;i++){
	
	  aux = aux->get_next();
	  
	  }
	
	  dummy->set_next(aux->get_next());
	  aux->set_next(dummy);
	  tam++;
	} 
	catch(std::bad_alloc& ba)
	{
	  std::cerr << ba.what() << std::endl;
	  exit(1);
	}
	
	
      }
  
    }
  }
  
}

template <class T2>
T2 listilla<T2>::extraer(unsigned int pos) {

  if(empty()) {
    
    std::cout << "La lista ya está completamente vacia" << std::endl;
    
  } else {
  
	if(pos == 0){
  
	  return(extraer_inicio());
    
	} else { if(pos==tam-1) {
  
	  return(extraer_final());
    
	  } else { if(pos>tam-1) {
      
	    std::cout << "ERROR, la posición solicitada es mayor que el tamaño de la lista" << std::endl;
      
	    } else {
      
	      mynodo<T2>* aux = front;mynodo<T2>* aux2=front;
	      unsigned int i,j;
	      for(i=1;i<pos;i++){
	
		aux = aux->get_next();
	  
	      } for(j=1;j<pos-1;j++) {
	
		aux2 = aux2->get_next();
	  
	      }
	
	      aux2->set_next(aux->get_next());
	      tam--;
	      return (aux->get_dato());
	
	    }
  
	  }
	}
	
   }
  
}

template <class T2>
void listilla<T2>::edicion(T2 dato, unsigned int pos) {

  if((pos<tam-1) || (pos<0)) {
      
      std::cout << "ERROR, la posición solicitada es mayor que el tamaño de la lista" << std::endl;
      
  } else {
      
	mynodo<T2>* aux = front;
	unsigned int i;
	for(i=1;i<pos;i++){
	
	  aux = aux->get_next();
	  
	}
	
	aux->set_dato(dato);
	
      }
  
}


template <>
std::ostream& listilla<numero_t*>::imprime_ptr_numero(std::ostream& os)
{
  mynodo<numero_t*>* aux = front;
  
  while(aux != NULL) {
  
    aux->get_dato()->toStream(os);
    cout<< " ";
    aux= aux->get_next();
  }
  
}