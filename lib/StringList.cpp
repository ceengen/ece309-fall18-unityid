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

class List
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
StringList(h= NULL, t= NULL)
{
  head= h;
  tail= t;
}

//destructor
~StringList()
{
  int length = length();
  int i;
  while(i=0; i<=length; i++)
  {
    remove_front()
  }
}

//add a string to the tail of a list
push_back(string)
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
get(n) 
    {
      while(int i =0; i<=n; i++)
      {
        return item;
      }
    }

//get the number of items in the list
int length()
    {
      int total=0;
      while()
      {
        total++;
      }
      return total;
    }

//remove the head of the list and return a copy of the data that was removed
remove_front()
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

