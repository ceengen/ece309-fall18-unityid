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
