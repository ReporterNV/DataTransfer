#include"fun.h"

int main(int argc, char *argv[])
{
	unsigned char x = 0;	//byte 

	FILE *file;
	FILE *out;


	if ((file = fopen(argv[1], "r+b")) == 0) {
		printf("Cannot open file:%s\n", argv[1]);
		return 0;
	}

	if ((out = fopen(argv[2], "w")) == 0) {
		printf("Cannot create file:%s\n", argv[2]);
		fclose(file);
		return 0;
	}
	if (!argv[3]) {
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
			puts("");

		}
	} else {
		while ((fscanf(file, "%hhc", &b1)) != EOF) {
			if (b1 == 10) {
				fprintf(out, "%c", 10);
				continue;
			}
			fscanf(file, "%hhc", &b2);
			printf("IN:");
			print_bin(b1);
			print_bin(b2);
			printf("OUT:");
			print_bin(repeat_decipher());
			fprintf(out, "%c", repeat_decipher());
			puts("");

		}
	}
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
	fclose(file);
	fclose(out);
	return 0;
}
