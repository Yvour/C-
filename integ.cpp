// интежер.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ostream.h>
#include <stdio.h>
#include <conio.h>

typedef unsigned int RegType;
typedef RegType Vier[4];
typedef RegType Acht[8];
typedef RegType Neun[9];
typedef RegType Fuenf[5];
class integ128
{
public:
    Vier Numbers;
    Vier Data;
    void operator /=(integ128);
    void operator *=(integ128);
    void operator +=(integ128);
    void operator -=(integ128);
    void operator <<=(int);
    void operator >>=(int);
    void operator %=(integ128);
    integ128 operator /(integ128);
    integ128 operator *(integ128);
    integ128 operator +(integ128);
    integ128 operator -(integ128);
    integ128 operator <<(int);
    integ128 operator >>(int);
    integ128 operator %(integ128);
//	void operator ++();
//	void operator ++(int);
    integ128 operator--(int);
    integ128 operator--();
    integ128 operator++(int);
    integ128 operator++();

    integ128 operator ~();
//****** Побитовые логические операторы с присваиванием ******
    void operator &=(integ128);
    void operator |=(integ128);
    void operator ^=(integ128);
//****** Побитовые логические операторы без присваивания *****
    integ128 operator &(integ128);
    integ128 operator |(integ128);
    integ128 operator ^(integ128);
//******** Операторы сравнения *******************************
    bool operator >=(integ128);
    bool operator > (integ128);
    bool operator <=(integ128);
    bool operator < (integ128);
    bool operator ==(integ128);
    bool operator !=(integ128);
//********* Логические операторы ****************************
    bool operator !();
    bool operator &&(integ128);
    bool operator ||(bool Bool);
    integ128();
    integ128(RegType n1,RegType n2,RegType n3,RegType n4);
    integ128(Acht Eighter);
//	integ128(Vier Fourer);
//	  ,Numbers[1],Numbers[2],Numbers[3]);

    char * Out();
};

