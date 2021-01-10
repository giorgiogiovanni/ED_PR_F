/**
 * @file    Ruta.h
 * @brief   Cabeceras e Implementacion de la clase RutaAerea
 * @date    Dic-2020
 * @author  JorgeBG & RafaelCE
 */

#ifndef __RUTA_AEREA__
#define __RUTA_AEREA__

#include <iostream>
#include <iomanip>
#include <string>
#include <list>
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
    list<PuntoE> ruta;
    
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
        
        list<PuntoE>::const_iterator it;
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
        ruta = list<PuntoE>();
    }

    /**
     * @brief   Constructor de copia
     * @param   otra    Otro objeto RutaAerea desde el que copiar
     */
    RutaAerea(const RutaAerea &otra) { Copy(otra); }

    RutaAerea (const string &name, const list<PuntoE> &puntos ){
        Delete();
        this->name = name;
        this->ruta.insert(ruta.begin(),puntos.begin(),puntos.end());
    }

    /**
     * @brief   Metodo de consulta del tamaño de la RutaAerea
     * @return  Numero de puntos que contiene la RutaAerea
     */
    int size() {  return ruta.size(); }

    /**
     * @brief   Consultor del nombre de una RutaAerea
     * @return  un dato @c string con el nombre asignado a la Ruta
     */
    string getName() const { return name; }

    /**
     * 
     */
    list<PuntoE> getPuntos() const {
        return ruta;
    }
    /**
     * @brief   Metodo para añadir un punto al final de la ruta
     * @param   p   PuntoE a añadir
     */
    void addPunto(const PuntoE &p) {
        ruta.push_back(p);
    }

    /**
     * @brief   Sobrecarga de operador ordenacion <. 
     *          Se considerará menor si su nombre es alfabeticamente anterior
     * @return  @c true si this.name ( @e lvalue ) es anterior a @e rvalue .name
     */
    bool operator<(const RutaAerea &r) const{
        return (this->name < r.name );
    }

    /**
     * @brief   Sobrecarga de orperador ordenacion >
     *          Se considerará mayor si su nombre es alfabeticamente posterior
     * @return  @c true si this.name ( @e lvalue ) es posterior a @e rvalue .name
     */
    bool operator>(const RutaAerea &r) const {
        return (this->name > r.name);
    }

    /**************************************************************************/
    // CLASES ITERADORAS
    /**************************************************************************/

    /**
     * Clase Iteradora de RutaAerea
     */
    class iterator {
    private:
        list<PuntoE>::iterator it;
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
        list<PuntoE>::const_iterator it;
         
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