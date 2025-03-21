/*
2. verzi�:
K�sz�tsen el egy kockadob�s szimul�tort a k�vetkez� m�don:
-	K�rjen be egy sz�mot 1-6 k�z�tt
-	100-szor gener�ljon v�letlen sz�mokat 1-6 k�z�tt
-	sz�molja meg, a 100 dob�sb�l h�nyszor dobott olyan sz�mot, mint amit bek�rt.
-	�rja ki az eredm�nyt a k�perny�re.
*/

#include <iostream>
#include <ctime>

int main()
{
	setlocale(LC_ALL, "HU");

	int sz�m, random, nTal�lat;

	_asm
	{
		mov sz�m, 0;
		mov random, 0;
		mov nTal�lat, 0;
	}

	printf("Adjon egy sz�mot 1-6 = ");
	scanf_s("%d", &sz�m);

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


		mov eax, sz�m;
		cmp eax, random;
		jne nemTal�lt;

		inc nTal�lat;

	nemTal�lt:
		loop ciklus;
	}

	printf("%d alkalommal egyeztek a sz�mok!\n", nTal�lat);


	return 0;
}