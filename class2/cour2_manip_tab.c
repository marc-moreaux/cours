#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// ***********************************
// *** Déclaration des fonctions
// ***********************************
void tab_alloc(int** tab,int tab_size);		// Alloue le tableau
void tab_init(int* tab,int tab_size);		// Init le tableau avec des valeurs aléatoires a valeur dans [48,122]
void tab_free(int* tab); 					// desalocation du tableau
void tab_print_int(int* tab,int tab_size);	// Affiche au format <int> le tableau
void tab_print_char(int* tab,int tab_size);	// Affiche au format <char> le tableau
void tab_modify(int* tab,int tab_size, int idx, int val); 	// 'tab' prends la valeur 'val' à l'index 'idx'
void tab_swap(int* tab,int tab_size, int idx1, int idx2); 	// Swap 2 valeurs du tableau


// Ecrire une programme pour manipuler des tableaux par pointeur.
// Le tableau est de taille dynamique. ('tailleTab')
// Le tableau est initialisé avec des valeurs aléatoires (dans [48,122]).
// Bien evidemment, le programme implemente les fonctions si dessus.
int main(){

	printf("%d",(int)sizeof(int*));

	// ***********************************
	// *** Déclaration de variables
	// ***********************************
	int i;
	int tailleTab = 20;
	int* monTab;

	srand(time(NULL));

	// ***********************************
	// *** Utilisation des fonctions
	// ***********************************
	tab_alloc(&monTab,tailleTab);
	tab_init(monTab,tailleTab);
	tab_print_char(monTab,tailleTab);
	tab_print_int(monTab,tailleTab);
	tab_free(monTab);



	return 0;
}

void tab_print_int(int* tab,int tab_size){
	int i;
	printf("Mon tableau : \n");
	for(i=0;i<tab_size;i++){
		printf("%d\t",tab[i]);
	}
	printf("\n");
}

void tab_print_char(int* tab,int tab_size){
	int i;
	printf("Mon tableau : \n");
	for(i=0;i<tab_size;i++){
		printf("%c\t",(char)tab[i]);
	}
	printf("\n");
}

void tab_alloc(int** tab,int tab_size){
	(*tab) = (int*)malloc(tab_size*sizeof(int));
	//
}

void tab_init(int* tab,int tab_size){
	int i; 
	for(i=0 ; i<tab_size ; i++ ){
		tab[i] = rand()%74+48; // [48,122]
	}
}

void tab_modify(int* tab,int tab_size, int idx, int val){
	if(idx < tab_size){
		tab[idx] = val;
	}else{
		printf("[Warning] dans tab_modify, (tab_size-idx) = (%d-%d) \n",tab_size,idx);
	}
}

void tab_swap(int* tab,int tab_size, int idx1, int idx2){
	int tmp;
	if(idx1 < tab_size && idx2 < tab_size){
		tmp = tab[idx1];
		tab[idx1] = tab[idx2];
		tab[idx2] = tmp;
	}else{
		printf("[Warning] dans tab_swap, (tab_size-idx1-idx2) = (%d-%d-%d) \n",tab_size,idx1,idx2);
	}
}

void tab_free(int* tab){
	free(tab);
	//
}