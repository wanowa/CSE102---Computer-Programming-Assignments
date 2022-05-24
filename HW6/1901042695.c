#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
void play(char puzzle[20][20],char words[10][15]);
void top_to_bottom(char puzzle[20][20],char words[10][15],int locked_cells[20][20],int number,int length);
void bottom_to_top(char puzzle[20][20],char words[10][15],int locked_cells[20][20],int number,int length);
void right_to_left(char puzzle[20][20],char words[10][15],int locked_cells[20][20],int number,int length);
void left_to_right(char puzzle[20][20],char words[10][15],int locked_cells[20][20],int number,int length);
void lb_to_rt(char puzzle[20][20],char words[10][15],int locked_cells[20][20],int number,int length);
void lt_to_rb(char puzzle[20][20],char words[10][15],int locked_cells[20][20],int number,int length);
void rb_to_lt(char puzzle[20][20],char words[10][15],int locked_cells[20][20],int number,int length);
void rt_to_lb(char puzzle[20][20],char words[10][15],int locked_cells[20][20],int number,int length);
int check(char puzzle[20][20],char word[15],int row,int column,char words[10][15]);
int main(){
	FILE *fp;			
	fp=fopen("turkish.txt","r");			//Dosyayı okuma modunda açtım
	srand(time(NULL));
	int rand_letter,rand_word,rand_scribe,n=0,row,column,number=0,locked_cells[20][20],length=0,locked[1],uzunluk,var=0,old_words[10],x=0;
	char letters[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};	//random harf almak için harflerle dolu array oluşturdum
	char puzzle[20][20],words[10][15],scan;
	locked[0]=0;
	for(row=0;row<20;row++){
		for(column=0;column<20;column++){
			rand_letter=rand()%26;
			puzzle[row][column]=letters[rand_letter];
			locked_cells[row][column]=0;	//Locked cells dediğim array puzzle'daki herhangi bir hücrenin dolu olup olmadığını kontrol ediyor. Puzzle arrayi ile aynı büyüklükte.
		}									//Puzzle'daki bir hücre daha önce kullanılmışsa 1 değerini döndürüyor, kullanılmamışsa 0 değerini. Henüz puzzle'a kelime ataması 
	}										//yapmadığımdan bütün hücreleri 0 ile dolduruyorum.
	for(number=0;number<10;number++){
		x=0;
		length=0;
		rand_word=rand()%99;				//100 kelimeyi temsilen 0-99 arasında rastgele bir sayı alıyorum.
		while(x<=number){
			if(rand_word==old_words[x]){	//Aynı kelimenin iki kez kullanılmasını önlemek için kullandığım kelimeleri old_words arrayine atıyorum ve 
				rand_word=rand()%99;		//eski kelimeye eşit olması durumunda tekrar rastgele kelime alıyorum.
				x=0;
			}
			x++;
		}
		old_words[number]=rand_word;		//Aldığım kelimeyi bir daha kullanmamak için old_words arrayine attım.
		rewind(fp);							//Her dönüşte dosyanın aktif konumunu başa aldım.
		while(rand_word!=n){				
			fscanf(fp,"%c",&scan);			//Her '\n' gördüğümde n değişkenini bir arttırıyorum. rand_word ile n eşit olduğunda aktif konum aradığım kelimenin başına gelmiş oluyor.
			if(scan=='\n'){
				n++;
			}
		}
		fscanf(fp,"%c",&scan);
		while(scan!='\n'){
			words[number][length]=scan;		//Birdahaki satır başına gelene kadarki harfleri words arrayime atıyorum.
			fscanf(fp,"%c",&scan);
			length++;
		}
		while(scan!='\n'){
			words[number][length]=scan;
			fscanf(fp,"%c",&scan);
			length++;
		}
		words[number][length]=' ';			//Kelime sonlarını bulabilmek için words arrayinin sonuna boşluk karakteri koydum.
		length=length-1;
		rand_scribe=rand()%8;				//Her farklı yazım şekli için 0-7 arasında sayı atadım. Gelen rastgele sayıya göre yazım fonksiyonlarına gönderiyorum.
		if (rand_scribe==0){
			top_to_bottom(puzzle,words,locked_cells,number,length);
		}
		else if(rand_scribe==1){
			bottom_to_top(puzzle,words,locked_cells,number,length);
		}
		else if(rand_scribe==2){
			right_to_left(puzzle,words,locked_cells,number,length);
		}
		else if(rand_scribe==3){
			left_to_right(puzzle,words,locked_cells,number,length);
		}
		else if(rand_scribe==4){
			lb_to_rt(puzzle,words,locked_cells,number,length);
		}
		else if(rand_scribe==5){
			lt_to_rb(puzzle,words,locked_cells,number,length);
		}
		else if(rand_scribe==6){
			rb_to_lt(puzzle,words,locked_cells,number,length);
		}
		else if(rand_scribe==7){
			rt_to_lb(puzzle,words,locked_cells,number,length);
		}
		n=0;
	}
	play(puzzle,words);
	fclose(fp);
}

