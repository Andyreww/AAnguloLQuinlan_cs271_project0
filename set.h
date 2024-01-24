//========================================================
// Liam Quinlan, Andrew Angulo
// January 2024
// set.h
// This file contains the Set class declaration.  
//========================================================

#include <iostream>
#include <string>
using namespace std;

#ifndef SET_H
#define SET_H

#define DEFAULT_SET_CAPACITY 10

template <class T> 
class Set{
public:													// (need to create "contains", <= operator, & operator, and - operator)
	Set(void);											// KEEP (creates Set Object)
	Set(const Set<T> &myset);							// KEEP (copies the set)
	~Set(void);											// KEEP (Deletes the set)
	Set<T> operator=(const Set<T> &myset);				// KEEP  
	string toString(void) const;						// KEEP (returns set as a string {1, 2, 3})
	void append	(const T &item);						// KEEP (adds value into the set)
	T &	operator[](int index);
	void insert(const T &item, int index);				// KEEP (inserts element into index)
	void remove(int index);								// KEEP (removes element from set)
	Set<T> operator+(const Set<T> &myset) const;		// KEEP (Adds 2 sets together) !NO DUPLICATES
	int	cardinality(void) const;						// KEEP (returns the length of the set)
	bool empty(void) const;								// KEEP (returns T/F if set is empty)
	void clear(void);									// KEEP (removes all values in set)
	bool contains(void) const;							// KEEP (returns T/F if its in set)

	bool operator<=(const Set<T> &myset) const;         // How would this work logically --> s <= t from this???)

	friend ostream & operator<< ( ostream &os, Set<T> &myset )
	{
		for ( int i = 0; i < myset.size; i++ )
			os << myset.set[i] << " ";
		return os;	
	}

private:
	T	*Set;			// the pointer for the dynamic set
	int capacity;		// the size of the set
	int size;			// the number of items in the set

	void reallocate(void);
};


#include "Set.cpp"

#endif


