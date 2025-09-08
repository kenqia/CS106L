/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <random>

std::string kYourName = "Ken Wia";

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(const std::string& filename) {
  std::ifstream fs(filename);
  if (!fs.is_open()) {
    std::cerr << "Failed to open file: " << filename << std::endl;
    exit(1);
  }
  std::set<std::string> applicant_set;
  std::string s;

  while(std::getline(fs, s)){
    if(!s.empty())
      applicant_set.insert(s);
  }

  return applicant_set;
}


std::string getinitials(const std::string& name){
  std::string result;
  bool flag = true;
  for(char c : name){
    if(flag){
      result += c;
      result += '.';
      flag = false;
    }else if(c == ' '){
      flag = true;
    }
  }
  return result;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(const std::string& name, std::set<std::string>& students) {
  std::string nameI = getinitials(name);
  std::queue<const std::string*> result;

  for(const auto &s : students){
    if(getinitials(s) == nameI){
      result.push(&s);
    }
  }
  return result;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  if(matches.empty())
    return "NO MATCHES FOUND.";
  
  std::mt19937 rng(std::random_device{}());
  std::uniform_int_distribution<size_t> dist(0, matches.size() - 1);
  size_t cnt = dist(rng);

  for( ; cnt > 0 ; --cnt){
    matches.pop();
  }

  return *matches.front();
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
