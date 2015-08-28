#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define WIDTH 7
#define HEIGHT 5


#ifdef __linux
	#include <termios.h>
	#include <unistd.h>
	#include <fcntl.h>
	 
	int kbhit(void){
	  struct termios oldt, newt;
	  int ch;
	  int oldf;
	 
	  tcgetattr(STDIN_FILENO, &oldt);
	  newt = oldt;
	  newt.c_lflag &= ~(ICANON | ECHO);
	  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
	 
	  ch = getchar();
	 
	  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	  fcntl(STDIN_FILENO, F_SETFL, oldf);
	 
	  if(ch != EOF)
	  {
	    ungetc(ch, stdin);
	    return 1;
	  }
	 
	  return 0;
	}
#endif


// All these pieces of codes manage a 
// hard-coded heap
void razHeap(char heap[100][2]){
	int i;
	for(i=0; i<100; i++)
		heap[i][0] = heap[i][1] = -1;
}
void printHeap(char heap[100][2]){
	int i;
	for(i=0; heap[i][0]!=-1; i++)
		printf("(%d/%d)\n", heap[i][0], heap[i][1]);
	
	if(heap[0][0] == -1)
		printf("empty heap");

	printf("\n");
}
void stack(char heap[100][2], int x, int y){
	int i;
	for(i=0; heap[i][0] != -1; i++);
	
	heap[i][0] = x;
	heap[i][1] = y;
}
void pop(char heap[100][2], char pop[2]){
	int i;
	for(i=0; heap[i][0] != -1; i++);
	i-=1;
	pop[0] = heap[i][0];
	pop[1] = heap[i][1];
	heap[i][0] = -1;
	heap[i][1] = -1;
}
void swap(void *a, void *b, size_t size) {
  char temp[size]; 

  memcpy(temp, b,    size);
  memcpy(b,    a,    size);
  memcpy(a,    temp, size);
}



