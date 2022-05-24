#include <stdio.h>
int sum(int n, int flag){
	int i=1,top=0,j=1,f=1;
	if(flag==0){
		for(i=1;i<=n;i++){
			if(i%2==0){
				top=top+i;
				printf("%d ",i);
				if(n==i||n-i==1){
					j=0;
				}
				else{
					j=1;
				}
				while(j==1){
					printf("+ ");
					j=0;
				}
			}
		}
	}
	else if(flag==1){
		for(i=1;i<=n;i++){
			if(i%2==1){
				top=top+i;
				printf("%d ",i);
				if(n==i||n-i==1){
					j=0;
				}
				else{
					j=1;
				}
				while(j==1){
					printf("+ ");
					j=0;
				}
			}
		}
	}
	return top;
}
int mult(int n, int flag){
	int i=1,carp=1,f=0,j=1;
	if(flag==0){
		for(i=1;i<=n;i++){
			if(i%2==0){
				carp=carp*i;
				f=1;
				printf("%d ",i);
				if(n==i||n-i==1){
					j=0;
				}
				else{
					j=1;
				}
				while(j==1){
					printf("* ");
					j=0;
				}
			}
		}
	}	
	else if(flag==1){
		for(i=1;i<=n;i++){
			if(i%2==0){
				carp=carp*i;
				f=1;
				printf("%d ",i);
				if(n==i||n-i==1){
					j=0;
				}
				else{
					j=1;
				}
				while(j==1){
					printf("* ");
					j=0;
				}
			}
		}
	}	
	if(f==0){
		return 0;
	}
	return carp;
}
int main(){
	int n,flag,a,top,carp;
	printf("Enter an integer: ");
	scanf("%d",&n);
	printf("\nPlease enter '0' for sum, '1' for multiplication\n");
	scanf("%d",&a);
	printf("Please enter '0' to work on even numbers, '1' to work on odd numbers\n");
	scanf("%d",&flag);
	if(a==0){
		top=sum(n,flag);
		printf("= %d\n",top);
	}
	else if(a==1){
		carp=mult(n,flag);
		printf("= %d\n",carp);
	}
	else{
		printf("Unsupported operation");
	}
	if(flag!=0&&flag!=1){
		printf("Invalid value for odd/even selection");
	}
}