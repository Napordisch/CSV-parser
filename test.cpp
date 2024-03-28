#include "Clients.h"
#include <fstream>
#include <iostream>
#include <map>

int main() {
  std::fstream db("example.csv", std::ios::in);
  std::string fields[5];

  for (unsigned int i = 0; i < 5; ++i) {
    std::getline(db, fields[i], ',');
  }

  for (unsigned int i = 0; i < 5; ++i) {
    std::cout << fields[i] << '\n';
  }
}
