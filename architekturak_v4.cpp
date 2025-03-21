/*
4. verzi�:
K�sz�tsen egy oszt�lyzat �rt�kel� szimul�tort a k�vetkez�k�ppen:
-	K�rjen be egy pontsz�mot 0-100 k�z�tt.
-	Gener�ljon 100 sz�mot 0-100 k�z�tt �s sz�molja meg, h�ny pont nagyobb vagy egyenl� a bek�rt sz�mn�l.
-	�rja ki az eredm�nyt a k�perny�re.
*/

#include <iostream>
#include <ctime>

int main()
{
	setlocale(LC_ALL, "HU");

	int pontsz�m, nNagyobb = 0;

	printf("Adjon egy pontsz�mot 0-100 = ");
	scanf_s("%d", &pontsz�m);

	srand((unsigned)time(NULL));

	_asm
	{
		mov ecx, 100;
	ciklus:
		push ecx;
		call rand;
		pop ecx;

		mov ebx, 101;
		xor edx, edx;
		div ebx;

		cmp edx, pontsz�m;
		jl semelyik;

		inc nNagyobb;

		semelyik:
		loop ciklus;
	}

	printf("Nagyobb = %d\n", nNagyobb);


	return 0;
}