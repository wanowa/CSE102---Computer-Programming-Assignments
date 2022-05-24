#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void read_news(char buffer[500], char file_path[10], int is_Only_Title);	
void menu();
void append_file(char* file_path, char c);
void read_magic_numbers(char buffer_magic[10], char buffer_news[500]);
double f_func(int x);
double g_func(double f(int x), int a);
int main(){
	menu();
}

void menu(){
	char c,n,d,read_again,buffer[500],buffer_news[500],buffer_magic[10],file_path[10],o,a;
	int n1=0,n2=0,n3=0,n4=0,z1=0,z2=0,z3=0,z4=0,i=1,size;
	FILE *fp;
	fp=fopen("readed_news_id.txt","r");
	while(!feof(fp)){
		fscanf(fp,"%c",&a);
		if (a=='1'){
			n1=1;
		}
		else if(a=='2'){
			n2=1;
		}
		else if(a=='3'){
			n3=1;
		}
		else if(a=='4'){
			n4=1;
		}
	}
	fclose(fp);
	while(i==1){
		printf("**********Daily Press**************\n\n");
		printf("Today's news are listed for you :\n\n");
		printf("Title of 1. news:");
		read_news(buffer,"news/1.txt",1);
		printf("Title of 2. news:");
		read_news(buffer,"news/2.txt",1);
		printf("Title of 3. news:");
		read_news(buffer,"news/3.txt",1);
		printf("Title of 4. news:");
		read_news(buffer,"news/4.txt",1);
		printf("\nWhat do you want to do?\na.Read a new\nb.List the readed news\nc.Get decrypted information from the news\n");
		scanf(" %c",&c);
		if(c=='a'||c=='A'){
			printf("\nWhich news text you want to read:");
			scanf(" %c",&n);
			if(n=='1'){
				if(n1==1){
					printf("This news has been read before. Do you want to read it again? Yes(1) / No(0):\n");
					scanf(" %c",&read_again);
				}
				else{
					read_news(buffer,"news/1.txt",0);
					n1=1;
				}
				if(read_again=='1'){
					read_news(buffer,"news/1.txt",0);
				}
			} 
			else if(n=='2'){
				if(n2==1){
					printf("This news has been read before. Do you want to read it again? Yes(1) / No(0):\n");
					scanf(" %c",&read_again);
				}
				else{
					read_news(buffer,"news/2.txt",0);
					n2=1;
				}
				if(read_again=='1'){
					read_news(buffer,"news/2.txt",0);
				}
			} 
			else if(n=='3'){
				if(n3==1){
					printf("This news has been read before. Do you want to read it again? Yes(1) / No(0):\n");
					scanf(" %c",&read_again);
				}
				else{
					read_news(buffer,"news/3.txt",0);
					n3=1;
				}
				if(read_again=='1'){
					read_news(buffer,"news/3.txt",0);
				}
			} 
			else if(n=='4'){
				if(n4==1){
					printf("This news has been read before. Do you want to read it again? Yes(1) / No(0):\n");
					scanf(" %c",&read_again);
				}
				else{
					read_news(buffer,"news/4.txt",0);
					n4=1;
				}
				if(read_again=='1'){
					read_news(buffer,"news/4.txt",0);
				}
				read_again='0';
			} 
			else{
				printf("You entered wrong.\n");
			}
			append_file("readed_news_id.txt",n);
		}
		else if (c=='b'||c=='B')
		{
			fp=fopen("readed_news_id.txt","r");
			fscanf(fp,"%c",&o);
			printf("\nReaded news are listed below:\n");
			if(o!='1'&&o!='2'&&o!='3'&&o!='4'){
				printf("No news readed\n");
			}
			else{
				while(!feof(fp)){
					if(o=='1'&&z1==0){
						printf("1. new is readed\n");
						z1=1;
						n1=1;
					}
					else if(o=='2'&&z2==0){
						printf("2. new is readed\n");
						z2=1;
						n2=1;
					}
					else if(o=='3'&&z3==0){
						printf("3. new is readed\n");
						z3=1;
						n3=1;
					}
					else if(o=='4'&&z4==0){
						printf("4. new is readed\n");
						z4=1;
						n4=1;
					}
					fscanf(fp,"%c",&o);
				}
				z1=0;z2=0;z3=0;z4=0;
			}
			fclose(fp);
		}
		else if(c=='c'||c=='C'){
			read_magic_numbers(buffer_magic,buffer_news);
		}

		printf("\nDo you want to continue? Yes(y)/No(n):\n");
		scanf(" %c",&d);
		if(d=='y'||d=='Y'){
			i=1;
		}
		else if(d=='n'||d=='N'){
			i=0;
		}
		else{
		 	printf("You entered wrong.\n");
		 	i=0;
		}
		if(i==0){
			printf("Good Bye!\n");
		}
	}
}

