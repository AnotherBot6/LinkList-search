#include <cstddef>
#include <fstream>
#include <iostream>
#include <sstream>
#include <time.h>
#define NOMBRE_ARCHIVO "bitacora.csv"
using namespace std;
#include "city.h"
#include "lista.h"
#include "persona.h"
#include "task.h"


void Regresion();
template <typename T> void swap(T *a, T *b);


template <typename T,typename S> int partition(T arr[], S copyarr[], int low, int high);

template <typename T, typename S> void quickSort(T arr[], S copyarr[], int low, int high); 

int BusquedaBin(string Copy[], string dato, int searchFirst);



void opcion1(string arr[], string Original[]);

void opcion2(Persona<string> personas[10000]);

void opcion3(string arr[], string Original[]);

void opcion4(string Copy[], string Original[]);

void opcion5(string Copy[], string Original[]);


void menu();

int main() {

  menu();

  return 0;
}

template <typename T> void swap(T *a, T *b) {
  T t = *a;
  *a = *b;
  *b = t;
}

template <typename T,typename S> int partition(T arr[], S copyarr[], int low, int high) {
  T pivot = arr[high]; // pivot
  int i = (low - 1);   // Index of smaller element and indicates
                       // the right position of pivot found so far
  for (int j = low; j <= high - 1; j++) {
    // If current element is smaller than the pivot
    if (arr[j] < pivot) {
      i++; // increment index of smaller element
      swap(&arr[i], &arr[j]);
      swap(&copyarr[i], &copyarr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  swap(&copyarr[i + 1], &copyarr[high]);

  return (i + 1);
}
template <typename T, typename S> void quickSort(T arr[], S copyarr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, copyarr, low, high);

    // Separately sort elements before
    // partition and after partition
    quickSort(arr, copyarr, low, pi - 1);
    quickSort(arr, copyarr, pi + 1, high);
  }
}


int BusquedaBin(string Copy[], string dato, int searchFirst) {
  int inf, sup, mitad, i;

  // Algoritmo de la Busqueda Binaria
  inf = 0;
  sup = 10000;
  i = 0;
  int result = -1;
  while ((inf <= sup) && (i < 10000)) {
    
    mitad = (inf + sup) / 2;
    if (Copy[mitad] == dato) {
      result = mitad;
      // seguir buscando hacia la izquierda (índices inferiores)
      if (searchFirst) {
        sup = mitad - 1;
      }
      // seguir buscando hacia la derecha (índices más altos)
      else {
        inf = mitad + 1;
      }
    }
    if (Copy[mitad] > dato) {
      sup = mitad;
      mitad = (inf + sup) / 2;
    }
    if (Copy[mitad] < dato) {
      inf = mitad;
      mitad = (inf + sup) / 2;
    }
    i++;
  }
  return result;
}




/*
O(3n+nlogn)
peor caso = O(n^2*log n)
*/
void opcion1(string arr[], string Original[]){
  LinkedList<string> Per1;
  //Extraer el valor de las ciudades
  for (int i = 0; i < 10000; i++) {
    int pos = arr[i].find(" ");

    arr[i] = arr[i].substr(pos + 1);

    int pos2 = arr[i].find(" ");
    arr[i] = arr[i].substr(pos2 + 1);

    int pos3 = arr[i].find(" ");
    arr[i] = arr[i].substr(pos3 + 1);

    int pos4 = arr[i].find(" ");
    arr[i] = arr[i].substr(pos4 + 1);
  }


  // metodo de ordenamiento
  quickSort(arr, Original, 0, 10000);

  //Busqueda de personas en cada ciudad
  string Starter =arr[0];
  int counter = 1;
  string persons[10000];
  int p[10000];
  string x;
  for(int i=0; i<10000; i++){
    if(Starter==arr[i]){
      counter++;
    }
    else if(Starter!=arr[i]){
      //if(Starter!=""){
        x=to_string(counter);
        persons[i]=x+" "+Starter;
        p[i]=counter;
        //cout<<Starter<<" Tiene "<<counter<<" Personas"<<endl;
        Starter = arr[i];
        counter =1;
      //}
    }
  }
  //Guardar informacion de la ciudad y habitantes 
  
  string com[3675];
  int com2[3675];
  int cont=0;
  for(int i=0; i<10000; i++){
    if(persons[i]!=""){
      com[cont]=persons[i];
      com2[cont]=p[i];
      //cout << persons[i] << endl;
      cont++;
    }
  }
  // metodo de ordenamiento
  quickSort(com2, com, 0, 3675);

  for (int i = 1; i < 3676; i++) {
    Per1.addFirst(com[i]);
  }
  //Per1.print();

  //Imprimir los resultados
  cout << endl;
  cout << "Las 5 ciudades con mayor numero de poblacion: " << endl;
  cout << Per1.get(0) << endl;
  cout << Per1.get(1) << endl;
  cout << Per1.get(2) << endl;
  cout << Per1.get(3) << endl;
  cout << Per1.get(4) << endl;

  
  //Volver al menu
  //Regresion();
};





/*
O(n)
peor caso = O(n)
*/
void opcion2(Persona<string> personas[10000]) {
  int counter = 0;
  string nombre;
  cout << "Primer Nombre: ";
  cin >> nombre;
  for (int i = 0; i < 10000; i++) {
    if (nombre == personas[i].getFirstName()) {
      counter++;
    }
  }

  cout << "el nombre se repite: " << counter << endl;

  //Regresion();
}






/*
// O(3n+nlog(n))
//peor caso = O(3n+n^2)
*/
void opcion3(string arr[], string Original[]){
  LinkedList<string> Per1;
  for (int i = 0; i < 10000; i++) {
    int pos = arr[i].find(" ");

    arr[i] = arr[i].substr(pos + 1);

    int pos2 = arr[i].find(" ");
    arr[i] = arr[i].substr(pos2 + 1);

    int pos3 = arr[i].find(" ");
    arr[i] = arr[i].substr(pos3 + 1);

    int pos4 = arr[i].find(" ");
    arr[i] = arr[i].substr(pos4 + 1);
  }

  // string arr[] = array de solo ciudades
  // string Original[] = array completo

  quickSort(arr, Original, 0, 10000);
  for (int i = 0; i < 10000; i++) {
    Per1.addLast(Original[i]);
  }


  string Starter =arr[0];
  int counter = 1;
  
  for(int i=0; i<10000; i++){
    if(Starter==arr[i]){
      counter++;
    }
    else if(Starter!=arr[i]){
      //if(Starter!=""){
        
        cout<<Starter<<" Tiene "<<counter<<" Personas"<<endl;
        Starter = arr[i];
        counter =1;
      //}
    }
  }
  //Regresion();
}




/*
¿Qué método de ordenamiento utilizarás y por qué?
Haciendo una investigacion sobre cuales son los algoritmos de ordenamiento de mayo eficacia nos topamos que el alritmo de quick sort, viene muy bien para ordenar una gran cantidad de datos
El algoritmo trabaja de la siguiente forma:

Elegir un elemento del conjunto de elementos a ordenar, al que llamaremos pivote.
Resituar los demás elementos de la lista a cada lado del pivote, de manera que a un lado queden todos los menores que él, y al otro los mayores. Los elementos iguales al pivote pueden ser colocados tanto a su derecha como a su izquierda, dependiendo de la implementación deseada. En este momento, el pivote ocupa exactamente el lugar que le corresponderá en la lista ordenada.
La lista queda separada en dos sublistas, una formada por los elementos a la izquierda del pivote, y otra por los elementos a su derecha.
Repetir este proceso de forma recursiva para cada sublista mientras éstas contengan más de un elemento. Una vez terminado este proceso todos los elementos estarán ordenados.

La complejidad en el mejor de los casos seria de O(n*log(n)), en le peor caso seria O(n^2) y el caso promedio seria O(n*log(n))
*/
void opcion4(string Copy[], string Original[]) {
  LinkedList<string> Per1;
  for (int i = 0; i < 10000; i++) {
    int pos = Copy[i].find(" ");

    Copy[i] = Copy[i].substr(pos + 1);

    int pos2 = Copy[i].find(" ");
    Copy[i] = Copy[i].substr(pos2 + 1);

    int pos3 = Copy[i].find(" ");
    Copy[i] = Copy[i].substr(0, pos3);
  }

  // string arr[] = {"f", "e", "d", "a", "c", "b"};

  quickSort(Copy, Original, 0, 10000);
  cout << "Sorted array: \n";
  for (int i = 0; i < 10000; i++) {
    Per1.addLast(Original[i]);
  }

  Per1.print();

  
  //Regresion();
}
// O(nlog(n)+2n)
//peor caso = O(3n+n^2)






/*
La complejidad en el mejor de los casos seria de O(n), en le peor caso seria O(n^2) y el caso promedio seria O(n)
*/
void opcion5(string Copy[], string Original[]) {
  
  for (int i = 0; i < 10000; i++) {
    int pos = Copy[i].find(" ");

    Copy[i] = Copy[i].substr(pos + 1);

    int pos2 = Copy[i].find(" ");
    Copy[i] = Copy[i].substr(pos2 + 1);

    int pos3 = Copy[i].find(" ");
    Copy[i] = Copy[i].substr(0, pos3);
  }

  quickSort(Copy, Original, 0, 10000);
   cout << "Sorted array: \n";
  
LinkedList<string> Per1;
  for (int i = 0; i < 10000; i++) {
    Per1.addLast(Original[i]);
  }

  Per1.print();
      

  string dato;

  cout << "Escriba el apellido a buscar: " << endl;

  cin >> dato;
  
  for (int i = 0; i < dato.length(); i++) {
    // Y cambiar cada letra por su representación
    // minúscula
    dato[i] = tolower(dato[i]);
  }

  int first = BusquedaBin(Copy, dato, 1);
  int last = BusquedaBin(Copy, dato, 0);

  
  //Imprimr todas las personas con el appelido introducido
  
  for (int i = first ; i <= last; i++) {
    cout << Original[i] << endl;
  }


  
  //Imprimr la primera persona encontrada
  
  //cout << Original[first] << endl;
  int count = last - first + 1;
  
  cout << "Numero de personas con apellido " << dato << " : " << count << endl;
  cout << endl;
  
  //Regresion();
};
//O(2n+log(n))
//peor caso = O(2n+n^2)



void menu() {
  ifstream archivo(NOMBRE_ARCHIVO);
  string linea;
  char delimitador = ',';
  // Leemos la primer línea para descartarla, pues es el encabezado
  getline(archivo, linea);
  // Leemos todas las líneas
  Persona<string> personas[10000];
  string Copy[10000];
  string Original[10000];
  int contador = 0;
  // Guardamos el csv en un objeto para luego pasarlo a una lista ligada
  while (getline(archivo, linea)) {
    stringstream stream(linea); // Convertir la cadena a un stream
    string id, first_name, last_name, ZIP, city;

    // Extraer todos los valores de esa fila

    getline(stream, id, delimitador);
    getline(stream, first_name, delimitador);
    getline(stream, last_name, delimitador);
    getline(stream, ZIP, delimitador);
    getline(stream, city, delimitador);
    // crear arreglo de personas
    personas[contador].SetPersona(id, first_name, last_name, ZIP, city);

    Copy[contador] =
        id + " " + first_name + " " + last_name + " " + ZIP + " " + city;
    Original[contador] =
        id + " " + first_name + " " + last_name + " " + ZIP + " " + city;
    contador++;
  }


  
  int expression;
  cout << "--------------------------------------------------------------------"
          "--------------------------"
       << endl;
  cout
      << "Programa que contiene una base de datos de personas y sus direcciones"
      << endl;
  cout << "Seleccione una opcion (digite solo el numero)" << endl;
  cout << endl;
  cout << "1 <-- ¿Cuáles son las cinco ciudades con mayor número de personas "
          "registradas?"
       << endl;
  cout << "2 <-- ¿Con qué frecuencia se repite un nombre en la lista ligada?"
       << endl;
  cout << "3 <-- ¿Cuántos habitantes existen por ciudad?" << endl;
  cout << "4 <-- Ordenar por apellido" << endl;
  cout << "5 <-- Búsqueda binaria para encontrar una persona" << endl;
  cout << "6 <-- Salir" << endl;
  cout << "Opcion : ";
  cin >> expression;

  switch (expression) {
  case 1:
    opcion1(Copy, Original);
    break;
  case 2:
    opcion2(personas);
    break;
  case 3:
    opcion3(Copy, Original);
    break;
  case 4:
    opcion4(Copy, Original);
    break;
  case 5:
    opcion5(Copy, Original);
    break;
  case 6:
    cout << "Fin del programa" << endl;
    break;
  default:
    cout << "---------------------------------------------" << endl;
    
    cout << "Opcion fuera de rango" << endl; 

        cout << "---------------------------------------------" << endl;
    
    //void menu();
    
    break;
    
  }
  archivo.close();
};
