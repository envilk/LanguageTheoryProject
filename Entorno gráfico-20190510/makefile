#fichero Makefile

FUENTE = ejemplo.cpp

fin: ejemplo
	./ejemplo 
	
ejemplo : ejemplo.o entorno_dspl.o 
	g++ -oejemplo entorno_dspl.o ejemplo.o -lallegro -lallegro_acodec -lallegro_audio -lallegro_color -lallegro_dialog -lallegro_font -lallegro_image -lallegro_main -lallegro_memfile -lallegro_physfs -lallegro_primitives -lallegro_ttf

entorno_dspl.o : entorno_dspl.cpp
	g++ -c entorno_dspl.cpp

ejemplo.o : $(FUENTE)
	g++ -c -oejemplo.o $(FUENTE) 

clean :
	rm -f *.o	
