//constructor
StringList()

//destructor
~StringList()

//add a string to the tail of a list
push_back(string){
  ListNode *node = new ListNode(string);
  if(head==NULL) {
    head = node;
    tail = node;
  }
  else(
    tail->setNext(node);
    tail = node;
   }
}

//return a copy of the n-th item in the list
get(n)

//get the number of items in the list
length()

//remove the head of the list and return a copy of the data that was removed
remove_front()
