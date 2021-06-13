hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/DisAVLTree.o -c ./src/DisAVLTree.cpp
	g++ -I ./include/ -o ./lib/DisNode.o -c ./src/DisNode.cpp
	g++ -I ./include/ -o ./lib/IcAVLTree.o -c ./src/IcAVLTree.cpp
	g++ -I ./include/ -o ./lib/IcNode.o -c ./src/IcNode.cpp
	g++ -I ./include/ -o ./bin/test ./lib/DisAVLTree.o ./lib/IcAVLTree.o ./lib/DisNode.o ./lib/IcNode.o ./src/Main.cpp
	
calistir:
	./bin/test