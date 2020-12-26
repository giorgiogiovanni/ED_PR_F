#include "Ruta.h"
#include "almacen_rutas.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(int argc, char * argv[]){
  if (argc!=2){
    cout<<"Dime el nombre del fichero de entrada"<<endl;
    return 0;
  }
  ifstream f(argv[1]);
  if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }
  
  Almacen_Rutas A;
  f>>A; //leemos las rutas y los puntos de interes

  cout << "PRIMERA RUTA:" << endl;
  cout << (*A.begin()).second << endl << endl;

  cout << "LEIDAS las rutas del archivo: " << endl;
  cout << A << endl << endl;
  
}
  