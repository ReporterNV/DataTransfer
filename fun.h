#include<stdio.h>
#include<string.h>

unsigned char b1 = 0;
unsigned char b2 = 0;
//add getopt
void bin_out(unsigned char x)	//Выводит в бинарном формате
{
	for (int i = 7; i >= 0; i--)	//Мб сделать на смещении в условиях на огр и на инкр
		printf("%x ", (x >> i) % 2);
}

void out_bin(unsigned char x)	//Закидывает 2ичное значение в перемен
{
	printf("%x\n", x);
	for (int i = 7; i >= 0; i--) {
		unsigned char out = (x >> i) % 2;
		printf("%x ", out);
		b1 += out << i;
	}
	puts("");

	puts("");
	printf("%x", b1);
	puts("");
}

void print_bin(unsigned char x)	//Выводит в бинарном формате
{
	printf("%x(%c)[%d]\n", x, x, x);
	for (int i = 7; i >= 0; i--)	//Мб сделать на смещении в условиях на огр и на инкр
		printf("%x ", (x >> i) % 2);
	puts("");
}

unsigned char dupl_decipher()	//Кодирование дублированием
{
	unsigned char c = 0;
	for (int i = 0; i <= 3; i++)
		c += (b1 >> i * 2) % 2 << 4 + i;

	for (int i = 0; i <= 3; i++)	//Переписать со смещением?
		c += (b2 >> i * 2) % 2 << i;
	return c;
}

void manchester_code(unsigned char x)	//Манчес
{	
	b1 = b2 = 0;

	unsigned char out;
	for (int i = 7; i >= 4; i--) {
		out = (x >> i) % 2;
		b1 += out << (2 * i - 7);
		b1 += !out << (2 * i - 8);
	}

	for (int i = 3; i >= 0; i--) {
		out = (x >> i) % 2;
		b2 += out << (2 * i + 1);
		b2 += !out << (2 * i);
	}
}

unsigned char manchester_decode(unsigned char x){	//Декодер Манчестерского кода
unsigned char c = 0;
	for (int i = 0; i <= 3; i++)
		c += (b1 >> i * 2) % 2 << 4 + i;

	for (int i = 0; i <= 3; i++)	//Переписать со смещением?
		c += (b2 >> i * 2) % 2 << i;
	return c;
}
void dupl(unsigned char x)	//кодирование дублированием
{	
	b1 = b2 = 0;

	unsigned char out;
	for (int i = 7; i >= 4; i--) {
		out = (x >> i) % 2;
		b1 += out << (2 * i - 7);
		b1 += out << (2 * i - 8);
	}

	for (int i = 3; i >= 0; i--) {
		out = (x >> i) % 2;
		b2 += out << (2 * i + 1);
		b2 += out << (2 * i);
	}
}

void test(void){
	unsigned char x = 0b00000000;
	for(x = 0b00000000;x<0b11111111;x+=0b00000001){
	dupl(x);
	printf("%d)", x);
	bin_out(x);
	printf(": ");
	bin_out(b1);
	printf(" - ");
	bin_out(b2);
	b1 = b2 = 0;
	printf("\n\n");	}
}
