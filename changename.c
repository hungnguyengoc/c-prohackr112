#include <stdio.h>

void makemap(int i, FILE *origin)
{
	char buf[100] = {0};
	int x;
	FILE *fbuf = fmemopen(buf,sizeof(buf),"w");
	fprintf(fbuf,"dungeon_%d.map",i);
	fclose(fbuf);
	fbuf = fopen(buf,"w");
	while ((x = getc(origin)) != EOF)
		putc(x,fbuf);
	fclose(fbuf);
}

int main(void)
{
	FILE *origin = fopen("dungeon_1.map","r");
	int i;
	for (i = 2; i <= 25; i++) {
		makemap(i,origin);
		rewind(origin);
	}
	fclose(origin);	
}