void read_news(char buffer[], char file_path[], int is_Only_Title){
	char a;
	int i=0,j=1;
	FILE *fp;
	fp=fopen(file_path,"r");
	if(is_Only_Title==1){
		while(j==1){
			fscanf(fp,"%c",&a);
			printf("%c",a);
			buffer[i]=a;
			i++;
			if (a=='\n')
			{
				j=0;
			}
		}
	}
	else if(is_Only_Title==0){
		while(!feof(fp)){
			fscanf(fp,"%c",&a);
			printf("%c",a);
			buffer[i]=a;
			i++;
		}
	}
	fclose(fp);
}

void append_file(char* file_path, char c){
	FILE *fp;
	fp=fopen(file_path,"a+");
	fprintf(fp,"%c",c);
	fclose(fp);
}

void read_magic_numbers(char buffer_magic[10], char buffer_news[500]){
	int i=0,j=0,num,x,decrypt;
	double magic,sum=0;
	printf("\nWhich news would you like to decrypt?:");
	scanf("%d",&decrypt);
	FILE *fp;
	if(decrypt==1){
		fp=fopen("news/1.txt","r");
		while(!feof(fp)){
			fscanf(fp,"%c",&buffer_news[i]);
			printf("%c",buffer_news[i]);
			if(buffer_news[i-1]=='#'){
				num=buffer_news[i]-48;
				buffer_magic[j]=buffer_news[i];
				j++;
				magic=g_func(f_func,num);
				sum=sum+magic;
			}
			i++;
		}
		printf("\nNumber of tests performed:%.2lf\n",sum);
	}
	else if(decrypt==2){
		fp=fopen("news/2.txt","r");
		while(!feof(fp)){
			fscanf(fp,"%c",&buffer_news[i]);
			printf("%c",buffer_news[i]);
			if(buffer_news[i-1]=='#'){
				num=buffer_news[i]-48;
				buffer_magic[j]=buffer_news[i];
				j++;
				magic=g_func(f_func,num);
				sum=sum+magic;
			}
			i++;
		}
		printf("\nNumber of sick people:%.2lf\n",sum);
	}
	else if(decrypt==3){
		fp=fopen("news/3.txt","r");
		while(!feof(fp)){
			fscanf(fp,"%c",&buffer_news[i]);
			printf("%c",buffer_news[i]);
			if(buffer_news[i-1]=='#'){
				num=buffer_news[i]-48;
				buffer_magic[j]=buffer_news[i];
				j++;
				magic=g_func(f_func,num);
				sum=sum+magic;
			}
			i++;
		}
		printf("\nNumber of deaths:%.2lf\n",sum);
	}
	else if(decrypt==4){
		fp=fopen("news/4.txt","r");
		while(!feof(fp)){
			fscanf(fp,"%c",&buffer_news[i]);
			printf("%c",buffer_news[i]);
			if(buffer_news[i-1]=='#'){
				num=buffer_news[i]-48;
				buffer_magic[j]=buffer_news[i];
				j++;
				magic=g_func(f_func,num);
				sum=sum+magic;
			}
			i++;			
		}
		printf("\nExpected number of sick people:%.2lf\n",sum);
	}
	fclose(fp);
}

double f_func(int x){
	return x*x*x-x*x+2;
}

double g_func(double f(int x), int a){
	a=f(a);
	return a*a;
}