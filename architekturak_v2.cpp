/*
2. verzió:
Készítsen el egy kockadobás szimulátort a következõ módon:
-	Kérjen be egy számot 1-6 között
-	100-szor generáljon véletlen számokat 1-6 között
-	számolja meg, a 100 dobásból hányszor dobott olyan számot, mint amit bekért.
-	Írja ki az eredményt a képernyõre.
*/

#include <iostream>
#include <ctime>

int main()
{
	setlocale(LC_ALL, "HU");

	int szám, random, nTalálat;

	_asm
	{
		mov szám, 0;
		mov random, 0;
		mov nTalálat, 0;
	}

	printf("Adjon egy számot 1-6 = ");
	scanf_s("%d", &szám);

	srand((unsigned)time(NULL));

	_asm
	{
		mov ecx, 100;
	ciklus:
		push ecx;
		call rand;
		pop ecx;

		mov ebx, 6;
		xor edx, edx;
		div ebx;
		inc edx;
		mov random, edx;


		mov eax, szám;
		cmp eax, random;
		jne nemTalált;

		inc nTalálat;

	nemTalált:
		loop ciklus;
	}

	printf("%d alkalommal egyeztek a számok!\n", nTalálat);


	return 0;
}