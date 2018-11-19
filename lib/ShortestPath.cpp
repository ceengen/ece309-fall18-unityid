#include <stdio.h>

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


SparseGraph::SparseGraph(int n) : Graph(n) { nodes = new Node[numNodes]; }

void SparseGraph::addEdge(int v1, int v2) {
  nodes[v1].edge.append(v2);
  nodes[v2].edge.append(v1);
}

bool SparseGraph::isAdjacent(int v1, int v2) const {
  List::iterator it = nodes[v1].edge.begin();
  while (!it.end()) {
    if (it.getItem() == v2) {
      return true;
    }
    it.increment();
  }
  return false;
}

DenseGraph::DenseGraph(int n) : Graph(n) {
  edges = new bool[numNodes * numNodes];
  for (int i = 0; i < numNodes * numNodes; i++)
    edges[i] = false;
}
void DenseGraph::addEdge(int v1, int v2) {
  edges[v1 * numNodes + v2] = true;
  edges[v2 * numNodes + v1] = true;
}

bool DenseGraph::isAdjacent(int v1, int v2) const {
  return edges[v1 * numNodes + v2];
}

bool doesPathExist(Graph &g, int *path, int length) {
  for (int i = 0; i < length - 1; i++) {
    if (!g.isAdjacent(path[i], path[i + 1]))
      return false;
  }
  return true;
}

class MinHeap {
private:
  int *heapArray;    // this is the maxheap
  int heapArraySize; // size of the array
  int nextIndex;     // location of next free array entry

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
      : heapArray(array), heapArraySize(size), nextIndex(length) {
    int m = nextIndex / 2 - 1; // last internal BTNode
    while (m >= 0) {
      percolate_down(m, length);
      m--;
    }
  }

public:
  static void sort(int *array, int size);
};

void MinHeap::percolate_up(int index) {
  while (index > 0) {
    int parent_index = (index - 1) / 2;
    if (heapArray[index] < heapArray[parent_index]) {
      int tmp = heapArray[index];
      heapArray[index] = heapArray[parent_index];
      heapArray[parent_index] = tmp;
      index = parent_index;
    } else
      return;
  }
}

void MinHeap::percolate_down(int index, int size) {
  int child_index = index * 2 + 1;
  int val = heapArray[index];
  while (child_index < size) {
    int min_val = val;
    int min_index = -1;
    for (int i = child_index; i < child_index + 2 && i < size; i++) {
      if (heapArray[i] < max_val) {
        min_val = heapArray[i];
        min_index = i;
      }
    }
    if (min_val == val)
      return;
    heapArray[index] = min_val;
    heapArray[min_index] = val;
    index = min_index;
    child_index = index * 2 + 1;
  }
}

bool MinHeap::insert(int data) {
  if (nextIndex < heapArraySize) {
    heapArray[nextIndex] = data;
    percolate_up(nextIndex);
    nextIndex++;
    return true;
  } else {
    return false;
  }
}

bool MinHeap::remove(int &val) {
  if (nextIndex > 0) {
    val = heapArray[0];
    heapArray[0] = heapArray[nextIndex - 1];
    nextIndex -= 1;
    percolate_down(0, nextIndex);
    return true;
  }
  return false;
}

void MinHeap::sort(int *array, int size) {
  MinHeap heap(array, size, size);

  printf("\nheapify: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }

  for (int i = size - 1; i > 0; i--) {
    int ref;
    heap.remove(ref);
    array[i] = ref;
  }

  // return, and the array passed in is sorted
}

bool MinHeap::empty(){
  if(nextIndex == 0)
    return true;
  else
    return false;
}


class node_helper {
public:
  node_helper() {
    distance = INT_MAX;
    pred = -1;
  }
  int distance;
  int pred;
};

node_helper *ShortestPath(Graph &g, int startV) {
   int numNodes = g.getNumNodes();
   node_helper *nodesH = new node_helper[numNodes];
  
  nodesH[startV].distance =0;
  MinHeap unvisited(numNodes);
  for(int i=0; i< numNodes; i++)
    unvisited.insert(i);
  
  while(!unvisited.empty()){
    int min_node = unvisited.heapArray[0];
    int min_distance = nodesH[min_node].distance;
  
  int index =0;
  while(index < numNodes)
  {
    if(nodesH[index].distance < min_distance)
    {
      min_node = index;
      min_distance = nodesH[min_node].distance;
    }
    index++;
  }
  
  int currentV = min_node;
  unvisited.remove(min_node);
  
  List adjList = g.getAdjacenyList(currentV);
  for(int index2 =0; index2 < numNodes; index2++)
  {
    int toNode = index2;
    if(g.getWeight(currentV, toNode) + min_distance < nodesH[toNode].distance)
    {
      nodesH[toNode].distance = g.getWeight(currentV, toNode) + min_distance;
      nodesH[toNode].pred = currentV;
    }
  }
  }
  return nodesH;
}
