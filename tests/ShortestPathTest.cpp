#include <stdio.h>
#include "ShortestPath.h"

int main() {

  SparseGraph g(14);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 3);

  g.addEdge(1, 4);
  g.addEdge(3, 5);
  g.addEdge(2, 6);
  g.addEdge(3, 6);
  g.addEdge(2, 7);
  g.addEdge(1, 8);
  g.addEdge(7, 8);
  g.addEdge(1, 9);
  g.addEdge(4, 10);
  g.addEdge(6, 11);
  g.addEdge(7, 12);
  g.addEdge(8, 13);

  /*  int path[3] = {0, 1, 9};
    if (doesPathExist(g, path, 3))
      printf("Exists!\n");*/

  WeightedDenseGraph wg(6);
  wg.addEdge(0, 1, 450);
  wg.addEdge(0, 3, 150);
  wg.addEdge(0, 2, 370);
  wg.addEdge(1, 3, 550);
  wg.addEdge(2, 4, 210);
  wg.addEdge(3, 4, 370);
  wg.addEdge(3, 5, 340);
  wg.addEdge(2, 5, 130);
  wg.addEdge(4, 5, 5);

  printf("\nwg DFS(0): ");
  DepthFirstSearch(wg, 0);
  printf("\n\n");

  node_helper *nodesH = ShortestPath(wg, 0);

  for (int j = 0; j < wg.getNumNodes(); j++) {
    printf("%d: dist=%d pred=%d \n", j, nodesH[j].distance, nodesH[j].pred);
  }

  return 0;
}
