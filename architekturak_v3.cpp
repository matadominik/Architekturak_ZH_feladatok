/*
3. verzi�:
K�sz�tsen el egy kockadob�s szimul�tort a k�vetkez� m�don:
�	100-szor gener�ljon v�letlen sz�mokat 1-6 k�z�tt
�	Sz�molja meg a dobott sz�mok �tlag�t (csak eg�sz sz�m el�g).
�	�rja ki az eredm�nyt a k�perny�re.
*/

#include <iostream>
#include <ctime>

int main()
{
    setlocale(LC_ALL, "HU");

    int random, sum = 0, oszt� = 100, �tlag;

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
        mov edx, 0;
        mov ebx, oszt�;
        div oszt�;
        mov �tlag, eax;
    }

    printf("�tlag = %d\n", �tlag);
    

    return 0;
}