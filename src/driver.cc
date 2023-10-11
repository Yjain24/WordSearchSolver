#include <iostream>
#include <string>
#include <vector>

#include "WordSearchSolver.hpp"

int main() {
  std::vector<std::vector<char>> puzzle{{'o', 'e', 'a', 'o', 'h'},
                                        {'h', 'l', 'l', 'e', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'l', 't', 'e', 'u'},
                                        {'o', 'e', 't', 'o', 'f'}};
  WordSearchSolver wss(puzzle);
  std::cout << wss.FindWord("laa", CheckDirection::kLeftDiag);
}