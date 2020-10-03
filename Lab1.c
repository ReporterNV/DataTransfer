#include<stdio.h>
unsigned char b1 = 0;
unsigned char b2 = 0;

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
	for (int i = 7; i >= 0; i--)
		printf("%x ", (x >> i) % 2);
	puts("");
}

void repeat(unsigned char x)	//Кодирование дублированием
{
	unsigned char out;
	for (int i = 7; i >= 4; i--) {
		out = (x >> i) % 2;
		printf("%x ", out);
		b1 += out << (2 * i - 7);
		b1 += out << (2 * i - 8);
	}

	for (int i = 3; i >= 0; i--) {
		out = (x >> i) % 2;
		printf("%x ", out);
		b2 += out << (2 * i + 1);
		b2 += out << (2 * i);
	}

	puts("");
}

void main()
{
	unsigned char x = 0;	//byte 
	FILE *file = fopen("text", "r+b");
	fread(&x, sizeof(x), 1, file);
//x= 0b10110101;
	printf("IN:");
	print_bin(x);
	puts("");
	printf("OUT:");
	repeat(x);
	puts("");
	print_bin(b1);
	puts("");
	print_bin(b2);
	puts("");
	printf("%c", b1);
	printf("%c", b2);
	fclose(file);
}
