## PRACTICA FINAL ESTRUCTURA DE DATOS

### Autores: 
* Jorge Bailon Gonzalez
* Rafa Cano Exposito

_Proyecto final para asignatura de E.D.2020-2021_

### Uso del proyecto:
Existen 2 archivos para probar la lectura de la clase Ruta y de la clase Almacen_Rutas
para ello también existen los archivos ruta1.txt (consiste en una unica ruta para su lectura)
y el archivo almacen_rutas.txt (para leer una serie de rutas y crear la instancia de la clase)

 * _PRUEBA RUTA_
    ```
    make pruebaruta
    ```
    ejecutar:   ./bin/pruebaruta datos/ruta1.txt

 * _RUTAS_
    ```
    make rutas
    ```
    ejecutar:  ./bin/rutas datos/almacen_rutas.txt 

Finalmente el proyecto definitivo se realiza mediante la rutina [ rutas_aereas ]

 * _RUTAS AEREAS_ FINAL
    ```
    make rutas_aereas
    ```
    ejectuar:   ./bin/rutas_aereas <... parametros ...>
        
        PARAMETROS:
         1. Fichero con la informacion de los paises
         2. Nombre de la imagen con el mapa del mundo
         3. Directorio con las banderas
         4. Fichero con el almacen de rutas
         5. Nombre de la imagen con el avion
         6. Nombre de la imagen de la mascara del avion
    Existe tambien una rutina preparada:
    make exe
    _Esta rutina ejecutará el programa con una serie de archivos previamente seleccionados_

### Diario:
