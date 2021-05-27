// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
BST<std::string>Tree;
  std::string word;
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return Tree;
  }
  while (!file.eof()) {
    char letter = file.get();
    if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')) {
      if (letter >= 'A' && letter <= 'Z')
        letter += char(32);
      word += letter;
    } else if (word != "") {
      Tree.add(word);
      word = "";
    }
  }
  file.close();
  return Tree;
}
