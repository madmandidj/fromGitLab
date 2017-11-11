all: PointsC.out PointsCPP.out


PointsC.out: EyalsPoints.c
	gcc -g -ansi -pedantic -Wall -o PointsC.out EyalsPoints.c -lm
	
PointsCPP.out: points_jul_17.cpp
	g++ -g -o PointsCPP.out points_jul_17.cpp -lm
	

clean:
	rm PointsC.out PointsCPP.out
