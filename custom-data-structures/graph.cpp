#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
graphs:
-nodes: yhese are the states or vertex.
-edges: links between states in a graph.
  -undirected: two way edges.
  -directed: one way edges.

-representation:
  -adjacency matrix: 2d array where a[i][j]=1 if there is    an edge from i to j else a[i][j]=0.
  -adjacency list: array of list, where each a[i] is a       list of nodes x<i> that are reachable from i.

-searching:
  -depth first search:
  -breath first search:

-pre-order: first time when call comes on the node.
-in-order: when the call works inside the sebtree (in DFS 
 tree) of that node.
-post-order: after working on the subtree, call comes 
 back to the node. comes on the same node.

-degree of vertex:
  -indegree: no. of incoming edges.
  -outdegree: no. of outgoing edges.

-path between two vertices: all vertices in the path of 
 two given vertices.

-connected graph: each node has path from every other 
 node.
-disconnected graph: each node does not have path from 
 every other node.
-connected component: each connected graph in a 
 disconnected graph is called a connected component.

-cycle: path from a vertex to the same vertex in a graph 
 is known as cycle.
-cyclic: graph that contain cycle.
-acyclic: graph that do not contain cycle.

-tree: is a connected acyclic graph.

-DAG(directed acyclic graph): acyclic graph with all 
 directed edges.

-complete graph: graph in which each vertex is connected 
 to every other vertex by a directed edge. (no. of edges 
 here is nC2).

-weighed graph: graph with weighted edges.

*/

int main() {
  
  return 0;
}
