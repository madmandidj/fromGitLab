#include <stdio.h>
#include "BitOps.h"

int main()
{
	int cont = 1;
	int option;
	Byte byte;
	Byte byteInv;
	Byte byteRot;
	int rotNum;
	Byte x;
	Byte y;
	int n;
	int p;
	unsigned int w;
	int i;
	int j;
	int value;
	while(cont)
	{
		printf("\nSelect an option:\n");
		printf("1:\tInvert Byte\n");
		printf("2:\tRotate Byte\n");
		printf("3:\tn bits from y in place p of x\n");
		printf("4:\tset i to j bits of int to value\n");
		printf("5:\tExit\n");
		scanf("%d", &option);
		switch (option)
		{
			case 1:
				printf("Enter the value to invert (0 - 255)\n");
				scanf("%u", &byte);
				printf("Original Byte:\n");
				PrintByte(byte);
				printf("\n");
				InvertByte(byte, &byteInv);
				printf("Inverted Byte:\n");
				PrintByte(byteInv);
				printf("\n");
				break;
			case 2:
				printf("Enter the value to rotate (0 - 255)\n");
				scanf("%u", &byte);
				printf("Enter the amount to rotate\n");
				scanf("%d", &rotNum);
				printf("Original Byte:\n");
				PrintByte(byte);
				printf("\n");
				RotateByteRight(byte, &byteRot, rotNum);
				printf("Rotated Byte:\n");
				PrintByte(byteRot);
				printf("\n");
				break;
			case 3:
				printf("Enter x (0 - 255)\n");
				scanf("%u", &x);
				printf("Enter y (0 - 255)\n");
				scanf("%u", &y);
				printf("Enter n\n");
				scanf("%d", &n);
				printf("Enter p\n");
				scanf("%d", &p);
				printf("x: ");
				PrintByte(x);
				printf("\n");
				printf("y: ");
				PrintByte(y);
				printf("\n");
				setBitsNP(&x, &y, n, p);
				printf("new x: ");
				PrintByte(x);
				printf("\n");
				break;
			case 4:
				printf("Enter w (0 - 4,294,967,295)\n");
				scanf("%d", &w);
				printf("Enter i\n");
				scanf("%d", &i);
				printf("Enter j\n");
				scanf("%d", &j);
				printf("Enter value\n");
				scanf("%d", &value);
				printf("w: ");
				PrintInt(w);
				printf("\n");
				setBitsIJ(&w, i, j, value);
				printf("new w: ");
				PrintInt(w);
				printf("\n");
				break;
			default:
				cont = 0;
				break;
		}
	}
	printf("Goodbye :-)\n");
	return 0;
}

