#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void menu();
char* remove_duplicates(char* str);
void generate_hofstadters_sequence(int *arr,int n);
int find_max (int arr[], int index, int max_value);
int sum_array (int arr[]);
double std_array (int arr[], double *mean, int n, int index);

int main(){
	menu();				//İşlemlerimin temelini menu fonksiyonunda yapıyorum.
}

void menu(){
	int j,temp=0,choose,again=1,secim,tekrar=1,arr[500]={0},n,i,max,index,entered=0,sum,var;
	double std,*mean=0;
	char str[100],*ptr;
	while(again==1){		//Kullanıcı exit diyene kadar 'again' 1 olarak kalacak, dönmeye devam edecek.
		printf("\nWelcome to Homework 8, please choose one of the parts to continue\n");
		printf("------------------------\n");
		printf("1) Execute Part 1\n2) Execute Part 2\n");
		printf("3) Execute Part 3\n4) Exit\n");
		scanf("%d",&choose);
		getchar();
		if(choose==1){
			tekrar=1;
			while(tekrar==1){	//Kullanıcı exit diyene kadar 'tekrar' 1 olarak kalacak, dönmeye devam edecek.
				printf("\n\nPlease make your choice:\n");
				printf("-------------------\n");
				printf("1) Fill Array\n2) Find Biggest Number\n3) Calculate Sum\n");
				printf("4) Calculate Standard Deviation\n5) Exit\n");
				scanf("%d",&secim);
				if(secim==1){
					printf("\nEnter an integer number:");
					scanf("%d",&n);
					arr[500]=0;
					if(n<=0){		//Girilen sayı pozitif değilse uyarı mesajı veriyor.
						printf("\nEntered number should be positive.\n");
						n=temp;		//hatalı girişte önceki girileni kaybetmiyoruz.
					}
					else{
						if(n<temp){					//Eğer girilen sayı öncekinden küçükse işlemleri
							for(j=0;j<temp;j++){	//hatalı yapabiliyor. Bunu engellemek için 
								arr[j]=0;			//bir önceki sayıya kadarki hücreleri 0 ile doldurdum.
							}
						}
						generate_hofstadters_sequence(arr,n);
						for(i=0;i<n;i++){
							printf("arr[%d]=%d\n",i,arr[i]);	//Arrayin elemanlarını bastırdım.
						}
						entered=1;		//Arrayi doldurduktan sonra entered değişkenine 1 atıyorum.
					}
					temp=n;
				}
				else if(secim==2){
					if(entered==0){		//Array doldurulmamışsa bu kısım gerçekleştirilemeyeceğinden
						printf("You haven't fill the array\n");	//Uyarı mesajı veriyorum.
					}
					else{
						index=n-1;
						max=find_max(arr,index,0);
						printf("\nBiggest number of the array=%d\n",max );
					}
				}
				else if(secim==3){
					if(entered==0){		//Array doldurulmamışsa bu kısım gerçekleştirilemeyeceğinden
						printf("You haven't fill the array\n"); //Uyarı mesajı veriyorum.
					}
					else{
						sum=sum_array(arr);
						if(n==500)			//son indexte değişkenimi tuttuğumdan toplama
							sum=sum-500;	//onu da dahil ediyor. 
						printf("Summary of array's elements=%d\n",sum);
					}
				}
				else if(secim==4){
					if(entered==0){		//Array doldurulmamışsa bu kısım gerçekleştirilemeyeceğinden
						printf("You haven't fill the array\n");	//Uyarı mesajı veriyorum.
					}
					else{
						var=0;
						(mean)=(double*)malloc(sizeof(double));	//mean değişkeninde 1 double'lık yer açtım.
						std=std_array(arr,mean,n,var);
						printf("Standard deviation of array=%lf\n",std);
						printf("Mean of the array=%lf\n",*mean);
					}
				}
				else if(secim==5){
					printf("Exiting this part...\n");
					tekrar=0;
				}
				else{
					printf("You entered wrong, please try again.\n");
				}
			}
		}
		else if(choose==2){
			printf("\nThis part will able to execute soon!\n\n");
		}
		else if(choose==3){
			printf("Enter a string(max 100 characters):\n");
			fgets(str,100,stdin);	//100 karakterlik string aldım
			remove_duplicates(str);
			puts(str);
		}
		else if(choose==4){
			printf("Exiting...\n");
			again=0;	//Again değişkeni 0 olduğu için loop tekrar dönemeyecek.
		}
		else{
			printf("You entered wrong, please try again.\n");
		}
	}
}
void generate_hofstadters_sequence(int *arr,int n){
	int i=0;
	if(arr[500]==n)		//arrayin 500. indexini değişkenim olarak kullandım, 
		return;			//eleman sayısına eşit olduğunda fonksiyonu sonlandırıyor.
	if(arr[500]==0||arr[500]==1)	//İlk iki elemanın 1 olduğu bilgisi verildi.
		arr[arr[500]]=1;
	else				//Array küçükten büyüğe doğru dolduruluyor.
		arr[arr[500]]=arr[arr[500]-arr[arr[500]-1]]+arr[arr[500]-arr[arr[500]-2]];
	arr[500]++;			//Her dönüşte n+1. indexteki sayıyı bir artırdım.
	generate_hofstadters_sequence(arr,n);	//arrayin küçük index'leri doldurulunca büyük index'leri  
}											//iplik söküğü gibi geliyor.

