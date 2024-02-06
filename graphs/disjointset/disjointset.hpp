/*--------------------------------------------------------------------*/
/* disjointset.hpp                                                    */
/* Author: Windsor Nguyen © 2024                                      */
/*--------------------------------------------------------------------*/

#ifndef DISJOINT_SET_UNION_H
#define DISJOINT_SET_UNION_H

#include <stdexcept>
#include <string>
#include <vector>

class DisjointSet {
 private:
  std::vector<size_t> parent;       // parent[i] = parent of i
  std::vector<unsigned char> rank;  // rank[i] = rank of subtree rooted at i
  std::vector<size_t> size;         // size[i] = size of subtree rooted at i
  size_t count;                     // Number of components

  void validate(size_t x) const;

 public:
  DisjointSet(size_t n);
  size_t get_count() const;
  size_t find(size_t x);
  void union_sets(size_t x, size_t y);
};

#endif  // DISJOINT_SET_UNION_H
