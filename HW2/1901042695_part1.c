#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int draw_triangle(int side1,int side2,int side3){
	if(abs(side2-side3)<side1&&side2+side3>side1&&abs(side1-side3)<side2&&side1+side3>side2&&abs(side1-side2)<side3&&side1+side2>side3){	//ucgen olma şartını karşılıyor mu
		return 1;
	}
	return 0;
}
void type_triangle(int side1,int side2,int side3){
	if (side1==side2&&side2==side3)						//Tüm kenarlar eşitse eşkenar
	{
		printf("\nIt is a Equilateral Triangle");
	}
	else if (side1!=side2&&side1!=side3&&side2!=side3) 	//Hiç bir kenar eşit değilse çeşitkenar 
	{
		printf("\nIt is a Scalene Triangle");
	}
	else{												//Üsttekilerin hiçbiri değilse ikizkenar
		printf("\nIt is a Isosceles Triangle");
	}

}
int perimeter_triangle(int side1,int side2, int side3){
	return side1+side2+side3;							//Üçgenin çevresini bulma işlemi
}
double area_triangle(int side1,int side2, int side3,int perimeter){
	int p=perimeter/2;
	double area;
	area=sqrt(p*(p-side1)*(p-side2)*(p-side3));			//Özel metodla alan bulma işlemi
	return area;
}
int main()
{
	int side1,side2,side3,perimeter,p;					//Alan bulma metodunu uygulamak için p değişkeni
	double area;										//kullandım ve çevrenin yarısına eşitledim
	printf("The length of first side:\n");
	scanf("%d",&side1);
	printf("The length of second side:\n");
	scanf("%d",&side2);
	printf("The length of third side:\n");
	scanf("%d",&side3);
	if(side1<=0||side2<=0||side3<=0){
		printf("Sides length should be natural number.\n");//Kenar uzunlukları 0'dan büyük olmalı
		return 0;
	}
	if (draw_triangle(side1,side2,side3)==1)
	{
		printf("\nAccording to the triangle inequality theorem, this triangle can be drawn\n");
		type_triangle(side1,side2,side3);
		perimeter=perimeter_triangle(side1,side2,side3);
		printf("\nThe perimeter of the triangle:%d",perimeter);
		area=area_triangle(side1,side2,side3,perimeter);
		printf("\nThe area of the triangle:%lf\n",area);
	}
	else{
		printf("\nAccording to the triangle inequality theorem, this triangle cannot be drawn\n");
	}
}