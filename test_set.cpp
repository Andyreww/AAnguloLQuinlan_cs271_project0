//========================================================
// Matt Kretchmar
// October 2022
// listdriver.cpp
// This file tests the List class.
//========================================================

#include <iostream>
#include "set.h"

int main ( void )
{


	Set<int> 	Set1;
	
	for (int i = 1; i <= 10; i++ )
		Set1.append(i);

	cout << "Set 1 = " << Set1.to_string() << endl;

	Set<int> Set2(Set1);
	cout << "Set 2 = " << Set2.to_string() << endl;

	cout << "\nSet1.insert(50,10);\nSet1.insert(0,0)\n";
	cout << "Set1.remove(1);\n"; 


	Set2[2] = 100;
	Set1.insert(50,10);
	Set1.insert(0,0);
	Set1.remove(1);
	cout << "Set2 = " << Set2.to_string() << endl;
	cout << "Set1 = " << Set1.to_string() << endl;


	
	cout << "\nSet 3 new empty\n";
	Set<int> Set3;
	cout << "Set 3 size = " << Set3.length() << endl;
	if ( Set3.isEmpty() )
		cout << "Set 3 empty\n";
	else
		cout << "Set 3 not empty\n";

	cout << "\nSet 3= Set1+Set2\n";
	cout << "Set 1:" << Set1.to_string() << endl;
	cout << "Set 2:" << Set2.to_string() << endl;
	Set3 = Set1 + Set2; //Fix with the other function
	cout << "Set 3 = " << Set3.to_string() << endl;


	cout << "Set3 size = " << Set3.length() << endl;
	if ( Set3.isEmpty() )
		cout << "Set3 empty\n";
	else
		cout << "Set3 not empty\n";

	cout << "\nSet3.clear()\n";
	Set3.clear();

	cout << "Set3 size = " << Set3.length() << endl;
	if ( Set3.isEmpty() )
		cout << "Set3 empty\n";
	else
		cout << "Set3 not empty\n";

	cout << "\nTESTING -------------------------------\n";
	
	Set<int> Set10;
	cout << "Set10 = " << Set10.to_string() << endl;
		
	for ( int i = 1; i <= 20; i++ )
		Set10.append(i);
	cout << "Set10 = " << Set10.to_string() << endl;
	
	Set10.remove(19);
	cout << "Set10 = " << Set10.to_string() << endl;
	
	cout << "Set10 size = " << Set10.length() << endl;

	Set10.insert(50,19);
	cout << "Set10 = " << Set10.to_string() << endl;

	return 0;
}

