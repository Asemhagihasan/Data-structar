all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/Listeler.cpp -o ./lib/Listeler.o
bagla:
	g++  ./lib/Dugum.o  ./lib/main.o  ./lib/Listeler.o -o ./bin/program
calistir:
	./bin/program