//========================================================
// Liam Quinlan, Andrew Angulo
// January 2024
// set.h
// This file contains the Set class declaration.  
//========================================================

#include <iostream>
#include <string>
using namespace std;

#ifndef LIST_H
#define LIST_H

#define DEFAULT_LIST_CAPACITY 10

template <class T> 
class Set
{
public:
			Set		( void );
			Set		( const Set<T> &mylist );
		   ~Set		( void );
Set<T>		operator=	( const Set<T> &mylist );
string		to_string	( void ) const;	
void		append		( const T &item	);
T &			operator[]	( int index );
void		insert		( const T &item, int index );
void		insert		( const T &item );
void		remove		( int index );
Set<T>		operator+	( const Set<T> &mylist ) const;
bool     	operator==  (const Set<T> &mylist ) const;
int			length		( void ) const;
bool		isEmpty		( void ) const;
void		clear		( void );
bool		contains	( const T &item	) const;
bool     	operator<=  (const Set<T> &mylist ) const;

friend ostream & operator<< ( ostream &os, Set<T> &mylist )
{
	for ( int i = 0; i < mylist.size; i++ )
		os << mylist.list[i] << " ";
	return os;	
}

private:
	T	*list;			// the pointer for the dynamic array
	int capacity;		// the size of the array
	int size;			// the number of items in the list

	void	reallocate	( void );
};

#include "set.cpp"

#endif


