hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/GeometrikSekil.o -c ./src/GeometrikSekil.c
	gcc -I ./include/ -o ./lib/Daire.o -c ./src/Daire.c
	gcc -I ./include/ -o ./lib/Kare.o -c ./src/Kare.c
	gcc -I ./include/ -o ./bin/test ./lib/GeometrikSekil.o ./lib/Daire.o ./lib/Kare.o ./src/Test.c
	
calistir:
	./bin/test