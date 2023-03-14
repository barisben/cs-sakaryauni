hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Meyve.o -c ./src/Meyve.cpp
	g++ -I ./include/ -o ./lib/Sebze.o -c ./src/Sebze.cpp
	g++ -I ./include/ -o ./lib/Ogrenci.o -c ./src/Ogrenci.cpp
	g++ -I ./include/ -o ./bin/test ./lib/Ogrenci.o ./lib/Sebze.o ./lib/Meyve.o ./src/Main.cpp
	
calistir:
	./bin/test