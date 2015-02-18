#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// ***********************************
// *** Déclaration des fonctions
// ***********************************
void tab_alloc();		// Alloue le tableau
void tab_init();		// Init le tableau avec des valeurs aléatoires a valeur dans [48,122]
void tab_free(); 					// 
void tab_print_int();	// Affiche au format <int> le tableau
void tab_print_char();	// Affiche au format <char> le tableau
void tab_modify(); 	// 'tab' prends la valeur 'val' à l'index 'idx'
void tab_swap(); 	// Swap 2 valeurs du tableau


// Ecrire une programme pour manipuler des tableaux par pointeur.
// Le tableau est de taille dynamique. ('tailleTab')
// Le tableau est initialisé avec des valeurs aléatoires (dans [48,122]).
// Bien evidemment, le programme implemente les fonctions si dessus.
int main(){

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



	return 0;
}

