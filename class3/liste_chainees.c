#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define WIDTH 45
#define HEIGHT 35
#define FALSE 0
#define TRUE 1


// ***********************************
// *** Déclaration des structures
// ***********************************

// Declare une struture generique pour enregistrer les cases de la grille

typedef struct node{
	int visited;
	struct node* prev;

	int posX;
	int posY;
	struct node* gauche ;
	struct node* droite ;
	struct node* haut ;
	struct node* bas ;
}t_node;


enum dir {
   LEFT   = 1,
   RIGHT  = 2,
   TOP    = 3,
   BOTTOM = 4
};


// ***********************************
// *** Declaration des fonctions 
// ***   liées à une file
// ***********************************
typedef struct file{
    t_node* data;
    struct file *suivant;
} t_file;

void file_enqueue(t_file **p_file, t_node* data){
    t_file *p_nouveau = (t_file*)malloc(sizeof(t_file));
    if (p_nouveau != NULL)
    {
        p_nouveau->suivant = NULL;
        p_nouveau->data = data;
        if (*p_file == NULL)
        {
            *p_file = p_nouveau;
        }
        else
        {
            t_file *p_tmp = *p_file;
            while (p_tmp->suivant != NULL)
            {
                p_tmp = p_tmp->suivant;
            }
            p_tmp->suivant = p_nouveau;
        }
    }
}

t_node* file_dequeue(t_file **p_file){
    t_node* ret = NULL;
    /* On teste si la file n'est pas vide. */
    if (*p_file != NULL)
    {
        /* Création d'un élément temporaire pointant vers le deuxième élément de la file. */
        t_file *p_tmp = (*p_file)->suivant;
        /* Valeur à retourner */
        ret = (*p_file)->data;
        /* Effacement du premier élément. */
        free(*p_file), *p_file = NULL;
        /* On fait pointer la file vers le deuxième élément. */
        *p_file = p_tmp;
    }
    return ret;
}

void file_clear(t_file **p_file){
    /* Tant que la file n'est pas vide. */
    while (*p_file != NULL)
    {
        /* On enlève l'élément courant. */
        file_dequeue(p_file);
    }
}




// ***********************************
// *** Déclaration des fonctions node
// ***********************************

// set node avec des valeurs
void node_set(t_node* mNode, int posX, int posY, t_node* gauche, t_node* droite,t_node* haut,t_node* bas ){
	mNode->posX = posX;
	mNode->posY = posY;
	mNode->gauche = gauche;
	mNode->droite = droite;
	mNode->haut = haut;
	mNode->bas = bas;
}

void node_print(t_node mNode){
	printf("%d-%d\n",mNode.posX,mNode.posY);
	//
}

void node_print_dir_neighbor(t_node mNode, enum dir mDir){
	if(mDir == LEFT && mNode.gauche)
		node_print(*(mNode.gauche));

	if(mDir == RIGHT && mNode.droite)
		node_print(*(mNode.droite));

	if(mDir == TOP && mNode.haut)
		node_print(*(mNode.haut));

	if(mDir == BOTTOM && mNode.bas)
		node_print(*(mNode.bas));
}

void node_print_neighbor(t_node mNode){
	node_print_dir_neighbor(mNode, LEFT);
	node_print_dir_neighbor(mNode, RIGHT);
	node_print_dir_neighbor(mNode, TOP);
	node_print_dir_neighbor(mNode, BOTTOM);
}


// ***********************************
// *** Declaration des fonctions terrain
// ***********************************
void field_malloc(t_node** mField){
	*mField = (t_node*)malloc(WIDTH*HEIGHT*sizeof(t_node));
	//
}

// chaine la liste chainee
void field_generate(t_node* mField){
	int i;
	t_node* ptTop;
	t_node* ptBottom;
	t_node* ptLeft;
	t_node* ptRight;

	for(i=0;i<WIDTH*HEIGHT;i++){

		// Get the neighboring pointers
		ptTop = 	(i/WIDTH==0 ? 		NULL:&mField[i-WIDTH]);
		ptBottom = 	(i/WIDTH==HEIGHT-1? NULL:&mField[i+WIDTH]);
		ptLeft = 	(i%WIDTH==0 ? 		NULL:&mField[i-1]);
		ptRight = 	(i%WIDTH==WIDTH-1 ? NULL:&mField[i+1]);

		// chain current mField's node i
		node_set(&mField[i], i%WIDTH,i/WIDTH,ptLeft, ptRight, ptTop, ptBottom);
	}
}

void field_reset_visited(t_node* mField){
	for(int i=0;i<WIDTH*HEIGHT;i++){
		mField[i].visited = FALSE;
		mField[i].prev = NULL;
	}
}

void field_find_path(t_node* mField, t_node*beginNode, t_node*endNode){
	int i;
	t_file* mFile;
	t_node* nextNode;
	int end = FALSE;

	field_reset_visited(mField);
	file_enqueue(&mFile,beginNode);
	beginNode->prev=NULL;

	while(mFile!=NULL || end==FALSE){
		nextNode = file_dequeue(&mFile);
		if(nextNode==endNode){
			end=TRUE;
		}else{
			if(nextNode->gauche) {file_enqueue(&mFile,nextNode->gauche); nextNode->gauche->prev = nextNode;}
			if(nextNode->droite) {file_enqueue(&mFile,nextNode->droite); nextNode->droite->prev = nextNode;}
			if(nextNode->haut  ) {file_enqueue(&mFile,nextNode->haut  ); nextNode->haut->prev   = nextNode;}
			if(nextNode->bas   ) {file_enqueue(&mFile,nextNode->bas   ); nextNode->bas->prev    = nextNode;}
		}
	}
}

void field_print_path(t_node* mField, t_node*endNode){
	

	if(!endNode && !endNode->prev)
		printf("No fucking path !! \n");

	while(endNode->prev != NULL){
		node_print(*endNode);
		endNode = endNode->prev;
	}
}









int main(){
	// ***********************************
	// *** Déclaration des variables
	// ***********************************
	int iter;
	t_node* myField;



	// ***********************************
	// *** Debut de l'action
	// ***********************************
	field_malloc(&myField);
	field_generate(myField);
	
	field_find_path(myField,&myField[0],&myField[10] );
	
	
}