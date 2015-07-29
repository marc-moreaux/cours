#pragma once


class Node
{
public:
	Node(const Node&);
	Node(int = 0 );
	~Node(void);

	int getElement() const;
	Node* getNext();
	void  setNext(Node*);

	operator char*() const;
	bool  operator==(const Node&) const;
	bool  operator!=(const Node&) const;
	Node& operator+=(const Node&);
	Node& operator= (const Node&);

private:
	int element;
	Node* next;
};