int find_max (int arr[], int index, int max_value){
	if(index==0)	//index'e son elemanın arraydeki index değeri atandı.
		return max_value;
	if(max_value<arr[index])
		max_value=arr[index];
	return find_max(arr,index-1,max_value);	//her seferinde index 1 küçülüyor,
}											//ta ki sıfıra gelene kadar.

int sum_array (int arr[]){
	if(arr[0]==0)					//her dönüşte arrayin ilk elemanını toplayıp
		return 0;					//boyutunu baştan bir kısaltıyorum, out of range'deki 
	return arr[0]+sum_array(arr+1);	//elemana (0'a) gelince toplamı return ediyorum.
}
double std_array (int arr[], double *mean, int n, int index){
	double std=0;
	int sum;		//index'i 0 aldım, her dönüşte bir arttırdım.
	if(index==n)	//sonunda eleman sayısına eşit olunca hesaba katılacak
		return 0;	//daha fazla eleman olmadığından 0 döndürdüm.
	if(n==500)
		*mean=(double)(sum_array(arr)-500)/n;	//n=500 olduğunda son indexteki 
	else 										//değişkenimi de hesaba katıyor. bunu önlemek için yaptım.
		*mean=(double)sum_array(arr)/n;		//aritmetik ortalamayı hesapladım.
	std=std+pow(*mean-arr[index],2)+std_array(arr,mean,n,index+1);	//standart sapmayı her seferinde kendisi,arr[index]'deki sapma ve
	if(index==0)													//arr[index+1]'deki sapmayı toplayarak hesapladım.
		return sqrt(std/(n-1));		//index basamak basamak eleman sayısına kadar çıkıp tekrar 0'a döndüyse sonucu döndür.
	return std;		//Aksi halde bu zamana kadar indexlerdeki sapmaların toplamını döndür.
}

char* remove_duplicates(char* str){
	int i=0;
	if(str[0]=='\0'){	//stringin son elemanına gelinmişse sonucu döndür
		return str;
	}
	if(str[0]==str[1]){			//art arda gelen iki eleman eşitse; 
		while(str[i]!='\0'){	//arrayi tekrar eden ilk elemandan itibaren
			str[i]=str[i+1];	//bir sola kaydır.
			i++;
		}
		remove_duplicates(str);	//art arda gelen eleman sayısının 2'den fazla olma
	}							//ihtimaline karşı tekrar kontrol et
	remove_duplicates(str+1);	//Art arda gelen elemanlar eşit değilse bir sonraki elemana geç.
}