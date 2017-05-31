#include "LinkedListGrid.h"
#include<iostream>
#include<string>
using namespace std;


LinkedListGrid::LinkedListGrid()
{
	rows = 0;
	cols = 0;
	head  = NULL;
	// is tail necessary?
}


LinkedListGrid::~LinkedListGrid()
{
	clearList();
}

//copy constructor
// not finished it. one row is still different.
LinkedListGrid::LinkedListGrid(const LinkedListGrid &list)
{
	//make the head using the value
	int row = list.getRow();
	int col = list.getCol();
	elementType eltvalue;
	eltvalue = list.readAt(0,0);
	//cout << eltvalue;
	nodePtr add = new node;
	add->elt = eltvalue;
	head = add;
	rows = row;
	cols = col;

	nodePtr pre = head;
	nodePtr pretrace = pre;


	// make the first row
	// then shift. now pre is this row and curr is the next
	//crash at here i =5
	for (size_t i = 1; i < col; i++)
	{
		elementType eltvalue;
		eltvalue = list.readAt(0, i);
		nodePtr add = new node;
		add->elt = eltvalue;
		pretrace->east = add;
		//cout << "value of the head " << l.head->elt << endl;
		//cout << "made one(first row)! The value of slot " << i << " is " << pretrace->elt << endl;
		pretrace = pretrace->east;
		//cout << i << endl;
	}

	//after making the first row we have to think. 

	if (row > 1) {

		//currtrace = curr;
		for (int i = 1; i < row; i++)
		{
			// make a node. link it south of pre. call it curr.
			nodePtr curr;
			nodePtr currtrace;
			elementType eltvalue;
			eltvalue = list.readAt(i,0);
			//cout << eltvalue;
			nodePtr add = new node;
			add->elt = eltvalue;
			curr = currtrace = pre->south = add;
			pretrace = pre->east;

			for (size_t j = 1; j < col; j++)
			{
				// make the new node
				int eltvalue;
				eltvalue = list.readAt(i,j);
				nodePtr add = new node;
				add->elt = eltvalue;
				// link the last row content with the new row.
				currtrace->east = add;
				pretrace->south = add;

				//cout << "made one for "<<j<<"th slot of "<<i<<" th row! The value is " << currtrace->elt << endl;
				currtrace = currtrace->east;
				pretrace = pretrace->east;
			}
			// after a row is made,
			// curr becomes pre.
			pre = curr;
			//cout << "end of the row" << endl;

		}
	}
	cout << "finish getting info" << endl;


}

void LinkedListGrid::clearList()
{
	for (size_t i = 0; i < getRow(); i++)
	{
		nodePtr header = head;

		// find the first node of the last row
		for (size_t i = 0; i < rows-1; i++)
		{
			header = head->south;
		}

		nodePtr temptail = header;

		// delete the row of "header"
		for (size_t i = 0; i < cols-1; i++)
		{
			header = head->east;
			delete temptail;
			temptail = header;
		}
	}
	cout << "the head should be gone " << head->elt << endl;
}

elementType LinkedListGrid::readAt(int x, int y) const
{
	//cout << "The input slot is " << x<<","<<y<< endl;
	if (x >= rows && y >= cols)
	{
		return NULL;
	}
	else {
		nodePtr curr = head;
		for (int i = 0; i < getRow(); i++)
		{
			if (i == x)
			{
				for (int j = 0; j < getCol(); j++)
				{
					if (j == y)
					{
						return curr->elt;
					}
					curr = curr->east;
					//cout << curr->elt << endl;
				}

				curr = curr->south;
				//cout << curr->elt << endl;
				// this shit crashes when i=9...ofcourse
			}
		}
		return NULL;
	}
}

bool LinkedListGrid::writeAt(int x, int y, elementType e) 
{
	nodePtr curr = head;
	if (x >= getCol() && y >= getRow())
	{
		return false;
	}
	else {
		for (int i = 0; i < getRow(); i++)
		{
			if (i == x)
			{
				for (int j = 0; j < getCol(); j++)
				{
					if (j == y)
					{
						curr->elt = e;
						return true;
					}
					else
						curr = curr->south;
				}
			}
			else
			{
				curr = curr->east;
			}
		}
		return false;
	}
}


int LinkedListGrid::getCol() const
{ 
	return cols;
}

int LinkedListGrid::getRow() const
{
	return rows;
}

istream& operator >> (istream &in, LinkedListGrid &l) 
{
	int row;
	int col;
	in >> row >> col;
	
	l.cols = col;
	l.rows = row;
	//clearlist();

	// question: do I have to make head seperate? ??YES
	elementType eltvalue;
	in >> eltvalue;
	//cout << eltvalue;
	nodePtr add = new node;
	add->elt = eltvalue;
	l.head = add;


	nodePtr pre = l.head;
	nodePtr pretrace = pre;

	// make the first row
	// then shift. now pre is this row and curr is the next
	for (size_t i = 1; i < col; i++)
	{
		elementType eltvalue;
		in >> eltvalue;
		//cout << eltvalue;
		nodePtr add = new node;
		add->elt = eltvalue;
		pretrace->east = add;
		//cout << "value of the head " << l.head->elt << endl;
		//cout << "made one(first row)! The value of slot " << i << " is " << pretrace->elt << endl;
		pretrace = pretrace->east;
		//cout << i << endl;
	}

	//after making the first row we have to think. 
	
	if (row > 1) {

		//currtrace = curr;
		for (int i = 1; i < row; i++)
		{
			// make a node. link it south of pre. call it curr.
			nodePtr curr;
			nodePtr currtrace;
			elementType eltvalue;
			in >> eltvalue;
			//cout << eltvalue;
			nodePtr add = new node;
			add->elt = eltvalue;
			curr = currtrace = pre->south = add;
			pretrace = pre->east;

			for (size_t j = 1; j < col; j++)
			{
				// make the new node
				int eltvalue;
				in >> eltvalue;
				nodePtr add = new node;
				add->elt = eltvalue;
				// link the last row content with the new row.
				currtrace->east = add;
				pretrace->south = add;

				//cout << "made one for "<<j<<"th slot of "<<i<<" th row! The value is " << currtrace->elt << endl;
				currtrace = currtrace->east;
				pretrace = pretrace->east;
			}
			// after a row is made,
			// curr becomes pre.
			pre = curr;
			//cout << "end of the row" << endl;
			
		}
	}
	cout << "finish getting info"<<endl;
	return in;
}

ostream& operator << (ostream &out, const LinkedListGrid &l)
{
	cout << "Starting output:" << endl;

	// treverse by row use strat
	nodePtr start = l.head;
	// treverse by col use curr
	nodePtr curr = start;

	for (size_t i = 0; i < l.rows; i++)
	{

		for (size_t j = 0; j < l.cols; j++)		
		{
			out << curr->elt << " ";
			//cout << curr->elt << " - output value";
			curr = curr->east;
		}
		//cout << " Finished a line of printing.";
		out << endl;
		start = start->south;
		//cout <<"Sth in curr?" <<curr->elt << endl;
		curr = start;
	}

	return out;
}
