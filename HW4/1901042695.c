#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>void read_news(char buffer[500], char file_path[10], int is_Only_Title)
#include <string.h>
char decrypt_numbers (int);
void decrypt_and_print (char*);
void menu();
void deep_decrypt_and_print (char*);
void track_machine();
void refresh_position(int*,int*,double*,double*);
void encrypt_messages (char*);

int main(){
	srand(time(NULL));
	menu();
}

void menu(){
	char c;
	while(1){
		printf("\n1-) Decrypt and print encrypted_p1.img\n");
		printf("2-) Decrypt and print encrypted_p2.img\n");
		printf("3-) Switch on the tracking machine\n");
		printf("4-) Encrypt the message\n");
		printf("5-) Switch off\n");
		printf("\nPlease make your choice:\n");
		scanf(" %c",&c);
		if (c=='1')
		{
			decrypt_and_print ("encrypted_p1.img");
		}
		else if (c=='2')
		{
			deep_decrypt_and_print ("encrypted_p2.img");
		}
		else if (c=='3')
		{
			track_machine ();
		}
		else if (c=='4')
		{
			encrypt_messages ("decrypted_p4.img");
		}
		else if (c=='5')
		{
			printf("\nProgram Ended\n");
			break;
		}
		else{
			printf("\nYou entered wrong, please try again.");
		}
	}
}

void decrypt_and_print (char* ptr){
	int i;
	char s,number;
	FILE *fp;
	fp=fopen(ptr,"r");
	while(!feof(fp)){
		fscanf(fp,"%c",&number);
		s=decrypt_numbers(number);
		printf("%c",s);
	}
	fclose(fp);
}

char decrypt_numbers (int number){
	char s;
	switch(number){
		case '0': s=' '; break;
		case '1': s='-'; break;
		case '2': s='_'; break;
		case '3': s='|'; break;
		case '4': s='/'; break;
		case '5': s='\\'; break;
		case '6': s='O'; break;
		default : s='\n';
	}
	return s;
}

void deep_decrypt_and_print (char* ptr2){
	int i,j,sum=0,sayac=0,number;
	char s1,s2,s3,s,n;
	FILE *fp2;
	fp2=fopen(ptr2,"r");
	fscanf(fp2,"%c",&s1);
	fscanf(fp2,"%c",&s2);
	printf("  ");
	for (i=0;!feof(fp2);i++)
	{
		fscanf(fp2,"%c",&s3);
		if(s3=='\n'){
			printf("\n");
		}
		else
		{
			sum=(int)s1-48+s2-48+s3-48;
			number=sum%7;
			if(number==0){
				s=' ';
			}
			else if(number==1){
				s='-';
			}
			else if(number==2){
				s='_';
			}
			else if(number==3){
				s='|';
			}
			else if(number==4){
				s='/';
			}
			else if(number==5){
				s='\\';
			}
			else if(number==6){
				s='O';
			}
			printf("%c",s);
		}
		sum=0;
		s1=s2;
		s2=s3;
	}
	fclose(fp2);
}

void track_machine (){
	int ox=6,oy=6,ex=1,ey=1,x,y,tmpx=1,tmpy=1,a=1,s=1;
	double r=0,d=0;
	char c;
	d=sqrt((ex-ox)*(ex-ox)+(ey-oy)*(ey-oy));
	r=sqrt((ex-tmpx)*(ex-tmpx)+(ey-tmpy)*(ey-tmpy));
	while(a==1){
		for(x=1;x<12;x++){
			for(y=1;y<12;y++){
				if(y==oy&&x==ox&&y==ey&&x==ex){
					printf("OE\t");
				}
				else if(y==oy&&x==ox){
					printf("O\t");
				}
				else if(y==ey&&x==ex){
					printf("E\t");
				}
				else{
					printf(".\t");
				}
			}
			printf("\n");
		}
		printf("\nEnemies X position: %d, Y position: %d, Displacement: %.2lf, Distance to our camp: %.2lf",ex,ey,r,d);
		s=1;
		while(s==1){
			s=0;
			printf("\nCommand waiting...:");
			scanf(" %c",&c);
			if(c=='r'||c=='R'){
				a=1;
				refresh_position(&ex,&ey,&d,&r);
			}
			else if(c=='e'||c=='E'){
				a=0;
				printf("\nTrack ended.\n");
			}
			else{
				printf("\nYou entered wrong command, please try again.");
				s=1;
			}
		}
	}
}

void refresh_position (int *X, int *Y, double *D, double *R){
	int tmpx,tmpy,ox=6,oy=6;
	tmpx=*X;
	tmpy=*Y;
	*X=rand()%11+1;
	*Y=rand()%11+1;
	*R=sqrt((*X-tmpx)*(*X-tmpx)+(*Y-tmpy)*(*Y-tmpy));
	*D=sqrt((*X-ox)*(*X-ox)+(*Y-oy)*(*Y-oy));
}

void encrypt_messages (char* ptr4){
	FILE *fp4;
	FILE *fpw;
	char s=0,n='\n';
	int sum=0,i=1,number=0,a1,a2,a3;
	fp4=fopen(ptr4,"r");
	fpw=fopen("encrypted_p4.img","w");
	while(!feof(fp4)){
		
		fscanf(fp4,"%c",&s);
		if(s=='\n'){
			fprintf(fpw,"%c",n);
			i=1;
			a1=0;
			a2=0;
			a3=0;
		}
		else{
			if(i==1){
				if(s==' '){
					a3=0;
					sum=a3;
				}
				else if(s=='-'){
					a3=1;
					sum=a3;
				}
				else if(s=='_'){
					a3=2;
					sum=a3;
				}
				else if(s=='|'){
					a3=3;
					sum=a3;
				}
				else if(s=='/'){
					a3=4;
					sum=a3;
				}
				else if(s=='\\'){
					a3=5;
					sum=a3;
				}
				else if(s=='O'){
					a3=6;
					sum=a3;
				}
			}
			else if(i==2){
				a2=a3;
				if(s==' '){
					a3=0;
					sum=a2+a3;
				}
				else if(s=='-'){
					a3=1;
					sum=a2+a3;
				}
				else if(s=='_'){
					a3=2;
					sum=a2+a3;
				}
				else if(s=='|'){
					a3=3;
					sum=a2+a3;
				}
				else if(s=='/'){
					a3=4;
					sum=a2+a3;
				}
				else if(s=='\\'){
					a3=5;
					sum=a2+a3;
				}
				else if(s=='O'){
					a3=6;
					sum=a2+a3;
				}
			}
			else{
				a1=a2;
				a2=a3;
				if(s==' '){
					a3=0;
					sum=a1+a2+a3;
				}
				else if(s=='-'){
					a3=1;
					sum=a1+a2+a3;
				}
				else if(s=='_'){
					a3=2;
					sum=a1+a2+a3;
				}
				else if(s=='|'){
					a3=3;
					sum=a1+a2+a3;
				}
				else if(s=='/'){
					a3=4;
					sum=a1+a2+a3;
				}
				else if(s=='\\'){
					a3=5;
					sum=a1+a2+a3;
				}
				else if(s=='O'){
					a3=6;
					sum=a1+a2+a3;
				}
			}
		number=sum%7;
		fprintf(fpw,"%d",number);
		sum=0;
		number=0;
		}
		i++;
	}
	fclose(fp4);
	fclose(fpw);
}