// function for board game
void printGameTab(char gameTab[HEIGHT][WIDTH], int cursor[2]){
	int x,y;
	for(y=0; y<HEIGHT; y++){
		for(x=0; x<WIDTH; x++){
			if(cursor[0]==x && cursor[1]==y)
				printf("_");
			else 
				printf("%c",gameTab[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}
void randonInit(char gameTab[HEIGHT][WIDTH]){
	int x,y;
	for(y=0; y<HEIGHT; y++)
		for(x=0; x<WIDTH; x++)
		{
			gameTab[y][x] = rand()%4;
			if(gameTab[y][x] == 0)
				gameTab[y][x] = 'b';
			else if(gameTab[y][x] == 1)
				gameTab[y][x] = 'r';
			else if(gameTab[y][x] == 2)
				gameTab[y][x] = 'j';
			else
				gameTab[y][x] = 'v';
		}
}
void moveCursor(char dir, int cursor[2]){
	// top
	if(dir == 'z' && cursor[1] > 0)
		cursor[1]-=1;
	
	// right
	if(dir == 'd' && cursor[0] < WIDTH-1)
		cursor[0]+=1;
	
	// bottom
	if(dir == 's' && cursor[1] < HEIGHT-1)
		cursor[1]+=1;

	// left
	if(dir == 'q' && cursor[0] > 0)
		cursor[0]-=1;
}
void printGameTabSelected(char gameTab[HEIGHT][WIDTH], char selectTab[HEIGHT][WIDTH]){
	int x,y;
	for(y=0; y<HEIGHT; y++){
		for(x=0; x<WIDTH; x++){
			if(selectTab[y][x])
				printf("#");
			else 
				printf("%c",gameTab[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}


// routine for selected array
void printSelectedTab(char selectTab[HEIGHT][WIDTH]){
	int x,y;
	for(y=0; y<HEIGHT; y++){
		for(x=0; x<WIDTH; x++)
			printf("%d", selectTab[y][x]);
		printf("\n");
	}
	printf("\n");
}
void razSelectTab(char selectTab[HEIGHT][WIDTH]){
	int x,y;
	for(y=0; y<HEIGHT; y++){
		for(x=0; x<WIDTH; x++){
			selectTab[y][x] = 0;
		}
	}
}
int scoreSelection(char selectTab[HEIGHT][WIDTH]){
	int x, y, sum=0;
	for(y=0; y<HEIGHT; y++)
		for(x=0; x<WIDTH; x++)
			sum += selectTab[y][x];

	// printf("%d\n", sum*(sum-1));
	return sum*(sum-1);
}



void selectGame(char gameTab[HEIGHT][WIDTH], int cursor[2], char selectTab[HEIGHT][WIDTH]){
	char heap[100][2];
	char cNode[2];  // currentNode
	int x,y;


	// reset heap and selection array
	razSelectTab(selectTab);
	razHeap(heap);

	// find neighborhood
	stack(heap, cursor[0], cursor[1]);
	while(heap[0][0] != -1){
		// explore this node
		pop(heap, cNode);
		selectTab[cNode[1]][cNode[0]] = 1;

		// add neighbors to stack
		for(x=-1; x<2; x+=2)
			if(  cNode[0]+x >= 0
			  && cNode[0]+x < WIDTH
			  && !selectTab[cNode[1]][cNode[0]+x]
			  && gameTab[cNode[1]][cNode[0]] == gameTab[cNode[1]][cNode[0]+x] )
				stack(heap, cNode[0]+x, cNode[1]);

		for(y=-1; y<2; y+=2)
			if(  cNode[1]+y >= 0
			  && cNode[1]+y < HEIGHT
			  && !selectTab[cNode[1]+y][cNode[0]]
			  && gameTab[cNode[1]][cNode[0]] == gameTab[cNode[1]+y][cNode[0]] )
				stack(heap, cNode[0], cNode[1]+y);

	}

	if(gameTab[cursor[1]][cursor[0]] == '.')
		razSelectTab(selectTab);
}
void removeSelection(char gameTab[HEIGHT][WIDTH], char selectTab[HEIGHT][WIDTH]){
	int x,y,i;
	for(y=0; y<HEIGHT; y++)
		for(x=0; x<WIDTH; x++)
			if( selectTab[y][x] )
				gameTab[y][x] = '.';

	for(x=0; x<WIDTH; x++)
		for(i=0; i<HEIGHT; i++)
			for(y=0; y<HEIGHT-1; y++)
				if(gameTab[y+1][x] == '.')
					swap(&gameTab[y+1][x], &gameTab[y][x], sizeof(char));

	// move vertically if necessary
	for(i=0; i<WIDTH; i++)
		for(x=0; x<WIDTH-1; x++)
			if(gameTab[HEIGHT-1][x+1] == '.')
				for(y=0; y<HEIGHT; y++)
					swap(&gameTab[y][x+1], &gameTab[y][x], sizeof(char));
}
int gameFinished(char gameTab[HEIGHT][WIDTH]){
	char otherTab[HEIGHT][WIDTH];
	int x,y;
	int cursor[2];

	for(y=0; y<HEIGHT; y++)
		for(x=0; x<WIDTH; x++){
			razSelectTab(otherTab);
			cursor[0] = x; cursor[1] = y;
			selectGame(gameTab, cursor, otherTab);
			if(scoreSelection(otherTab))
				return 0;
		}

	return 1;
}


int main(){

	// Variable initialization
	srand(time(NULL));
	char gameTab[HEIGHT][WIDTH];
	char selectTab[HEIGHT][WIDTH];
	char entry;
	int cursor[2] = {0,0};
	int selected = 0;
	int score = 0;
	
	randonInit(gameTab);
	printGameTab(gameTab, cursor);

	while(1){

		if(kbhit()){
			entry = getchar();
			printf("\n");

			// move the cursor
			if(entry == 'z' || entry == 'd' || entry == 's' || entry == 'q' ){
				selected = 0;
				moveCursor(entry, cursor);
				printGameTab(gameTab, cursor);
			}

			// select region
			if(entry == ' '){
				if(!selected){
					selectGame(gameTab, cursor, selectTab);
					printGameTabSelected(gameTab, selectTab);
					selected = 1;
				}
				else if(scoreSelection(selectTab)){
					score += scoreSelection(selectTab);
					removeSelection(gameTab, selectTab);
					printGameTab(gameTab,cursor);
					selected = 0;
				}
				else
					printGameTabSelected(gameTab, selectTab);
			}

			if(entry == 'o')
				printf("%d\n", score);
			
		
			// check if finished
			if(gameFinished(gameTab))
				printf("Your score is %d\n", score);
		}		

		usleep(100000);
	}


}