# Makefile for project 0
#************************


#CPPOPTIONS = -std=c++11 -g -Wall
#LDOPTIONS =
#LIB = 

#all: test_set

#test_set: test_set.o set.o
#	g++ $(LDOPTIONS) -o test_set test_set.o set.o $(LIB)

#test_set.o: test_set.cpp set.h
#	g++ $(CPPOPTIONS) -c test_set.cpp

#set.o: set.cpp set.h
#	g++ $(CPPOPTIONS) -c set.cpp
	
driver: setdriver.o
	g++ -o driver setdriver.o
	
setdriver.o: setdriver.cpp set.h set.cpp
	g++ -c setdriver.cpp
	

