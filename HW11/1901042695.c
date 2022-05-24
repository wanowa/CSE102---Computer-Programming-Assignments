#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef struct node{		//Sayıları koyduğum struct
	int data;
	struct node *next;
}node;
typedef struct input{		//Kullanıcıdan input aldığım struct
	int number;
	struct input *next;
}input;
typedef struct array{		//Karşılaştırma sonucu linked list ve
	int n1;					//arraydeki farkları koyduğum struct
	int n2;
	struct array *next;
}array;

int *read_array(char *filename,int *byte_arr);
node *read_linkedlist(char *filename,int *byte_ll);
float *stats_array(int *arr);
float *stats_linkedlist(node *root);
array *comparison(input *root_input, int *arr_input);

int main(){
	struct node *root;
	struct node *iter;
	struct array *root_array;
	struct array *iter_array;
	struct input *root_input;
	struct input *iter_input;
	clock_t start,end;				//Süreyi ölçmek için
	char *filename="list.txt";
	int *arr,byte_arr=0,byte_ll=0,i=0,j=0,*arr_input,sayi;
	float *a_stat,*ll_stat;
	double t_read_array=0.0,t_read_linkedlist=0.0,t_stats_ll=0.0,t_stats_arr=0.0;
	for(i=0;i<4;i++){ 				//Read_array fonksiyonunu 4 çalışma süresinin
		start=clock();				//ortalamasını almak için 4 kez çalıştırıyorum.
		arr=read_array(filename,&byte_arr);
		end=clock();
		t_read_array=t_read_array+((double)(end-start))/CLOCKS_PER_SEC;
	}
	t_read_array=t_read_array/4;
	for(i=0;i<4;i++){
		start=clock();				//a_stat fonksiyonunu 4 çalışma süresinin 
		a_stat=stats_array(arr);	//ortalamasını almak için 4 kez çalıştırıyorum
		end=clock();
		t_stats_arr=t_stats_arr+((double)(end-start))/CLOCKS_PER_SEC;
	}
	t_stats_ll=t_stats_arr/4;
	for(i=0;i<4;i++){				//read_linkedlist fonksiyonunu 4 çalışma süresinin
		start=clock();				//ortalamasını almak için 4 kez çalıştırıyorum
		root=read_linkedlist(filename,&byte_ll);
		end=clock();
		t_read_linkedlist=t_read_linkedlist+((double)(end-start))/CLOCKS_PER_SEC;
	}
	iter=root;
	t_read_linkedlist=t_read_linkedlist/4;
	for(i=0;i<4;i++){				//ll_stat fonksiyonunun 4 çalışma süresinin
		start=clock();				//ortalamasını almak için 4 kez çalıştırıyorum
		ll_stat=stats_linkedlist(root);
		end=clock();
		t_stats_ll=t_stats_ll+((double)(end-start))/CLOCKS_PER_SEC;
	}
	t_stats_ll=t_stats_ll/4;
	printf("--------------------------------------------------------------\n");
	printf("\nRequired time for executing functions\n(Average the timing results of the last four calls)\n\n");
	printf("read_array = %lf\n",t_read_array);
	printf("read_linkedlist = %lf\n",t_read_linkedlist);
	printf("stats_array = %lf\n",t_stats_arr);
	printf("stats_linkedlist = %lf\n",t_stats_ll);
	printf("--------------------------------------------------------------\n");
	printf("\nStats of Array\n\n");
	printf("Used Bytes = %d\n",byte_arr);
	printf("Minimum Value = %.2f\nMaximum Value = %.2f\n",a_stat[0],a_stat[1]);
	printf("Mean of Numbers = %.2f\nStandard Deviation of Numbers = %.2f\n",a_stat[2],a_stat[3]);
	printf("--------------------------------------------------------------\n");	
	printf("\nStats of Linked List\n\n");
	printf("Used Bytes = %d\n",byte_ll);
	printf("Minimum Value = %.2f\nMaximum Value = %.2f\n",ll_stat[0],ll_stat[1]);
	printf("Mean of Numbers = %.2f\nStandard Deviation of Numbers = %.2f\n",ll_stat[2],ll_stat[3]);	
	printf("--------------------------------------------------------------\n");
	printf("\n____________________________PART 2____________________________\n\n");
	arr_input=(int*)malloc(sizeof(int));
	for(i=0;i==i;i++){			
		printf("Enter %d. element of the array(To finish, enter -1) = ",i+1);
		scanf("%d",&arr_input[i]);		//arr_input arrayini kullanıcının girdiği
		if(arr_input[i]==-1){			//sayıları atayıp her seferinde 
			break;						//arrayi genişletiyorum. Spesifik karakter olan
		}								//-1 girildiğinde input alma işlemi tamamlanıyor.
		arr_input=(int*)realloc(arr_input,(i+2)*sizeof(int));
	}
	printf("\n\n");
	root_input=(input*)malloc(sizeof(input));
	iter_input=root_input;
	for(j=0;j<i;j++){
		printf("Enter %d. element of the linked list = ",j+1);
		scanf("%d",&iter_input->number);					//kullanıcında arr_input arrayine girilen kadar
		iter_input->next=(input*)malloc(sizeof(input));		//"input" struct'ına sayı alıyorum.
		iter_input=iter_input->next;
	}	
	iter_input=NULL;
	iter_input=root_input;
	printf("\n\n");	
	root_array=comparison(root_input,arr_input);		//aynı indexteki farklı sayıların tespiti için
	iter_array=root_array;								//input struct'ını ve arr_input arrayini "comparison"
	int check=0;										//fonksiyonuna gönderdim ve sonucu, farklı elemanların 
	for(i=0;iter_array->next!=NULL;i++){				//depolandığı "array" structının root'una atadım.
		check=1;
		printf("\n%d. Difference:\nIn array=%d  ||  In Linked List=%d\n",i+1,iter_array->n1,iter_array->n2);
		iter_array=iter_array->next;		//Burada farklı olan elemanları yazdırdım.
	}
	if(check==0){			//Farklı eleman yoksa bunu belirttim.
		printf("There is no difference between array and linked list!\n");
	}
	free(arr);			//malloc ile hafızadan yer ayırdığım yerleri
	free(arr_input);	//iade ettim.
}

