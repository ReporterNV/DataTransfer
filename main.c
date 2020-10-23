#include "functions.h"

int main(int argc, char *argv[])
{
	unsigned char x;
	unsigned char buff[2] = { 0, 0 };
	int opt;
	FILE *file = 0;
	FILE *out = 0;
	unsigned char *(*function)(unsigned char[]);

//set args

	while ((opt = getopt(argc, argv, ":if:o:")) != -1) {
		char *key;
		switch (opt) {

		case 'f':
			key = optarg;
			printf("fileIN: %s\n", key);
			file = fopen(key, "r+b");
			break;

		case 'o':
			key = optarg;
			printf("fileOUT: %s\n", key);
			out = fopen(key, "w");
			break;
/*		case 'm':
			if (*optarg == 'd')
				function = manchester_decipher;
			else
				function = manchester;
			break;
*/
		case ':':
			printf("this key need a value: %s\n", optarg);
			break;
		case '?':
			printf("unknown option: %c\n", optopt);
			break;
		case 'i':
			printf("add info how use it\n");
			break;
		default:
			puts("Unknown");
		}

	}
//check setted args
	//puts("point");
	if (file == 0) {
		printf("Cannot open read file.\n");
		if (out)
			fclose(out);
		return 0;
	}

	if (out == 0) {
		printf("Cannot open write file.\n");
		if (file)
			fclose(file);
		return 0;
	}

	while ((fscanf(file, "%hhc", &x)) != EOF) {
		fprintf(stdout, "%c", x);
		fprintf(out, "%c", x);
	}








	if (file)
		fclose(file);
	if (out)
		fclose(out);
	return 0;
}
