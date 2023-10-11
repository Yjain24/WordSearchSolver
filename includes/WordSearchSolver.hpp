#ifndef WORDSEARCHSOLVER_HPP
#define WORDSEARCHSOLVER_HPP

#include <cstddef>
#include <string>
#include <vector>
#include <iostream>

#include "WordLocation.hpp"

enum class CheckDirection { kHorizontal, kVertical, kLeftDiag, kRightDiag };

class WordSearchSolver {
public:
  WordSearchSolver(const std::vector<std::vector<char>>& puzzle);
  WordLocation FindWord(const std::string& word);
  WordLocation FindWord(const std::string& word, CheckDirection direction);
  WordLocation FindHorizontal(const std::string& word);
  WordLocation FindVertical(const std::string& word);
  WordLocation FindRightDiag(const std::string& word);
  WordLocation FindLeftDiag(const std::string& word);

private:
  bool LocationInBounds(size_t row, size_t col) const;
  std::vector<std::vector<char>> puzzle_;
  size_t puzzle_height_;
  size_t puzzle_width_;
  bool CheckLeftDiag(const std::string& word, unsigned int row, unsigned int col);
  WordLocation GetLeftDiag(const std::string& word, unsigned int row, unsigned int col);
};

#endif