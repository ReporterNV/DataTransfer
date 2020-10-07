#include<stdio.h>
#include<unistd.h>
#include"fun.h"


int main(int argc, char *argv[])
{
	unsigned char x = 0;	//byte 
	
	x = 0b00000000;
	for(x = 0b00000000;x<=0b11111110;x+=0b00000001){
	repeat(x);
	printf("%d)", x);
	bin_out(x);
	printf(": ");
	bin_out(b1);
	printf(" - ");
	bin_out(b2);
	printf("\n\n");	}	
///	printf("%x: %x - %x\n", x, b1, b2);}
/*	if((b1 == 0b00000000)&&(b2 == 0b00000000))
		printf("PASS\n");
	x = 0b00000001;
	repeat(x);
	if((b1 == 0b00000000)&&(b2 == 0b00000011))
		printf("PASS\n");
*/
/*
	FILE *file;
	FILE *out;

	printf("ARG: %s\n", argv[1]);
	printf("ARG: %s\n", argv[2]);
	printf("ARG: %s\n", argv[3]);

	if ((file = fopen(argv[1], "r+b")) == 0) {
		printf("Cannot open file:%s\n", argv[1]);
		return 0;
	}
	if ((out = fopen(argv[2], "w")) == 0) {
		printf("Cannot create file:%s\n", argv[2]);
		fclose(file);
		return 0;
	}
	
	

	while ((fscanf(file, "%hhc", &x)) != EOF) {
		if (x == 10) {
			fprintf(out, "%c", 10);
			continue;
		}
		printf("IN:");
		print_bin(x);
		repeat(x);
		printf("OUT:");
		print_bin(b1);
		fprintf(out, "%c", b1);
		print_bin(b2);
		fprintf(out, "%c", b2);
	}
*/
/*	
	while((fscanf(file, "%hhc", &b1)) != EOF){ 
	if(x == 10){
		fprintf(out, "%c", 10);
		continue;}
	fscanf(file, "%hhc", &b2); 	
	repeat_decipher();
	puts("");
	}
*/

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
//	fclose(file);
//	fclose(out);
	return 0;
}
