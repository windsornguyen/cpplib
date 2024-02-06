/*--------------------------------------------------------------------*/
/* testdisjointset.cpp                                                */
/* Brief: Testing disjoint set data structure                         */
/* Author: Windsor Nguyen © 2024                                      */
/*--------------------------------------------------------------------*/

#include <chrono>
#include <iostream>
#include "disjointset.hpp"

int main() {
  size_t n;
  std::cin >> n;
  DisjointSet dsu(n);

  auto start = std::chrono::high_resolution_clock::now();

  while (std::cin) {
    size_t x, y;
    std::cin >> x >> y;
    if (!std::cin)
      break;
    if (dsu.find(x) != dsu.find(y))
      dsu.union_sets(x, y);
  }

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration<double>(stop - start).count();
  std::cout << dsu.get_count() << " components" << std::endl;
  std::cout << "Time taken: " << duration << " seconds" << std::endl;
  return EXIT_SUCCESS;
}
