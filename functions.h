#include <stdio.h>
#include <unistd.h>
#include <string.h>

void bin_out(unsigned char x)	//Выводит в бинарном формате
{
	for (int i = 7; i >= 0; i--)	//Мб сделать на смещении в условиях на огр и на инкр
		printf("%x ", (x >> i) % 2);
	puts("");
}

void test(unsigned char byte[])
{
	unsigned char bit;
	unsigned char x = byte[0];
	byte[0] = 0;		//bcz we use summ
	byte[1] = 0;
	for (int i = 7; i >= 4; i--) {
		bit = (x >> i) % 2;
		byte[0] += bit << (2 * i - 7);
		byte[0] += bit << (2 * i - 8);
	}
	for (int i = 3; i >= 0; i--) {
		bit = (x >> i) % 2;
		byte[1] += bit << (2 * i + 1);
		byte[1] += bit << (2 * i);
	}
}

void test_deciphe(unsigned char byte[])
{
	unsigned char bit;
	unsigned char x = 0;

	for (int i = 0; i <= 3; i++) {
		bit = (byte[0] >> (i * 2)) % 2;
		if (bit != (byte[0] >> ((i * 2) + 1)) % 2)
			fprintf(stderr,
				"\nPOSSIBLE ERROR. BITS ARE NOT EQUAL.\n");
		x += bit << 4 + i;
	}
	for (int i = 0; i <= 3; i++) {
		bit = (byte[1] >> (i * 2)) % 2;
		if (bit != (byte[1] >> ((i * 2) + 1)) % 2)
			fprintf(stderr,
				"\nPOSSIBLE ERROR. BITS ARE NOT EQUAL:%x != %x\n",
				bit, (byte[1] >> ((i * 2) + 1)) % 2);
		x += bit << i;
	}
	byte[0] = x;
	byte[1] = 0;
}

void manchester(unsigned char[]);
unsigned char *manchester_deciphe(unsigned char[]);
