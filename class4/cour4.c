#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


#define HEIGHT 24
#define WIDTH 38



// void initializeTable(char** table){

// 	// Allocate the table
// 	table = (char**) malloc(WIDTH*sizeof(char*));
// 	for(i=0; i<WIDTH; i++){
// 		(char*) malloc(HEIGHT*sizeof(char))
// 	}
// }


void ouvrirUnFichier(char table[WIDTH][HEIGHT]){
	FILE* file;
	int i,j;
	char tmp;


	file = fopen("experience2.txt", "r");
	if(!file){
		printf("superFail\n");
		exit(0);
	}

	for(j=0; j<HEIGHT; j++){
		for(i=0; i<WIDTH; i++){
			fscanf(file,"%c", &tmp);
			table[i][j] = tmp-'_'!=0;
		}
		fscanf(file,"\n");
	}
	fclose(file);
}

void fillTable(char table[WIDTH][HEIGHT]){
	int i,j;

	for(i=0; i<WIDTH; i++)
		for(j=0; j<HEIGHT; j++)
			table[i][j] = rand()%5>3;
}

void printTable(char table[WIDTH][HEIGHT]){
	int i,j;

	printf("\n");
	for(j=0; j<HEIGHT; j++){
		for(i=0; i<WIDTH; i++)
			printf("%c", table[i][j]?'#':'_');
		printf("\n");
	}
}


int countNeighbors(char table[WIDTH][HEIGHT], int col, int lig){
	int sum = 0;
	int i,j;

	
	for(i=-1;i<2;i++)
		for(j=-1;j<2;j++)
			if( (i!=0 || j!=0)
				&& lig+j > 0 
				&& lig+j < HEIGHT-1
				&& col+i > 0 
				&& col+i < WIDTH-1){
					sum += table[col+i][lig+j];
				}

	return sum;


	// Brainless method
	// Conditions are ordered this way
	// 7 6 5
	// 8 X 4
	// 1 2 3

	// if(lig>0 && col>0)
	// 	sum += table[col-1][lig-1];
	// if(lig>0)
	// 	sum += table[col][lig-1];
	// if(lig>0 && col<WIDTH-1)
	// 	sum += table[col+1][lig-1];
	// if(col<WIDTH-1)
	// 	sum += table[col+1][lig];
	// if(lig<HEIGHT-1 && col<WIDTH-1)
	// 	sum += table[col+1][lig+1];
	// if(lig<HEIGHT-1)
	// 	sum += table[col][lig+1];
	// if(lig<HEIGHT-1 && col>0)
	// 	sum += table[col-1][lig+1];
	// if(col>0)
	// 	sum += table[col-1][lig];

	// return sum;
}




void updateTable(char table[WIDTH][HEIGHT]){
	int i,j, count;

	printf("\n");

	// cpy of old table
	char oldTable[WIDTH][HEIGHT];
	for(j=0; j<HEIGHT; j++)
		for(i=0; i<WIDTH; i++)
			oldTable[i][j] = table[i][j];


	// Set the rule in here
	for(j=0; j<HEIGHT; j++)
		for(i=0; i<WIDTH; i++){
			count = countNeighbors(oldTable,i,j);
			// alive cell dies
			if(oldTable[i][j] && !(count==2 || count==3) )
				table[i][j]=0;

			// dead cell lives
			if(!oldTable[i][j] && count==3)
				table[i][j]=1;
		}


}

int main(){

	srand(time(NULL));

	// Initialize main table
	char table[WIDTH][HEIGHT];


	ouvrirUnFichier(table);
	while(1){
		printTable(table);
		updateTable(table);
		usleep(50000);
	}
}