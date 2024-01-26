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
#include <chrono>


/**
 * @brief Constructor Class
 *
 * creates a Set for depending on the type 
 *
 * @note No parameters are required.
 *
 * @returns none
 */
template <class T> 
Set<T>::Set	( void )
{
	list = new T[DEFAULT_LIST_CAPACITY];
	capacity = DEFAULT_LIST_CAPACITY;
	size = 0;
}
/**
 * @brief Deconstructor Class
 *
 * deletes the Set from existence
 *
 * @note No parameters are required
 *
 * @returns none
 */
template <class T> 
Set<T>::~Set(void)
{
	delete []list;
}

/**
 * @brief Set -> to_string
 *
 * turns the Set into a rable format
 *
 * @note No parameters are required
 *
 * @returns none
 */
template <class T> 
string Set<T>::to_string	( void ) const
{
    stringstream stream;
    if(size == 1) //Solves the case if Set only has 1 value
    {
        stream << list[0];
        return stream.str();
    }
    else
    {
        int i = 0;
        while(i < size-1) // copies until last index
        {
            stream << list[i] << " ";
            i++;
        }
        stream << list[size-1]; // adds last index
    } 
    
	return stream.str();
}

/**
 * @brief append
 *
 * adds a value into the set
 *
 * @param item has to be the type of the set
 *
 * @returns none
 */
template <class T> 
void Set<T>::append( const T &item	)
{
	if (size == capacity)
		reallocate();
	list[size] = item;
	size++;
}

/**
 * @brief reallocate
 *
 * increases the size of a linked list
 *
 * @note No parameters are required
 *
 * @returns none
 */
template <class T> 
void Set<T>::reallocate( void )
{
	capacity = capacity * 2;
	
	T* newptr;
	newptr = new T[capacity];
	
	for (int i = 0; i < size; i++)
		newptr[i] = list[i];
	
	delete list;
	list = newptr;
}

/**
 * @brief 
 *
 * 
 *
 * @note 
 *
 * @returns 
 */
template <class T> 
Set<T>::Set( const Set<T> &mylist )
{
	size = mylist.size;
	capacity = mylist.capacity;
	list = new T[mylist.capacity];
	
	for (int i = 0; i < size; i++)
		list[i] = mylist.list[i];
}

/**
 * @brief operator=
 *
 * 
 *
 * @param mylist 
 *
 * @returns 
 */
template <class T> 
Set<T> Set<T>::operator=( const Set<T> &mylist )
{
	delete []list;

	size = mylist.size;
	capacity = mylist.capacity;
	list = new T[mylist.capacity];
	
	for (int i = 0; i < size; i++)
		list[i] = mylist.list[i];

	return *this;
}

/**
 * @brief isEmpty
 *
 * checks the size of the set and returns T/F
 *
 * @note No parameters are required
 *
 * @returns boolean
 */
template <class T> 
bool Set<T>::empty( void ) const
{
	return (size == 0);
}

/**
 * @brief cardinality
 *
 * gives us the length of the set
 *
 * @note No parameters are required
 *
 * @returns int
 */
template <class T> 
int	Set<T>::cardinality( void ) const
{
	return size;
}

/**
 * @brief operator[]
 *
 * returns the value of the index within the set
 *
 * @param index integer 
 *
 * @returns value depending on type
 */
template <class T> 
T &	Set<T>::operator[]( int index )
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

/**
 * @brief clear
 *
 * clears everything from the set
 *
 * @note No parameters are required
 *
 * @returns none
 */
template <class T> 
void Set<T>::clear( void )
{
	size = 0;
	
	T* newptr;
	newptr = new T[capacity];

	delete []list;
	list = newptr;	
}

/**
 * @brief operator+
 *
 * Adds 2 sets together no like terms
 *
 * @param mylist your second Set
 *
 * @returns new Set
 */
