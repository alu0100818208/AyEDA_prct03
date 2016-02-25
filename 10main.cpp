#include "1natural.hpp"
#include "2entero.hpp"
#include "3racional.hpp"
#include "4real.hpp"
#include "5complejo.hpp"
#include "6vector.hpp"
#include "7lista.hpp"
#include "8pila.hpp"
#include "9cola.hpp"


int main()
{
  //DECLARAMOS LOS CONTENEDORES DE TIPO NUMERO*
  myvector<numero_t*> v1(5);
  pila<numero_t*> p1;
  cola<numero_t*> c1;
  listilla<numero_t*> l1;
  
  //AHORA COMENZAREMOS A INTRODUCIR DISTINTOS TIPOS DE NUMEROS EN LOS CONTENEDORES
  
  
    v1[0] = new natural(1);			//METEMOS UN NATURAL (1) EN LA POSICIÓN 0 DEL VECTOR
    p1.push(new natural(1));			//METEMOS UN NATURAL (1)
    c1.push(new natural(1));			//METEMOS UN NATURAL (1)
    l1.insertar_inicio(new natural(1));		//METEMOS UN NATURAL (1)
    l1.insertar_final(new natural(1));		//METEMOS UN NATURAL (1)
    
    v1[1] = new entero(-2);			//METEMOS UN ENTERO (-2) EN LA POSICIÓN 1 DEL VECTOR
    p1.push(new entero(-2));			//METEMOS UN ENTERO (-2)
    c1.push(new entero(-2));			//METEMOS UN ENTERO (-2)
    l1.insertar_inicio(new entero(-2));		//METEMOS UN ENTERO (-2)
    l1.insertar_final(new entero(-2));		//METEMOS UN ENTERO (-2)
    
    v1[2] = new racional(25,35);		//METEMOS UN RACIONAL (25_35) EN LA POSICIÓN 2 DEL VECTOR
    p1.push(new racional(25,35));		//METEMOS UN RACIONAL (25_35)
    c1.push(new racional(25,35));		//METEMOS UN RACIONAL (25_35)
    l1.insertar_inicio(new racional(25,35));	//METEMOS UN RACIONAL (25_35)
    l1.insertar_final(new racional(25,35));	//METEMOS UN RACIONAL (25_35)
    
    v1[3] = new real(3.14);			//METEMOS UN REAL (3.14) EN LA POSICIÓN 3 DEL VECTOR
    p1.push(new real(3.14));			//METEMOS UN REAL (3.14)
    c1.push(new real(3.14));			//METEMOS UN REAL (3.14)
    l1.insertar_inicio(new real(3.14));		//METEMOS UN REAL (3.14)
    l1.insertar_final(new real(3.14));		//METEMOS UN REAL (3.14)
    
    v1[4] = new complejo(2.5,-5.4);		//METEMOS UN COMPLEJO (2.5+-5.4i) EN LA POSICIÓN 4 DEL VECTOR
    p1.push(new complejo(2.5,-5.4));		//METEMOS UN COMPLEJO (2.5+-5.4i)
    c1.push(new complejo(2.5,-5.4));		//METEMOS UN COMPLEJO (2.5+-5.4i)
    l1.insertar_inicio(new complejo(2.5,-5.4));	//METEMOS UN COMPLEJO (2.5+-5.4i)
    l1.insertar_final(new complejo(2.5,-5.4));	//METEMOS UN COMPLEJO (2.5+-5.4i)
    
    v1.imprime_ptr_numero(cout);
    cout << endl;
    
    p1.imprime_ptr_numero(cout);
    cout << endl;
    
    c1.imprime_ptr_numero(cout);
    cout << endl;
  
    l1.imprime_ptr_numero(cout);
    cout << endl;
    
    
    return 0;
}