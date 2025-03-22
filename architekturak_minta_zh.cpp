#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL, "HU");

    //1. r�sz

    //1. feladat - Adjon �ssze egy regisztert �s egy v�ltoz�t!
    int a = 97;
    _asm
    {
        mov eax, 51;
        add eax, a;
    }

    //2. feladat - Adatmozgat� utas�t�sokkal cser�ljen ki k�t v�ltoz�t!
    int b = 98;
    _asm
    {
        mov eax, a;
        mov ebx, b;
        mov a, ebx;
        mov b, eax;
    }

    //3. feladat - K�pezze az EBX regiszter n�gyzet�t az EDX regiszterbe!
    _asm
    {
        mov ebx, 86;
        mov eax, ebx;
        mul ebx;
        mov edx, eax;   //EAX:EDX p�rost haszn�ljuk ilyen m�veletekn�l
    }

    //4. feladat - Ossza el 120-at 58-al eg�sz t�pus� m�veletekkel!
    _asm
    {
        mov eax, 120;
        mov ecx, 58;
        mov edx, 0;
        div ecx;
    }

    //5. feladat - Adjon nulla �rt�ket az EDI regiszternek MOV utas�t�s haszn�lata n�lk�l!
    _asm
    {
        xor edi, edi;   //kiz�r� vagy = azonos bitek eset�n 0-�t (hamis) ad vissza
    }

    //6. feladat - �ll�tsa be a carry flaget 0-ba!
    _asm
    {
        CLC;    //CLear Carry flag
    }

    //7. feladat - V�gezze el az EDX regiszter aritmetikai jobbra l�ptet�s�t 19-szer CL regiszter haszn�lat�val!
    _asm
    {
        mov cl, 19;
        sar edx, cl;    //shift arithmetic right
    }


    //2. r�sz

    /*
    K�sz�tse el a gondoltam egy sz�mot j�t�kot _asm blokkokkal a k�vetkez� elemekkel:
    - A gondolt sz�m tartom�nya 1 �s 1000 k�z� essen.
    - Sz�molja meg a tal�latok sz�m�t, �s jegyezze meg a k�s�bbi j�t�k sor�n.
    - Addig j�tsszon a j�t�kos, ameddig csak akar (legyen a v�g�n egy �j j�t�k lehet�s�g)
    - A j�t�k legv�g�n �rja ki, h�ny j�t�kot j�tszott �s h�ny tal�lata volt �sszesen.
    + rel�ci�

    - v�letlen sz�m gener�l�shoz a rand() f�ggv�ny haszn�lhat� (de a tartom�ny m�r _asm! )
    - bek�r�shez scanf_s, ki�r�shoz printf-et haszn�ljon
    - v�ltoz�knak kezd��rt�k adhat�.
    */

	srand((unsigned)time(NULL));
	
    int random, tipp, nTipp, sumTipp = 0, sumJ�t�k = 0;
    char i;

    //do-while f�les�g
    
    _asm
    {
    �jK�r:
        inc sumJ�t�k;
        mov nTipp, 0;   //tipp/k�r
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
        je egyenl�;
        jg nagyobb;
        jl kisebb;
    }

    _asm nagyobb:
    printf("A keresett sz�m kisebb!\n");
    _asm jmp compare;

    _asm kisebb:
    printf("A keresett sz�m nagyobb!\n");
    _asm jmp compare;

    _asm egyenl�:
    printf("\nTal�lt-s�llyedt! %d tippb�l tal�ltad ki!\n�sszes j�t�k = %d, �sszes tipp = %d\n\n", nTipp, sumJ�t�k, sumTipp);
    
    printf("Szeretn�l m�g egyet j�tszani (i)? ");
    scanf_s(" %c", &i, 1);

    printf("\n");


    _asm
    {
        cmp i, 'i';
        je m�gEgy;
        jne v�ge;
    }

    _asm
    {
    m�gEgy:
        jmp �jK�r;
    }

    _asm
    {
        v�ge:
    }

    
    return 0;
}