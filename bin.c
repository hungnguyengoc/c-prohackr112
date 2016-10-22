#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int maxbin(int x)
{
	int i, prev;
	if (x == 1) return 1;
	for (i = 1; i < 16777216; prev=i, i *= 2)
		if (i > x) return prev;
}

void printbin(int c)
{
	int r, d;
	r = d = 0;
	while (c > 0) {
		r = c % 2;
		d = c / 2;
		c -= d;
		printf("%d",r);
	}
}

int binfile(char *file)
{
	if (access(file,R_OK)) {
		fprintf(stderr,"Could not open file %s: %s\n",file,strerror(errno));
		return -1;
	} else {
		printf("Binary for file %s:\n",file);
	}

	FILE *f = fopen(file,"r");
	int c;
	while ((c = getc(f)) != EOF)
		printbin(c);
	fclose(f);
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		printf("Usage: bin [FILE]\n");
		return -1;
	}
	int i;
	for (i = 1; i < argc; i++)
		binfile(argv[i]);
}
