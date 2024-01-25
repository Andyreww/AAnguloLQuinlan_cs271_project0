//=================================================
// Liam Quinlan, Andrew Angulo
// January 2024
// set.cpp
// This file contains the class implementation for the 
// Set class.
//=================================================

#include "set.h"
#include <iomanip>
#include <iostream>
#include <sstream>

template <class T> 
		Set<T>::Set	( void )
{
	list = new T[DEFAULT_LIST_CAPACITY];
	capacity = DEFAULT_LIST_CAPACITY;
	size = 0;
}

template <class T> 
		Set<T>::~Set(void)
{
	delete []list;
}

template <class T> 
string		Set<T>::to_string	( void ) const
{
	stringstream stream;

	for (int i = 0; i < size; i++)
		stream << list[i] << ", ";

	return "{"+stream.str()+"}";
}

template <class T> 
void		Set<T>::append		( const T &item	)
{
	if (size == capacity)
		reallocate();
	list[size] = item;
	size++;
}

template <class T> 
void		Set<T>::reallocate		( void )
{
	capacity = capacity * 2;
	
	T* newptr;
	newptr = new T[capacity];
	
	for (int i = 0; i < size; i++)
		newptr[i] = list[i];
	
	delete list;
	list = newptr;
}


template <class T> 
		Set<T>::Set		( const Set<T> &mylist )
{
	size = mylist.size;
	capacity = mylist.capacity;
	list = new T[mylist.capacity];
	
	for (int i = 0; i < size; i++)
		list[i] = mylist.list[i];
}

template <class T> 
Set<T>		Set<T>::operator=	( const Set<T> &mylist )
{
	delete []list;

	size = mylist.size;
	capacity = mylist.capacity;
	list = new T[mylist.capacity];
	
	for (int i = 0; i < size; i++)
		list[i] = mylist.list[i];

	return *this;
}


template <class T> 
bool		Set<T>::isEmpty		( void ) const
{
	return (size == 0);
}


template <class T> 
int			Set<T>::length		( void ) const
{
	return size;
}

template <class T> 
T &			Set<T>::operator[]	( int index )
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

template <class T> 
void		Set<T>::clear		( void )
{
	size = 0;
	
	T* newptr;
	newptr = new T[capacity];

	delete []list;
	list = newptr;	
}

template <class T> 
Set<T>		Set<T>::operator+	( const Set<T> &mylist ) const
{
	Set<T> newlist;
	newlist.list = new T[capacity + mylist.capacity];
	newlist.size = size + mylist.size;
	newlist.capacity = capacity + mylist.capacity;

	for (int i = 0; i < size; i++)
		newlist.list[i] = list[i];
	
	for (int i = (0); i < (mylist.size); i++)
		newlist.list[size + i] = mylist.list[i];
	
	return newlist;
}

/*
template <class T>
Set<T> Set<T>::operator+(const Set<T> &mySet){
    Set<T> newSet;
    newSet.Set = new T[capacity + mySet.capacity];
    newSet.capacity = capacity + mySet.capacity;

    // copying elements from the first Set
    for(int i = 0; i < size; i++) newSet.Set[i] = Set[i];

    newSet.size = size;

    // copying the second Set but checking for dupes
    for(int i = 0; i < mySet.size; i++)
    {
        bool isDupe = false;
        for(int j = 0; j < newSet.size; j++)
        {
            if(newSet.Set[j] == mySet.Set[i])
            {
                isDupe = true;
                break;
            }
        }
        if(!isDupe)
        {
            newSet.Set[newSet.size] = mySet.Set[i];
            newSet.size++;
        }
    }
    return newSet;
        
}
*/

template <class T> 
void		Set<T>::insert		( const T &item, int index )
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


template <class T> 
void		Set<T>::remove		( int index )
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





