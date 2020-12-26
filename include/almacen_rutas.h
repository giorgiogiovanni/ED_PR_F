/**
 * @file    almacen_rutas.h
 * @brief   Cabeceras e Implementacion de la clase Almacen de Rutas
 * @date    Dic-2020
 * @author  JorgeBG
 */


#ifndef __ALMACEN_RUTAS_H__
#define __ALMACEN_RUTAS_H__

#define PASSWORD "#Rutas"
#include <string>
#include <iostream>
#include <list>
#include "Ruta.h"

using namespace std;


class Almacen_Rutas {
    private:
        /// Dato miembro @p rutas con una lista STL de RutaAerea
        list<RutaAerea> rutas;

        /**
         * @brief   Metodo privado para eliminar todo;
         */
        void Delete() { 
            if(!(rutas.empty()))
                rutas.clear();
        }

    public:
        Almacen_Rutas() { rutas = list<RutaAerea>(); }
        Almacen_Rutas(const Almacen_Rutas &otras);
        // ~Almacen_Rutas();

        int size() { return rutas.size(); }

        void addRuta(const RutaAerea &r) {
            rutas.push_back(r);
        }

        RutaAerea GetRuta(const string &cod) const {

        }

        /**
         * Clase Iteradora de Almacen_Rutas
         */
        class iterator {
        private:
            list<RutaAerea>::iterator it;
        public:
            iterator() {};
            
            iterator &operator++() { 
                ++it;
                return *this;
            }

            iterator &operator--() {
                --it;
                return *this;
            }

            const RutaAerea &operator*() {
                return *it;
            }
            
            bool operator==(const iterator it2) {
                return (it == it2.it);
            }

            bool operator!=(const iterator it2) {
                return (it != it2.it);
            }

            friend class Almacen_Rutas;
        };

        class const_iterator {
        private:
            list<RutaAerea>::const_iterator it;
        public:
            const_iterator() {};

            const_iterator &operator++() {
                ++it;
                return *this;
            }
            
            const_iterator &operator--() {
                --it;
                return *this;
            }

            const RutaAerea &operator*() {
                return *it;
            }

            bool operator==(const const_iterator &it2) const {
                return (it == it2.it);
            }

            bool operator!=(const const_iterator &it2) const {
                return (it != it2.it);
            }

            friend class Almacen_Rutas;
        };

    iterator begin() {
        iterator i;
        i.it = rutas.begin();
        return i;
    };

    iterator end() {
        iterator i;
        i.it = rutas.end();
        return i;
    };

    const_iterator begin() const {
        const_iterator i;
        i.it = rutas.begin();
        return i;
    };

    const_iterator end() const {
        const_iterator i;
        i.it = rutas.end();
        return i;
    };

    /**
     * @brief   Metodo Friend de lectura de almacen de rutas
     */
    friend istream &operator>> (istream &is, Almacen_Rutas &alm) {
        string a;
        RutaAerea temp;
        is >> a;
    cout << "Iniciado" << endl << "leido: " << a << endl;
        if (a != PASSWORD){
            cerr << "Error en PASSWORD de archivo o entrada de datos" << endl;
        }
        else {
            while(is) {
                is >> temp;
                cout << "LEIDA RUTA:\t" << temp << endl;
                alm.rutas.push_back(temp);
            }
        }
        return is;
    };

    friend ostream &operator<< (ostream &os, Almacen_Rutas &alm) {
        os << PASSWORD << endl;
        Almacen_Rutas::iterator it;
        for (it = alm.begin(); it!= alm.end(); ++it) {
            os << (*it) << endl;
        }

        return os;
    }
};

#endif