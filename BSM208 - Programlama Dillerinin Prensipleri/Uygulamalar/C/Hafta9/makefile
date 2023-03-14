hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/Order.o -c ./src/Order.c
	gcc -I ./include/ -o ./lib/Mean.o -c ./src/Mean.c
	gcc -I ./include/ -o ./bin/Main ./lib/Order.o ./lib/Mean.o ./src/Main.c
	
calistir:
	./bin/Main