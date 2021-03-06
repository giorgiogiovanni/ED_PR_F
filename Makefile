SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

	
rutas_aereas:
	g++ -g -o bin/rutasaereas -I./$(INC) $(SRC)/rutas_aereas.cpp $(SRC)/imagen.cpp $(SRC)/imagenES.cpp

pruebaruta:
	g++ -g -o bin/pruebaruta -I./$(INC) src/pruebaruta.cpp

rutas:
	g++ -g -o bin/rutas -I./$(INC) src/pruebarutas.cpp

# *********** Compresion del proyecto *******************
zip:	mrproper
	zip -r rutas_aereas.zip *
	# comentado para preservar archivos propios de e/s
	# zip -d rutas_aereas.zip "datos/*" "datos"

tgz:	mrproper
	tar zcv -f rutas_aereas.tgz *


# *********** Ejecución del programa ********************
exe:
	./bin/rutasaereas datos/paises.txt datos/imagenes/mapas/mapa1.ppm datos/imagenes/banderas/ datos/almacen_rutas.txt datos/imagenes/aviones/avion1.ppm datos/imagenes/aviones/mascara_avion1.pgm


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~
	-rm *.pgm *.ppm *.zip *.tgz

mrproper : clean
	-rm $(BIN)/* doc/html/*
