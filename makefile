# Makefile for project 0
#************************
	
test: test_set.o
	g++ -o test test_set.o
	
test_set.o: test_set.cpp set.h set.cpp
	g++ -c test_set.cpp
	

