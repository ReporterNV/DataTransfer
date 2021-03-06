#include "functions.h"

int main(int argc, char *argv[])
{
	unsigned char x;
	unsigned char buff[2] = { 0, 0 };
	int opt;
	FILE *file = 0;
	FILE *out = 0;
	void (*function)(unsigned char *);
	enum type { chipher, dechipher };
	enum type action = chipher;
//set args

	while ((opt = getopt(argc, argv, ":hf:o:t:d:m:r:i:")) != -1) {
		char *key;
		switch (opt) {

		case 'f':
			key = optarg;
			//printf("fileIN: %s\n", key);
			file = fopen(key, "r+b");
			break;

		case 'o':
			key = optarg;
			//printf("fileOUT: %s\n", key);
			out = fopen(key, "w");
			break;
		case 'm':
			if (*optarg == 'd') {
				function = manchester_deciphe;
				action = dechipher;
			} else {
				function = manchester;
				action = chipher;
			}
			break;

		case 't':
			if (*optarg == 'd') {
				function = test_deciphe;
				action = dechipher;

			} else {
				function = test;
				action = chipher;
			}
			break;
		case 'd':
			if (*optarg == 'd') {
				function = duplication_deciphe;
				action = dechipher;

			} else {
				function = duplication;
				action = chipher;
			}
			break;
		case 'r':
			if (*optarg == 'd') {
				function = repeat_deciphe;
				action = dechipher;

			} else {
				function = repeat;
				action = chipher;
			}
			break;

		case ':':
			printf("this key need a value: %s\n", optarg);
			break;
		case '?':
			printf("unknown option: %c\n", optopt);
			break;
		case 'h':
			printf
			    ("Usage: ./lab1 -f file_for_read -o file_for_out -{code_type} -{d,c} \n");
			printf("-c encrypt\n");
			printf("-d dechiphe\n");
			printf("-h help\n");
			printf("\nCode types:\n");
			printf("-m Manchester code\n");
			printf("-d Duplication code\n");
			printf("-r Repeat code\n");
			printf("-i Inversionepeat code\n");
			printf("-2 Two-Ten\n");
			printf("-g Grey code\n");
			printf("-t TEST code\n\n");
			printf("work only with ASCII\n");
			if (file)
				fclose(file);
			if (out)
				fclose(out);
			return 0;
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
	if (action == chipher) {
		while ((fscanf(file, "%c", &x)) != EOF) {
			buff[0] = x;

			printf("IN: %c[%d]: ", x, x);
			bin_out(x);
			function(buff);

			printf("OUT1: %c[%d]: ", buff[0], buff[0]);
			bin_out(buff[0]);
			printf("OUT2: %c[%d]: ", buff[1], buff[1]);
			bin_out(buff[1]);
			fprintf(out, "%c", buff[0]);
			fprintf(out, "%c", buff[1]);
			puts("_______\n");
		}
	} else {
		while ((fscanf(file, "%c", &x)) != EOF) {
			buff[0] = x;
			if ((fscanf(file, "%c", &x)) == EOF) {
				puts("ERROR. CANNOT READ BYTE.\nEXIT\n\n");
				return 0;
			}
			buff[1] = x;
			printf("IN1: %c[%d]: ", buff[0], buff[0]);
			bin_out(buff[0]);
			printf("IN2: %c[%d]: ", buff[1], buff[1]);
			bin_out(buff[1]);

			function(buff);

			printf("OUT1: %c[%d]: ", buff[0], buff[0]);
			bin_out(buff[0]);

			fprintf(out, "%c", buff[0]);
			fprintf(out, "%c", buff[1]);

			puts("_______\n");

		}
	}
	if (file)
		fclose(file);
	if (out)
		fclose(out);
	return 0;
}
