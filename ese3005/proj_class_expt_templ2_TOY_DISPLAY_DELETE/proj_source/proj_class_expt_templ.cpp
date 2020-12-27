//============================================================================
// Name        : proj_class_expt_templ.cpp
// Author      : takis
// Version     :
// Copyright   : copyright (C) 2020 emad studio inc.
// Description : code to experiment with templated classes
//============================================================================

#include <toys.h>		// Toy class
#include <iostream>
#include "proj_classes.h"	// main templated class
#include <string>

using namespace std;
// only use "using namespace" in your main code file

int main()
{
	// declare a Toy-database object, load from standard input
	DB<Toy> myToyDB;


	// print out the data
	myToyDB.display();
	myToyDB.del();
	cout <<"-----------------After deletion---------------------"<<endl;
	myToyDB.display();


	// exit
	cout << endl << myToyDB.numelements() << " processed." << endl;


	return 0;
}
