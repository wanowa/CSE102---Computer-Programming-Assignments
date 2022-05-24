#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int andop(int a,int b){
	int result=0,i,length,d,tempa,tempb;
	length=1+log10(a);
	for(i=1;i<=length;i++){
		d=length-i;
		tempa=a;
		tempb=b;
		tempa=(tempa/pow(10,d));
		tempa=tempa%10;
		tempb=(tempb/pow(10,d));
		tempb=tempb%10;
		if(result==0){
			if(tempa==tempb){
				result++;
			}
		}
		else{
			if(tempa==1&&tempb==1){
				result=result*10+1;
			}
			else{
				result=result*10;
			}
		}
	}
	return result;
}
int main(){
	int l1,l2,a,b,i=0,flag1=0,flag2=0,j,check,temp1=0,temp2=0,result,lengthresult,k,check2,f1=1,f2=1;
	while(i==0){
		printf("First Integer:");
		scanf("%d",&a);
		printf("\nSecond Integer:");
		scanf("%d",&b);
		temp1=a;
		temp2=b;
		l1=1+log10(a);
		l2=1+log10(b);
		if(l1==l2){
			flag1=1;
		}
		for(j=0;j<l1;j++){
			check=temp1%10;
			if(check==0||check==1){
				temp1=temp1/10;
			}
			else{
				f1=0;
				break;
			}
		}
		for(k=0;k<l2;k++){
			check2=temp2%10;
			if(check2==0||check2==1){
				temp2=temp2/10;
			}
			else{
				f2=0;
				break;
			}
		}
		if(f1==0){
			flag2=0;
		}
		else if(f2==0){
			flag2=0;
		}
		else if(f1==0&&f2==1){
			flag2=0;
		}
		else if(f1==1&&f2==0){
			flag2=0;
		}
		else{
			flag2=1;
		}
		
		if(flag1==0&&flag2==0){
			printf("\nIntegers should be binary and should have the same length, please enter 2 new integers.\n");
		}
		else if(flag1==0){
			printf("Integers should have the same length, please enter 2 new integers.\n");
		}
		else if (flag2==0)
		{
			printf("Integers should be binary, please enter 2 new integers.\n");
		}
		else{
			i=1;
		}
	}
	result=andop(a,b);
	lengthresult=1+log10(result);
	if(lengthresult<l1){
		printf("\n%d AND %d = 0%d",a,b,result);
	}
	else{
		printf("\n%d AND %d = %d",a,b,result);
	}
}