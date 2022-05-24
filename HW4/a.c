#include <stdio.h>
#include <stdlib.h>
int main(){
	FILE *fp;
	fp=fopen("deneme.img","w");
	char c='\n';
	fprintf(fp, "%cdeneme%c",c,c );
}