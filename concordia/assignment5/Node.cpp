#include "Node.h"
#include <stdlib.h>
#include <stdio.h>
#define NULL 0;

Node::Node(const Node& newNode){
	this->element = newNode.element;
	this->next = NULL;
}
Node::Node(int a){
	element = a;
	next = NULL;
}
Node::~Node(void){
}


// operator
bool  Node::operator!=(const Node &myNode) const{
	return !(*this==myNode);
}
bool  Node::operator==(const Node &myNode) const {
	if(this->element == myNode.element)
		return true;
	return false;
}
Node& Node::operator+=(const Node &right){
	Node* oldNext = this->next;
	this->next = new Node(right);
	this->next->next = oldNext;

	return *this;
}
Node& Node::operator= (const Node &myNode){
	this->element = myNode.element;
	return *this;
}
Node::operator char*()const{
	char *toChar = new char[10];
	itoa(element,toChar,10);
	return toChar;
}


// setters - getters
int   Node::getElement() const {return element;}
Node* Node::getNext(){return next;}
void  Node::setNext(Node* pt){next=pt;}
