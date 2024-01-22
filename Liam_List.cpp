//=================================================
// Liam Quinlan
// October 2022
// List.cpp
// This file contains the class implementation for the 
// List class.
//=================================================

#include "List.h"
#include <iomanip>


//=========================================================================
// default constructor
// Parameters: none
// Returns:	none
// Creates an empty List object with capacity 10
//=========================================================================
template <class T> 
		List<T>::List	( void )
{
	list = new T[DEFAULT_LIST_CAPACITY];
	capacity = DEFAULT_LIST_CAPACITY;
	size = 0;
}


//=========================================================================
// destructor
// Parameters: none
// Returns:	none
// Deletes List object
//=========================================================================
template <class T> 
		List<T>::~List		( void )
{
	delete []list;
}


//=========================================================================
// .to_string
// Parameters: none
// Returns:	string
// Returns string so List object can be printed using cout <<
//=========================================================================

template <class T> 
string		List<T>::to_string	( void ) const
{
	stringstream stream;

	for (int i = 0; i < size; i++)
		stream << list[i] << " ";

	return stream.str();
}


//=========================================================================
// append
// Parameters: item of type T to be appended to list
// Returns: none, but appends item T to list
// Appends an item of type T to calling List object
//=========================================================================

template <class T> 
void		List<T>::append		( const T &item	)
{
	if (size == capacity)
		reallocate();
	list[size] = item;
	size++;
}

//=========================================================================
// copy constructor
// Parameters: mylist, a List object
// Returns: none, but creates new List object of the same contents of 
// parameter object
// Creates new List object with same contents as parameter object
//=========================================================================

template <class T> 
		List<T>::List		( const List<T> &mylist )
{
	size = mylist.size;
	capacity = mylist.capacity;
	list = new T[mylist.capacity];
	
	for (int i = 0; i < size; i++)
		list[i] = mylist.list[i];
}


//=========================================================================
// reallocate
// Parameters: none
// Returns: none
// creates new List object of twice the capacity of calling object 
//=========================================================================

template <class T> 
void		List<T>::reallocate		( void )
{
	capacity = capacity * 2;
	
	T* newptr;
	newptr = new T[capacity];
	
	for (int i = 0; i < size; i++)
		newptr[i] = list[i];
	
	delete list;
	list = newptr;
}


//=========================================================================
// operator=
// Parameters: mylist, a List object
// Returns: List object
// Creates new List object, with same contents as parameter List object
//=========================================================================

template <class T> 
List<T>		List<T>::operator=	( const List<T> &mylist )
{
	delete []list;

	size = mylist.size;
	capacity = mylist.capacity;
	list = new T[mylist.capacity];
	
	for (int i = 0; i < size; i++)
		list[i] = mylist.list[i];

	return *this;
}


//=========================================================================
// isEmpty
// Parameters: none
// Returns: true if list is empty, false otherwise
// Returns true if list is empty
//=========================================================================

template <class T> 
bool		List<T>::isEmpty		( void ) const
{
	return (size == 0);
}


//=========================================================================
// length
// Parameters: none
// Returns: size of list
// Returns length of calling List object
//=========================================================================

template <class T> 
int			List<T>::length		( void ) const
{
	return size;
}


//=========================================================================
// operator[]
// Parameters: int index, the index of the list which is to be returned
// Returns: T &, a pointer to the parameter index of the calling object
// Returns a pointer to the parameter index of the calling List object, 
// terminates program if index is out of range
// Note:
// parameter int index must be between 0 and the size of the index - 1
//=========================================================================

template <class T> 
T &			List<T>::operator[]	( int index )
{
	if (index < 0 || index > (size - 1))
	{
		cout << "error: index out of range\n";
		exit(0);
	}
		
	T* retptr;
	retptr = &list[index];
	return *retptr;
}


//=========================================================================
// clear
// Parameters: none
// Returns: none, but removes all items from calling list object
// Removes all items from calling list object
//=========================================================================

template <class T> 
void		List<T>::clear		( void )
{
	size = 0;
	
	T* newptr;
	newptr = new T[capacity];

	delete []list;
	list = newptr;	
}


//=========================================================================
// operator+
// Parameters: mylist, a List object
// Returns: new List object of parameter object concatenated onto calling 
// object
// Concatenates parameter object to calling object, returns new List object
//=========================================================================

template <class T> 
List<T>		List<T>::operator+	( const List<T> &mylist ) const
{
	List<T> newlist;
	newlist.list = new T[capacity + mylist.capacity];
	newlist.size = size + mylist.size;
	newlist.capacity = capacity + mylist.capacity;

	for (int i = 0; i < size; i++)
		newlist.list[i] = list[i];
	
	for (int i = (0); i < (mylist.size); i++)
		newlist.list[size + i] = mylist.list[i];
	
	return newlist;
}


//=========================================================================
// insert
// Parameters: item of type T to be inserted into list
//			int index, index where item is to be inserted
// Returns: none, but inserts new item into list at parameter index 
// Inserts item into list at parameter index, shifting all following items
// by one index
//=========================================================================

template <class T> 
void		List<T>::insert		( const T &item, int index )
{
	if (index < 0 || index > size)
	{
		cout << "error: index out of range\n";
		exit(0);
	}
	
	if (size == capacity)
		reallocate();

	size = size + 1;

	T* newptr;
	newptr = new T[capacity];

	for (int i = 0; i < index; i++)
		newptr[i] = list[i];

	newptr[index] = item;

	for (int i = index; i < (size - 1); i++)
		newptr[i + 1] = list[i];
	
	delete []list;
	list = newptr;
}


//=========================================================================
// remove
// Parameters: int index, index where item is to be inserted
// Returns: none, but removes item at parameter index 
// Removes item from list at parameter index, shrinks list size by 1
//=========================================================================

template <class T> 
void		List<T>::remove		( int index )
{
	if (index < 0 || index > size)
	{
		cout << "error: index out of range\n";
		exit(0);
	}

	size = size - 1;
	
	T* newptr;
	newptr = new T[capacity];
	
	for (int i = 0; i < index; i++)
		newptr[i] = list[i];

	for (int i = (index); i < (size); i++)
		newptr[i] = list[i + 1];
	
	delete []list;
	list = newptr;	
}







