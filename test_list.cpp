#include "list.h"
#include <iostream>
#include <cassert>

using namespace std;

void testDefaultConstructor()
{
	List l1;
	assert(l1.toString() == "[]");
}

void testCopyConstructor() //check this
{
	List test2;
  test2.add("Hey");
  List test(test2);
  //cout << test2.toString() << endl; //Debug
	assert(test.toString() == test2.toString());
}

void testAdd() //from Andrew
{
	List l3;
	l3.add("Andrew");
	l3.add("Test");
	assert(l3.toString() == "[Andrew, Test]");
	//cout << l3.toString() << endl; //Debug
}

void testSize()
{
	//Checks normal sizing
	List l4;
	int test_num;
	l4.add("Hello");
	test_num = l4.size();
	assert(test_num == 1);
	//cout << l4.size() << endl; //Debug

	//Checks empty list size
	List l4_1;
	int test_num2;
	test_num2 = l4_1.size();
	assert(test_num2 == 0);
	//cout << l4_1.size() << endl; //Debug

}

void testIndex()
{
	List l5;
	int test_num2, test_num3;
	l5.add("Hi");
	l5.add("Hey");
	l5.add("Ice cream");

	//Checks for element in l5
	test_num2 = l5.index("Hi");
	assert(test_num2 == 2);

	//cout << "Index: " << l5.index("Ice cream") << endl; //Debug
	//Checks for element not in l5
	test_num3 = l5.index("Cookies");
	assert(test_num3 == -1);

}

void testInsert()
{
	List l6;
	l6.add("Noodles");
	l6.add("Pasta");
	l6.add("Spaghetti");

	//Checks general insert
	l6.insert(1, "Ravioli");
	assert(l6.toString() == "[Noodles, Ravioli, Pasta, Spaghetti]");  //to add in an element at index 1

	//Checks insert at first index
	l6.insert(0, "Mac & Cheese");
	//cout << l6.toString() << endl;
	assert(l6.toString() == "[Mac & Cheese, Noodles, Ravioli, Pasta, Spaghetti]");  //to add in an element at index 1
	//Checks insert out of range
	//l6.insert(22, "Error message likely");
	//assert(l6.toString() == "ERROR: Index is out of bounds");

}

void testRemove()
{
	List l7;
	l7.add("Cucumber");
	l7.add("Tomato");
	l7.add("Celery");

	//to remove the element from index 2
	l7.remove(2);
	assert(l7.toString() == "[Cucumber, Tomato]");

	//Checks remove out of range
	//l7.remove(5);
	//assert(l7.toString() == "ERROR: Index is out of bounds");
}

void testIndexing()
{
	string test_string, test_string2;
	List l8;
	l8.add("Wow");
	l8.add("Yay");
	l8.add("Hooray");

	//to check standard index= "[Sing
	test_string = l8[2];
	assert(test_string == "Hooray");

	//to check indexing out of range
	// test_string2 = l8[22];
	// assert(test_string2 == "");


}

void testAssignment()
{
	List l9;
	List l10;

	l9.add("Yes");
	l9.add("No");
	l9.add("Maybe");

	l10.add("CS");
	l10.add("Math");
	l10.add("Physics");

	//to check assigment of lists of the same size
	l9 = l10;
	assert(l9.toString() == "[CS, Math, Physics]");

	//to check assignment of lists of different sizes
	List l10_1;
	l10_1.add("Sentence");
	l10_1.add("Paragraph");
	l9 = l10_1;
	assert(l9.toString() == "[Sentence, Paragraph]");
}

void testConcat() //Check this
{
	List l11;
  List l12;
	l11.add("Sleep");
	l11.add("Nap");
	l12.add("Word");
	l11+=l12;
	assert(l11.toString() == "[Sleep, Nap, Word]");
}


void testReverse()
{
	List l13;
	l13.add("Hi");
	l13.add("Hello");
	l13.reverse();
	l13.toString();
}

int main()
{
	testReverse();
	testDefaultConstructor();
	testCopyConstructor();
	testAdd();

	testSize();
	testInsert();
	testRemove();
	testIndexing();
	testAssignment();
	testConcat();

	cout << "All tests completed successfully." << endl;

	return 0;
}
