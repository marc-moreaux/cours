// Ususal suspect inludes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// *************************************
// ***
// ***  Fonction pour afficher si un mot entre est un palindrome.
// ***  Le mot est enregistré 'en dur' dans la variable  <mot>.
// ***  <i> et <j> sont les indexes des char que l'on compare.
// ***  <i> vas de l'index 0 à <strlen(mot)> (peut mieux faire)
// ***
// *************************************

int main(){

	// initialisation des variables
	char mot[50] = "loppoli";
	int i = 0; // parcourir la chaine dans un sens
	int j = 0; // parcourir la chaine dans l'autre sens
	int isPalindrome = 1; // false if not palindrome

	// degug taille de chaine
	// printf("[DEBUG]taille de la chaine : %d\n",(int)strlen(mot));

	for(i=0;i<strlen(mot);i++){
		j = strlen(mot)-i-1;
		// debug printing
		// printf("[DEBUG]%c - %c\n", mot[i],mot[j]);

		if(mot[i] != mot[j]){
			// on s'arrete
			isPalindrome = 0;
			break;
		}

	}


	// Fin du programme, output ce que tu veux
	if(!isPalindrome)
		printf("==> %s n'est pas un palindrome\n",mot);
	else
		printf("==> %s est un palindrome YOUPIII\n",mot);

	return 0;
}



