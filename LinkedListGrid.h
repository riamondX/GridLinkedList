#pragma once
#include<iostream>
#include<string>
using namespace std;

typedef int elementType;
struct node;
typedef node* nodePtr;

struct node
{
	elementType elt;
	nodePtr east;
	nodePtr south;
};

class LinkedListGrid
{
protected:
	nodePtr head;// tail;//???
	int rows;
	int cols;

public:
	LinkedListGrid();
	virtual ~LinkedListGrid();
	LinkedListGrid(const LinkedListGrid &list); // copy constructor
 
	void clearList();

	elementType readAt(int x,int y) const;
	bool writeAt(int x, int y,elementType e);

	int getCol() const;
	int getRow() const;

	friend istream& operator >> (istream &in, LinkedListGrid &l);

	friend ostream& operator << (ostream &out, const LinkedListGrid &l);
};

