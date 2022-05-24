#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PI 3.14159265358979323846
struct point{
	char name[10];
	double x;
	double y;
}*p_ptr;

struct line{
	char name[10];
	struct point start;
	struct point end;
}*l_ptr;

struct polygon{
	char name[10];
	struct point vertices[20];
	int kose_sayisi;
}*pp_ptr;

void data(char satir[100],char str[20][10],int *p,int *l,int *pp);
void distance(char satir[100],char *fname, FILE *fwrite);
void angle(char satir[100],char *fname, FILE *fwrite);
void length(char satir[100],char *fname, FILE *fwrite);
void area(char satir[100],char *fname, FILE *fwrite);

int main(){
	p_ptr=(struct point*) malloc(100*sizeof(struct point));
	l_ptr=(struct line*) malloc(100*sizeof(struct line));
	pp_ptr=(struct polygon*) malloc(100*sizeof(struct polygon));
	char satir[100],scan,*end,temp[100],str[20][10],*fname,*command;
	int i,j=0,k=0,m=0,n=0,e=0,line,kose_sayisi[100]={0},find=0,sayac=0,number;
	int p=0,l=0,pp=0;
	double x,y;
	command=(char*)malloc(10*sizeof(char));
	fname=(char*)malloc(30*sizeof(char));
	FILE *fread;
	fread=fopen("commands.txt","r");
	fgets(satir,100,fread);
	fgets(satir,100,fread);
	line=strtol(satir,&end,10);
	for(i=0;i<line;i++){
		fgets(satir,100,fread);
		if(satir[0]>64&&satir[0]<91){
			memset(str,0,sizeof(str[0][0])*20*10);
			data(satir,str,&p,&l,&pp);
		}
		
		else{
			memset(str,0,sizeof(str));
			x=strtod(satir,&end);
			while(satir[k]==' '){
				k++;
			}
			while(satir[k]!=' '){
				k++;
			}
			while(satir[k]==' '){
				k++;
			}
			while(satir[k]!=' '){
				temp[j]=satir[k];
				k++;
				j++;
			}
			j=0;
			y=strtod(temp,&end);
			while(satir[k]==' '){
				k++;
			}
			while(j<2){
				str[i][j]=satir[k];
				j++;
				k++;
			}
			fflush(stdout);
			(p_ptr+i)->x=x;
			(p_ptr+i)->y=y;
			strcpy((p_ptr+i)->name,str[i]);
			fflush(stdout);
			j=0;
			k=0;
		}
	}

	while(strncmp(satir,"actions",7)!=0){
		fgets(satir,100,fread);
	}
	fgets(satir,100,fread);
	strncpy(fname,satir,30);
	int s=strlen(fname);
	fname[s-2]=0;
	fgets(satir,100,fread);
	line=strtol(satir,&end,10);
	FILE *fwrite=fopen(fname,"a+");
	for(i=0;i<line;i++){
		fgets(satir,100,fread);
		sscanf(satir,"%s",command);
		if(strcmp(command,"Distance")==0){
			distance(satir,fname,fwrite);
		}
		else if(strcmp(command,"Angle")==0){
			angle(satir,fname,fwrite);
		}
		else if(strcmp(command,"Length")==0){
			length(satir,fname,fwrite);
		}
		else if(strcmp(command,"Area")==0){
			area(satir,fname,fwrite);
		}
	}
	free(p_ptr);
	free(l_ptr);
	free(pp_ptr);
}

