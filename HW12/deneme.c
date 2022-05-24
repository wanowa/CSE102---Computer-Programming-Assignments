#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	FILE *fp=fopen("reference.txt","r");
	int i=0;
	char str[1000000];
	fgets(str,1000000,fp);
	printf("%s\n",str );
	fgets(str,1000000,fp);
	printf("%s\n",str );
	fgets(str,1000000,fp);
	printf("%s\n",str );
	fgets(str,1000000,fp);
	printf("%s\n",str );	
}