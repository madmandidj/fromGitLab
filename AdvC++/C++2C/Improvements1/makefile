all: MyVer3.out Ver3.out MyVer3.txt Ver3.txt 

MyVer3.out: Eyals_v3.c
	gcc -g -ansi -pedantic -Wall -o MyVer3.out Eyals_v3.c -lm
	
Ver3.out: cpp2c_v2.1_24-jul-2017.cpp
	g++ -g -o Ver3.out cpp2c_v2.1_24-jul-2017.cpp -lm
	
Ver3.txt: Ver3.out
	./Ver3.out >> Ver3.txt
	
MyVer3.txt: MyVer3.out
	./MyVer3.out >> MyVer3.txt
	
clean:
	rm MyVer3.out MyVer3.txt Ver3.out Ver3.txt 
	
	
