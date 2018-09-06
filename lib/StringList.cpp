#include <stdio.h>

class Item {
public:
  const char * str;
  Item(const char *as = "") 
  { 
    str = as; 
  }
};


class StringList {
private:

// StringListNode represents each 
// node of the StringList
  class StringListNode {
  public:
    Item item; // data in the StringList
    StringListNode *next;	
  public:
    StringListNode(Item a) 
    { 
      item = a; 
      next=NULL; // automatically serves as a StringList tail
    }
    StringListNode* getNext() 
    { 
      return next; 
    }
    void setNext(StringListNode *n) 
    { 
      next = n; 
    }
    Item getItem() //returns item value
    { 
      return item; 
    }
  };

  // add head and tail pointer
  StringListNode *head;
  StringListNode *tail;


 //declares functions 
public:
  StringList();
  ~StringList();
  void push_back(Item a);
  Item get(int n);
  int length();
  Item remove_front();    
  bool empty(); 
};

//constructor, initializes an empty list
StringList::StringList()
{
  // start with an empty StringList
  head = NULL;
  tail = NULL;
}

//destructor, deletes all nodes in list
StringList::~StringList()
{
	while(!empty())
  {
    remove_front();
  }
}

//add string to tail of list
void StringList::push_back(Item a)
{
  StringListNode *node = new StringListNode(a);
  if (head == NULL)
    {
      // StringList is empty
      head = node;
      tail = node;
    }
  else 
    {
      tail->setNext(node);
      tail = node;
    }
}

//return copy of n-th item in the list
Item StringList::get(int n)
{
	StringListNode * tmp = head;
	int i=0;
	Item val;
	while(i<=n)
	{
		tmp = tmp->next;
		val = tmp->getItem();
		i++;
	}
	return val;
}

//get number of items in the list
int StringList::length()
{
	StringListNode * tmp = head;
      int total=0;
      while(tmp != NULL)
      {
        tmp = tmp->next;
        total++;
      }
      return total;
}

//remove head of list and return copy of data removed
Item StringList::remove_front() 
{
  if (!empty()) // if StringList is not empty
    {
      Item copy = head->getItem(); // return copy
      StringListNode *tmp = head->getNext();
      delete head; // delete the node
      head = tmp;  // update the head
      if (tmp==NULL) // remove_frontd last element 
	tail = NULL;
      return copy;  //return value of item being deleted
    }
	// nothing in StringList
}

//checks if list is empty
bool StringList::empty()
{
  return head==NULL;
}


int main()
{
  return 0;
}
