all: MyVer2.out Ver2.out

MyVer2.out: Eyals_v2.c
	gcc -g -ansi -pedantic -Wall -o MyVer2.out Eyals_v2.c -lm
	
Ver2.out: cpp2c_v2.1_24-jul-2017.cpp
	g++ -g -o Ver2.out cpp2c_v2.1_24-jul-2017.cpp -lm
	

clean:
	rm MyVer2.out Ver2.out
