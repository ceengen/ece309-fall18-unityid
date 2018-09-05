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
  public:
    class ListNode {
      public:
        Item item;
        ListNode *next;
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
      return head==NULL;
    }
};



ListNode *head;
ListNode *tail;

  public:
  StringList();
  ~StringList();
  void push_back(char string);
  Item get(int n);
  int length();
  Item remove_front();  
};

//constructor
StringList::StringList()
{
  head= NULL;
  tail= NULL;
}

//destructor
StringList::~StringList()
{
  while(!empty())
  {
    remove_front();
  }
}

//add a string to the tail of a list
void StringList::push_back(char string)
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
Item StringList::get(int n) 
    {
      ListNode * tmp = head;
      int i;
      while(i =0; i<=n; i++)
      {
        tmp = tmp->next;
      }
        return tmp;
    }

//get the number of items in the list
int StringList::length()
    {
      ListNode * tmp = head;
      int total=0;
      while(tmp != NULL)
      {
        tmp = tmp->next;
        total++;
      }
      return total;
    }

//remove the head of the list and return a copy of the data that was removed
Item StringList::remove_front()
    {
      if(!empty())
      {
        ListNode *copy = head;
        ListNode *tmp = head->getNext();
        delete head;
        head = tmp;
        if (tmp==NULL)
          tail=NULL;
        return copy;
      }
    }

