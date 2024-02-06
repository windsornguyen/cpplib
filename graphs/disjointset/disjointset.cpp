/*--------------------------------------------------------------------*/
/* disjointset.cpp                                                    */
/* Brief: Implementation of the disjoint set union data structure     */
/* Author: Windsor Nguyen © 2024                                      */
/*--------------------------------------------------------------------*/

#include "disjointset.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

DisjointSet::DisjointSet(size_t n) : parent(n), rank(n, 0), count(n) {
  for (size_t i = 0; i < n; ++i) {
    parent[i] = i;
    rank[i] = 0;
  }
}

void DisjointSet::validate(size_t x) const {
  size_t n = parent.size();
  if (x < 0 || x >= n) {
    throw std::out_of_range("index " + std::to_string(x) +
                            " is not between 0 and " + std::to_string(n - 1));
  }
}

size_t DisjointSet::get_count() const {
  return count;
}

size_t DisjointSet::find(size_t x) {
  validate(x);
  
  // recursive approach
  if (parent[x] != x)  // path compression
    parent[x] = find(parent[x]);

  return parent[x];

  // iterative approach
  // int root = x;
  // while (root != parent[root])
  //   root = parent[root];

  // while (x != root) {  // path compression
  //   int newParent = parent[x];
  //   parent[x] = root;
  //   x = newParent;
  // }
  // return parent[root]
}

void DisjointSet::union_sets(size_t x, size_t y) {
  validate(x);
  validate(y);

  size_t rootX = find(x);
  size_t rootY = find(y);
  if (rootX == rootY)
    return;

  // make root of smaller rank point to root of larger rank
  if (rank[rootX] < rank[rootY])
    parent[rootX] = rootY;
  else if (rank[rootX] > rank[rootY])
    parent[rootY] = rootX;
  else {
    parent[rootY] = rootX;
    ++rank[rootX];
  }

  --count;
}
