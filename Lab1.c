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
	for (int i = 7; i >= 0; i--)	//Мб сделать на смещении в условиях на огр и на инкр
		printf("%x ", (x >> i) % 2);
	puts("");
}

unsigned char repeat_decipher()	//Кодирование дублированием
{
	unsigned char c = 0;
	for (int i = 0; i <= 3; i++)
		c += (b1 >> i * 2) % 2 << 4+i;
	
	for (int i = 0; i <= 3; i++)//Переписать со смещением?
		c += (b2 >> i * 2) % 2 << i;
	return c;
}

void repeat(unsigned char x)	//Кодирование дублированием
{
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

void main(int argc, char*argv[])
{
	unsigned char x = 0;	//byte 
	FILE *file = fopen("text", "r+b");
	FILE *out = fopen("out", "w");
	while((fscanf(file, "%hhc", &x)) != EOF){ 
	if(x == 10){
		fprintf(out, "%c", 10);
		continue;}	
	printf("IN:");
	print_bin(x);
//	x = 0b10101010;
	//b1 = 0b00111111;
	//b2 = 0b11001100;
	repeat(x);
	printf("OUT:");
	print_bin(b1);
	fprintf(out,"%c",b1);
	print_bin(b2);
	fprintf(out,"%c",b2);
	print_bin(repeat_decipher());
	puts("");

}
	//x= 0b10110101;
	/*printf("IN:");

	   print_bin(x);
	   puts("");
	   printf("OUT:");
	   repeaT(X);
	   puts("");
	   print_bin(b1);
	   puts("");
	   print_bin(b2);

	   puts("");
	   fprintf(out, "%c", b1);
	   fprintf(out, "%c", b2);
	 */
	fclose(file);
	fclose(out);
}
