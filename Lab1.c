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
	switch (argv[3][0]) {
	case 'm':
		if (strcmp(argv[3], "md")) {
			while ((fscanf(file, "%hhc", &x)) != EOF) {
				if (x == 10) {
					fprintf(out, "%c", 10);
					continue;
				}
				dupl(x);
				fprintf(out, "%c", b1);
				fprintf(out, "%c", b2);
				printf(".");

			}
		} else {

			while ((fscanf(file, "%hhc", &b1)) != EOF) {
				if (b1 == 10) {
					fprintf(out, "%c", 10);
					continue;
				}
				fscanf(file, "%hhc", &b2);
				fprintf(out, "%c", dupl_decipher());
				printf(".");
			}
		}

		break;
	case 'd':
		if (strcmp(argv[3], "dd")) {
			while ((fscanf(file, "%hhc", &x)) != EOF) {
				if (x == 10) {
					fprintf(out, "%c", 10);
					continue;
				}
				dupl(x);
				fprintf(out, "%c\n", b1, b2);
				printf(".");

			}
		} else {

			while ((fscanf(file, "%hhc", &b1)) != EOF) {
				if (b1 == 10) {
					fprintf(out, "%c", 10);
					continue;
				}
				fscanf(file, "%hhc", &b2);
				fprintf(out, "%c", dupl_decipher());
				printf(".");
			}
		}

		break;
	default:
		printf("Cannot work with this arg: %s", argv[3]);
	}

	fclose(file);
	fclose(out);
	return 0;
}
