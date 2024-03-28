#include <fstream>
#include <iostream>

int main() {
  std::fstream db("example.csv", std::ios::in | std::ios::out);
  std::string second_string;
  {
    std::string temp;
    std::getline(db, temp);
  }
  std::getline(db, second_string);
  std::cout << second_string << '\n';
  std::string id;
}
