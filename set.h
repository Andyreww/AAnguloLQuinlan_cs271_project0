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
class Set
{
public:												// (need to create "contains", <= operator, & operator, and - operator)
			Set		( void );							// KEEP
			Set		( const Set<T> &myset );				// KEEP
		   ~Set		( void );							// KEEP
Set<T>		operator=	( const Set<T> &myset );				// KEEP (need to create s.contains(x) and s <= t from this???)
string		to_string	( void ) const;					// KEEP
void		append		( const T &item	);
T &			operator[]	( int index );
void		insert		( const T &item, int index );			// KEEP
void		remove		( int index );						// KEEP
Set<T>		operator+	( const Set<T> &myset ) const;		// KEEP
int			length		( void ) const;				// KEEP rename to s.cardinality()
bool		isEmpty		( void ) const;					// KEEP rename to s.empty()
void		clear		( void );

friend ostream & operator<< ( ostream &os, Set<T> &myset )
{
	for ( int i = 0; i < myset.size; i++ )
		os << myset.set[i] << " ";
	return os;	
}

private:
	T	*set;			// the pointer for the dynamic array
	int capacity;		// the size of the array
	int size;			// the number of items in the set

	void	reallocate	( void );
};


#include "Set.cpp"

#endif


