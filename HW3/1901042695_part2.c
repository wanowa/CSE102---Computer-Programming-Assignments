#include<stdio.h>
#include<math.h>
int isprime(int a){
	int x,s=sqrt(a);
	for(x=2;x<=s;x++){
		if(a%x==0){
			return x;
		}
	}
	return 1;
}
int main(){
	int a,n,r;
	printf("Please enter an integer: ");
	scanf("%d",&n);
	for(a=2;a<n;a++){
		r=isprime(a);
		if(r==1){
			printf("\n%d is a prime number\n",a);
		}
		else{
			printf("\n%d is not a prime number, it is dividible by %d\n",a,r);
		}
	}
}