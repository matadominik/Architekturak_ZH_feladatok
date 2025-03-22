#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "HU");

    //1. rész

    //1. feladat - Adjon össze egy regisztert és egy változót!
    int a = 97;
    _asm
    {
        mov eax, 51;
        add eax, a;
    }

    //2. feladat - Adatmozgató utasításokkal cseréljen ki két változót!
    int b = 98;
    _asm
    {
        mov eax, a;
        mov ebx, b;
        mov a, ebx;
        mov b, eax;
    }

    //3. feladat - Képezze az EBX regiszter négyzetét az EDX regiszterbe!
    _asm
    {
        mov ebx, 86;
        mov eax, ebx;
        mul ebx;
        mov edx, eax;   //EAX:EDX párost használjuk ilyen mûveleteknél
    }

    //4. feladat - Ossza el 120-at 58-al egész típusú mûveletekkel!
    _asm
    {
        mov eax, 120;
        mov ecx, 58;
        mov edx, 0;
        div ecx;
    }

    //5. feladat - Adjon nulla értéket az EDI regiszternek MOV utasítás használata nélkül!
    _asm
    {
        xor edi, edi;   //kizáró vagy = azonos bitek esetén 0-át (hamis) ad vissza
    }

    //6. feladat - Állítsa be a carry flaget 0-ba!
    _asm
    {
        CLC;    //CLear Carry flag
    }

    //7. feladat - Végezze el az EDX regiszter aritmetikai jobbra léptetését 19-szer CL regiszter használatával!
    _asm
    {
        mov cl, 19;
        sar edx, cl;    //shift arithmetic right
    }


    //2. rész

    /*
    Készítse el a gondoltam egy számot játékot _asm blokkokkal a következõ elemekkel:
    - A gondolt szám tartománya 1 és 1000 közé essen.
    - Számolja meg a találatok számát, és jegyezze meg a késõbbi játék során.
    - Addig játsszon a játékos, ameddig csak akar (legyen a végén egy új játék lehetõség)
    - A játék legvégén írja ki, hány játékot játszott és hány találata volt összesen.
    + reláció

    - véletlen szám generáláshoz a rand() függvény használható (de a tartomány már _asm! )
    - bekéréshez scanf_s, kiíráshoz printf-et használjon
    - változóknak kezdõérték adható.
    */

	srand((unsigned)time(NULL));
	
    int random, tipp, nTipp, sumTipp = 0, sumJáték = 0;
    char i;

    //do-while féleség
    
    _asm
    {
    újKör:
        inc sumJáték;
        mov nTipp, 0;   //tipp/kör
    }

    _asm    //random
    {
        call rand;
        mov ebx, 1000;
        xor edx, edx;
        div ebx;
        inc edx;
        mov random, edx;
    }

    _asm compare:

    printf("Tipp 1-1000 = ");
    scanf_s("%d", &tipp);

    _asm
    {
        inc nTipp;
        inc sumTipp;

        mov eax, tipp;
        cmp eax, random;
        je egyenlõ;
        jg nagyobb;
        jl kisebb;
    }

    _asm nagyobb:
    printf("A keresett szám kisebb!\n");
    _asm jmp compare;

    _asm kisebb:
    printf("A keresett szám nagyobb!\n");
    _asm jmp compare;

    _asm egyenlõ:
    printf("\nTalált-süllyedt! %d tippbõl találtad ki!\nÖsszes játék = %d, összes tipp = %d\n\n", nTipp, sumJáték, sumTipp);
    
    printf("Szeretnél még egyet játszani (i)? ");
    scanf_s(" %c", &i, 1);

    printf("\n");


    _asm
    {
        cmp i, 'i';
        je mégEgy;
        jne vége;
    }

    _asm
    {
    mégEgy:
        jmp újKör;
    }

    _asm
    {
        vége:
    }

    
    return 0;
}