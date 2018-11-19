#include <stdio.h>
#include <climits>

using Item = int;

class List {
private:
  // ListNode represents each
  // node of the list
  class ListNode {
  public:
    Item item; // data in the list
    ListNode *next;

  public:
    ListNode(Item a, ListNode *n = NULL) {
      item = a;
      next = n; // automatically serves as a list tail
    }
    ListNode *getNext() { return next; }
    void setNext(ListNode *n) { next = n; }
    Item &getItem() { return item; }
  };

  // add head and tail pointer
  ListNode *head;
  ListNode *tail;

public:
  class iterator {
  private:
    ListNode *node;

  public:
    iterator(ListNode *n = NULL) { node = n; }
    Item &getItem() { return node->getItem(); }
    void increment() { node = node->next; }
    bool end() { return node == NULL; }

    friend class List;
  };

public:
  List();
  List(const List &copy);

  void append(Item a);
  bool remove(Item &a);
  bool empty();

  iterator begin() { return iterator(head); }

  void removeAfter(iterator it); // pseudocode in zyBook 2.4
  void insertAfter(iterator it, Item item);
};



class Graph {
protected:
  int numNodes;

public:
  Graph(int n) : numNodes(n){};
  virtual void addEdge(int, int) = 0;
  virtual bool isAdjacent(int, int) const = 0;

  virtual List getAdjacencyList(int) const = 0;
  virtual int getWeight(int, int) const { return 1; }
  int getNumNodes() const { return numNodes; }
};

class SparseGraph : public Graph {
protected:
  class Node {
  public:
    List edge;
  };
  Node *nodes;

public:
  SparseGraph(int n);
  void addEdge(int, int) override;
  bool isAdjacent(int, int) const override;

  List getAdjacencyList(int node) const override { return nodes[node].edge; }
};

class DenseGraph : public Graph {
  bool *edges;

public:
  DenseGraph(int n);
  void addEdge(int, int) override;
  bool isAdjacent(int, int) const override;

  List getAdjacencyList(int node) const override {
    List ret;
    for (int i = 0; i < numNodes; i++) {
      if (isAdjacent(node, i)) {
        ret.append(i);
      }
    }
    return ret;
  }
};

class WeightedDenseGraph : public DenseGraph {
protected:
  int *weights;
  void addWeight(int from, int to, int weight);

private:
  void addEdge(int f, int t) override { DenseGraph::addEdge(f, t); }

public:
  WeightedDenseGraph(int n) : DenseGraph(n) {
    weights = new int[n * n];
    for (int i = 0; i < n * n; i++)
      weights[i] = 0;
  }

  void addEdge(int src, int dest, int weight);
  int getWeight(int src, int dest) const override {
    return weights[src * numNodes + dest];
  }
};

class MinHeap {
private:
  int heapArraySize; // size of the array
  int nextIndex;     // location of next free array entry
  int *heapArray;    // this is the maxheap
protected:
  void percolate_up(int);
  void percolate_down(int, int);

public:
  MinHeap(int size = 100) : heapArraySize(size) {
    heapArray = new int[size];
    for (int i = 0; i < size; i++)
      heapArray[i] = 0;
    nextIndex = 0;
  }
  
  int getItem(int index)
  {return heapArray[index];}
  
  void print() {
    for (int i = 0; i < nextIndex; i++) {
      printf("%d ", heapArray[i]);
    }
    printf("\n");
  }

  bool insert(int);
  bool remove(int &); // remove the max value
  bool empty();

private:
  MinHeap(int *array, int size, int length = 0)
      : heapArraySize(size), nextIndex(length), heapArray(array) {
    int m = nextIndex / 2 - 1; // last internal BTNode
    while (m >= 0) {
      percolate_down(m, length);
      m--;
    }
  }

public:
  static void sort(int *array, int size);
};

class node_helper {
public:
  node_helper() {
    distance = INT_MAX;
    pred = -1;
  }
  int distance;
  int pred;
  node_helper* ShortestPath(Graph &g, int startV);
};
