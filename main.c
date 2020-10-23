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
//set args

	while ((opt = getopt(argc, argv, ":if:o:t:")) != -1) {
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
				function = manchester_deciphe;
			else
				function = manchester;
						break;
*/
			   case 't':
			   if (*optarg == 'd')
			   function = test_deciphe;
			   else
			   function = test;
			   break;
			 
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


	while ((fscanf(file, "%c", &x)) != EOF) {
		buff[0] = x;
		//fprintf(out, "%c", x);
		//printf("%c[%d]:\n", x, x);
		//bin_out(x);
		function(buff);
		bin_out(buff[0]);
		//bin_out(buff[1]);
		fprintf(out, "%c", buff[0]);
		fprintf(out, "%c", buff[1]);
	}

	if (file)
		fclose(file);
	if (out)
		fclose(out);
	return 0;
}
