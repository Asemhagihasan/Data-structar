all:derle bagla calistir

derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/IkiliAramaAgaci.cpp -o ./lib/IkiliAramaAgaci.o
	g++ -c -I "./include" ./src/yigin.cpp -o ./lib/yigin.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/test.cpp -o ./lib/test.o
bagla:
	g++ ./lib/main.o  ./lib/yigin.o  ./lib/test.o ./lib/Dugum.o  ./lib/IkiliAramaAgaci.o  -o ./bin/program.exe
calistir:
	./bin/program