void play(char puzzle[20][20],char words[10][15]){
	int row,column,exit=0,n=0,i=1,satir,sutun,number=0,result=0,k,space=0,x=0,y=0,z=0,t=0;
	char input[20],letter,word[15],temp[2],finish[]="exit",buffer[20];
	while(1){
		printf("Words are:\n");
		for(x=0;x<10;x++){
			for(z=0;z<20;z++){
				buffer[z]=' ';		//Kelimeleri yazdıracak olan buffer arayini boşluk karakteri ile doldurdum ki her kelimenin sonu boşluk ile bitsin.
			}
			for(y=0;words[x][y]!=' ';y++){
				buffer[y]=words[x][y];
			}
			for(t=0;buffer[t+1]!=' ';t++){
				printf("%c",buffer[t]);
			}
			if(x!=9){
				printf(",");		//Son kelimenin sonuna da virgül koymaması için böyle bir önlem aldım.
			}
		}
		printf("\n\n");
		printf("\t\t 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19\n\n\n");
		for(satir=0;satir<20;satir++){
		letter=satir+65;		//Decimal tabloya göre 0 ile A karakteri arasındaki fark 65.
		printf("\t%c\t",letter);//Bununla satır sayılarını temsil eden harfleri yazdırdım.
		for(sutun=0;sutun<20;sutun++){
			printf(" %c ",puzzle[satir][sutun]);	//Puzzle arrayini yazdırdım.
		}
		printf("\n");
		}
		printf("Please enter the coordinate and the word (Example: P11 random):\n");
		fgets(input,20,stdin);		//Kullanıcının girdiği koordinat ve kelimeyi input'a aldım.
		for(k=0;k<5;k++){
			if(input[k]==' '){		//Space karakterinin yerini bulmak için böyle birşey yaptım. Sütun iki basamaklı sayıysa space 2,
				space++;			//tek basamaklı bir sayıysa space 3 oluyor.
			}
		}
		if(strncmp(input,finish,4)==0){		//finish arrayinin içinde exit yazısı var. ikisinin ilk dört karakterini karşılaştırdım.
			printf("\nExiting...\n");		//strncmp fonksiyonu 0 dönmesi halinde (eşit olması) programı sonlandırdım.
			return;
		}
		if(space==0||input[1]<48||input[1]>57){				//input'ta hiç space kullanılmamışsa, 2. karakter decimal tabloya göre rakam değilse
			printf("Wrong entered, program will end\n");	//kullanıcı yanlış biçimde input girmiş demektir. Bu durumda da segfault'u önlemek için 
			return;											//programı sonlandırıyorum.
		}
		row=input[0]-'A';		//Satır değerine kullanıcının girdiği harfle A harfi arasındaki farkı integer olarak atıyorum.
		while(input[i]!=' '){
			temp[i]=input[i];	//Burda sütun karakter veya karakterlerini temp arrayine atıyorum.
			n++;				
			i++;
		}
		i++;
		while(input[i]!='\0'){
			word[i-n-2]=input[i];	//Hazır i'nin konumu kelimenin başındayken kelimeyi de word arrayine atıyorum.
			i++;
		}
		word[i-n-2]='\0';
		if(n==1){
			column=input[1]-48;		//Sütun tek basamaklıysa 48, iki basamaklıysa 38 çıkararak column değişkenine attım.
		}
		else if(n==2){
			column=input[2]-38;		//Sütun tek basamaklıysa 48, iki basamaklıysa 38 çıkararak column değişkenine attım.
		}
		result=check(puzzle,word,row,column,words);		//Satır, sütün, kelime ve puzzle'ı kontrol fonksiyonuna gönderdim. Öyle bir kelime var mı, varsa kullanıcının 
		if(result==1){									//dediği yerde mi diye kontrol ediyor.
			printf("TRUE!\n\n\n");						//Doğru cevap için 1, yanlış cevap için 0 döndürüyor.
			number++;
		}
		else{
			printf("Wrong answer\n\n\n");
		}
		if(number==10){
			printf("CONGRATULATIONS! YOU FOUND ALL THE WORDS!\n");		//10 kere doğru cevap verince bulacak başka kelime kalmadığından tebrik edip program sonlanıyor.
			return;
		}
		i=1;
		n=0;
		result=0;
	}
}

