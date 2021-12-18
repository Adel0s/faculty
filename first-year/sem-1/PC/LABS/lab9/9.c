/*
Sa se scrie o functie cu urmatorul antent

uint32_t string_replace(char *where, const char *what, const char *replace)

Functia inlocuieste fiecare aparitie a string-ului what in string-ul where cu string-ul replace. Se considera ca zona de memorie a lui where este suficient de mare ca sa poata contine noul string. Functia returneaza numarul de inlocuiri
*/

#include <stdio.h>
#include <string.h>

// str: "ion si ana si maria citesc."\0
// src: "si" -> dst:"sau" => "ion sau ana sau maria citesc."
// src: "si" -> dst:"," => "ion , ana , maria citesc."
int str_replace(char *str,const char *src,const char *dst)
{
	int nr=0;		// nr inlocuiri
	int i,j,k;
	int lenStr=(int)strlen(str);
	int lenSrc=(int)strlen(src);
	int lenDst=(int)strlen(dst);
	for(i=0;str[i];i++){
		int egal=1;
		for(j=0;src[j];j++){
			if(str[i+j]!=src[j]){
				egal=0;
				break;
				}
			}
		if(egal){ // s-a gasit src la pozitia i in str => inlocuire
			if(lenDst>lenSrc){	// este nevoie de pozitii libere
				for(k=lenStr;k>=i+lenSrc;k--){
					str[k+(lenDst-lenSrc)]=str[k];
					}
				lenStr+=lenDst-lenSrc;
				}else{	// prea multe pozitii
				for(k=i+(lenSrc-lenDst);k<=lenStr;k++){
					str[k-(lenSrc-lenDst)]=str[k];
					}
				lenStr-=lenSrc-lenDst;
				}
			// copiere dst in str la pozitia i
			for(j=0;dst[j];j++){
				str[i+j]=dst[j];
				}
			nr++;
			}
		}

	return nr;
}
int main()
{
	char str[100]="ion si ana si maria citesc.";
	printf("inlocuiri: %d\n",str_replace(str,"si",","));
	printf("=>%s\n",str);
	return 0;
}
// teste de totalitate: ORICARE - flag=true; 
	// si daca exista un element care nu se potriveste, flag=false
// teste de existenta: EXISTA - flag=false; 
	// si daca exista un element care se potriveste, flag=true
