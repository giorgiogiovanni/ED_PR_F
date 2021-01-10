PRACTICA FINAL ESTRUCTURA DE DATOS


Autores:
-------------------------------------------------
    - Jorge Bailon Gonzalez
    - Rafa Cano Exposito

Proyecto final para asignatura de E.D.2020-2021


USO DEL PROYECTO:
-------------------------------------------------
Existen 2 archivos para probar la lectura de la clase Ruta y de la clase Almacen_Rutas
para ello también existen los archivos ruta1.txt (consiste en una unica ruta para su lectura)
y el archivo almacen_rutas.txt (para leer una serie de rutas y crear la instancia de la clase)

 * PRUEBA RUTA
    make pruebaruta
    ejecutar:   ./bin/pruebaruta datos/ruta1.txt

 * RUTAS
    make rutas
    ejecutar:  ./bin/rutas datos/almacen_rutas.txt 

Finalmente el proyecto definitivo se realiza mediante la rutina [ rutas_aereas ]

 * RUTAS AEREAS_ FINAL

    make rutas_aereas
    ejectuar:   ./bin/rutas_aereas <... parametros ...>
        
    PARAMETROS:
    1  Fichero con la informacion de los paises
    2  Nombre de la imagen con el mapa del mundo
    3  Directorio con las banderas
    4  Fichero con el almacen de rutas
    5  Nombre de la imagen con el avion
    6  Nombre de la imagen de la mascara del avion
    
    Existe tambien una rutina preparada:
    make exe
    Esta rutina ejecutará el programa con una serie de archivos previamente seleccionados

DIARIO:
-------------------------------------------------

0.  Primer análisis y diseño de la practica     Jorge y Rafael
1.  Implementacion de Punto.h                   Jorge
2.  Primera implementacion de Ruta.h            Rafael
3.  Creación pruebaruta.cpp                     Rafael
        para probar la lectura
4.  Primera implementacion de AlmacenRutas.h    Jorge
5.  Creación pruebarutas.cpp                    Jorge
        para probar la lectura
6.  Rectificacion de implmentaciones            Jorge y Rafael
        Ruta.h y AlmacenRutas.h Jorge y Rafael
        Aquí se rectificaron los tipos de la STL utilizados internamente en los TDA según comentamos por correo

7.  Revisión de rutas_aereas.cpp                Rafael
        para uso con nuestros espacios de nombres de los TDAs

8.  Corrección Documentacion final              Rafael
9.  Complementar Makefile                       Jorge
10. Revision README.md (github sintaxis)        Jorge
        y README.txt (explicativo)
