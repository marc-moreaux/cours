#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // rand lib


#define WIDTH 25
#define HEIGHT 10


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
#elif _WIN32
	#include <conio.h>
	void usleep(int mTime){
		if(mTime<1000)
			mTime=1000;
		sleep(mTime/1000);
	}
#endif

//***************************************
//   Functions to manage snake array
//***************************************

// Init array to -1
void queueInit(char snake[WIDTH*HEIGHT+1][2], int x, int y){
	int i,j;
	for (i=0; i<WIDTH*HEIGHT+1; i++)
		for (j=0; j < 2; j++)
			snake[i][j] = -1;

	snake[0][0] = x;
	snake[0][1] = y;
}

// Find head position of snake
int queueHeadPos(char snake[WIDTH*HEIGHT+1][2]){
	int i, seenSnake=0;
	// Find head on array
	if(snake[0][0]!=-1)
		seenSnake=1;
	for(i=0; (snake[i][0]!=-1 || !seenSnake) && i<WIDTH*HEIGHT+1; i++)
		if(snake[i][0]!=-1)
			seenSnake=1;

	// adjust i pos
	if(--i<0)
		i = WIDTH*HEIGHT;

	return i;
}

// checks if structure is empty
int queueEmpty(char snake[WIDTH*HEIGHT+1][2]){
	if(queueHeadPos(snake)==WIDTH*HEIGHT+1)
		return 1;
	return 0;
}

// Add new position to head of array
void queueAdd(char snake[WIDTH*HEIGHT+1][2], int x, int y){
	int i;
	i = queueHeadPos(snake);

	// go to i+=1
	if(++i==WIDTH*HEIGHT+1)
		i=0;

	
	// Add new position to snake
	snake[i][0] = x;
	snake[i][1] = y;
}

// Remove back position
void queuePop(char snake[WIDTH*HEIGHT+1][2]){
	int i, headPos;


	// Find tail position
	headPos = queueHeadPos(snake);
	for(i=headPos; snake[i][0]!=-1; i--)
		if(i<0)
			i=WIDTH*HEIGHT+1;

	i+=1;
	if(i>WIDTH*HEIGHT)
		i=0;

	// remove snake's tail
	snake[i][0] = -1;
	snake[i][1] = -1;
}

// print the structure of thingy
void queuePrint(char snake[WIDTH*HEIGHT+1][2]){
	int i;
	for (i=0; i<WIDTH*HEIGHT+1; i++)
		printf(" %d", snake[i][0]);
	printf("\n");
	for (i=0; i<WIDTH*HEIGHT+1; i++)
		printf(" %d", snake[i][1]);
	printf("\n");
}

int queueIsPresent(char snake[WIDTH*HEIGHT+1][2], int x, int y){
	int i;
	for(i=0; i<WIDTH*HEIGHT+1; i++)
		if(snake[i][0]==x && snake[i][1]==y)
			return 1;
	
	return 0;
}

//***************************************
//          Game functions
//***************************************

// Display snake & board on screen
void displayBoard(char snake[WIDTH*HEIGHT+1][2], char food[2]){
	int x,y,i, hasSnake;

	
	// Draw top line
	for(x=0; x<WIDTH+2; x++)
		printf("#");
	printf("\n");

	// Draw snake on board (+board borders)
	for(y=0; y<HEIGHT; y++){
		printf("#");
		for(x=0; x<WIDTH; x++){
			hasSnake = 0;
			for(i=0; i<WIDTH*HEIGHT+1; i++){
				if(snake[i][0]==x && snake[i][1]==y){
					printf("%c", '@');
					hasSnake=1;
				}
			}
			if(food[0]==x && food[1]==y)
				printf("*");
			else if(hasSnake==0)
				printf(" ");
		}
		printf("#\n");
	}

	// Draw bottom line
	for(x=0; x<WIDTH+2; x++)
		printf("#");
	printf("\n");
}

void ahead(char snake[WIDTH*HEIGHT+1][2], char dir, int nextPos[2]){
	int x,y,headPos;

	headPos=queueHeadPos(snake);

	x=snake[headPos][0];
	y=snake[headPos][1];

	if(dir=='z') y--;
	if(dir=='d') x++;
	if(dir=='s') y++;
	if(dir=='q') x--;

	if(y<0) y=HEIGHT-1;
	if(x<0) x=WIDTH-1;
	if(y>HEIGHT-1) y=0;
	if(x>WIDTH-1) x=0;

	nextPos[0] = x;
	nextPos[1] = y;
}

// move snake ahead
void move(char snake[WIDTH*HEIGHT+1][2], char dir){
	int x,y,nextPos[2];

	ahead(snake, dir, nextPos);
	x = nextPos[0];
	y = nextPos[1];
	printf("%d/%d\n",x,y );

	queueAdd(snake,x,y);
}

void makeFood(char snake[WIDTH*HEIGHT+1][2], char food[2]){
	do{
		food[0] = rand()%WIDTH;
		food[1] = rand()%HEIGHT;
	}while(queueIsPresent(snake, food[0], food[1]));
}

// return 1 if food eaten
int foodEaten(char snake[WIDTH*HEIGHT+1][2], char food[2]){
	int x,y, headPos;

	headPos = queueHeadPos(snake);

	if( snake[headPos][0] == food[0]
	 && snake[headPos][1] == food[1]){
		makeFood(snake, food);	
		return 1;
	}
		

	return 0;
}

// return 1 if snake collide into snake
int collision(char snake[WIDTH*HEIGHT+1][2], char dir){
	int nextPos[2];

	ahead(snake, dir, nextPos);

	return queueIsPresent(snake, nextPos[0],nextPos[1]);
}


int main(){
	
	// Declarations
	char snake[WIDTH*HEIGHT+1][2];
	char food[2]={1,1};
	char entry, dir='d';
	int score;
	char end=0;

	// Initialization
	queueInit(snake,0,0);


	// Game loop
	displayBoard(snake, food);

	while(!end){

		// Manage keyboard entries
		if(kbhit()){
			entry = getchar();
			printf("\n");

			// move the cursor
			if(entry == 'z' || entry == 'd' || entry == 's' || entry == 'q' )
				dir = entry;
		}

		// Intra snake collision
		if(collision(snake,dir))
			end = 1;

		// Manage each sec of game
		move(snake, dir);
		if(!foodEaten(snake, food))
			queuePop(snake);
		else
			score++;



		// display
		displayBoard(snake, food);
		usleep(100000);
	}


	// Game Loop


}