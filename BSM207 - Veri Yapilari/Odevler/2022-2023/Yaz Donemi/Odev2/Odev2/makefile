hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/BST.o -c ./src/BST.cpp
	g++ -I ./include/ -o ./lib/BSTNode.o -c ./src/BSTNode.cpp
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/StackNode.o -c ./src/StackNode.cpp
	g++ -I ./include/ -o ./bin/main ./lib/BST.o ./lib/BSTNode.o ./lib/Stack.o ./lib/StackNode.o ./src/main.cpp
	
calistir:
	./bin/main