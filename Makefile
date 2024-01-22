# Makefile for Project 6
#****************************************************************

CPPOPTIONS = -std=c++11 -g -Wall
LDOPTIONS = 
LIB = 

all: test_list

test_list: test_list.o list.o
	g++ $(LDOPTIONS) -o test_list test_list.o list.o $(LIB)

test_list.o: test_list.cpp list.h
	g++ $(CPPOPTIONS) -c test_list.cpp

list.o: list.cpp list.h
	g++ $(CPPOPTIONS) -c list.cpp