/*integ128::integ128(Vier Fourer)
{
	for (int i=0;i<4;i++) Numbers[i]=Fourer[i];
	for (i=0;i<4;i++) Data[i]=Fourer[i];
};*/
integ128::integ128(Acht Eighter)
{
    for (int i = 0 ; i < 4 ; i ++)
    {   Numbers[i] = Eighter[i];
        Data[i]=Eighter[i+4];
    };
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++ Операторы сравнения ++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool integ128::operator >=(integ128 second)
{
    if (Numbers[3]<second.Numbers[3]) return false;
    else if (Numbers[3]==second.Numbers[3])
    {
        if (Numbers[2]<second.Numbers[2]) return false;
        else if (Numbers[2]==second.Numbers[2])
        {
            if (Numbers[1]<second.Numbers[1]) return false;
            else if (Numbers[1]==second.Numbers[1])
            {
                if (Numbers[0]<second.Numbers[0]) return false;
                else return true;
            } else return true;
        } else return true;
    } else return true;
};

bool integ128::operator <=(integ128 second)
{
    if (Numbers[3]>second.Numbers[3]) return false;
    else
    {
        if (Numbers[2]>second.Numbers[2]) return false;
        else
        {
            if (Numbers[1]>second.Numbers[1]) return false;
            else
            {
                if (Numbers[0]>second.Numbers[0]) return false;
                else return true;
            }
        }
    };
};

bool integ128::operator ==(integ128 second)
{
    if (  (Numbers[0]==second.Numbers[0]) &&
            (Numbers[1]==second.Numbers[1]) &&
            (Numbers[2]==second.Numbers[2]) &&
            (Numbers[3]==second.Numbers[3])) return true;
    else return false;
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++ Логические побитовые операторы ++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
integ128 integ128::operator~()
{
    Vier Numbers1;
    for (int i=0; i<4; i++) Numbers1[i]=~Numbers[i];
    return integ128(Numbers1[0],Numbers1[1],Numbers1[2],Numbers1[3]);
};

//=========== Побитовое И с присваиванием =======================================
void integ128::operator &=(integ128 second)
{
    for (int i=0; i<4; i++) Numbers[i]&=second.Numbers[i];
};
//=========== Побитовое ИЛИ с присваиванием =====================================
void integ128::operator |=(integ128 second)
{
    for (int i=0; i<4; i++) Numbers[i]|=second.Numbers[i];
};
//=========== Побитовое исключающее ИЛИ с присваиванием ========================
void integ128::operator ^=(integ128 second)
{
    for (int i=0; i<4; i++) Numbers[i]^=second.Numbers[i];
};
//++++//========== Побитовое И ========================================================
integ128 integ128::operator &(integ128 second)
{
    return
        integ128(this->Numbers[0]&second.Numbers[0],this->Numbers[1]&second.Numbers[1],
                 this->Numbers[2]&second.Numbers[2],this->Numbers[3]&second.Numbers[3]);
};
//========== Побитовое ИЛИ ========================================================
integ128 integ128::operator |(integ128 second)
{
    return
        integ128(this->Numbers[0]|second.Numbers[0],this->Numbers[1]|second.Numbers[1],
                 this->Numbers[2]|second.Numbers[2],this->Numbers[3]|second.Numbers[3]);
};

//========== Побитовое исключающее ИЛИ ========================================================
integ128 integ128::operator ^(integ128 second)
{
    return
        integ128(this->Numbers[0]^second.Numbers[0],this->Numbers[1]^second.Numbers[1],
                 this->Numbers[2]^second.Numbers[2],this->Numbers[3]^second.Numbers[3]);
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++ Операторы вычисления значения числа по модулю +++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void integ128::operator %= (integ128 second)
{
    Neun Acc= {this->Numbers[0],this->Numbers[1],this->Numbers[2],this->Numbers[3],0,0,0,0};
    Vier Mint;
    for (int i=0; i<4; i++) Mint[i] = 0xffffffff-(second.Numbers[i]);
    bool ok=true;
    i = 0;
    while (ok)
    {
        Mint[i]++;
        if (Mint[i]==0) i++;
        else ok=false;
        if (i==3) ok=false;
    };

    Fuenf Vych= {Mint[0],Mint[1],Mint[2],Mint[3],0x3};
    __asm {


        mov ecx,128
        cycl:
        // сдвиг на один разряд вправо
        mov eax,[Acc]
        add	[Acc],eax		//1
        mov eax,[Acc+4]
        adc [Acc+4],eax		//2
        mov eax,[Acc+8]
        adc [Acc+8],eax		//3
        mov eax,[Acc+12]
        adc [Acc+12],eax	//4
        mov eax,[Acc+16]
        adc [Acc+16],eax	//5
        mov eax,[Acc+20]
        adc [Acc+20],eax	//6
        mov eax,[Acc+24]
        adc [Acc+24],eax	//7
        mov eax,[Acc+28]
        adc [Acc+28],eax	//8
        mov eax,[Acc+32]
        adc [Acc+32],eax
        //вычисление результата после вычисления
// далее следует проверка результата на отрицательность
        mov eax,[Vych]
        add [Acc+16],eax;
        mov eax,[Vych+4];
        adc [Acc+20],eax;
        mov eax,[Vych+8];
        adc [Acc+24],eax
        mov eax,[Vych+12]
        adc [Acc+28],eax;
        mov eax,[Vych+16]
        adc [Acc+32],eax
        and dword ptr[Acc+32],3
        //приведение байта, отвечающего за знак, к двум значащим битам
        mov eax,[Acc+32]
        cmp eax,0
        je more;
        // обратное прибавление, восстановление исходного значения мантиссы
        mov eax,[second]
        add [Acc+16],eax;
        mov eax,[second+4];
        adc [Acc+20],eax;
        mov eax,[second+8];
        adc [Acc+24],eax
        mov eax,[second+12]
        adc [Acc+28],eax;
        adc [Acc+32],0
        and dword ptr [Acc+32],3		//оставление лишь двух последних битов(значащих)

        jmp aftmor;
        more:	add dword ptr [Acc],0x00000000001
        aftmor:
        xor eax,eax
        loop weit;
        jmp the_end
        weit:	jmp cycl;
        the_end:
    };
    for (i=0; i<4; i++) this->Numbers[i]=Acc[i+4];
};


integ128 integ128::operator % (integ128 second)
{
    Neun Acc= {this->Numbers[0],this->Numbers[1],this->Numbers[2],this->Numbers[3],0,0,0,0};
    Vier Mint;
    for (int i=0; i<4; i++) Mint[i] = 0xffffffff-(second.Numbers[i]);
    bool ok=true;
    i = 0;
    while (ok)
    {
        Mint[i]++;
        if (Mint[i]==0) i++;
        else ok=false;
        if (i==3) ok=false;
    };

    Fuenf Vych= {Mint[0],Mint[1],Mint[2],Mint[3],0x3};
    __asm {


        mov ecx,128
        cycl:
        // сдвиг на один разряд вправо
        mov eax,[Acc]
        add	[Acc],eax		//1
        mov eax,[Acc+4]
        adc [Acc+4],eax		//2
        mov eax,[Acc+8]
        adc [Acc+8],eax		//3
        mov eax,[Acc+12]
        adc [Acc+12],eax	//4
        mov eax,[Acc+16]
        adc [Acc+16],eax	//5
        mov eax,[Acc+20]
        adc [Acc+20],eax	//6
        mov eax,[Acc+24]
        adc [Acc+24],eax	//7
        mov eax,[Acc+28]
        adc [Acc+28],eax	//8
        mov eax,[Acc+32]
        adc [Acc+32],eax
        //вычисление результата после вычисления
// далее следует проверка результата на отрицательность
        mov eax,[Vych]
        add [Acc+16],eax;
        mov eax,[Vych+4];
        adc [Acc+20],eax;
        mov eax,[Vych+8];
        adc [Acc+24],eax
        mov eax,[Vych+12]
        adc [Acc+28],eax;
        mov eax,[Vych+16]
        adc [Acc+32],eax
        and dword ptr[Acc+32],3
        //приведение байта, отвечающего за знак, к двум значащим битам
        mov eax,[Acc+32]
        cmp eax,0
        je more;
        // обратное прибавление, восстановление исходного значения мантиссы
        mov eax,[second]
        add [Acc+16],eax;
        mov eax,[second+4];
        adc [Acc+20],eax;
        mov eax,[second+8];
        adc [Acc+24],eax
        mov eax,[second+12]
        adc [Acc+28],eax;
        adc [Acc+32],0
        and dword ptr [Acc+32],3		//оставление лишь двух последних битов(значащих)

        jmp aftmor;
        more:	add dword ptr [Acc],0x00000000001
        aftmor:
        xor eax,eax
        loop weit;
        jmp the_end
        weit:	jmp cycl;
        the_end:
    };
    return integ128(Acc[4],Acc[5],Acc[6],Acc[7]);
};




//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Операторы деления

void integ128::operator /= (integ128 second)
{
    Neun Acc= {this->Numbers[0],this->Numbers[1],this->Numbers[2],this->Numbers[3],0,0,0,0};
    Vier Mint;
    for (int i=0; i<4; i++) Mint[i] = 0xffffffff-(second.Numbers[i]);
    bool ok=true;
    i = 0;
    while (ok)
    {
        Mint[i]++;
        if (Mint[i]==0) i++;
        else ok=false;
        if (i==3) ok=false;
    };

    Fuenf Vych= {Mint[0],Mint[1],Mint[2],Mint[3],0x3};
    __asm {


        mov ecx,128
        cycl:
        // сдвиг на один разряд вправо
        mov eax,[Acc]
        add	[Acc],eax		//1
        mov eax,[Acc+4]
        adc [Acc+4],eax		//2
        mov eax,[Acc+8]
        adc [Acc+8],eax		//3
        mov eax,[Acc+12]
        adc [Acc+12],eax	//4
        mov eax,[Acc+16]
        adc [Acc+16],eax	//5
        mov eax,[Acc+20]
        adc [Acc+20],eax	//6
        mov eax,[Acc+24]
        adc [Acc+24],eax	//7
        mov eax,[Acc+28]
        adc [Acc+28],eax	//8
        mov eax,[Acc+32]
        adc [Acc+32],eax
        //вычисление результата после вычисления
// далее следует проверка результата на отрицательность
        mov eax,[Vych]
        add [Acc+16],eax;
        mov eax,[Vych+4];
        adc [Acc+20],eax;
        mov eax,[Vych+8];
        adc [Acc+24],eax
        mov eax,[Vych+12]
        adc [Acc+28],eax;
        mov eax,[Vych+16]
        adc [Acc+32],eax
        and dword ptr[Acc+32],3
        //приведение байта, отвечающего за знак, к двум значащим битам
        mov eax,[Acc+32]
        cmp eax,0
        je more;
        // обратное прибавление, восстановление исходного значения мантиссы
        mov eax,[second]
        add [Acc+16],eax;
        mov eax,[second+4];
        adc [Acc+20],eax;
        mov eax,[second+8];
        adc [Acc+24],eax
        mov eax,[second+12]
        adc [Acc+28],eax;
        adc [Acc+32],0
        and dword ptr [Acc+32],3		//оставление лишь двух последних битов(значащих)

        jmp aftmor;
        more:	add dword ptr [Acc],0x00000000001
        aftmor:
        xor eax,eax
        loop weit;
        jmp the_end
        weit:	jmp cycl;
        the_end:
    };
    for (i=0; i<4; i++) this->Numbers[i]=Acc[i];
};


integ128 integ128::operator / (integ128 second)
{
    Neun Acc= {this->Numbers[0],this->Numbers[1],this->Numbers[2],this->Numbers[3],0,0,0,0};
    Vier Mint;
    for (int i=0; i<4; i++) Mint[i] = 0xffffffff-(second.Numbers[i]);
    bool ok=true;
    i = 0;
    while (ok)
    {
        Mint[i]++;
        if (Mint[i]==0) i++;
        else ok=false;
        if (i==3) ok=false;
    };

    Fuenf Vych= {Mint[0],Mint[1],Mint[2],Mint[3],0x3};
    __asm {


        mov ecx,128
        cycl:
        // сдвиг на один разряд вправо
        mov eax,[Acc]
        add	[Acc],eax		//1
        mov eax,[Acc+4]
        adc [Acc+4],eax		//2
        mov eax,[Acc+8]
        adc [Acc+8],eax		//3
        mov eax,[Acc+12]
        adc [Acc+12],eax	//4
        mov eax,[Acc+16]
        adc [Acc+16],eax	//5
        mov eax,[Acc+20]
        adc [Acc+20],eax	//6
        mov eax,[Acc+24]
        adc [Acc+24],eax	//7
        mov eax,[Acc+28]
        adc [Acc+28],eax	//8
        mov eax,[Acc+32]
        adc [Acc+32],eax
        //вычисление результата после вычисления
// далее следует проверка результата на отрицательность
        mov eax,[Vych]
        add [Acc+16],eax;
        mov eax,[Vych+4];
        adc [Acc+20],eax;
        mov eax,[Vych+8];
        adc [Acc+24],eax
        mov eax,[Vych+12]
        adc [Acc+28],eax;
        mov eax,[Vych+16]
        adc [Acc+32],eax
        and dword ptr[Acc+32],3
        //приведение байта, отвечающего за знак, к двум значащим битам
        mov eax,[Acc+32]
        cmp eax,0
        je more;
        // обратное прибавление, восстановление исходного значения мантиссы
        mov eax,[second]
        add [Acc+16],eax;
        mov eax,[second+4];
        adc [Acc+20],eax;
        mov eax,[second+8];
        adc [Acc+24],eax
        mov eax,[second+12]
        adc [Acc+28],eax;
        adc [Acc+32],0
        and dword ptr [Acc+32],3		//оставление лишь двух последних битов(значащих)

        jmp aftmor;
        more:	add dword ptr [Acc],0x00000000001
        aftmor:
        xor eax,eax
        loop weit;
        jmp the_end
        weit:	jmp cycl;
        the_end:
    };
    return integ128(Acc[0],Acc[1],Acc[2],Acc[3]);
};


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Операторы декремента и инкремента
integ128 integ128::operator--()
{
    for (int i=0; i<4; i++)
    {
        if (Numbers[i]) {
            Numbers[i]--;
            i=9;
        }
        else {
            Numbers[i]--;
        }
    };
    return integ128(this->Numbers[0],this->Numbers[1],this->Numbers[2],this->Numbers[3]);
};


integ128 integ128::operator--(int)
{
    Vier Buffer;
    for (int i=0; i<4; i++)
        Buffer[i]=this->Numbers[i];
    for (i=0; i<4; i++)
    {
        if (Numbers[i]) {
            Numbers[i]--;
            i=9;
        }
        else {
            Numbers[i]--;
        }
    };
    return integ128(Buffer[0],Buffer[1],Buffer[2],Buffer[3]);
};

integ128 integ128::operator++()
{
    __asm
    {
        mov edi,this
        inc dword ptr [edi]
        jnz the_end
        inc dword ptr [edi+4];
        jnz the_end;
        inc dword ptr [edi+8];
        jnz the_end;
        inc dword ptr [edi+12];
        the_end:
    }
    return integ128(this->Numbers[0],this->Numbers[1],this->Numbers[2],this->Numbers[3]);
};
integ128 integ128::operator ++(int)
{   Vier Buffer;
    __asm	{
        mov edi,this;
        mov eax,[edi];
        mov ebx,[edi+4];
        mov ecx,[edi+8];
        mov edx,[edi+12];
        mov [Buffer],eax
        mov [Buffer+4],ebx
        mov [Buffer+8],ecx
        mov [Buffer+12],edx
        inc eax
        jnz the_end;
        inc ebx
        jnz the_end
        inc ecx
        jnz the_end
        inc edx
        the_end:
        mov [edi],eax
        mov [edi+4],ebx
        mov [edi+8],ecx
        mov [edi+12],edx
    };
    return integ128(Buffer[0],Buffer[1],Buffer[2],Buffer[3]);


};

/*void integ128::operator ++()
{
	__asm
	{
	mov edi,this
	inc dword ptr [edi]
	jnz the_end
	inc dword ptr [edi+4]
	jnz the_end;
	inc dword ptr [edi+8]
	jnz the_end;
	inc dword ptr [edi+12]

the_end:
	}
};
*/
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++ Операторы логического сдвига +++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//========== Операторы сдвига вправо =======================
void integ128::operator>>=(int Number)
{
    __asm {
        mov edi,this
        mov ebx,Number;
        and ebx,0x07f; //учёт максимально возможной величины сдвига = 127
        mov bh,bl;
        and ebx,0xE01F // в bh сдвиг в dword'ах, в bl - в битах;
        cmp bh,0
        je shifter;
        shr bh,5;
        xor edx,edx
        mov dl,bh;
        mov esi,edx
        xor edx,3;
        mov ecx,edx
        neg edx

//	shl edx,2
//	add edi,edx;
        xor edx,edx
        inc ecx
        lup:
        mov eax,[edi+esi*4]
        mov [edi],eax
        add edi,4
        loop lup
//	shl	esi,2
//	add edi,esi
        sub edi,4
        mov cl,bh

        lup1:mov dword ptr [edi+ecx*4],dword ptr 0;
        loop lup1;
        shifter: //битовый сдвиг
        mov edi,this
        mov cl,bl
        xor edx,edx
        xor ebx,ebx
        mov eax,dword ptr [edi+12];
        shrd edx,eax,cl
        shr eax,cl
        mov [edi+12],eax;
        mov eax,[edi+8];
        shrd ebx,eax,cl;
        shr eax,cl
        add eax,edx;
        xor edx,edx;
        mov [edi+8],eax;
        mov eax,[edi+4]
        shrd edx,eax,cl
        shr eax,cl
        add eax,ebx
        mov [edi+4],eax;
//	xor ebx,ebx
        mov eax,[edi]
        shr eax,cl
        add eax,edx
        mov [edi],eax;
        and eax,eax

    }
};

integ128 integ128::operator>>(int Number)
{
    Vier Buffer= {this->Numbers[0],this->Numbers[1],this->Numbers[2],this->Numbers[3]};
    Vier* Zeiger =  &Buffer;
    __asm {
        mov edi,Zeiger
        mov ebx,Number;
        and ebx,0x07f; //учёт максимально возможной величины сдвига = 127
        mov bh,bl;
        and ebx,0xE01F // в bh сдвиг в dword'ах, в bl - в битах;
        cmp bh,0
        je shifter;
        shr bh,5;
        xor edx,edx
        mov dl,bh;
        mov esi,edx
        xor edx,3;
        mov ecx,edx
        neg edx

//	shl edx,2
//	add edi,edx;
        xor edx,edx
        inc ecx
        lup:
        mov eax,[edi+esi*4]
        mov [edi],eax
        add edi,4
        loop lup
//	shl	esi,2
//	add edi,esi
        sub edi,4
        mov cl,bh

        lup1:mov dword ptr [edi+ecx*4],dword ptr 0;
        loop lup1;
        shifter: //битовый сдвиг
        mov edi,Zeiger
        mov cl,bl
        xor edx,edx
        xor ebx,ebx
        mov eax,dword ptr [edi+12];
        shrd edx,eax,cl
        shr eax,cl
        mov [edi+12],eax;
        mov eax,[edi+8];
        shrd ebx,eax,cl;
        shr eax,cl
        add eax,edx;
        xor edx,edx;
        mov [edi+8],eax;
        mov eax,[edi+4]
        shrd edx,eax,cl
        shr eax,cl
        add eax,ebx
        mov [edi+4],eax;
//	xor ebx,ebx
        mov eax,[edi]
        shr eax,cl
        add eax,edx
        mov [edi],eax;
        and eax,eax

    }
    return integ128(Buffer[0],Buffer[1],Buffer[2],Buffer[3]);
};


//========== Операторы сдвига влево ======================
void integ128::operator <<=(int Number)
{
    __asm {
        mov edi,this
        mov ebx,Number;
        and ebx,0x07f; //учёт максимально возможной величины сдвига = 127
        mov bh,bl;
        and ebx,0xE01F // в bh сдвиг в dword'ах, в bl - в битах;
        cmp bh,0
        je shifter;
        shr bh,5;
        xor edx,edx
        mov dl,bh;
        mov esi,edx
        xor edx,3;
        mov ecx,edx

        shl edx,2
        add edi,edx;
        xor edx,edx
        inc ecx
        lup:
        mov eax,[edi]
        mov [edi+esi*4],eax
        sub edi,4
        loop lup

        mov cl,bh

        lup1:mov dword ptr [edi+ecx*4],dword ptr 0;
        loop lup1;
        shifter: //битовый сдвиг
        mov edi,this
        mov cl,bl
        xor edx,edx
        xor ebx,ebx
        mov eax,dword ptr [edi];
        shld edx,eax,cl
        shl eax,cl
        mov [edi],eax;
        mov eax,[edi+4];
        shld ebx,eax,cl;
        shl eax,cl
        add eax,edx;
        xor edx,edx;
        mov [edi+4],eax;
        mov eax,[edi+8]
        shld edx,eax,cl
        shl eax,cl
        add eax,ebx
        mov [edi+8],eax;
//	xor ebx,ebx
        mov eax,[edi+12]
        shl eax,cl
        add eax,edx
        mov [edi+12],eax;
        and eax,eax

    }
};




integ128 integ128::operator <<(int Number)
{
    Vier Buffer;
    for (int i = 0; i < 4 ; i++) Buffer[i] = this->Numbers[i];
    Vier* Zeiger=&Buffer;
    __asm {
        mov edi,Zeiger;
        mov ebx,Number;
        and ebx,0x07f; //учёт максимально возможной величины сдвига = 127
        mov bh,bl;
        and ebx,0xE01F // в bh сдвиг в dword'ах, в bl - в битах;
        cmp bh,0
        je shifter;
        shr bh,5;
        xor edx,edx
        mov dl,bh;
        mov esi,edx
        xor edx,3;
        mov ecx,edx

        shl edx,2
        add edi,edx;
        xor edx,edx
        inc ecx
        lup:
        mov eax,[edi]
        mov [edi+esi*4],eax
        sub edi,4
        loop lup

        mov cl,bh

        lup1:mov dword ptr [edi+ecx*4],dword ptr 0;
        loop lup1;
        shifter: //битовый сдвиг
        mov edi,Zeiger
        mov cl,bl
        xor edx,edx
        xor ebx,ebx
        mov eax,dword ptr [edi];
        shld edx,eax,cl
        shl eax,cl
        mov [edi],eax;
        mov eax,[edi+4];
        shld ebx,eax,cl;
        shl eax,cl
        add eax,edx;
        xor edx,edx;
        mov [edi+4],eax;
        mov eax,[edi+8]
        shld edx,eax,cl
        shl eax,cl
        add eax,ebx
        mov [edi+8],eax;
//	xor ebx,ebx
        mov eax,[edi+12]
        shl eax,cl
        add eax,edx
        mov [edi+12],eax;
        and eax,eax

    };
    return integ128(Buffer[0],Buffer[1],Buffer[2],Buffer[3]);
};


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++ Операторы умножения (мультипликативные операторы) +++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void integ128::operator *=(integ128 second)
{
    Acht Buffer= {0,0,0,0,0,0,0,0};
    Acht Buffer1= {0,0,0,0,0,0,0,0};
    Acht * TBuf= &Buffer;



    __asm
    {

        mov edi,this.Numbers;
        mov eax,second.Numbers
        mul dword ptr [edi];//0
        mov	[Buffer],eax;
        mov ecx,edx
        mov eax,[second.Numbers+4]
        mul dword ptr [edi];//1
        mov ebx,0
        add ecx,eax
        mov eax,[second.Numbers+8]
        adc ebx,edx;
        mul dword ptr [edi];//2
        mov [Buffer+4],ecx;
        add ebx,eax;
        mov ecx,0;
        mov [Buffer+8],ebx;
        adc ecx,edx
        mov eax,[second.Numbers+12]
        mul dword ptr [edi];//3
        add ecx,eax;
        mov [Buffer+12],ecx;
        adc edx,0;
        mov [Buffer+16],edx
//+++++++++++++Lowest "Digit"
        mov ecx,3
        mov esi,TBuf
        cycle:	add	edi,4
        add esi,4
        push ecx
        mov eax,second.Numbers
        mul dword ptr [edi];//0
        mov	[Buffer1],eax;
        mov ecx,edx
        mov eax,[second.Numbers+4]
        mul dword ptr [edi];//1
        mov ebx,0
        add ecx,eax
        mov eax,[second.Numbers+8]
        adc ebx,edx;
        mul dword ptr [edi];//2
        mov [Buffer1+4],ecx;
        add ebx,eax;
        mov ecx,0;
        mov [Buffer1+8],ebx;
        adc ecx,edx
        mov eax,[second.Numbers+12]
        mul dword ptr [edi];//3
        add ecx,eax;
        mov [Buffer1+12],ecx;
        adc edx,0;
        mov [Buffer1+16],edx
// Do Result
        push edi
        mov eax,esi
        mov edi,eax
        mov eax,[Buffer1]
        add [edi],eax;
        mov eax,[Buffer1+4]
        adc [edi+4],eax;
        mov eax,[Buffer1+8]
        adc [edi+8],eax;
        mov eax,[Buffer1+12];
        adc [edi+12],eax;
        mov eax,[Buffer1+16]
        adc [edi+16],eax;
        pop edi
        pop ecx
        loop	cycle;
//saving the results
        mov edi,this.Numbers;
        mov eax,[Buffer]
        mov [edi],eax;
        mov eax,[Buffer+4]
        mov [edi+4],eax;
        mov eax,[Buffer+8]
        mov [edi+8],eax;
        mov eax,[Buffer+12]
        mov [edi+12],eax;
        mov edi,dword ptr this.Numbers
        add edi,0x10

        mov eax,[Buffer+16]
        mov [edi],eax;
        mov eax,[Buffer+20];
        mov [edi+4],eax;
        mov eax,[Buffer+24];
        mov [edi+8],eax;
        mov eax,[Buffer+28];
        mov [edi+12],eax;
    };


};

integ128 integ128::operator *(integ128 second) // Простое умножение 128-битных операндов
{
    Acht Buffer= {0,0,0,0,0,0,0,0};
    Acht Buffer1= {0,0,0,0,0,0,0,0};
    Acht * TBuf= &Buffer;



    __asm
    {

        mov edi,this.Numbers;
        mov eax,second.Numbers
        mul dword ptr [edi];//0
        mov	[Buffer],eax;
        mov ecx,edx
        mov eax,[second.Numbers+4]
        mul dword ptr [edi];//1
        mov ebx,0
        add ecx,eax
        mov eax,[second.Numbers+8]
        adc ebx,edx;
        mul dword ptr [edi];//2
        mov [Buffer+4],ecx;
        add ebx,eax;
        mov ecx,0;
        mov [Buffer+8],ebx;
        adc ecx,edx
        mov eax,[second.Numbers+12]
        mul dword ptr [edi];//3
        add ecx,eax;
        mov [Buffer+12],ecx;
        adc edx,0;
        mov [Buffer+16],edx
//+++++++++++++Lowest "Digit"
        mov ecx,3
        mov esi,TBuf
        cycle:	add	edi,4
        add esi,4
        push ecx
        mov eax,second.Numbers
        mul dword ptr [edi];//0
        mov	[Buffer1],eax;
        mov ecx,edx
        mov eax,[second.Numbers+4]
        mul dword ptr [edi];//1
        mov ebx,0
        add ecx,eax
        mov eax,[second.Numbers+8]
        adc ebx,edx;
        mul dword ptr [edi];//2
        mov [Buffer1+4],ecx;
        add ebx,eax;
        mov ecx,0;
        mov [Buffer1+8],ebx;
        adc ecx,edx
        mov eax,[second.Numbers+12]
        mul dword ptr [edi];//3
        add ecx,eax;
        mov [Buffer1+12],ecx;
        adc edx,0;
        mov [Buffer1+16],edx
// Do Result
        push edi
        mov eax,esi
        mov edi,eax
        mov eax,[Buffer1]
        add [edi],eax;
        mov eax,[Buffer1+4]
        adc [edi+4],eax;
        mov eax,[Buffer1+8]
        adc [edi+8],eax;
        mov eax,[Buffer1+12];
        adc [edi+12],eax;
        mov eax,[Buffer1+16]
        adc [edi+16],eax;
        pop edi
        pop ecx
        loop	cycle;
//saving the results
    };
    return integ128(Buffer);

};



char* integ128::Out()
{
    integ128 Buffer(this->Numbers[0],this->Numbers[1],this->Numbers[2],this->Numbers[3]);
    integ128 Zehn(10,0,0,0);
    integ128 Result(0,0,0,0);
    integ128 Zero(0,0,0,0);
    char Ziffer[10]= {'0','1','2','3','4','5','6','7','8','9'};
    int Ten=10;
    char Digits[40];
    for (int i=0; i<40; i++) Digits[i]=0;
    i=39;
    bool Nummer = true;
    while (Nummer)
    {
        //cout<<"Result ";
        //for (int n=0;n<4;n++) cout<<Result.Numbers[n]<<" ";
        //cout<<endl<<"Buffer ";
        //for (n=0;n<4;n++) cout<<Buffer.Numbers[n]<<" ";
        //cout<<endl;
        Result= Buffer % Zehn;
        Buffer/=Zehn;
        //cout<<"Result ";
        //for (n=0;n<4;n++) cout<<Result.Numbers[n]<<" ";
        //cout<<endl<<"Buffer ";
        //for (n=0;n<4;n++) cout<<Buffer.Numbers[n]<<" ";
        //cout<<endl;
        if (Buffer>=Zehn) {
            Digits[i]=Ziffer[Result.Numbers[0]];
            i--;
            //cout<<"Buffer>=Zehn"<<endl;
        }
        else
        {   Digits[i]=Ziffer[Result.Numbers[0]];
            i--;
            Nummer=false;
            //cout<<"Buffer<Zehn"<<endl;
        } ;

    };
    if (Buffer.Numbers[0]) Digits[i]=Ziffer[Buffer.Numbers[0]];
    //cout<<endl;
    for (i=0; i<40; i++) cout<<Digits[i];
    char* a = "              ";
//	for (i=0;i<40;i++) (*a)[i]=Digits[i];
    return a;
};

integ128::integ128(RegType n0,RegType n1,RegType n2,RegType n3)
{
    /*	Numbers[0]=n0;
    	Numbers[1]=n1;
    	Numbers[2]=n2;
    	Numbers[3]=n3;
    	for (int i=0;i<4;i++) Data[i]=0;*/
    __asm {
        mov edi,this
        mov eax,n0;
        mov dword ptr [edi],eax
        mov eax,n1
        mov [edi+4],eax
        mov eax,n2
        mov [edi+8],eax
        mov eax,n3
        mov [edi+12],eax

        mov [edi+16],eax
        mov [edi+20],eax
        mov [edi+24],eax
        mov [edi+28],eax
    };
};

integ128::integ128()
{
    for (int indx=0; indx<4; ++indx) Numbers[indx]=0;
    for (int i=0; i<4; i++) Data[i]=0;
};

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++ Операторы сложения и вычитания ++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void integ128::operator +=(integ128 second)
{

    __asm
    {
        push eax
        push edi
        mov edi,this.Numbers;
        mov eax,[second.Numbers];
        add [edi],eax;
        mov eax,[second.Numbers+4];
        adc [edi+4],eax;
        mov eax,[second.Numbers+8];
        adc [edi+8],eax;
        mov eax,[second.Numbers+12];
        adc [edi+12],eax;
        pop edi
        pop eax

    };

};


void integ128::operator -=(integ128 second)
{

    __asm
    {
        push eax
        push edi
        mov edi,this.Numbers;
        mov eax,second.Numbers;
        sub [edi],eax;
        mov eax,second.Numbers+4;
        sbb [edi+4],eax;
        mov eax,second.Numbers+8;
        sbb [edi+8],eax;
        mov eax,second.Numbers+12;
        sbb [edi+12],eax;
        pop edi
        pop eax

    };

};

integ128 integ128::operator+( integ128 second)
{
    RegType n0,n1,n2,n3;
    __asm {
        push eax
        mov eax,second.Numbers;
        add n0,eax;
        mov eax,second.Numbers+4;
        adc n1,eax;
        mov eax,second.Numbers+8;
        adc n2,eax;
        mov eax,second.Numbers+12;
        adc n3,eax;
        pop eax
    };
    return integ128(n0,n1,n2,n3);

};

integ128 integ128::operator-( integ128 second)
{
    RegType n0,n1,n2,n3;
    __asm {
        push eax
        mov eax,second.Numbers;
        sub n0,eax;
        mov eax,second.Numbers+4;
        sbb n1,eax;
        mov eax,second.Numbers+8;
        sbb n2,eax;
        mov eax,second.Numbers+12;
        sbb n3,eax;
        pop eax
    };
    return integ128(n0,n1,n2,n3);

};





int main(int argc, char* argv[])
{

    integ128 erdst(0,0xfffffff,0,0);
    //for (int i = 0; i<4;i++) erdst.Numbers[i]=0;
    //erdst.Numbers[0]=3;
    integ128 second(0x0,0x0,0x0,3);
    integ128 walter(1,0xfafafaf,0,0x0);
    cout<<walter.Out()<<endl;
    cout<<erdst.Out()<<endl;


    walter*=erdst;
    cout<<walter.Out()<<endl;


    return 0;
}
