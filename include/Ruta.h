/**
 * @file    Ruta.h
 * @brief   Cabeceras e Implementacion de la clase RutaAerea
 * @date    Dic-2020
 * @author  JorgeBG
 */

#ifndef __RUTA_AEREA__
#define __RUTA_AEREA__

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <unistd.h>
#include "Punto.h"

using namespace std;

/**
 * @brief   T.D.A. Ruta Aerea en base a STL Vector
 */
class RutaAerea{
private:
    /// Nombre de la Ruta aerea
    string name;
    /// Lista con los puntos por los que pasa una ruta 
    vector<PuntoE> ruta;
    
    /**
     * @brief   Metodo privado para borrar datos del objeto
     */
    void Delete() {
        this->name = "";
        if(!(ruta.empty())) ruta.clear();
    }

    /**
     * @brief   Metodo privado para copiar los datos de otro objeto en @e this
     */
    void Copy( const RutaAerea &otra) {
        Delete();
        this->name = otra.name;
        
        vector<PuntoE>::const_iterator it;
        for(it=otra.ruta.begin(); it!=otra.ruta.end(); it++){
            ruta.push_back(*it);
        }
    }

public:
    /**
     * @brief   Constructor por defecto
     */
    RutaAerea() {
        name = "";
        ruta = vector<PuntoE>();
    }

    /**
     * @brief   Constructor de copia
     * @param   otra    Otro objeto RutaAerea desde el que copiar
     */
    RutaAerea(const RutaAerea &otra) { Copy(otra); }

    RutaAerea (const string &name, const vector<PuntoE> &vpunt ){
        Delete();
        this->name = name;
        this->ruta.insert(ruta.begin(),vpunt.begin(),vpunt.end());
    }


/* 
    ~RutaAerea() { Delete; } 
*/

    /**
     * @brief   Metodo de consulta del tamaño de la RutaAerea
     * @return  Numero de puntos que contiene la RutaAerea
     */
    int size() {  return ruta.size(); }

    /**
     * @brief   Consultor del nombre de una RutaAerea
     * @return  un dato @c string con el nombre asignado a la Ruta
     */
    string getName() {  return name; }

    /**
     * @brief   Consultor del PuntoE en una posicion (indice) concreto
     * @param   i   indice a consultar
     * @return  dato PuntoE en el indice @p i
     * @pre     0 <= @p i < size()
     */
    PuntoE getPunto( const int &i ) { return ruta.at(i); }

    /**
     * @brief   Modificador para un punto concreto en la RutaAerea
     * @param   punto   PuntoE a colocar en dicha posicion
     * @param   i   indice en el que insertar
     * @return  @c true si se puede insertar, @c false si no
     */
    bool setPunto( const PuntoE &punto, const int i) {
        bool cond = (i >= 0 && i < size() );
        if(cond){
            ruta.at(i).setPunto(punto.getLat(), punto.getLon());
        }
        return cond;
    }

    /**
     * @brief   Metodo para añadir un punto al final de la ruta
     * @param   p   PuntoE a añadir
     */
    void addPunto(const PuntoE &p) {
        ruta.push_back(p);
    }

    /**
     * Clase Iteradora de RutaAerea
     */
    class iterator {
    private:
        vector<PuntoE>::iterator it;
    public:
        iterator() {};

        iterator &operator++() {
            ++it;
            return *this;
        };

        iterator &operator--() {
            --it;
            return *this;
        }

        const PuntoE &operator*() { return *it; }

        bool operator==(const iterator &it2) const {
            return  (it == it2.it);
        }

        bool operator!=(const iterator &it2) const {
            return  (it != it2.it);
        }

        friend class RutaAerea;
    };

    /**
     * Clase Iteradora constante de RutaAerea
     */
    class const_iterator {
    private:
        vector<PuntoE>::const_iterator it;
         
    public:
        const_iterator() {};

        const_iterator &operator++() {
            ++it;
            return *this;
        };

        const_iterator &operator--() {
            --it;
            return *this;
        }

        const PuntoE &operator*() { return *it; }

        bool operator==(const const_iterator &it2) const {
            return  (it == it2.it);
        }

        bool operator!=(const const_iterator &it2) const {
            return  !(*this == it2);
        }

        friend class RutaAerea;
    };

    iterator begin() {
        iterator i;
        i.it = ruta.begin();
        return i;
    }

    iterator end() {
        iterator i;
        i.it = ruta.end();
        return i;
    }

    const_iterator begin() const {
        const_iterator i;
        i.it = ruta.begin();
        return i;
    }

    const_iterator end() const {
        const_iterator i;
        i.it = ruta.end();
        return i;
    }

    /**
     * @brief   Metodo friend E de Ruta [Sobrecarga operador >> ]
     */
    friend istream &operator>> (istream &is, RutaAerea &r) {
        string cad;
        int np;
        PuntoE ptemp;

        r.Delete();

        // leemos nombre
        is >> cad;
        if(cad != ""){
            r.name = cad;
            // numero puntos
            is >> np;

            for(int i=0; i<np; i++) {
                // lectura y guardado de puntos
                is >> ptemp;
                r.addPunto(ptemp);
            }
        }

        return is;
    };

    /**
     * @brief   Metodo friend S de Ruta [Sobrecarga operador << ]
     */
    friend ostream &operator<<(ostream &os, const RutaAerea &r) {
        os  << r.name << " "
            << r.ruta.size() << " ";
            
        const_iterator it;
        for(it = r.begin(); it != r.end(); ++it ) {
            os << (*it) << " ";
        }

        return os;
    };

};

#endif