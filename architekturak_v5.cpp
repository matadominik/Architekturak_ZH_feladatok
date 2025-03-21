/*
5. verzió:
Készítsen egy osztályzat értékelõ szimulátort a következõképpen:
-	Generáljon 100 számot 0-100 között és számolja meg, hány osztályzat lett 50 pont felett és alatt.
-	Adja meg a kettõ közötti különbséget is.
-	Írja ki az eredményt a képernyõre.
*/

#include <iostream>
#include <ctime>

int main()
{
    setlocale(LC_ALL, "HU");

    int random, felett = 0, alatt = 0, különbség;

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
        jmp vége;   //ha egyik sem

    nagyobb:
        inc felett;
        jmp vége;

    kisebb:
        inc alatt;

        vége:
        loop ciklus;
    }

    _asm
    {
        mov eax, felett;
        cmp eax, alatt;
        jg felettbõl;
        jl alattból;

    felettbõl:
        sub eax, alatt;
        mov különbség, eax;
        jmp végevége;

    alattból:
        mov eax, alatt;
        sub eax, felett;
        mov különbség, eax;

        végevége:
    }

    printf("Felett = %d  -  Alatt = %d  -  Különbség: %d\n", felett, alatt, különbség);


    return 0;
}