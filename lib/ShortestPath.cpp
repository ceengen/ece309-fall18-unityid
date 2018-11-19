#include <stdio.h>
#include <climits>
#include "ShortestPath.h"


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
      if (heapArray[i] < min_val) {
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


node_helper *ShortestPath(Graph &g, int startV) {
   int numNodes = g.getNumNodes();
   node_helper *nodesH = new node_helper[numNodes];
  
  nodesH[startV].distance =0;
  MinHeap unvisited(numNodes);
  for(int i=0; i< numNodes; i++)
    unvisited.insert(i);
  
  while(!unvisited.empty()){
    int min_node = 0;
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
