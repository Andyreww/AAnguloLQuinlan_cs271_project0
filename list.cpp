// list.cpp
// This is a (singly) linked list implementation of a List class.

#include <sstream>
#include "list.h"

Node::Node()
{
   value = "";
   next = NULL;
}

Node::Node(string initValue)
{
   value = initValue;
   next = NULL;
}

Node::Node(string initValue, Node *initNext)
{
   value = initValue;
   next = initNext;
}

List::List()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

List::List(const List& src)
{
	deepCopy(src);
}

List::~List()
{
	deallocate();
}

void List::add(string item)
{
	Node *newNode = new Node(item);

	if (head != NULL)  // list is not empty
	{
		tail->next = newNode;
	}
	else
	{
		head = newNode;
	}

	tail = newNode;
	count++;
}

int List::size() const
{
    return count;
}

int List::index(string item) const
{
    Node *current = head;
    int counter = 0;

    while ((current != NULL) && (current->value != item))
    {
        counter++;
        current = current->next;
    }
    if (current == NULL)
    {
      cout << "TEST2" << endl;
      throw ValueError();

    }
    else
        return counter;
}

void List::insert(int index, string item)
{
	if ((index < 0) || (index > count))
  {
    cout << "TEST" << endl;
    throw IndexError();

  }


	Node *newNode = new Node(item);
	if (index == 0)
	{
	  newNode->next = head;
		head = newNode;
	}
	else
	{
	  Node *prevNode = find(index - 1);
	  newNode->next = prevNode->next;
		prevNode->next = newNode;
	}

	if (index == count)
	    tail = newNode;

	count++;
}

void List::remove(int index)
{
	if ((index < 0) || (index >= count))
  {
    cout << "TEST3" << endl;
    throw IndexError();

  }


	Node *nodeToDelete;

	if (index == 0)
	{
		nodeToDelete = head;
		head = head->next;
		if (head == NULL)  // equivalently, if (count == 1)
		    tail = NULL;
	}
	else
	{
		Node *prevNode = find(index - 1);
		nodeToDelete = prevNode->next;
		prevNode->next = prevNode->next->next;
		if (index == count - 1)
		    tail = prevNode;
	}
	delete nodeToDelete;
	count--;
}

string List::toString() const
{
    if (head == NULL)
        return "[]";

    std::stringstream ss;
    ss << "[";

	Node *current = head;
	while (current->next != NULL)  // get all but the last item
	{
		ss << current->value << ", ";
		current = current->next;
	}
	ss << current->value << "]";  // last item followed by closing bracket

	return ss.str();
}

string& List::operator[](int index)
{
	if ((index < 0) || (index >= count))
  {
    cout << "TEST5";
    throw IndexError();
  }

	Node *node = find(index);
	return node->value;
}

List& List::operator=(const List& src)
{
    if (this != &src)
    {
	    deallocate();
	    deepCopy(src);
	}

	return *this;
}

List& List::operator+=(const List& src)
{
    Node *current = src.head;
    while (current != NULL)
    {
        add(current->value);
        current = current->next;
    }

    return *this;
}

void List::deepCopy(const List& src)
{
    if (src.head == NULL)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
	    Node *srcNode = src.head;
		head = new Node(srcNode->value);

		tail = head;
		srcNode = srcNode->next;
	    while (srcNode != NULL)
	    {
		    tail->next = new Node(srcNode->value);
		    tail = tail->next;
		    srcNode = srcNode->next;
	    }
	}
	count = src.count;
}

void List::deallocate()
{
	Node *nodeToDelete;
	Node *current = head;

	while (current != NULL)
	{
		nodeToDelete = current;
		current = current->next;
		delete nodeToDelete;
	}
}

// private method used by insert, [], remove
Node* List::find(int index)
{
	if ((index < 0) || (index >= count))
  {
    cout << "TEST6" << endl;
    throw IndexError();
  }

	Node *current = head;
	for (int i = 0; i < index; i++)
		current = current->next;

	return current;
}

std::ostream& operator<<(std::ostream& os, const List& list)
{
	os << list.toString();

	return os;
}


void List::insert(Node* front, int index, string item)
{
	if (index == 1) //insert after node you are on
	{
		Node * newNode = new Node(item); //our node to insert
	  Node *prevNode = find(index - 1); //identifies previous Node
		Node *nextNode = find(index); //identifies next Node


	  newNode->next = prevNode->next; //makes newNode connect to the correct next Node
		nextNode-> prev = newNode; //added in
		prevNode->next = newNode; //connects the previous node to NewNode
		newNode -> prev = prevNode; //added in
	}
	else if (index == 0)
	{
		Node * newNode1 = new Node(item); //our node to insert

		if(count == 0)
		{
      tail = newNode1;
			count++;
		}
		else
		{
      head->prev = newNode1;
			count ++;
   	}
		newNode1->next = head;
		head = newNode1;

	}
	else
	{
		index --;
		insert(front -> next, index, item);
	}
}

// // version of insert that calls the private recursive insert
// void List::insert(int index, string item)
// {
//  	if ((index < 0) || (index > count)) //to make sure not out of bounds
//  		throw IndexError();
//
//  	insert(head, index, item);
// }


// recursive reverse
void List::reverse(Node *front) //front == head
{
  if(!front)
  {
    cout << "List is empty" << endl;
    return;
  }
  else if(front->next == NULL)
  {
    head = front;
    tail = front;
  }
  else
  {
    reverse(front->next);
    tail->next = front;
    front -> prev = tail;
    front -> next = NULL;
    tail = front;
  }
}


void List::reverse()
{
	reverse(head);
}
