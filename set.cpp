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

/**
 * @brief Default constructor for Set.
 *
 * Creates an empty Set object with capacity 10.
 *
 * @note No parameters are required for this constructor.
 *
 * @returns None.
 */
 template <class T> 
 Set<T>::Set(void){
    Set = new T[DEFAULT_SET_CAPACITY]; //Set Size is 10
    capacity = DEFAULT_SET_CAPACITY;
    size = 0;
}

/**
 * @brief Destructor for Set.
 *
 * Completely deletes the Set for existence.
 *
 * @note No parameters are required.
 *
 * @returns None.
 */
template <class T>
Set<T>::~Set(void){
    delete []Set;
}

/**
 * @brief Set --> toString
 *
 * converts the Set into a readable string
 * ex: {1, 2, 3, 4}
 *
 * @note No parameters are required.
 *
 * @returns string of the set.
 */
template <class T>
string Set<T>::toString(void) const{
    stringstream stream;

    for(int i = 0; i < size; i++){
        stream << Set[i] << ", ";
    }

    return "{" + stream.str() + "}";
}

/**
 * @brief appends values
 *
 * appends item of type T to the Set
 *
 * @param T item to be appended to the Set
 *
 * @returns none.
 */
template <class T>
void Set<T>::append(const T &item){
    if(size == capacity) reallocate();
    Set[size] = item;
    size++;
}

/**
 * @brief reallocates set
 *
 * creates new Set object of twice the capacity
 *
 * @note No parameters are required.
 *
 * @returns none.
 */
template <class T>
void Set<T>::reallocate(void){
    capacity *= 2;

    T* newptr;
    newptr = new T[capacity];

    for(int i = 0; i<size; i++) newptr[i] = Set[i];

    delete Set;

    Set = newptr;
}

/**
 * @brief Empty
 *
 * returns T/F if the Set is empty or not
 *
 * @note No parameters are required.
 *
 * @returns boolean.
 */
template <class T>
bool Set<T>::empty(void) const{
    return (size == 0);
}

/**
 * @brief Cardinality
 *
 * returns the length of a Set
 *
 * @note No parameters are required.
 *
 * @returns int.
 */
template <class T>
bool Set<T>::cardinality(void) const{
    return size;
}

/**
 * @brief clear
 *
 * Removes all items from the Set object
 *
 * @note No paramters are required.
 *
 * @returns none
 */
template <class T>
void Set<T>::clear(void){
    size = 0;
    T* newptr;
    newptr = new T[capacity];

    delete []Set;
    Set = newptr;
}

/**
 * @brief operator=
 *
 * creates new Set object which like terms
 *
 * @param mySet a Set object
 *
 * @returns Set object.
 */
template <class T>
Set<T> Set<T>::operator=(const Set<T> &mySet){
    delete []Set;

    size = mySet.size;
    capacity = mySet.capacity;
    Set = new T[mySet.capacity];

    for(int i = 0; i < size; i++) Set[i] = mySet.Set[i];

    return *this;
}

/**
 * @brief operator+
 *
 * adds 2 sets together, doesn't contain duplicates, Plus = Union
 *
 * @param mySet a Set object
 *
 * @returns Set object.
 */
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

/**
 * @brief operator<=
 *
 * Logically idk
 *
 * @param mySet a Set object
 *
 * @returns boolean.
 */
template <class T>
bool Set<T>::operator<=(const Set<T> &mySet){
    // im stuck here
}




// LQ ADDED FUNCTIONS

//=========================================================================
// insert
// Parameters: item of type T to be inserted into list
//			int index, index where item is to be inserted
// Returns: none, but inserts new item into list at parameter index 
// Inserts item into list at parameter index, shifting all following items
// by one index
//=========================================================================
/*
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
*/

//=========================================================================
// remove
// Parameters: int index, index where item is to be inserted
// Returns: none, but removes item at parameter index 
// Removes item from list at parameter index, shrinks list size by 1
//=========================================================================
/*
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
*/

//=========================================================================
// contains
// Parameters:
// Returns:
//
//=========================================================================

//template <class T> 


//=========================================================================
// operator==
// Parameters:
// Returns:
//
//=========================================================================

//template <class T> 


//=========================================================================
// operator<=
// Parameters:
// Returns:
//
//=========================================================================

//template <class T> 


//=========================================================================
// operator&
// Parameters:
// Returns:
//
//=========================================================================

//template <class T> 


//=========================================================================
// operator-
// Parameters:
// Returns:
//
//=========================================================================

//template <class T> 












