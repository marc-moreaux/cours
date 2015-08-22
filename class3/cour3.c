#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // rand lib


// realisation d'un pendu
// L'utilisateur entre des lettres au clavier le logiciel comlete le pendu.


#define NB_TRIALS 10

// Defini les donées variables du jeu
typedef struct penduWord{
	char wordToFind[30];
	char triedLetters[30];
}t_penduWord;

// Prototyping
t_penduWord initWordToFind();
void printCurrentState(t_penduWord);
int getScore(t_penduWord);
void getNewLetter(t_penduWord*);
int getFails(t_penduWord);
int finishedPendu(t_penduWord);



int main(){
	srand(time(NULL)); // initialize rand
	int endOfGame = 0;

	// Initialize a word for a new game
	t_penduWord penduWord = initWordToFind();

	finishedPendu(penduWord);

	// Start game loop
	while(getFails(penduWord) < 10 && !finishedPendu(penduWord)){
		printCurrentState(penduWord);
		getNewLetter(&penduWord);

	}

	printCurrentState(penduWord);


}

t_penduWord initWordToFind(){
	t_penduWord newWord;
	char* stg[] = {"philosophy", "is", "the", "study", "of", "the", "general", "and", "fundamental", "nature", "of", "reality", "existence", "knowledge", "values", "reason", "mind", "and", "language", "the", "ancient", "greek", "word", "philosophia", "was", "probably", "coined", "by", "Pythagoras", "and", "literally", "means", "love", "of", "wisdom", "or", "friend", "of", "wisdom", "Philosophy", "has", "been", "divided", "into", "many", "subfields", "tt", "has", "been", "divided", "chronologically", "ancient", "and", "modern", "by", "topic", "the", "major", "topics", "being", "epistemology", "logic", "metaphysics", "ethics", "and", "aesthetics", "and", "by", "style", "analytic", "philosophy"};

	strcpy(newWord.triedLetters, "");



	strcpy(newWord.wordToFind, stg[rand()%71]);

	return newWord;
}

// UI to get a new letter
void getNewLetter(t_penduWord *penduWord){
	char newLetter;
	int i, alreadyPicked;


	printf("New Letter : \n");
	fflush(stdin);
	scanf("%c", &newLetter);

	alreadyPicked = 0;
	for(i=0; i<strlen((*penduWord).triedLetters); i++)
		if((*penduWord).triedLetters[i] == newLetter){
			alreadyPicked = 1;
			break;
		}
	if(newLetter != '\n' && !alreadyPicked){
		int lastIdx = strlen((*penduWord).triedLetters);
		(*penduWord).triedLetters[lastIdx] = newLetter;
		(*penduWord).triedLetters[lastIdx+1] = '\0';
	}
}

// Return an iteger value with the amount of failed atempts
int getFails(t_penduWord penduWord){
	
	return strlen(penduWord.triedLetters) - getScore(penduWord);
}

int finishedPendu(t_penduWord penduWord){
	int diffLetters;
	int letterPresent;
	int i, j;

	diffLetters = 0;
	// count how many different letters in the word
	for(i=0; i<strlen(penduWord.wordToFind); i++){
		letterPresent = 0;
		for(j=i-1; j>0; j--)
			if(penduWord.wordToFind[i] == penduWord.wordToFind[j])
				letterPresent = 1;
		if(!letterPresent)
			diffLetters++;
	}
	printf("(%d)", diffLetters);

	// if you fond all the letters to find
	if(diffLetters == getScore(penduWord))
		return 1;
	return 0;
}

// Return the number of correct trials
int getScore(t_penduWord penduWord){
	int score = 0;
	int i,j;

	for(i=0; i<strlen(penduWord.triedLetters); i++)
		for(j=0;j<strlen(penduWord.wordToFind); j++)
			if(penduWord.triedLetters[i] == penduWord.wordToFind[j]){
				score++;
				break;
			}

	return score;
}

// print the current state of the pendu
void printCurrentState(t_penduWord penduWord){
	int currLIdx;

	printf("\n\n\t");
	// Go through the word to find and compare it with tested letters
	currLIdx = 0;
	while(penduWord.wordToFind[currLIdx] != '\0'){
		int triedLIdx;
		int hasLetter = 0;

		// Compare current letter of the word to find with tried letters
		triedLIdx = 0;
		while(penduWord.triedLetters[triedLIdx] != '\0'){
			if(penduWord.wordToFind[currLIdx] == 
				penduWord.triedLetters[triedLIdx]){
				hasLetter = 1;
				break;
			}
			triedLIdx++;
		}

		// All word printing appears here in o(n)
		// or O(np) considering n word letters and p tries
		if(hasLetter == 1)
			printf("%c ",penduWord.wordToFind[currLIdx]);
		else 
			printf("_ ");
		
		currLIdx++;
	}

	printf("  %d/%d", getScore(penduWord), (int)strlen(penduWord.triedLetters) );
	printf("  -- tried letters : %s \n", penduWord.triedLetters);

}