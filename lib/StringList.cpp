#include <stdio.h>

class Item
{
  public:
    const char * str;
    Item(const char *as = "")
    {
      str = as;
    }
};

class StringList
{
  private:
    Item item;
    ListNode *next;
  public:
    ListNode(Item a)
    {
      item = a;
      next=NULL;
    }
    ListNode* getNext()
    {
      return next;
    }
    Item getItem()
    {
      return item;
    }
    bool empty()
    {
      retrun head==NULL;
    }
};



ListNode *head;
ListNode *tail;


//constructor
StringList::StringList(h= NULL, t= NULL)
{
  head= h;
  tail= t;
}

//destructor
StringList::~StringList()
{
  int length = length();
  int i;
  while(i=0; i<=length; i++)
  {
    remove_front()
  }
}

//add a string to the tail of a list
void StringList::push_back(string)
{
  ListNode *node = new ListNode(string);
  if(head==NULL) 
  {
    head = node;
    tail = node;
  }
  else
  {
    tail->setNext(node);
    tail = node;
  }
}

//return a copy of the n-th item in the list
char StringList::get(n) 
    {
      while(int i =0; i<=n; i++)
      {
        return item;
      }
    }

//get the number of items in the list
int StringList::length()
    {
      int total=0;
      while(!empty())
      {
        
        total++;
      }
      return total;
    }

//remove the head of the list and return a copy of the data that was removed
bool StringList::remove_front()
    {
      if(!empty())
      {
        copy = head->getItem();
        ListNode *temp = head->getNext();
        delete head;
        head = tmp;
        if (tmp==NULL)
          tail=NULL;
        return copy;
      }
      return false;
    }

