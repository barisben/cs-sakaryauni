hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/Exception.o -c ./src/Exception.c
	gcc -I ./include/ -o ./lib/IOException.o -c ./src/IOException.c
	gcc -I ./include/ -o ./lib/Dosya.o -c ./src/Dosya.c
	gcc -I ./include/ -o ./bin/test ./lib/Exception.o ./lib/IOException.o ./lib/Dosya.o ./src/Test.c
	
calistir:
	./bin/test