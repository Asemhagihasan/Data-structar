all:derle bagla calistir
derle:
	g++  -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++  -c -I "./include" ./src/Kuyruk.cpp -o ./lib/Kuyruk.o
	g++  -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++  -c -I "./include" ./src/Radix.cpp -o ./lib/Radix.o	
	g++  -c -I "./include" ./src/Doku.cpp -o ./lib/Doku.o	
	g++  -c -I "./include" ./src/kontrol.cpp -o ./lib/kontrol.o	
	g++  -c -I "./include" ./src/hucre.cpp -o ./lib/hucre.o		
	g++  -c -I "./include" ./src/Organ.cpp -o ./lib/Organ.o	
	g++  -c -I "./include" ./src/hucreDugum.cpp -o ./lib/hucreDugum.o	
	g++  -c -I "./include" ./src/dokuDugum.cpp -o ./lib/dokuDugum.o	
	g++  -c -I "./include" ./src/IkiliAramaAgaci.cpp -o ./lib/IkiliAramaAgaci.o	
	g++  -c -I "./include" ./src/testProgram.cpp -o ./lib/testProgram.o	
	g++  -c -I "./include" ./src/System.cpp -o ./lib/System.o	
	g++  -c -I "./include" ./src/Organizma.cpp -o ./lib/Organizma.o	
		
	
bagla:
	g++  ./lib/Dugum.o ./lib/Kuyruk.o  ./lib/System.o  ./lib/Organizma.o ./lib/dokuDugum.o  ./lib/testProgram.o   ./lib/IkiliAramaAgaci.o   ./lib/hucreDugum.o ./lib/Organ.o ./lib/kontrol.o ./lib/Doku.o  ./lib/hucre.o    ./lib/Radix.o ./lib/main.o -o ./bin/program

calistir:
	./bin/program