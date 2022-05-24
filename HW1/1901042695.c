#include<stdio.h>
#include <math.h>
#include <stdlib.h>
void find_root(){
	int a,b,c,d;
	double r1,r2;
	printf("Please Enter the first coefficient:");
	scanf("%d",&a);
	printf("\nPlease Enter the second coefficient");
	scanf("%d",&b);
	printf("\nPlease Enter the third coefficient");
	scanf("%d",&c);
	d=b*b-(4*a*c);
	if(d<0){
		printf("Your equation %+dx^2 %+dx %+d does not have any real roots.\n",a,b,c);
	}
	else{
		r1=(-b-sqrt(d))/2*a;
		r2=(-b+sqrt(d))/2*a;
		printf("Your equation %+dx^2 %+dx %+d have real roots {%.4lf,%.4lf}",a,b,c,r1,r2);
	}
}
void find_newtonian_root(){
	int a,b,c,d;
	double r1,r2,x0,x1,x2,x3,x4,x5;
	printf("Please Enter the first coefficient:");
	scanf("%d",&a);
	printf("\nPlease Enter the second coefficient:");
	scanf("%d",&b);
	printf("\nPlease Enter the third coefficient:");
	scanf("%d",&c);
	printf("\nPlease Enter the initial:");
	scanf("%lf",&x0);
	d=b*b-(4*a*c);
	if(d<0){
		printf("Your equation %+dx^2 %+dx %+d does not have any real roots.\n",a,b,c);
	}
	else{
		r1=(-b-sqrt(d))/(2*a);
		r2=(-b+sqrt(d))/(2*a);
		printf("Your equation %+dx^2 %+dx %+d and iterations are\n",a,b,c);
		x1=x0-((a*x0*x0+b*x0+c)/(2*a*x0+b));
		x2=x1-((a*x1*x1+b*x1+c)/(2*a*x1+b));
		x3=x2-((a*x2*x2+b*x2+c)/(2*a*x2+b));
		x4=x3-((a*x3*x3+b*x3+c)/(2*a*x3+b));
		x5=x4-((a*x4*x4+b*x4+c)/(2*a*x4+b));
		if (fabs(x0-r1)<fabs(x0-r2))
		{
			printf("Step\t\tx\t\tf(x)\t\tDifference\n\n");
			printf("x1\t\t%.4lf\t\t%.4lf\t\t%.4lf\n",x1,(a*x1*x1+b*x1+c),fabs(x1-r1));
			printf("x2\t\t%.4lf\t\t%.4lf\t\t%.4lf\n",x2,(a*x2*x2+b*x2+c),fabs(x2-r1));
			printf("x3\t\t%.4lf\t\t%.4lf\t\t%.4lf\n",x3,(a*x3*x3+b*x3+c),fabs(x3-r1));
			printf("x4\t\t%.4lf\t\t%.4lf\t\t%.4lf\n",x4,(a*x4*x4+b*x4+c),fabs(x4-r1));
			printf("x5\t\t%.4lf\t\t%.4lf\t\t%.4lf\n",x5,(a*x5*x5+b*x5+c),fabs(x5-r1));
		}
		else{
			printf("Step\t\tx\t\tf(x)\t\tDifference\n\n");
			printf("x1\t\t%.4lf\t\t%.4lf\t\t%.4lf\n",x1,(a*x1*x1+b*x1+c),fabs(x1-r2));
			printf("x2\t\t%.4lf\t\t%.4lf\t\t%.4lf\n",x2,(a*x2*x2+b*x2+c),fabs(x2-r2));
			printf("x3\t\t%.4lf\t\t%.4lf\t\t%.4lf\n",x3,(a*x3*x3+b*x3+c),fabs(x3-r2));
			printf("x4\t\t%.4lf\t\t%.4lf\t\t%.4lf\n",x4,(a*x4*x4+b*x4+c),fabs(x4-r2));
			printf("x5\t\t%.4lf\t\t%.4lf\t\t%.4lf\n",x5,(a*x5*x5+b*x5+c),fabs(x5-r2));
		}
	}
}
int find_multiple_closest(int a, int b){
	int r,k,f1,f2,d;
	if(a%b==0){
		return 0;
	}
	else{
		f1=a%b;
		d=(a-f1)/b;
		f2=b*(d+1)-a;
		if (f1<f2)
		{
			r=d*b;
		}
		else
		{
			r=(d+1)*b;
		}
	}
	return r;
}
int main()
{
	int o;
	printf("(1) Find root\n(2) Find Newtonian root\n(3) Find multiple closest\n");
	printf("Select Operation:");
	scanf("%d",&o);
	if (o==1)
	{
		find_root();
	}
	else if (o==2)
	{
		find_newtonian_root();
	}
	else if (o==3)
	{
		int a,b,c,r;
		printf("Enter the first integer:");
		scanf("%d",&a);
		printf("Enter the second integer:");
		scanf("%d",&b);
		r=find_multiple_closest(a,b);
		if (r==0)
		{
			printf("Closest number to %d that is multiple of %d is itself.",a,b);
		}
		else{
			printf("Closest number to %d that is multiple of %d is %d",a,b,r);
		}
	}
	else{
		printf("You entered wrong number.");
	}
	return 0;
}