template <class T>
Set<T> Set<T>::operator+( const Set<T> &mylist ) const
{
    Set<T> newlist;
    newlist.list = new T[capacity + mylist.capacity];
    newlist.capacity = capacity + mylist.capacity;

    // copying elements from the first Set
    for(int i = 0; i < size; i++) newlist.list[i] = list[i];

    newlist.size = size;

    // copying the second Set but checking for dupes
    for(int i = 0; i < mylist.size; i++)
    {
        bool isDupe = false;
        for(int j = 0; j < newlist.size; j++)
        {
            if(newlist.list[j] == mylist.list[i])
            {
                isDupe = true;
                break;
            }
        }
        if(!isDupe)
        {
            newlist.list[newlist.size] = mylist.list[i];
            newlist.size++;
        }
    }
    return newlist;
        
}

/**
 * @brief insert
 *
 * inserts value into Set based on index
 *
 * @param item data type depending on set
 * @param index integer 
 *
 * @returns none
 */
template <class T> 
void Set<T>::insert( const T &item, int index )
{
	if(contains(item)) remove(item);
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

/**
 * @brief insert
 *
 * inserts value into Set in descending order
 *
 * @param item data type depending on set
 *
 * @returns none
 */
template <class T> 
void Set<T>::insert( const T &item)
{
	insert(item, 0);



	
}

/**
 * @brief remove
 *
 * removes a value from the set
 *
 * @param index integer 
 *
 * @returns none
 */
template <class T> 
void Set<T>::remove(T value)
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (list[i] == value)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "ERROR: value not found in the set" << endl;
        return;
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




/**
 * @brief contains
 *
 * checks to see if a value is within a set
 *
 * @param item constant data type depending on set
 *
 * @returns boolean
 */
template <class T> 
bool Set<T>::contains( const T &item ) const
{
	bool ret = false; 
	
	T* newptr;
	newptr = new T[capacity];
	
	//cout << newptr << endl;
	
	for (int i = 0; i < size+1; i++)
	{
		newptr[i] = list[i];
		//cout << "IN LOOP ";
		//cout << newptr[i] << endl
		if (newptr[i]==item) 
		{
			return true; 
		}
	}

	return false;
}

/**
 * @brief operator==
 *
 * checks to see if 2 sets contain the same values
 *
 * @param myList const Set 
 *
 * @returns boolean
 */
template <class T> 
bool Set<T>::operator==( const Set<T> &mylist ) const
{

    if(size != mylist.size)
    {
        return false;
    }

    else
    {
        for(int i = 0; i<size; i++)
        {
            if(contains(mylist.list[i]) == false)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    
    }
    
    return false;
}

/**
 * @brief operator <=
 *
 * checks to see if a set is a subset of another set
 *
 * @param mylist const Set 
 *
 * @returns boolean
 */
template <class T>
bool Set<T>::operator<=( const Set<T> &mylist ) const
{
    int trueCounter = 0;
    if(size == 0) return false;
    for(int i = 0; i < size; i++)
    {
        //cout << "outer if statement index:" << list[i] << endl;
        for(int j = 0; j<mylist.size; j++)
        {
            if(list[i] == mylist.list[j]) trueCounter++;
        }
        
    }
    if(trueCounter == size) return true;
    return false;
}

template <class T>
Set<T>	Set<T>::operator&( const Set<T> &mylist ) const
{
	Set<T> newlist;
	newlist.list = new T[capacity + mylist.capacity];
	newlist.capacity = capacity + mylist.capacity;

	for(int i = 0; i<size; i++)
	{
		if(mylist.contains(list[i]))
		{
			newlist.append(list[i]);
		}
	}
	return newlist;
}


template <class T>
Set<T>	Set<T>::operator-( const Set<T> &mylist ) const
{
	Set<T> newlist;
	newlist.list = new T[capacity + mylist.capacity];
	newlist.capacity = capacity + mylist.capacity;

	for(int i = 0; i<size; i++)
	{
		if(!mylist.contains(list[i]))
		{
			newlist.append(list[i]);
		}
	}
	return newlist;
}