int check(char puzzle[20][20],char word[15],int row,int column,char words[10][15]){
	int length,i=0,result=1,row2,column2,number,x=0,y=0,equal=1,exit=1,z=0;
	char buffer[20];
	row2=row;
	column2=column;
	length=strlen(word)-1;
	for(x=0;x<10;x++){
		for(z=0;z<20;z++){
			buffer[z]=' ';			//buffer ve words arraylerinin kelime sonu karakteri boşluk.
		}
		equal=1;			//loop'un her dönüşünde equal'ı 1 yapıyorum.
		for(y=0;words[x][y]!=' ';y++){		
			buffer[y]=words[x][y];
		}
		y=0;
		for(y=0;buffer[y+1]!=' ';y++){
			if(word[y]!=buffer[y]){		
				equal=0;		//eğer equal en aşağı 0 olmadan gelebilirse, kullanıcının girdiği kelimenin aranan kelimelerden biri olduğu doğrulanıyor
			}
		}
		if(equal==1){
			exit=0;
			break;
		}
	}
	if(exit==1){				//Kullanıcının girdiği kelime, kelime arrayinde yoksa yanlış cevap döndürüyorum.
		return 0;
	}
	while(word[i+1]!='\0'){
		if(puzzle[row][column]!=word[i]){
			result=0;
		}														//check fonksiyonunun bundan sonraki kısımlarında puzzle arrayinde kullanıcının girdiği kelimeyi,
		i++;													//kullanıcının girdiği koordinatta başlayan bir kelime arıyorum. Tabii 8 farklı yazım biçimi olduğu için 
		row++;													//8 farklı yöntemle arıyorum. Mesela soldan sağa yazım için sütun'u bir arttırarak, aşağıdan yukarı için
	}															//satır'ı bir azaltarak, sağ alttan sol üste yazım için satır'ı bir azaltıp sütunu bir arttırarak arıyorum.
	i=0;														//eğer herhangi birini sağlarsa o harfleri büyütüyorum.
	if(result==1){
		while(i<length){
			puzzle[row2][column2]=puzzle[row2][column2]-32;		//decimal tabloya göre küçük a ile büyük a arasında 32 karakter farkı var.
			i++;
			row2++;
		}
		return 1;
	}
	result=1;
	i=0;
	row=row2;
	column=column2;
	while(word[i+1]!='\0'){
		if(puzzle[row][column]!=word[i]){
			result=0;
		}
		i++;
		row--;
	}
	i=0;
	if(result==1){
		while(i<length){
			puzzle[row2][column2]=puzzle[row2][column2]-32;
			i++;
			row2--;
		}
		return 1;
	}
	result=1;
	i=0;
	row=row2;
	column=column2;
	while(word[i+1]!='\0'){
		if(puzzle[row][column]!=word[i]){
			result=0;
		}
		i++;
		column--;
	}
	i=0;
	if(result==1){
		while(i<length){
			puzzle[row2][column2]=puzzle[row2][column2]-32;
			i++;
			column2--;
		}
		return 1;
	}
	result=1;
	i=0;
	row=row2;
	column=column2;
	while(word[i+1]!='\0'){
		if(puzzle[row][column]!=word[i]){
			result=0;
		}
		i++;
		column++;
	}
	i=0;
	if(result==1){
		while(i<length){
			puzzle[row2][column2]=puzzle[row2][column2]-32;
			i++;
			column2++;
		}
		return 1;
	}
	result=1;
	i=0;
	row=row2;
	column=column2;
	while(word[i+1]!='\0'){
		if(puzzle[row][column]!=word[i]){
			result=0;
		}
		i++;
		row--;
		column++;
	}
	i=0;
	if(result==1){
		while(i<length){
			puzzle[row2][column2]=puzzle[row2][column2]-32;
			i++;
			row2--;
			column2++;
		}
		return 1;
	}
	result=1;
	i=0;
	row=row2;
	column=column2;
	while(word[i+1]!='\0'){
		if(puzzle[row][column]!=word[i]){
			result=0;
		}
		i++;
		row++;
		column++;
	}
	i=0;
	if(result==1){
		while(i<length){
			puzzle[row2][column2]=puzzle[row2][column2]-32;
			i++;
			row2++;
			column2++;
		}
		return 1;
	}
	result=1;
	i=0;
	row=row2;
	column=column2;
	while(word[i+1]!='\0'){
		if(puzzle[row][column]!=word[i]){
			result=0;
		}
		i++;
		row--;
		column--;
	}
	i=0;
	if(result==1){
		while(i<length){
			puzzle[row2][column2]=puzzle[row2][column2]-32;
			i++;
			row2--;
			column2--;
		}
		return 1;
	}
	result=1;
	i=0;
	row=row2;
	column=column2;
	while(word[i+1]!='\0'){
		if(puzzle[row][column]!=word[i]){
			result=0;
		}
		i++;
		row++;
		column--;
	}
	i=0;
	if(result==1){
		while(i<length){
			puzzle[row2][column2]=puzzle[row2][column2]-32;
			i++;
			row2++;
			column2--;
		}
		return 1;
	}
	return 0;
}
void top_to_bottom(char puzzle[20][20],char words[10][15],int locked_cells[20][20],int number,int length){
	int row,column,row2,column2,i=0,j=0,rand_scribe,cakisma=1,fit=0;
	while(cakisma==1||fit==0){	//hiçbir hücre çakışmayana ve kelime puzzle'a sığana kadar dön.
		column=rand()%20;		
		row=rand()%20;			//rastgele satır ve sütun değeri alıp, yazım fonksiyonunun gereğine göre puzzle'a yazıyorum.
		column2=column;
		row2=row;
		cakisma=0;
		fit=1;
		while(i<length){
			if(locked_cells[row2][column2]==1){		//Kelimenin yazılacağı alanda kilitli hücre(daha önce kullanılmış) var mı diye kontrol ediyorum.
				cakisma=1;							//Herhangi bir harf çakışmaması için eğer kilitli hücre varsa tekrar rastgele satır/sütun alıyorum.
			}
			row2++;
			i++;
		}
		if(20-row<length){		//Sığmıyorsa fit değişkenini sıfır yapıyorum.
			fit=0;
		}
		i=0;
	}
	while(i<length){
		puzzle[row][column]=words[number][i];		//Herşey tamamsa burda puzzle'a yazdırıyorum.
		locked_cells[row][column]=1;
		i++;										
		row++;		//Bu fonksiyonda sütun sabit, satır her seferinde bir artıyor.
	}
}

