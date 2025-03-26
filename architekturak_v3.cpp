/*
3. verzió:
Készítsen el egy kockadobás szimulátort a következő módon:
-	100-szor generáljon véletlen számokat 1-6 között
-	Számolja meg a dobott számok átlagát (csak egész szám elég).
-	Írja ki az eredményt a képernyőre.
*/

#include <iostream>
#include <ctime>

int main()
{
    setlocale(LC_ALL, "HU");

    int random, sum = 0, osztó = 100, átlag;

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

        mov eax, sum;
        add eax, random;
        mov sum, eax;

        loop ciklus;
    }

    _asm
    {
        mov eax, sum;
        xor edx, edx;
        div osztó;
        mov átlag, eax;
    }

    printf("Átlag = %d\n", átlag);
    

    return 0;
}
