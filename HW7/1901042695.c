#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	int choose,again=1,try,row=0,genre_row=0,platform_row=0,column=0,i=0,j=0,exist=0,time,year,g,p;
	int g_freq[12]={0,0,0,0,0,0,0,0,0,0,0,0},p_freq[10]={0,0,0,0,0,0,0,0,0,0};		//platform ve genre'lerin sıklığını bu arraylerde tutuyorum. Başlangıçta tüm indexler 0.
	float data[2000][7],sum;
	char name[2005][1000],genre[100][20],platform[100][20],satir[200],scan=' ';
	char buffer[20],*end,isim[100],not_available[]="Not Available";
	double veri;
	FILE *fp=fopen("Video_Games.txt","r");
	fgets(satir,200,fp);
	while(!feof(fp)){			//Dosya sonunua kadar okudum.
		column=0;
		i=0;
		j=0;
		fgets(satir,200,fp);		//Satırı satir arrayine aldım.
		while(satir[i]!=','){		//ilk virgüle kadarki kısmı name arrayine attım.
			name[row][column]=satir[i];
			column++;
			i++;
		}
		column=0;
		i++;

		while(satir[i]!=','){						//Sonraki virgüle kadarki kısmı buffer arrayine attım.
			buffer[column]=satir[i];
			column++;
			i++;
		}
		j=0;
		exist=0;
		while(j<=row){				
			if(strcmp(buffer,genre[j])==0){			//Bu zaman kadar okunan genre'ler ile buffer'daki genreyi karşılaştırdım.
				data[row][0]=j;						//Buffer, hangi index'deki genre ile uyuşuyorsa data'nın o satırındaki genre'ye j'yi atıyorum.
				g_freq[j]++;						//Her genre bulduğumda g_freq arrayinin gerekli index'indeki sayıyı 1 arttırıyorum.
				exist=1;							//Ve programa aradığım genre'nin mevcut olduğunu söyledim.
			}
			j++;
		}
		if(exist==0){								//Eğer row satırındaki oyunun genre'si daha önce kaydedilmemişse, yukarıdaki işlemde de 
			for(j=0;j<column;j++){					//bulamamışsam genre arrayinin genre_row satırına(0'dan başlıyor) buffer'daki genre'yi
				genre[genre_row][j]=buffer[j];		//koyuyorum.
			}
			data[row][0]=genre_row;					//Data arrayindeki mevcut satıra da buffer'ı koyduğum genre_row indexini atıyorum.
			g_freq[genre_row]++;					//Her genre bulduğumda g_freq arrayinin gerekli index'indeki sayıyı 1 arttırıyorum.
			genre_row++;							//Artık genre_row satırında bir genre var. Daha önce kayıtlı olmayan bir genre gelirse
		}											//yeni satıra atmak için 1 arttırıyorum.
		column=0;
		i++;
		memset(buffer,0,sizeof(buffer));			//Buffer arrayinin tüm hücrelerini temizliyorum, ki bir sonraki string öncekinden kısaysa 
													//uzun olan stringin son karakterleri array'de kalmaya devam etmesin.
		while(satir[i]!=','){						//Sonraki virgüle kadarki kısmı buffer arrayine attım.
			buffer[column]=satir[i];				
			column++;
			i++;
		}
		j=0;
		exist=0;
		while(j<=row){
			if(strcmp(buffer,platform[j])==0){		//Genre için yaptığım işlemlerin aynısını platform için yaptım.
				data[row][1]=j;
				p_freq[j]++;
				exist=1;
			}
			j++;
		}
		if(exist==0){
			for(j=0;j<column;j++){
				platform[platform_row][j]=buffer[j];
			}
			data[row][1]=platform_row;
			p_freq[platform_row]++;
			platform_row++;
		}
		column=0;
		i++;
		memset(buffer,0,sizeof(buffer));			//Buffer arrayini temizledim.

		while(satir[i]!=','){						//Sonraki virgüle kadar olan kısmı buffer arrayine attım.
			buffer[column]=satir[i];
			column++;
			i++;
		}
		veri=strtod(buffer,&end);					//Buffer arrayindeki verileri strtod fonksiyonunu kullanarak double'a çevirdim.
		data[row][2]=veri;							//Çıkış yılı verisini data arrayine attım.
		column=0;
		i++;
		memset(buffer,0,sizeof(buffer));			//Buffer arrayini temizledim.

		while(satir[i]!=','){						//Sonraki virgüle kadar olan kısmı buffer arrayine attım.
			buffer[column]=satir[i];
			column++;
			i++;
		}
		veri=strtod(buffer,&end);					//Buffer arrayindeki verileri strtod fonksiyonunu kullanarak double'a çevirdim.
		data[row][3]=veri;							//NA sales verisini data arrayine attım.
		column=0;
		i++;
		memset(buffer,0,sizeof(buffer));			//Buffer arrayini temizledim.

		while(satir[i]!=','){						//Sonraki virgüle kadar olan kısmı buffer arrayine attım.
			buffer[column]=satir[i];
			column++;
			i++;
		}
		veri=strtod(buffer,&end);					//Buffer arrayindeki verileri strtod fonksiyonunu kullanarak double'a çevirdim.
		data[row][4]=veri;							//EU sales verisini data arrayine attım.
		column=0;
		i++;
		memset(buffer,0,sizeof(buffer));			//Buffer arrayini temizledim.

		while(satir[i]!=','){						//Sonraki virgüle kadar olan kısmı buffer arrayine attım.
			buffer[column]=satir[i];
			column++;
			i++;
		}
		veri=strtod(buffer,&end);					//Buffer arrayindeki verileri strtod fonksiyonunu kullanarak double'a çevirdim.
		data[row][5]=veri;							//Global sales verisini data arrayine attım.
		column=0;
		i++;
		memset(buffer,0,sizeof(buffer));			//Buffer arrayini temizledim.

		while(satir[i]!='\n'){						//Sonraki virgüle kadar olan kısmı buffer arrayine attım.
			buffer[column]=satir[i];
			column++;
			i++;
		}
		veri=strtod(buffer,&end);					//Buffer arrayindeki verileri strtod fonksiyonunu kullanarak double'a çevirdim.
		data[row][6]=veri;							//User score verisini data arrayine attım.
		memset(buffer,0,sizeof(buffer));			//Buffer arrayini temizledim.
		row++;
	}


	while(again==1){								//Kullanıcı 8 girip again değişkenini 0 yapmadığı sürece dönüyor.
		printf("0: List of the Genres\n");
		printf("1: List of the Platforms\n");
		printf("2: List of the Games Through the Years\n");
		printf("3: All Informations of a Single Game\n");
		printf("4: Average of the User Scores\n");
		printf("5: Georographical Information of a Single Game\n");
		printf("6: Frequence of the Genres\n");
		printf("7: Frequence of the Platforms\n");
		printf("8: Exit\n");
		printf("\n\nPlease select an operation: ");
		scanf("%d",&choose);
		if(choose==0){
			for(i=0;i<genre_row;i++){				//Genre arrayine her genre atamamızda genre_row integer'ı bir arttı.
				printf("%s\n",genre[i]);			//Yani genre_row artık kaç tane genre adı olduğunu tutuyor. i'yi genre_row
			}										//kadar döndürerek tüm genre adlarını yazdırıyorum.
			printf("\n\n\n");
		}
		else if(choose==1){
			for(i=0;i<platform_row;i++){			//Platform arrayine her platform adı atamamızda platform_row integer'ı bir arttı.
				printf("%s\n",platform[i]);			//Yani platform_row artık kaç tane platform adı olduğunu tutuyor. i'yi platform_row
			}										//kadar döndürerek tüm platform adlarını yazdırıyorum.
			printf("\n\n\n");
		}
		else if(choose==2){
			try=0;
			while(try==0){							//try değişkeni, belirtilen yıl aralığında hiç oyun olmaması veya kullanıcıdan
				printf("Enter a year:\n");			//Until/Since bilgisi istediğimizde 0 veya 1'den başka sayı girdiğinde 0 oluyor.
				scanf("%d",&year);					//Bu da döngüyü tekrar döndürüyor.
				printf("\nUntil (0) or Since (1) %d: ",year);
				scanf("%d",&time);
				printf("\n\n");
				for(i=0;i<2000;i++){
					if(time==0){
						if(data[i][2]<year){
							try=1;
							printf("%s\n",name[i]);
						}
					}
					else if(time==1){
						if(data[i][2]>year){
							try=1;
							printf("%s\n",name[i]);
						}
					}
					else{
						try=0;
					}
				}
				if(try==0){
					printf("\nTRY AGAIN.");

				}
				printf("\n\n\n");
			}
		}
		else if(choose==3){
			try=0;
			while(try==0){							//Belirtilen isimde oyun adı bulunamadığında tekrar dönecek.
				printf("\n\nPlease enter the name of the game:\n");
				scanf("%s",isim);
				for(i=0;i<2000;i++){				//i'yi oyun sayısı kadar döndürdüm.
					if(strcmp(isim,name[i])==0){	//Girilen oyun ismi ile name[i] satırındaki isim aynı olduğunda işlem yapmaya başlıyoruz.
						g=(int)data[i][0];			//Tutulan genre indexini int olarak g değişkenine attım.
						p=(int)data[i][1];			//Tutualn platform indexini int olarak p değişkenine attım.
						try=1;
						printf("Name:\t\t%s\nGenre:\t\t%s\nPlatform:\t%s\n",name[i],genre[g],platform[p]);
						printf("Year:\t\t%.0f\nSales In NA:\t%f\nSales In Eu:\t%f\n",data[i][2],data[i][3],data[i][4]);
						if(data[i][5]==0){			//Global sales'ın 0 olması, strtod fonksiyonunun dönüştürecek değer bulamadığı anlamına geliyor. Bu durumda
							printf("Total Sales:\t%s\nUser Score:\t%f\n\n",not_available,data[i][6]);		//global sales kısmına not_available yazıyoruz.
						}
						else{
							printf("Total Sales:\t%f\nUser Score:\t%f\n\n",data[i][5],data[i][6]);
						}
						break;
					}
				}
				if(try==0){
					printf("\nTRY AGAIN.\n\n");
				}
			}
			printf("\n\n\n");
		}
		else if(choose==4){
			sum=0.0;
			for(i=0;i<2000;i++){					//Tüm user score'ları sum değişkeninde toplayıp
				sum=sum+data[i][6];					//oyun sayısı olan 2000'e böldüm.
			}
			printf("\n\nAverage: %f\n\n\n",sum/2000);
		}
		else if(choose==5){
			try=0;
			while(try==0){							//Girilen isimde oyun bulunamazsa döngü tekrar dönecek.
				printf("\n\nPlease enter the name of the game:\n");
				scanf("%s",isim);
				for(i=0;i<2000;i++){
					if(strcmp(isim,name[i])==0){
						try=1;
						if(data[i][3]>data[i][4]){				//Basit bir karşılaştırmayla oyunun hangi kıtada daha popüler olduğunu buldum.
							printf("\nThis game was more popular in North America\n\n\n");
						}
						else if(data[i][3]<data[i][4]){
							printf("\nThis game was more popular in Europe\n\n\n");
						}
						else if (data[i][3]==data[i][4]){
							printf("\nThis game popularity was the same on both continents\n\n\n");
						}
						break;
					}
				}
				if(try==0){
					printf("\nTRY AGAIN.\n\n\n");
				}
			}
			printf("\n\n\n");
		}
		else if(choose==6){
			for(i=0;i<12;i++){										//i'yi genre isimlerinin adedi olan 12 kere döndürdüm.
				if(strlen(genre[i])<=7){							//if satırını yazılar aynı hizada yazdırılsın diye koydum.
					printf("%s\t\t%d\n",genre[i],g_freq[i]);		//Her dönüşte o indexteki genre adını ve sıklık'ı bastırdım.
				}
				else{
					printf("%s\t%d\n",genre[i],g_freq[i]);
				}
			}
			printf("\n\n\n");
		}
		else if(choose==7){	
			for(i=0;i<10;i++){										//i'yi platform isimlerinin adedi olan 10 kere döndürdüm.
				if(strlen(platform[i])<=7){							//if satırını yazılar aynı hizada yazdırılsın diye koydum.
					printf("%s\t\t%d\n",platform[i],p_freq[i]);		//Her dönüşte o indexteki platform adını ve o sıklık'ı bastırdım.
				}
				else{
					printf("%s\t%d\n",platform[i],p_freq[i]);
				}
			}
			printf("\n\n\n");
		}
		else if(choose==8){
			printf("8\n");
			again=0;							//8 girilirse again değişkeni 0 olacak ve döngüden çıkılacak.
			printf("\n\nExiting...\n\n");
		}
		else{
			printf("\n\nTRY AGAIN.\n\n\n\n");	//Bunlar dışında input girilmesi halinde program dönmeye devam edecek.
		}
	}
}