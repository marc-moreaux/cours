#pragma once
#include <iostream>
#include <String>
#include "Node.h"


class LinkedList
{
	friend std::ostream &operator<<( std::ostream &, const LinkedList&);
	friend std::istream &operator>>( std::istream &,       LinkedList&);

public:
	LinkedList(int,int); //conversion constructor
	LinkedList(const LinkedList&);
	LinkedList(int,int*);
	LinkedList(const Node &);
	LinkedList(int nodeNbr,...);
	LinkedList(void);
	~LinkedList(void);

	operator std::string() const;
	operator char*() const;
	LinkedList &operator= (const LinkedList&);
	LinkedList &operator+ (const LinkedList&);
	LinkedList &operator- (const LinkedList&);
	LinkedList &operator+=(const Node&);
	LinkedList &operator-=(const Node&);
	bool        operator==(const LinkedList&) const;
	bool        operator!=(const LinkedList&) const;
	Node       &operator[](const int);
	Node        operator[](const int) const;

	void deleteNodeAt(const int);
	void add(const Node&);
	void add(const Node&,int);
	int  size() const;
	void refreshTail();

	Node *getHead() const;
	bool alreadyPresent(const Node &myNode) const;

private:
	Node* head;
	Node* tail;
	
};