void bottom_to_top(char puzzle[20][20],char words[10][15],int locked_cells[20][20],int number,int length){
	int row,column,row2,column2,i=0,rand_scribe,cakisma=1,fit=0;
	while(cakisma==1||fit==0){
		column=rand()%20;			//rastgele satır ve sütun değeri alıp, yazım fonksiyonunun gereğine göre puzzle'a yazıyorum.(ilk yazım fonksiyonu ile aynı mantık).
		row=rand()%20;
		column2=column;
		row2=row;
		cakisma=0;
		fit=1;
		while(i<length){
			if(locked_cells[row2][column2]==1){
				cakisma=1;
			}
			row2--;
			i++;
		}
		if(row+1<length){
			fit=0;
		}
		i=0;
	}
	while(i<length){
		puzzle[row][column]=words[number][i];
		locked_cells[row][column]=1;
		i++;
		row--;
	}
}

void right_to_left(char puzzle[20][20],char words[10][15],int locked_cells[20][20],int number,int length){
	int row,column,row2,column2,i=0,rand_scribe,cakisma=1,fit=0;
	while(cakisma==1||fit==0){
		column=rand()%20;			//rastgele satır ve sütun değeri alıp, yazım fonksiyonunun gereğine göre puzzle'a yazıyorum.(ilk yazım fonksiyonu ile aynı mantık).
		row=rand()%20;
		column2=column;
		row2=row;
		cakisma=0;
		fit=1;
		while(i<length){
			if(locked_cells[row2][column2]==1){
				cakisma=1;
			}
			column2--;
			i++;
		}
		if(column+1<length){
			fit=0;
		}
		i=0;
	}
	while(i<length){
		puzzle[row][column]=words[number][i];
		locked_cells[row][column]=1;
		i++;
		column--;
	}
}