array *comparison(input *root_input, int *arr_input){
	struct array *root_array;
	struct array *iter_array;
	struct input *iter_input;
	iter_input=root_input;
	root_array=(array*)malloc(sizeof(array));
	iter_array=root_array;
	for(int i=0;arr_input[i]!=-1;i++){
		if(arr_input[i]!=iter_input->number){		//eğer belirli indexteki sayılar eşit değilse
			iter_array->n1=arr_input[i];			//farklı elemanların depolandığı array struct'ının
			iter_array->n2=iter_input->number;		//n1 değişkenine arr_input[i]'yi, n2 değişkenine
			iter_array->next=(array*)malloc(sizeof(array));		//iter_input->number'ı atıyorum.
			iter_array=iter_array->next;		//iter_array'i next'liyorum
		}
		iter_input=iter_input->next;		//iter_input'u next'liyorum
	}
	iter_array=NULL;		//iter_array'in sonuna NULL atıyorum.
	return root_array;		//ve bu array struct'ının root'unu döndürüyorum
}

node *read_linkedlist(char *filename,int *byte_ll){
	FILE *fp=fopen(filename,"r");
	int i=0,j=0,sayi;
	char virgul;
	node *iter,*root;
	root=(node*)malloc(sizeof(node));
	iter=root;
	*byte_ll=0;
	for(i=0;fscanf(fp,"%d%c",&sayi,&virgul)!=EOF;i++){		//EOF'a kadar devam et
		iter->data=sayi;
		iter->next=(node*)malloc(sizeof(node));
		iter=iter->next;
		*byte_ll=*byte_ll+8;		//her dönüşte linked list'in kapladığı byte 
	}								//kadar byte_ll değişkenini arttır.
	iter=NULL;		//linked list'in sonuna NULL ataıdm.
	return root;	//linked list'in root adresini döndür.
}

int *read_array(char *filename, int *byte_arr){
	FILE *fp=fopen(filename,"r");
	int i=0,j=0,sayi,*arr;
	char virgul;
	arr=malloc(sizeof(int));
	*byte_arr=0;
	for(i=0;fscanf(fp,"%d%c",&sayi,&virgul)!=EOF;i++){
		if(i%1000==0){
			arr=(int*)realloc(arr,(i+1000)*sizeof(int));
		}
		arr[i]=sayi;
		*byte_arr=*byte_arr+4;		//her dönüşte array'in kapladığı byte
	}								//kadar byte_arr değişkenini arttır.
	arr[i]=-1;
	return arr;			//arrayin adresini döndür.
}

float *stats_linkedlist(node *root){				//Basit 4 işlemle istenilen hesapları yaptım.
	int i;
	float *ll_stat,min,max,mean,std,sum=0;
	node *iter;
	ll_stat=(float*)malloc(4*sizeof(double));
	iter=root;
	min=iter->data;
	max=iter->data;
	for(i=0;iter->next!=NULL;i++){
		sum=sum+iter->data;
		if(iter->data<min){
			min=iter->data;
		}
		if(iter->data>max){
			max=iter->data;
		}
		iter=iter->next;
	}
	mean=sum/i;
	sum=0.0;
	iter=root;
	for(int j=0;j<i;j++){
		sum=sum+(iter->data-mean)*(iter->data-mean);
		iter=iter->next;
	}
	std=sqrt(sum/i);
	ll_stat[0]=min;
	ll_stat[1]=max;
	ll_stat[2]=mean;
	ll_stat[3]=std;
	return ll_stat;
}

float *stats_array(int *arr){				//Basit 4 işlemle istenilen hesapları yaptım.
	int i;
	float *a_stat,min,max,mean,std,sum=0;
	a_stat=(float*)malloc(4*sizeof(double));
	min=arr[0];
	max=arr[0];
	for(i=0;arr[i]!=-1;i++){
		sum=sum+arr[i];
		if(arr[i]<min){
			min=arr[i];
		}
		if(arr[i]>max){
			max=arr[i];
		}
	}
	mean=sum/i;
	sum=0.0;
	for(int j=0;j<i;j++){
		sum=sum+(arr[j]-mean)*(arr[j]-mean);
	}
	std=sqrt(sum/i);
	a_stat[0]=min;
	a_stat[1]=max;
	a_stat[2]=mean;
	a_stat[3]=std;
	return a_stat;
}