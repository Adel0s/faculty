#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Un fisier CSV are urmatoarele campuri: nume,functie,salariu. Exemplu:
Ion,inginer,3500
Ana,manager,4000
Maria,secretara,2300
Se cere sa se mareasca cu 15% toate salariile mai mici de 3000 de lei,
iar rezulatul sa se scrie inapoi in fisier.
*/
typedef struct{
	char nume[20];
	char fn[20];
	float salariu;
	}Pers;
Pers persoane[1000];
int nPers=0;

// split - care pune intr-un vector pointeri la fiecare componenta
// din linia data. componentele sunt separate prin ,
// returneaza nr de componente gasite
int split(char*componente[],char *linie){
	int i;
	int start=0;
	int n=0;		// nr componente
	for(i=0;linie[i];i++){
		if(linie[i]==','){
			linie[i]='\0';
			componente[n]=&linie[start];	// linie+start
			start=i+1;
			n++;
			}
		}
	componente[n]=&linie[start];
	n++;
	return n;
	}

void citire(){
	FILE *fis;
	fis=fopen("bd.csv","r");
	if(fis==NULL){
		puts("eroare deschidere fisier");
		exit(EXIT_FAILURE);
		}
	char linie[1000];
	// while(feof(fis)){...}
	while(fgets(linie,1000,fis)!=NULL){
		//puts(linie);
		char *componente[10];
		int nc=split(componente,linie);
		//printf("n=%d\n",nc);
		//for(int i=0;i<nc;i++)printf("#%s\n",componente[i]);
		if(nc==3){
			strcpy(persoane[nPers].nume,componente[0]);
			strcpy(persoane[nPers].fn,componente[1]);
			persoane[nPers].salariu=atof(componente[2]);
			nPers++;
			}
		}
	fclose(fis);
	}

void marire(){
	int i;
	for(i=0;i<nPers;i++){
		if(persoane[i].salariu<3000){
			persoane[i].salariu*=1.15;
			}
		}	
	}

void scriere(){
	FILE *fis;
	fis=fopen("bd.csv","w");
	if(fis==NULL){
		puts("eroare deschidere fisier");
		exit(EXIT_FAILURE);
		}
	for(int i=0;i<nPers;i++){
		fprintf(fis,"%s,%s,%g\n"
			,persoane[i].nume,persoane[i].fn,persoane[i].salariu);
		}
	fclose(fis);	
	}
	
int main()
{
	citire();
	marire();
	scriere();
	return 0;
}
