#include "LinkedList.h"
#include <stdarg.h>

// CONSTRUCTOR & DESTRUCTOR
LinkedList::LinkedList(int nodeNbr,...){
	tail = head = NULL;
	va_list args;
	va_start(args,nodeNbr);

	for(int i=0; i<nodeNbr; i++ ) 
		*this+=(va_arg(args, Node));
}
LinkedList::LinkedList(int size,int*tab){
	head = NULL;

	for(int i=0;i<size;i++)
		*this+=Node(tab[i]);

}
LinkedList::LinkedList(const LinkedList& toCopy){
	head = NULL;
	Node* pt2 = toCopy.getHead();
	while(pt2){
		*this += *pt2;
		pt2 = pt2->getNext();
	}
}
LinkedList::LinkedList(const Node &myNode){
	head = tail = new Node(myNode);
}
LinkedList::LinkedList(void){
	head = NULL;
	tail = NULL;
}
LinkedList::~LinkedList(void){
	Node* pt = head;
	Node* ptNext;

	while(pt){
		ptNext=pt->getNext();
		delete pt;
		pt = ptNext;
	}

}


// Functions
int  LinkedList::size() const {
	Node *pt = head;
	int size=0;
	while(pt){
		size++;
		pt = pt->getNext();
	}
	return size;
}
bool LinkedList::alreadyPresent(const Node& myNode)const{
	Node *pt = head;

	while(pt){
		if(pt->getElement() == myNode.getElement())
			return true;
		pt = pt->getNext();
	}
	return false;
}
void LinkedList::add(const Node &newNode){
	*this+=newNode;
}
void LinkedList::add(const Node &myNode,int index){
	if(index == 0){
		Node *oldHead = head;
		head = new Node(myNode);
		head->setNext(oldHead);
	}
	index--;
	if(!alreadyPresent(myNode) && (index < size()) )
		(*this)[index]+=Node(myNode);
}
void LinkedList::deleteNodeAt(const int index){
	Node *pt =head;
	Node *pt2=NULL;

	if(!head || size()<index+1)
		return;

	if(index==0){
		pt2 = head->getNext();
		delete head;
		head = pt2;
		return;
	}

	pt=&(*this)[index-1];
	pt2=pt->getNext()->getNext();
	delete pt->getNext();
	pt->setNext(pt2);


}
void LinkedList::refreshTail(){}



// operators 
std::ostream &operator<<( std::ostream &output, const LinkedList& myThis){
	if(!myThis.getHead())
		output << "empty List";


	Node* pt=myThis.getHead();
	while(pt){
		output << pt->getElement() << (pt->getNext()? " " : "" );
		pt=pt->getNext();
	}

	return output;
}
std::istream &operator>>( std::istream &input,        LinkedList& myThis){
	std::string buff;
	char bufInt[10]={'\0'};
	std::getline(input,buff);
	int j=0;
	if(buff.size()==0)
		return input;


	for(int i=0;i<buff.size()+1;i++){
		if(i!=buff.size() && buff[i]!=' ')
			bufInt[j++]=buff[i];
		else{
			std::cout << atoi(bufInt) << " ";
			myThis+=Node(atoi(bufInt));
			for(int i(0); i<j;i++)
				bufInt[i]='\0';
			j=0;
		}
	}

	return input;
}
LinkedList::operator char*() const{
	std::string str = (std::string)(*this);
	char * toChar = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), toChar);
	toChar[str.size()] = '\0';

	return toChar;
}
LinkedList::operator std::string() const{
	if(!head)
		return "nothing in the linkedList\n";

	Node *pt = head;
	char buff[10]={'\0'};
	std::string toString = "list : ";

	while(pt->getNext()){
		toString += itoa(pt->getElement(),buff,10);
		toString += "_";
		pt=pt->getNext();
	}
	toString += itoa(pt->getElement(),buff,10);
	
	
	return toString;
}
LinkedList &LinkedList::operator= (const LinkedList &right){
	Node* pt=head;
	Node* pt2=NULL;
	while(pt){
		pt2=pt->getNext();
		delete pt;
		pt=pt2;
	}
	head=NULL;
	pt=right.getHead();
	while(pt){
		(*this)+=(*pt);
		pt = pt->getNext();
	}

	return *this;
}
LinkedList &LinkedList::operator+ (const LinkedList &right){
	LinkedList *newLinkedList = new LinkedList(*this);

	Node* pt2 = right.head;
	while(pt2){
		*newLinkedList+=(*pt2);
		pt2 = pt2->getNext();
	}

	return *newLinkedList;
}
LinkedList &LinkedList::operator- (const LinkedList &right){
	LinkedList *newLinkedList = new LinkedList(*this);

	Node*pt2 = right.getHead();
	while(pt2){
		if(alreadyPresent(*pt2))
			*this-=*pt2;
		else *this+=*pt2;
		pt2=pt2->getNext();
	}



	return *newLinkedList;
}
LinkedList &LinkedList::operator+=(const Node &newNode){
	if(!head){
		head = tail = new Node(newNode);
		return *this;
	}

	Node* pt = head;
	if(!alreadyPresent(newNode)){
		while(pt->getNext())
			pt=pt->getNext();
	
		*pt += Node(newNode);
		tail = pt;
	}

	return *this;
}
LinkedList &LinkedList::operator-=(const Node &newNode){
	if(!head)
		return *this;
	if(!alreadyPresent(newNode))
		return *this;


	if(head->getElement() == newNode.getElement()){ // delete the first element
		Node*toDelete = head;
		head = head->getNext();
		delete toDelete;
		return *this;
	}
	

	Node* pt=head;
	while(pt&&pt->getNext()){  // delete in the list
		if(pt->getNext()->getElement() == newNode.getElement()){
			Node*toDelete = pt->getNext();
			pt->setNext( pt->getNext()->getNext() );
			delete toDelete;
		}
		pt = pt->getNext();
	}

	return *this;
}
Node &LinkedList::operator[](const int index){
	Node* pt=head;
	if(!head)
		return *pt; // retrive NULL => error

	if(index == 0)
		return *head;
	
	int cpt=0;
	while(cpt<index && pt){
		cpt++;
		pt=pt->getNext();
	}

	return *pt;
}
Node  LinkedList::operator[](const int index) const{
	Node* pt=head;
	if(!head)
		return *pt; // retrive NULL => error

	if(index == 0)
		return *head;
	
	int cpt=0;
	while(cpt<index && pt){
		cpt++;
		pt=pt->getNext();
	}

	return *pt;
}
bool LinkedList::operator==(const LinkedList &right) const{
	Node *pt = head;
	Node *pt2= right.getHead();

	if( size()!=right.size() )
		return false;


	while(pt){
		pt2 = right.getHead();
		while(pt2){
			if(pt->getElement() == pt2->getElement())
				break;
			pt2 = pt2->getNext();
		}
		if(!pt2)
			return false;
		pt = pt->getNext();
	}

	return true;
}
bool LinkedList::operator!=(const LinkedList &right) const{
	return !((*this)==right);
}

// getters
Node* LinkedList::getHead() const {return head;}