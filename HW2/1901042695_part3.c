#include<stdio.h>
#include <stdlib.h>
int main(){
	printf("***** Welcome to ABC Exchange Office *****\n");
	double amount,dollar=6.14,euro=6.69; //Bütün dövizlerin TL cinsinden değerini tanımladım.
	int i;	//Switch case değişkeni olması için tanımladım.
	printf("Enter your amount:\n");
	scanf("%lf",&amount);
	if(amount<=0){
		printf("If you haven't money, don't come to Exchange Office.\n");		//Para sıfır veya daha az ise yapılan işlemler 
		return 0;																//anlamsız oluyor.
	}
	printf("\nPlease select your currency\n1. Turkish Lira\n2. Euro\n3. Dollar\n\n");
	scanf("%d",&i);
	switch(i){
		case 1:printf("You have %lf Turkish Liras\n",amount);break;				//Türk lirası ortak çatı.
		case 2:printf("You have %lf Euros\n",amount);amount*=euro;break;		//Çevirme işlemlerinin daha basit olması
		case 3:printf("You have %lf Dollars\n",amount);amount*=dollar;break;	//için bütün dövizleri Türk lirasına çevirdim.
		default:printf("Your selection is invalid!\n");return 0;
	}
	printf("Choose which currency you want to convert\n");
	scanf("%d",&i);
	switch(i){
		case 1:printf("\nYou have %lf Turkish Liras\n",amount);break;
		case 2:printf("\nYou have %lf Euros\n",amount/=euro);break;			
		case 3:printf("\nYou have %lf Dollars\n",amount/=dollar);break;		
		default:printf("\nYour selection is invalid!\n");break;
	}
}