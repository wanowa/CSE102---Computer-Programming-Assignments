#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_CARD 52
#define MAX_SUIT 4
#define MAX_FACE 13
#define LENGTH 10
struct card{
	const char *face;
	const char *suit;
}kart[MAX_CARD],temp;
struct Hospital{
	char *name;
	char citiesServed[3];
}results[4];
int numPathsHome(int street, int avenue);
void default_place(char suits[MAX_SUIT][LENGTH],char faces[MAX_FACE][LENGTH]);
void change();
int canOfferCovidCoverage(char _cities[6],char _locations[4][3],int _numHospitals,struct Hospital results[4]);
int main(){
	int choice,street,avenue,path, _numHospitals,sonuc;
	char _cities[6]={'A','B','C','D','E','F'};
	char _locations[4][3]={ {'A','B','C'}, {'A', 'C', 'D'}, {'B', 'F'}, {'C', 'E', 'F'} };
	srand(time(NULL));
	results[0].citiesServed[0]='A';	results[0].citiesServed[1]='B';	results[0].citiesServed[2]='C';
	results[1].citiesServed[0]='A';	results[1].citiesServed[1]='C';	results[1].citiesServed[2]='D';
	results[2].citiesServed[0]='B';	results[2].citiesServed[1]='F';
	results[3].citiesServed[0]='C';	results[3].citiesServed[1]='E';	results[3].citiesServed[2]='F';
	while(1){
		printf("1)Execute Part 1\n2)Execute Part 2\n3)Execute Part 3\n4)Exit\n");
		scanf("%d",&choice);
		printf("\n");
		if(choice==1){
			printf("Enter the street number: \n");
			scanf("%d",&street);
			printf("street:%d\n",street);
			printf("Enter the avenue number: \n");
			scanf("%d",&avenue);
			printf("avenue:%d\n",avenue);
			path=numPathsHome(street,avenue);
			printf("Number of optimal paths to take back home: %d\n\n\n",path);
		}
		else if(choice==2){
			printf("Enter the maximum number of hospitals that can be constructed:\n");
			scanf("%d",&_numHospitals);
			sonuc=canOfferCovidCoverage(_cities,_locations,_numHospitals,results);
		}
		else if(choice==3){
			char faces[MAX_FACE][LENGTH]={"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
			char suits[MAX_SUIT][LENGTH]={"Hearts","Diamonds","Clubs","Spades"};
			default_place(faces,suits);
			change();
			for(int i=0;i<MAX_CARD;i++){
				printf("%5s of %-10s\t\t",kart[i].face,kart[i].suit );
				if(i%2==1){
					printf("\n");
				}
			}
			printf("\n\n");
		}
		else if(choice==4){
			printf("Exiting...\n");
			return 0;
		}
		else{
			printf("You entered wrong,please try again.\n");
		}
	}
}

int numPathsHome(int street, int avenue){
	if(street==1||avenue==1){
		return 1;
	}
	return numPathsHome(street,avenue-1)+numPathsHome(street-1,avenue);
}

void default_place(char faces[MAX_FACE][LENGTH],char suits[MAX_SUIT][LENGTH]){
	int i=0;
	for(i=0;i<MAX_CARD;i++){
		kart[i].face=faces[i/MAX_SUIT];
		kart[i].suit=suits[i%MAX_SUIT];
	}
}

void change(){
	int random,i=0;
	for(i=0;i<MAX_CARD;i++){
		random=rand()%MAX_CARD;
		temp=kart[i];
		kart[i]=kart[random];
		kart[random]=temp;
	}
}

int canOfferCovidCoverage(char _cities[6],char _locations[4][3],int _numHospitals,struct Hospital results[4]){
 	
}