void left_to_right(char puzzle[20][20],char words[10][15],int locked_cells[20][20],int number,int length){
	int row,column,row2,column2,i=0,rand_scribe,cakisma=1,fit=0;
	while(cakisma==1||fit==0){
		column=rand()%20;
		row=rand()%20;			//rastgele satır ve sütun değeri alıp, yazım fonksiyonunun gereğine göre puzzle'a yazıyorum.(ilk yazım fonksiyonu ile aynı mantık).
		column2=column;
		row2=row;
		cakisma=0;
		fit=1;
		while(i<length){
			if(locked_cells[row2][column2]==1){
				cakisma=1;
			}
			column2++;
			i++;
		}
		if(20-column<length){
			fit=0;
		}
		i=0;
	}
	while(i<length){
		puzzle[row][column]=words[number][i];
		locked_cells[row][column]=1;
		i++;
		column++;
	}
}

void lb_to_rt(char puzzle[20][20],char words[10][15],int locked_cells[20][20],int number,int length){
	int row,column,row2,column2,i=0,rand_scribe,cakisma=1,fit=0;
	while(cakisma==1||fit==0){
		column=rand()%20;
		row=rand()%20;			//rastgele satır ve sütun değeri alıp, yazım fonksiyonunun gereğine göre puzzle'a yazıyorum.(ilk yazım fonksiyonu ile aynı mantık).
		column2=column;
		row2=row;
		cakisma=0;
		fit=1;
		while(i<length){
			if(locked_cells[row2][column2]==1){
				cakisma=1;
			}
			row2--;
			column2++;
			i++;
		}
		if(row+1<length||20-column<length){
			fit=0;
		}
		i=0;
	}
	while(i<length){
		puzzle[row][column]=words[number][i];
		locked_cells[row][column]=1;
		i++;
		row--;
		column++;
	}
}

void lt_to_rb(char puzzle[20][20],char words[10][15],int locked_cells[20][20],int number,int length){
	int row,column,row2,column2,i=0,rand_scribe,cakisma=1,fit=0;
	while(cakisma==1||fit==0){
		column=rand()%20;
		row=rand()%20;			//rastgele satır ve sütun değeri alıp, yazım fonksiyonunun gereğine göre puzzle'a yazıyorum.(ilk yazım fonksiyonu ile aynı mantık).
		column2=column;
		row2=row;
		cakisma=0;
		fit=1;
		while(i<length){
			if(locked_cells[row2][column2]==1){
				cakisma=1;
			}
			row2++;
			column2++;
			i++;
		}
		if(20-row<length||20-column<length){
			fit=0;
		}
		i=0;
	}
	while(i<length){
		puzzle[row][column]=words[number][i];
		locked_cells[row][column]=1;
		i++;
		row++;
		column++;
	}
}

void rb_to_lt(char puzzle[20][20],char words[10][15],int locked_cells[20][20],int number,int length){
	int row,column,row2,column2,i=0,rand_scribe,cakisma=1,fit=0;
	while(cakisma==1||fit==0){
		column=rand()%20;
		row=rand()%20;			//rastgele satır ve sütun değeri alıp, yazım fonksiyonunun gereğine göre puzzle'a yazıyorum.(ilk yazım fonksiyonu ile aynı mantık).
		column2=column;
		row2=row;
		cakisma=0;
		fit=1;
		while(i<length){
			if(locked_cells[row2][column2]==1){
				cakisma=1;
			}
			row2--;
			column2--;
			i++;
		}
		if(row+1<length||column+1<length){
			fit=0;
		}
		i=0;
	}
	while(i<length){
		puzzle[row][column]=words[number][i];
		locked_cells[row][column]=1;
		i++;
		row--;
		column--;
	}
}

void rt_to_lb(char puzzle[20][20],char words[10][15],int locked_cells[20][20],int number,int length){
	int row,column,row2,column2,i=0,rand_scribe,cakisma=1,fit=0;
	while(cakisma==1||fit==0){
		column=rand()%20;
		row=rand()%20;			//rastgele satır ve sütun değeri alıp, yazım fonksiyonunun gereğine göre puzzle'a yazıyorum.(ilk yazım fonksiyonu ile aynı mantık).
		column2=column;
		row2=row;
		cakisma=0;
		fit=1;
		while(i<length){
			if(locked_cells[row2][column2]==1){
				cakisma=1;
			}
			row2++;
			column2--;
			i++;
		}
		if(20-row<length||column+1<length){
			fit=0;
		}
		i=0;
	}
	while(i<length){
		puzzle[row][column]=words[number][i];
		locked_cells[row][column]=1;
		i++;
		row++;
		column--;
	}
}