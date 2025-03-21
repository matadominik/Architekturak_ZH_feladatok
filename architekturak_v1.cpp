#include <iostream>
#include <ctime>

int main()
{
    setlocale(LC_ALL, "HU");

    int szám, tipp, nTipp;

    _asm
    {
        mov szám, 0;
        mov tipp, 0;
        mov nTipp, 0;
    }

    printf("Adjon meg egy számot 1-1000 = ");
    scanf_s("%d", &szám);

    srand((unsigned)time(NULL));
    _asm //véletlen szám generálás
    {
    random:
        call rand;
        mov ebx, 1000;
        xor edx, edx;
        div ebx;
        inc edx;
        mov tipp, edx;  // tipp = rand() ...

        inc nTipp;
    }

    _asm
    {
    összehasonlítás:
        mov eax, tipp;
        cmp eax, szám;
        je egyenlő; //jump if equal
        jg nagyobb; //jump if greater
        jl kisebb;  //jump if less
    }

    _asm egyenlő:
    printf("\nTipp = %d  -  Talált! Találatok száma = %d\n", tipp, nTipp);
    _asm jmp vége;

    _asm nagyobb:
    printf("Tipp = %d  -  A szám kisebb! \n", tipp);
    _asm jmp random;

    _asm kisebb:
    printf("Tipp = %d  -  A szám nagyobb!\n", tipp);
    _asm jmp random;

    vége:

    
    return 0;
}