void distance(char satir[100],char *fname,FILE *fwrite){
	int fp=0,sp=0,i=0,j=0;
	double result,m,fx1,fx2,sx1,sx2,fy1,fy2,sy1,sy2,a,b;
	char *first,*second,*temp;
	temp=(char*)malloc(10*sizeof(char));
	first=(char*)malloc(10*sizeof(char));
	second=(char*)malloc(10*sizeof(char));
	sscanf(satir,"%s %s %s",temp,first,second);
	for(i=0;i<100;i++){
		if(strcmp(first,(p_ptr+i)->name)==0){
			fx1=(p_ptr+i)->x;
			fy1=(p_ptr+i)->y;
			fp=1;
		}
		if(strcmp(first,(l_ptr+i)->name)==0){
			fx1=(l_ptr+i)->start.x;
			fy1=(l_ptr+i)->start.y;
			fx2=(l_ptr+i)->end.x;
			fy2=(l_ptr+i)->end.y;
		}
		if(strcmp(second,(p_ptr+i)->name)==0){
			sx1=(p_ptr+i)->x;
			sy1=(p_ptr+i)->y;
			sp=1;
		}
		if(strcmp(second,(l_ptr+i)->name)==0){
			sx1=(l_ptr+i)->start.x;
			sy1=(l_ptr+i)->start.y;
			sx2=(l_ptr+i)->end.x;
			sy2=(l_ptr+i)->end.y;
		}
	}
	if(fp==1&&sp==1){
		result=sqrt(pow((fx1-sx1),2)+pow((fy1-sy1),2));
	}
	else if(fp==0&&sp==1){
		m=fabs((fy1-fy2)/(fx1-fx2));
		a=m;
		b=fy1-(m*fx1);
		result=(fabs(sy1-a*sx1-b))/sqrt(1+a*a);
	}
	else if(fp==1&&sp==0){
		m=fabs((sy1-sy2)/(sx1-sx2));
		a=m;
		b=sy1-(m*sx1);
		result=(fabs(fy1-a*fx1-b))/sqrt(1+a*a);
	}
	fseek(fwrite,0,SEEK_SET);
	fprintf(fwrite,"%s(%s,%s) = %.1lf\n",temp,first,second,result);
}
void angle(char satir[100],char *fname,FILE *fwrite){
	int i=0;
	double m1,m2,result,fx1,fy1,fx2,fy2,sx1,sy1,sx2,sy2,atan1,atan2;
	char *first,*second,*temp;
	temp=(char*)malloc(10*sizeof(char));
	first=(char*)malloc(10*sizeof(char));
	second=(char*)malloc(10*sizeof(char));
	sscanf(satir,"%s %s %s",temp,first,second);
	for(i=0;i<100;i++){
		if(strcmp(first,(l_ptr+i)->name)==0){
			fx1=(l_ptr+i)->start.x;
			fy1=(l_ptr+i)->start.y;
			fx2=(l_ptr+i)->end.x;
			fy2=(l_ptr+i)->end.y;			
		}
		if(strcmp(second,(l_ptr+i)->name)==0){
			sx1=(l_ptr+i)->start.x;
			sy1=(l_ptr+i)->start.y;
			sx2=(l_ptr+i)->end.x;
			sy2=(l_ptr+i)->end.y;
		}
	}
	if(fx1==fx2&&sx1!=sx2){
		m1=PI/2;
		m2=fabs((sy1-sy2)/(sx1-sx2));
		atan1=90/57.2957795130822;
		atan1=(m1*180)/PI;
		atan2=atan(m2);
		atan2=(m2*180)/PI;
		result=fabs(atan2-atan1);
	}
	else if(sx1==sx2&&fx1!=fx2){
		m1=fabs((fy1-fy2)/(fx1-fx2));
		m2=PI/2;
		atan2=90/57.2957795130822;
		atan1=atan(m1);
		atan1=(m1*180)/PI;
		atan2=(m2*180)/PI;		
		result=fabs(atan1-atan2);
	}
	else if(fx1==fx2&&sx1==sx2){
		result=0;
	}
	else{
		m1=fabs((fy1-fy2)/(fx1-fx2));
		m2=fabs((sy1-sy2)/(sx1-sx2));
		atan1=atan(m1);
		atan1=(m1*180)/PI;
		atan2=atan(m2);
		atan2=(m2*180)/PI;
		result=atan((m2-m1)/(1+m2*m1));
		result=fabs(result*180/PI);
	}
	fprintf(fwrite,"%s(%s,%s) = %.1lf\n",temp,first,second,result);
}
void length(char satir[100],char *fname,FILE *fwrite){
	char *temp,*first;
	int i=0,l=0,var,sayi=0;
	double result=0,fx1,fx2,fy1,fy2,asd;
	temp=(char*)malloc(10*sizeof(char));
	first=(char*)malloc(10*sizeof(char));
	sscanf(satir,"%s %s",temp,first);		
	for(i=0;i<100;i++){
		if(strcmp(first,(l_ptr+i)->name)==0){
			l=1;
			var=i;
			break;
		}
		else if(strcmp(first,(pp_ptr+i)->name)==0){
			var=i;
			break;
		}
	}
	if(l==1){
		fx1=(l_ptr+var)->start.x;
		fy1=(l_ptr+var)->start.y;
		fx2=(l_ptr+var)->end.x;
		fy2=(l_ptr+var)->end.y;
		result=sqrt(pow((fx2-fx1),2)+((fy2-fy1),2));
	}
	else{
		sayi=(pp_ptr+var)->kose_sayisi;
		for(i=1;i<sayi;i++){
			fx1=(pp_ptr+var)->vertices[i-1].x;
			fy1=(pp_ptr+var)->vertices[i-1].y;
			fx2=(pp_ptr+var)->vertices[i].x;
			fy2=(pp_ptr+var)->vertices[i].y;
			asd=sqrt((fx2-fx1)*(fx2-fx1)+(fy2-fy1)*(fy2-fy1));
			result=result+asd;
		}
		fx1=(pp_ptr+var)->vertices[0].x;
		fy1=(pp_ptr+var)->vertices[0].y;
		fx2=(pp_ptr+var)->vertices[sayi-1].x;
		fy2=(pp_ptr+var)->vertices[sayi-1].y;
		asd=sqrt((fx2-fx1)*(fx2-fx1)+(fy2-fy1)*(fy2-fy1));
		result=result+asd;
	}
	fprintf(fwrite,"%s(%s) = %.1lf\n",temp,first,result );
}
void area(char satir[100],char *fname,FILE *fwrite){
	int i,var,sayi;
	double result=0,fx1,fx2,fy1,fy2;
	char *first,*temp;
	temp=(char*)malloc(10*sizeof(char));
	first=(char*)malloc(10*sizeof(char));
	sscanf(satir,"%s %s",temp,first);
	for(i=0;i<100;i++){
		if(strcmp(first,(pp_ptr+i)->name)==0){
			var=i;
			break;
		}
	}
	sayi=(pp_ptr+var)->kose_sayisi;
	for(i=0;i<sayi;i++){
		if(i==sayi-1){
			fx1=(pp_ptr+var)->vertices[0].x;
			fy1=(pp_ptr+var)->vertices[0].y;
			fx2=(pp_ptr+var)->vertices[i].x;
			fy2=(pp_ptr+var)->vertices[i].y;
			result=result+(fx2*fy1-fy2*fx1);
		}
		else{
			fx1=(pp_ptr+var)->vertices[i].x;
			fy1=(pp_ptr+var)->vertices[i].y;
			fx2=(pp_ptr+var)->vertices[i+1].x;
			fy2=(pp_ptr+var)->vertices[i+1].y;
			result=result+(fx1*fy2-fy1*fx2);
		}
	}
	result=result/2.0;
	fprintf(fwrite,"%s(%s) = %.1lf\n",temp,first,result );
}


