// assignment5.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "LinkedList.h"
#include <stdarg.h>

using std::cout;
using std::cin;
using std::endl;


int _tmain(int argc, _TCHAR* argv[]){
	
	int tab[7] = {8,7,3,4,10};
	LinkedList mainLinkedList  (5,Node(4),Node(9),Node(6),Node(3),Node(5));	 // constructor with variable number of entry node
	LinkedList mainLinkedList2 (Node(2));									 // constructor with 1 node entry
	LinkedList mainLinkedList3 (mainLinkedList);							 // constructor by copy
	LinkedList mainLinkedList4 (5,tab);										 // constructor with tab of integer
	
	Node mainNode;
	Node mainNode2(120);

	
	cout << "mainLinkedList 1\t" << mainLinkedList  << endl;
	cout << "mainLinkedList 2\t" << mainLinkedList2 << endl;
	cout << "mainLinkedList 3\t" << mainLinkedList3 << endl;
	cout << "mainLinkedList 4\t" << mainLinkedList4 << endl << endl;


	cout << "testing (1+4)\t\t" << (mainLinkedList + mainLinkedList4) << endl;
	cout << "testing (1-4)\t\t" << (mainLinkedList - mainLinkedList4) << endl;
	
	mainLinkedList.add(Node(8));mainLinkedList.add(Node(-8));
	mainLinkedList.add(Node(-9),4);
	cout << "list 1: added value 8 and -8\t\t" << mainLinkedList << endl;
	cout << "list 1: added value -9 at index 4\t" << mainLinkedList << endl;
	
	mainLinkedList.deleteNodeAt(3);
	cout << "list 1: Node at index 3 deleted\t\t" << mainLinkedList << endl;
	mainLinkedList -= Node(-9);
	cout << "list 1: remove node -9  \t\t" << mainLinkedList << endl;
	cout << "list 1: is 3 present? " << ((mainLinkedList.alreadyPresent(Node(3))==0)?"false\t\t":"true\t\t") << mainLinkedList << endl;
	cout << "list 1: is 10 present? " << ((mainLinkedList.alreadyPresent(Node(10))==0)?"false\t\t":"true\t\t") << mainLinkedList << endl;
	mainLinkedList[3]=Node(10);
	cout << "list 1: List[3]=10\t\t\t" << mainLinkedList << endl;
	mainLinkedList4 = mainLinkedList;
	cout << "list4  = list1   \t" << mainLinkedList4 << endl;

	cout << "list 1: size of list is : " << mainLinkedList.size() << endl;
	cout << "list1==list2 ? " << bool(mainLinkedList==mainLinkedList2) << endl;
	
	cout << "list1==list4 ? " << bool(mainLinkedList==mainLinkedList4) << endl;
	cout << "list 1: at index 1 : " << mainLinkedList[1] << endl;

	cout << "actual list2:\t\t" << mainLinkedList2 << endl;
	cin >> mainLinkedList2;
	cout << endl << "new list2:\t\t" << mainLinkedList2 << endl;

	system("pause");

	return 0;
}