/**
 * @file    AlmacenRutas.h
 * @brief   Cabeceras e Implementacion de la clase Almacen de Rutas
 * @date    Dic-2020
 * @author  JorgeBG
 */


#ifndef __ALMACEN_RUTAS_H__
#define __ALMACEN_RUTAS_H__

#define PASSWORD "#Rutas"

#include <string>
#include <iostream>
#include <map>
#include "Ruta.h"

using namespace std;


class Almacen_Rutas {
    private:
        /// Dato miembro @p rutas con una map STL de RutaAerea
        map<string,RutaAerea> rutas;

        /**
         * @brief   Metodo privado para eliminar todo;
         */
        void Delete() { 
            if(!(rutas.empty()))
                rutas.clear();
        }

        /**
         * @brief   Metodo privado para copiar los datos de un map
         */
        void Copiar(const Almacen_Rutas &otro) {
            Delete();
            rutas.insert(otro.rutas.begin(),otro.rutas.end());
        }

    public:
        /**
         * @brief   Constructor por defecto
         */
        Almacen_Rutas() { rutas = map<string,RutaAerea>(); }

        /**
         * @brief   Constructor de copia
         * @param   otras   otro almacen desde el que copiar
         */
        Almacen_Rutas(const Almacen_Rutas &otras) {
            Copiar(otras);
        }
        
        /**
         * @brief   Metodo publico para limpiar el almacen
         */
        void clear() { Delete(); }

        /**
         * @brief   Metodo para consultar el tamaño del almacen
         * @return  valor @c int con el numero de rutas almacenadas
         */
        int size() { return rutas.size(); }

        /**
         * @brief   Metodo para almacenar una nueva ruta aerea
         */
        bool addRuta(const RutaAerea &r) {
            pair<map<string,RutaAerea>::iterator,bool> res;
            // emplace devuelve un pair con un iterador apuntando al
            // elemento insertado y un bool si ha sido posible insertarlo
            pair<string,RutaAerea> elem(r.getName(),r);
            res = rutas.emplace(elem);
            return res.second;
        }

        RutaAerea GetRuta(const string &cod) const {
            // find devuelve un puntero al pair donde second es 
            // la ruta aerea
            return (rutas.find(cod)->second);
        }

    /**************************************************************************/
    // CLASES ITERADORAS
    /**************************************************************************/

        /**
         * Clase Iteradora de Almacen_Rutas
         */
        class iterator {
        private:
            map<string,RutaAerea>::iterator it;
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

            const pair<const string,RutaAerea> &operator*() {
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
            map<string,RutaAerea>::const_iterator it;
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

            const pair<const string,RutaAerea> &operator*() {
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
     *          [ Sobrecarga del operador >> ]
     */
    friend istream &operator>> (istream &is, Almacen_Rutas &alm) {
        string a;
        RutaAerea temp;

        is >> a;
        if (a != PASSWORD){
            cerr << "Error en PASSWORD de archivo o entrada de datos" << endl;
        }
        else {
            while(is) {
                is >> temp;
                alm.addRuta(temp);
            }
        }
        return is;
    };

    /**
     * @brief   Metodo Friend de escritura de almacen de rutas 
     *          [ Sobrecarga del operador << ]
     */
    friend ostream &operator<< (ostream &os, Almacen_Rutas &alm) {
        os << PASSWORD << endl;
        Almacen_Rutas::iterator it;
        for (it = alm.begin(); it!= alm.end(); ++it) {
            os << (*it).second << endl;
        }

        return os;
    }
};

#endif