void data(char satir[100],char str[20][10],int *p,int *l,int *pp){
	int i=0,j=0,k=0,element=0,number=0,m=0,n=0,find=0,z=0,kose=0,sayi;
	while(satir[i]!='/'&&satir[i]!='\n'&&satir[i]<91&&satir[i]>47){
		while(satir[i]!=' '&&satir[i]!='\n'&&satir[i]<91&&satir[i]>47){
			str[element][j]=satir[i];
			i++;
			j++;
		}
		number++;
		while(satir[i]==' '){
			i++;
		}
		j=0;
		element++;
	}
	if(number<4){
		strcpy((l_ptr+*l)->name,str[number-1]);
		for(k=0;k<number-1;k++){
			for(m=0;m<100;m++){
				if(strcmp(str[k],(p_ptr+m)->name)==0){
					if(find==0){
						(l_ptr+*l)->start.x=(p_ptr+m)->x;
						(l_ptr+*l)->start.y=(p_ptr+m)->y;
						find=1;
						break;
					}
					else if(find==1){
 						(l_ptr+*l)->end.x=(p_ptr+m)->x;
 						(l_ptr+*l)->end.y=(p_ptr+m)->y;
 						find=2;
 						break;
					}
				}
			}
		}
		*l=*l+1;
	}
	else if(number>=4){
		(pp_ptr+*pp)->kose_sayisi=number-1;
		sayi=(pp_ptr+*pp)->kose_sayisi;
		strcpy((pp_ptr+*pp)->name,str[number-1]);
		for(k=0;k<number-1;k++){
			for(m=0;m<100;m++){
				if(strcmp(str[k],(p_ptr+m)->name)==0){
					(pp_ptr+*pp)->vertices[kose].x=(p_ptr+m)->x;
					(pp_ptr+*pp)->vertices[kose].y=(p_ptr+m)->y;
					kose++;
					break;
				}
				if(strcmp(str[k],(l_ptr+m)->name)==0){
					(pp_ptr+*pp)->vertices[kose].x=(l_ptr+m)->start.x;
					(pp_ptr+*pp)->vertices[kose].y=(l_ptr+m)->start.y;
					kose++;
					break;
				}
			}
		}
		*pp=*pp+1;
	}
}