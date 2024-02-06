/*--------------------------------------------------------------------*/
/* generate.cpp                                                       */
/* Brief: Generate pairings for testing                               */
/* Author: Windsor Nguyen © 2024                                      */
/*--------------------------------------------------------------------*/

#include <cstdlib>
#include <ctime>
#include <iostream>

void generate_pairings(int n, int max_val, unsigned int seed) {
  std::cout << n << std::endl;  // print the total number of pairings
  for (int i = 0; i < n; ++i) {
    // generate and print each pairing
    int a = rand_r(&seed) % (max_val + 1);
    int b = rand_r(&seed) % (max_val + 1);
    std::cout << a << " " << b << std::endl;
  }
}

int main() {
  // initialize random seed
  unsigned int seed = static_cast<unsigned int>(time(nullptr));
  int n, max_val;
  std::cin >> n >> max_val;
  // validate that max_val is at most n
  if (max_val >= n) {
    std::cerr << "Error: max_val cannot be greater than n." << std::endl;
    return EXIT_FAILURE;
  }
  generate_pairings(n, max_val, seed);
  return EXIT_SUCCESS;
}
