#include <stdio.h> 
#include <unistd.h> 
#include <string.h>

void bin_out(unsigned char x)	//Выводит в бинарном формате
{
	for (int i = 7; i >= 0; i--)	//Мб сделать на смещении в условиях на огр и на инкр
		printf("%x ", (x >> i) % 2);
}

unsigned char* manchester (unsigned char[]);
unsigned char* manchester_decipher (unsigned char[]);