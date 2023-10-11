#include "WordSearchSolver.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

bool WordSearchSolver::LocationInBounds(size_t row, size_t col) const {
  return ((row < puzzle_height_) && (col < puzzle_width_));
}

WordSearchSolver::WordSearchSolver(const std::vector<std::vector<char>>& puzzle) {
  puzzle_= puzzle;
  puzzle_height_=puzzle.size();
  puzzle_width_=puzzle[0].size();
}

WordLocation WordSearchSolver::FindWord(const std::string& word) {
  if (FindWord(word, CheckDirection::kHorizontal).word == word)
    return FindWord(word, CheckDirection::kHorizontal);
  if (FindWord(word, CheckDirection::kVertical).word == word)
    return FindWord(word, CheckDirection::kVertical);
  if (FindWord(word, CheckDirection::kLeftDiag).word == word)
    return FindWord(word, CheckDirection::kLeftDiag);
  if (FindWord(word, CheckDirection::kRightDiag).word == word)
    return FindWord(word, CheckDirection::kRightDiag);
  return WordLocation{};
}

WordLocation WordSearchSolver::FindWord(const std::string& word, CheckDirection direction) {
  WordLocation obj;
  switch(direction) {
    case CheckDirection::kHorizontal:
      obj = FindHorizontal(word);
      break;
    case CheckDirection::kVertical:
      obj = FindVertical(word);
      break;
    case CheckDirection::kRightDiag:
      obj = FindRightDiag(word);
      break;
    case CheckDirection::kLeftDiag:
      obj = FindLeftDiag(word);
      break;
  }
  return obj;
}

WordLocation WordSearchSolver::FindHorizontal(const std::string& word) {
  WordLocation obj;
  for (size_t row = 0; row < puzzle_height_; row++) {
    for (size_t col = 0; col < puzzle_width_ - word.size() + 1; col++) {
      bool found = true;
      for (unsigned int p = 0; p < word.size(); p++) {
        if (puzzle_[row][col + p] != word[p]) {
          found = false;
          break;
        }
      }
      if (found) {
        obj.word = word;
        for (unsigned int p = 0; p < word.size(); p++) {
          CharPositions cp={};
          cp.character = puzzle_[row][col + p];
          cp.row = row;
          cp.col = col + p;
          obj.char_positions.push_back(cp);
        }
        return obj;
      }
    }
  }
  return WordLocation{};
}

WordLocation WordSearchSolver::FindVertical(const std::string& word) {
  WordLocation obj;
  for (size_t row = 0; row < puzzle_height_- word.size() + 1; row++) {
    for (size_t col = 0; col < puzzle_width_; col++) {
      bool found = true;
      for (unsigned int p = 0; p < word.size(); p++) {
        if (puzzle_[row + p][col] != word[p]) {
          found = false;
          break;
        }
      }
      if (found) {
        obj.word = word;
        for (unsigned int p = 0; p < word.size(); p++) {
          CharPositions cp={};
          cp.character = puzzle_[row+p][col];
          cp.row = row + p;
          cp.col = col;
          obj.char_positions.push_back(cp);
        }
        return obj;
      }
    }
  }
  return WordLocation{};
}

WordLocation WordSearchSolver::FindRightDiag(const std::string& word) {
  WordLocation obj;
  for (size_t row = 0; row < puzzle_.size() - word.length() + 1; row++) {
      for (size_t col = 0; col < puzzle_[0].size() - word.length() + 1; col++) {
          bool found = true;
          std::vector<CharPositions> char_positions;
          for (unsigned int i = 0; i < word.length(); i++) {
              if (puzzle_[row + i][col + i] != word[i]) {
                  found = false;
                  break;
              } else {
                  char_positions.push_back(CharPositions{word[i], row + i, col + i});
              }
          }
          if (found) {
              obj.word = word;
              obj.char_positions = char_positions;
              return obj;
          }
          
          
      }
  }
        return WordLocation{};
}




WordLocation WordSearchSolver::FindLeftDiag(const std::string& word) {
  WordLocation obj;
  std::vector<CharPositions> char_positions;
  for (size_t row = 0; row < puzzle_height_; row++) {
    for (size_t col = 0; col < puzzle_width_; col++) {
        if (CheckLeftDiag(word, row, col)) {
          return GetLeftDiag(word, row, col);
        }
    }
}
  return WordLocation{};
}

bool WordSearchSolver::CheckLeftDiag(const std::string& word, unsigned int row, unsigned int col) {
  for (size_t i = 0; i < word.length(); i++) {
    if (!LocationInBounds(row + i, col - i) || puzzle_[row + i][col - i] != word.at(i)) {
      return false;
    }
  }
  return true;
}

WordLocation WordSearchSolver::GetLeftDiag(const std::string& word, unsigned int row, unsigned int col) {
  WordLocation ret;
  for (unsigned int i = 0; i < word.length(); i++) {
    CharPositions pos{word.at(i), row + i, col - i};
    ret.char_positions.push_back(pos);
  }
  ret.word = word;
  return ret;
}








// WordLocation WordSearchSolver::FindRightDiag(const std::string& word) {
//   WordLocation obj;
//   for (size_t row = 0; row < puzzle_height_ - word.length() + 1; row++) {
//     for (size_t col = 0; col < puzzle_width_ - word.length() + 1; col++) {
//       bool found = true;
//       bool found2=true;
//       for (unsigned int p = 0; p < word.size(); p++) {
//         if (puzzle_[row + p][col + p] != word[p]) {
//           found = false;
//           break;
//         }
//       }
//       if (found) {
//         obj.word = word;
//         for (unsigned int p = 0; p < word.size(); p++) {
//           CharPositions cp={};
//           cp.character = puzzle_[row + p][col + p];
//           cp.row = row + p;
//           cp.col = col+p;
//           obj.char_positions.push_back(cp);
//         }
//         return obj;
//       }
//       if(found2) {
//         obj.word = word;
//         for (unsigned int p = 0; p < word.size(); p++) {
//           CharPositions cp={};
//           cp.character = puzzle_[row + word.length() - 1 - p][col + word.length() - 1 - p];
//           cp.row = row + p;
//           cp.col = col+p;
//           obj.char_positions.push_back(cp);
//         }
//         return obj;
//       }
//     }
//   }
//   return WordLocation{};
// }

// WordLocation WordSearchSolver::FindLeftDiag(const std::string& word) {
//   WordLocation obj;
//   for (size_t row = 0; row < puzzle_height_ - word.length() + 1; row++) {
//     for (size_t col = word.length() - 1; col < puzzle_width_ - word.length() + 1; col++) {
//       bool found = true;
//       for (unsigned int p = 0; p < word.size(); p++) {
//         if (puzzle_[row + p][col - p] != word[p]) {
//           found = false;
//           break;
//         }
//       }
//       if (found) {
//         obj.word = word;
//         for (unsigned int p = 0; p < word.size(); p++) {
//           CharPositions cp={};
//           cp.character = puzzle_[row + p][col - p];
//           cp.row = row + p;
//           cp.col = col-p;
//           obj.char_positions.push_back(cp);
//         }
//         return obj;
//       }
//     }
//   }
//   return WordLocation{};
// }