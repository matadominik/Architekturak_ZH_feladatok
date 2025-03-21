/*
4. verzió:
Készítsen egy osztályzat értékelõ szimulátort a következõképpen:
-	Kérjen be egy pontszámot 0-100 között.
-	Generáljon 100 számot 0-100 között és számolja meg, hány pont nagyobb vagy egyenlõ a bekért számnál.
-	Írja ki az eredményt a képernyõre.
*/

#include <iostream>
#include <ctime>

int main()
{
	setlocale(LC_ALL, "HU");

	int pontszám, nNagyobb = 0;

	printf("Adjon egy pontszámot 0-100 = ");
	scanf_s("%d", &pontszám);

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

		cmp edx, pontszám;
		jl semelyik;

		inc nNagyobb;

		semelyik:
		loop ciklus;
	}

	printf("Nagyobb = %d\n", nNagyobb);


	return 0;
}