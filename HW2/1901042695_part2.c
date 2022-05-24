#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int number_length(int number){
	int length;
	length=1+(int)log10(number);			//Onluk tabanda logaritmadan yararlanarak
	if (length>6||number<=0)				//verilen sayının basamak sayısını buldum
	{
		return 0;
	}
	return length;
}
int find_digit(int number, int index){
	int length,p,digit,result;
	length=1+(int)log10(number);			//Sayının basamak sayısı burada da gerekti
	if(index>length*100){					//Girilen index, sayının 100 kere art arda yazılmasıyla
		return -1;							//ortaya çıkan basamak sayısından büyükse, hata mesajı vermek 
	}										//üzere -1 döndürüyor.
	else{
		if(index%length==0){				//Girilen indexin basamak sayısına bölümünden kalan sıfır ise;
			return number%10;				//O indexteki sayı, girilen sayının son basamağıdır.
		}
		else{
			digit=index%length;				//Değilse; Girilen indexin basamak sayısına bölümünden kalan sayı,
			p=length-digit;					//girilen sayının o basamağındaki sayıya eşittir. Basamağın değeri
			result=number/pow(10,p);		//ne kadar büyük ise, o kadar büyük sayıya bölüp (son basamağı cevap
			result=result%10;				//olacak şekilde) 10 ile modunu alıyorum.
		}
	}
	return result;
}
int main(){
	int number,length,index,digit;
	printf("Enter a number (maximum 6 digits):\n");
	scanf("%d",&number);
	length=number_length(number);
	if(length==0){
		printf("Enter a integer number between 0 to 1000000\n");
		return 0;
	}
	else{
		printf("Your number has %d digits\n\n",length);
	}
	printf("When your number is written 100 times next to each other, which digit of this number would you like to see? :\n");
	scanf("%d",&index);
	digit=find_digit(number,index);
	if (digit==-1)
	{
		printf("\nEntered index is too big.\n");
		return 0;
	}
	printf("\n%d.th digit of the big number sequence: %d\n",index,digit);
	return 0;
}