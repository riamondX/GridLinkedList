#include "LinkedListGrid.h"
#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
using namespace std;

const string FILENAME = "gridnumbers2.txt";

int main() 
{
	
	LinkedListGrid g;
	ifstream read;
	read.open(FILENAME);
	if (read.fail())
	{
		cout << "That file could not be opened. Boom." << endl;
		read.close();
		read.clear();
		assert(read.fail());
	}
	read >> g;
	read.close();
	cout << g;
	cout << "slot (1,2)" << g.readAt(1,2) << endl;
	cout << "slot (4,4)" <<g.readAt(g.getRow()-1,g.getCol()-1)<<endl;
	//g.readAt(1,2);
	cout << g;

	g.writeAt(4, 2, 5);
	cout << g;
	LinkedListGrid c = g;
	cout<<c;
	return 0;
}