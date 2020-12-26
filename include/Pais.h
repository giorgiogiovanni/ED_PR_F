/**
 * @file    Pais.h
 * @author  Dpto. Ciencias de la Computacion e I.A.
 * @brief   Archivo con cabeceras para la clase Pais
 */

#ifndef __PAIS__
#define __PAIS__

#include "Punto.h"

/**
 * @brief   Clase para T.D.A. Pais
 */
class Pais{
  private:
    /// Punto de referencia
    PuntoE p;
    /// Nombre del Pais
    string pais;
    /// Nombre del archivo con la bandera del pais
    string bandera;
    
  public:
    Pais(){}
    PuntoE GetPunto()const { return p;}
    string GetPais()const{ return pais;}
    string GetBandera()const{ return bandera;}
    
    bool operator<(const Pais &P)const{
	return pais<P.pais;
    }	
    bool operator==(const Pais &P)const{
	return pais==P.pais;
    }
     bool operator==(const PuntoE &P)const{
	return p==P;
    }

    friend istream & operator>>(istream & is, Pais & P){
        double lat,lng;
	
	    is>>lat>>lng>>P.pais>>P.bandera;

        // P.p=PuntoE(lat,lng,"");
        // Cambio para adaptar a nuestro constructor
	    P.p=PuntoE(lat,lng);
	    return is;
    }
    
    friend ostream & operator<<(ostream & os, const Pais &P){
	    os<<P.p<<" "<<P.pais<<" "<<P.bandera<<endl;
	    return os;
    }
};

#endif