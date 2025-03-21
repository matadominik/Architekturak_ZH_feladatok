/*
5. verzi�:
K�sz�tsen egy oszt�lyzat �rt�kel� szimul�tort a k�vetkez�k�ppen:
-	Gener�ljon 100 sz�mot 0-100 k�z�tt �s sz�molja meg, h�ny oszt�lyzat lett 50 pont felett �s alatt.
-	Adja meg a kett� k�z�tti k�l�nbs�get is.
-	�rja ki az eredm�nyt a k�perny�re.
*/

#include <iostream>
#include <ctime>

int main()
{
    setlocale(LC_ALL, "HU");

    int random, felett = 0, alatt = 0, k�l�nbs�g;

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

        cmp edx, 50;
        jg nagyobb;
        jl kisebb;
        jmp v�ge;   //ha egyik sem

    nagyobb:
        inc felett;
        jmp v�ge;

    kisebb:
        inc alatt;

        v�ge:
        loop ciklus;
    }

    _asm
    {
        mov eax, felett;
        cmp eax, alatt;
        jg felettb�l;
        jl alattb�l;

    felettb�l:
        sub eax, alatt;
        mov k�l�nbs�g, eax;
        jmp v�gev�ge;

    alattb�l:
        mov eax, alatt;
        sub eax, felett;
        mov k�l�nbs�g, eax;

        v�gev�ge:
    }

    printf("Felett = %d  -  Alatt = %d  -  K�l�nbs�g: %d\n", felett, alatt, k�l�nbs�g);


    return 0;
}