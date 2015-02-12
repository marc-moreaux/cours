// librairies génériques
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int parite(int);
int fibonacci(int,int,int iters);


int main(){

	// ***********************************
	// *** Déclaration de variables
	// ***********************************
	int input = 0; // parite's var
	int nb1 = 0;   // fibonacci's var
	int nb2 = 0;   // fibonacci's var
	int iters = 0; // fibonacci's var


	// ***********************************
	// *** Test de la fonction parite
	// ***********************************
	printf("test parité : \n");
	input = 0; 		if(parite(input) == 0) printf("%6d => est PAIR\n",input); else printf("%6d => est IMPAIR\n",input);
	input = 1; 		if(parite(input) == 0) printf("%6d => est PAIR\n",input); else printf("%6d => est IMPAIR\n",input);
	input = 10005;	if(parite(input) == 0) printf("%6d => est PAIR\n",input); else printf("%6d => est IMPAIR\n",input);
	input = 5000;	if(parite(input) == 0) printf("%6d => est PAIR\n",input); else printf("%6d => est IMPAIR\n",input);
	input = -10; 	if(parite(input) == 0) printf("%6d => est PAIR\n",input); else printf("%6d => est IMPAIR\n",input);
	input = -11;	if(parite(input) == 0) printf("%6d => est PAIR\n",input); else printf("%6d => est IMPAIR\n",input);


	// ***********************************
	// *** Test de la fonction fibonacci
	// ***********************************
	nb1=0;nb2=1;iters=0;	printf("[%2d,%2d] ==%d=> %d\n",nb1,nb2,iters,fibonacci(nb1,nb2,iters));
	nb1=0;nb2=1;iters=1;	printf("[%2d,%2d] ==%d=> %d\n",nb1,nb2,iters,fibonacci(nb1,nb2,iters));
	nb1=0;nb2=1;iters=2;	printf("[%2d,%2d] ==%d=> %d\n",nb1,nb2,iters,fibonacci(nb1,nb2,iters));
	nb1=0;nb2=1;iters=7;	printf("[%2d,%2d] ==%d=> %d\n",nb1,nb2,iters,fibonacci(nb1,nb2,iters));
	nb1=0;nb2=0;iters=7;	printf("[%2d,%2d] ==%d=> %d\n",nb1,nb2,iters,fibonacci(nb1,nb2,iters));
	nb1=-1;nb2=1;iters=7;	printf("[%2d,%2d] ==%d=> %d\n",nb1,nb2,iters,fibonacci(nb1,nb2,iters));


}


// Fonction qui détermine si un entier est pair ou impair.
int parite(int input){
	return input%2;
}

// Fonction qui additionne la somme des deux dernier nombres (fibonacci number)
int fibonacci(int nb1,int nb2,int iters){
	int i;
	int sum = 0;

	for(i=0;i<iters;i++){
		sum = nb1 + nb2;
		nb1 = nb2;
		nb2 = sum;
	}

	return sum;
}