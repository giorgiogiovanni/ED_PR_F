/**
 * @file    Punto.h
 * @brief   Cabeceras e Implementacion de la clase Punto Esferico (Latitud, Longitud)
 * @date    Dic-2020
 * @author  JorgeBG
 */

#ifndef __PUNTO_E__
#define __PUNTO_E__

#include <iostream>
#include <iomanip>
using namespace std;

#define INI '('
#define FIN ')'
#define SEP ','

/**
 * @brief   T.D.A. PuntoE (Punto Esferico en Coordenadas Angulares)
 */
class PuntoE {
private:
    /// Valor Latitud del Punto Esferico
    double  lat;
    /// Valor Longitud del Punto esferico
    double  lon;

public:
    
    /**
     * @brief   Constructor por defecto
     * @post    objeto Punto con valores latitud=0, longitud=0
     */
    PuntoE() { lon=lat=0;};

    /**
     * @brief   Constructor con valores
     * @param   lat    Valor inicial @e latitud del punto
     * @param   lon    Valor inicial @e longitud del punto
     */
    PuntoE(const double &lat, const double &lon) {
        this->lat = lat;
        this->lon = lon;
    }

    /**
     * @brief   Constructor de copia
     * @param   otro    Intancia de @e Punto del que copiar
     */
    PuntoE( const PuntoE &otro ) {
        this->lat = otro.lat;
        this->lon = otro.lon;
    }

    // METODOS PUBLICOS SETTERS Y GETTERS

    /**
     * @brief   Modificador valor @p lat
     * @param   lat  Nuevo valor para dato miembro @p lat
     */
    void setLat (const double &lat) {
        this->lat = lat;
    }

    /**
     * @brief   Modificador valor @p lon
     * @param   lon  Nuevo valor para dato miembro @p lon
     */
    void setLon (const double &lon) {
        this->lon = lon;
    }

    /**
     * @brief   Modificador valores @p lat @e latitud y @p lon @e longitud
     * @param   lat  Nuevo valor para dato miembro @p lat
     * @param   lon  Nuevo valor para dato miembro @p lon
     */
    void setPunto (const double &lat, const double &lon ){
        this->lat = lat;
        this->lon = lon;
    }

    /**
     * @brief   Consultor del valor @p lat @e latitud
     */
    double getLat () const { return this->lat; }

    /**
     * @brief   Consultor del valor @p lon @e longitud
     */
    double getLon () const { return this->lon; }


    bool operator==(const PuntoE &p) const {
        bool res = (lat == p.lat) && (lon == p.lon);
        return res;
    }

    bool operator!=(const PuntoE &p) const {
        bool res = (lat != p.lat) || (lon != p.lon);
        return res;
    }

    /**
     * @brief   Metodo friend escritura Punto [ Sobrecarga Operador << ]
     */
    friend ostream &operator<< (ostream &os, const PuntoE &p) {
        os << INI << setprecision(16) << p.lat << SEP << p.lon << FIN;
        return os;
    }

    /**
     * @brief   Metodo friend lectura Punto [ Sobrecarga Operador >> ]
     */
    friend istream &operator>> (istream &is, PuntoE &p) {
        char l;
        double plat, plon;
        
        is >> l;
        //revisar esto
        if (l!= INI)    EXIT_FAILURE;
        is >> plat;
        is >> l;
        if (l!= SEP)    EXIT_FAILURE;
        is >> plon;
        is >> l;
        if (l!= FIN)    EXIT_FAILURE;

        p.setPunto(plat,plon);
        return is;
    }
};

#endif