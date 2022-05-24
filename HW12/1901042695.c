#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct characters{
	int number;
	char c;
}characters;
int main(){
	int i=0,j=0,k=0,check=0;
	char str[1000];
	FILE *fp=fopen("reference.txt","r");
	characters arr[100];
	while(!feof(fp)){
		fgets(str,1000,fp);
		while(str[i]!='\0'){
			while(j<100){
				if(str[i]==arr[j].c){
					check=1;
					arr[j].number=arr[j].number+1;
				}
				j++;
			}
			if(check==0){
				arr[k].c=str[i];
				arr[k].number=1;
				k++;
			}
			i++;
			j=0;
			check=0;
		}
		i=0;
	}
	for(i=0;i<k;i++){
		printf("CHARACTER='%c'   USED %d TIMES\n",arr[i].c,arr[i].number);
	}
}