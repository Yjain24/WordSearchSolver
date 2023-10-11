// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : Student Name                    Environment : ubuntu:bionic               //
//  Date ......: 2021/02/10                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdexcept>

#include "CharPositions.hpp"
#include "WordLocation.hpp"
#include "WordSearchSolver.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("True == True", "") { REQUIRE(true == true); }

TEST_CASE("horizontal") {
    std::vector<std::vector<char>> puzzle{{'o', 'e', 'a', 'o', 'h'},
                                        {'h', 'l', 'l', 'e', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'l', 't', 'e', 'u'},
                                        {'o', 'e', 't', 'o', 'f'}};
    WordSearchSolver w(puzzle);

    WordLocation obj = w.FindWord("hll", CheckDirection::kHorizontal);
    REQUIRE(obj.char_positions[0].character == 'h');
    REQUIRE(obj.char_positions[1].character == 'l');
    REQUIRE(obj.char_positions[2].character == 'l');
    REQUIRE(obj.char_positions[0].row == 1);
    REQUIRE(obj.char_positions[0].col == 0);
    REQUIRE(obj.char_positions[1].row == 1);
    REQUIRE(obj.char_positions[1].col == 1);
    REQUIRE(obj.word == "hll");
}

TEST_CASE("vertical") {
    std::vector<std::vector<char>> puzzle{{'o', 'e', 'a', 'o', 'h'},
                                        {'h', 'l', 'l', 'e', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'l', 't', 'e', 'u'},
                                        {'o', 'e', 't', 'o', 'f'}};
    WordSearchSolver w(puzzle);

    WordLocation obj = w.FindWord("ohc", CheckDirection::kVertical);
    REQUIRE(obj.char_positions[0].character == 'o');
    REQUIRE(obj.char_positions[1].character == 'h');
    REQUIRE(obj.char_positions[2].character == 'c');
    REQUIRE(obj.char_positions[0].row == 0);
    REQUIRE(obj.char_positions[0].col == 0);
    REQUIRE(obj.char_positions[1].row == 1);
    REQUIRE(obj.char_positions[1].col == 0);
    REQUIRE(obj.word == "ohc");
}
TEST_CASE("right diagonal") {
    std::vector<std::vector<char>> puzzle{{'o', 'e', 'a', 'o', 'h'},
                                        {'h', 'l', 'l', 'e', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'l', 't', 'e', 'u'},
                                        {'o', 'e', 't', 'o', 'f'}};
    WordSearchSolver w(puzzle);

    WordLocation obj = w.FindWord("aem", CheckDirection::kRightDiag);
    REQUIRE(obj.char_positions[0].character == 'a');
    REQUIRE(obj.char_positions[1].character == 'e');
    REQUIRE(obj.char_positions[2].character == 'm');
    REQUIRE(obj.char_positions[0].row == 0);
    REQUIRE(obj.char_positions[0].col == 2);
    REQUIRE(obj.char_positions[1].row == 1);
    REQUIRE(obj.char_positions[1].col == 3);
    REQUIRE(obj.word == "aem");
}

TEST_CASE("left diagonal") {
    std::vector<std::vector<char>> puzzle{{'o', 'e', 'a', 'o', 'h'},
                                        {'h', 'l', 'l', 'e', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'l', 't', 'e', 'u'},
                                        {'o', 'e', 't', 'o', 'f'}};
    WordSearchSolver w(puzzle);

    WordLocation obj = w.FindWord("hel", CheckDirection::kLeftDiag);
    REQUIRE(obj.char_positions[0].character == 'h');
    REQUIRE(obj.char_positions[1].character == 'e');
    REQUIRE(obj.char_positions[2].character == 'l');
    REQUIRE(obj.char_positions[0].row == 0);
    REQUIRE(obj.char_positions[0].col == 4);
    REQUIRE(obj.char_positions[1].row == 1);
    REQUIRE(obj.char_positions[1].col == 3);
    REQUIRE(obj.word == "hel");
}

TEST_CASE("horizontal return empty") {
    std::vector<std::vector<char>> puzzle{{'o', 'e', 'a', 'o', 'h'},
                                        {'h', 'l', 'l', 'e', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'l', 't', 'e', 'u'},
                                        {'o', 'e', 't', 'o', 'f'}};
    WordSearchSolver w(puzzle);

    WordLocation obj = w.FindWord("yash", CheckDirection::kHorizontal);
    REQUIRE(w.FindWord("yash").word.empty());
    REQUIRE(w.FindWord("yash", CheckDirection::kHorizontal).word.empty());
}

TEST_CASE("vertical return empty") {
    std::vector<std::vector<char>> puzzle{{'o', 'e', 'a', 'o', 'h'},
                                        {'h', 'l', 'l', 'e', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'l', 't', 'e', 'u'},
                                        {'o', 'e', 't', 'o', 'f'}};
    WordSearchSolver w(puzzle);

    WordLocation obj = w.FindWord("jain", CheckDirection::kVertical);
    REQUIRE(w.FindWord("jain").word.empty());
    REQUIRE(w.FindWord("jain", CheckDirection::kVertical).word.empty());
}

TEST_CASE("rightdiag return empty") {
    std::vector<std::vector<char>> puzzle{{'o', 'e', 'a', 'o', 'h'},
                                        {'h', 'l', 'l', 'e', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'l', 't', 'e', 'u'},
                                        {'o', 'e', 't', 'o', 'f'}};
    WordSearchSolver w(puzzle);

    WordLocation obj = w.FindWord("aaaa", CheckDirection::kRightDiag);
    REQUIRE(w.FindWord("aaaa").word.empty());
    REQUIRE(w.FindWord("aaaa", CheckDirection::kRightDiag).word.empty());
}

TEST_CASE("leftdiag return empty") {
    std::vector<std::vector<char>> puzzle{{'o', 'e', 'a', 'o', 'h'},
                                        {'h', 'l', 'l', 'e', 'o'},
                                        {'c', 'a', 'l', 'o', 'm'},
                                        {'a', 'l', 't', 'e', 'u'},
                                        {'o', 'e', 't', 'o', 'f'}};
    WordSearchSolver w(puzzle);

    WordLocation obj = w.FindWord("yeue", CheckDirection::kLeftDiag);
    REQUIRE(w.FindWord("yeue").word.empty());
    REQUIRE(w.FindWord("yeue", CheckDirection::kLeftDiag).word.empty());
}





/////////////////////////////////////////////////////////////////////////////////////////////

