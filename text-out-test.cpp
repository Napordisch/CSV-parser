#include <fstream>
#include <ios>
#include <iostream>
#include <limits>
#include <string>

void ReplaceById(std::fstream &file, unsigned int int_id) {
  std::string id = std::to_string(int_id);
  std::string found_id;
  file.seekg(std::ios::beg);

  while (!file.eof()) {
    std::getline(file, found_id, ',');
    std::cout << found_id << '\n';
    if (found_id == id) {
      break;
    }
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  file.seekp(file.tellg());
  file.ignore();

  if (found_id != id) {
    return;
  }
  file << "lol\n";
}

int main() {
  std::fstream the_file;
  the_file.open("text-file.csv", std::ios::in | std::ios::out);
  unsigned int Apple_id = 1;
  unsigned int Orange_id = 2;
  ReplaceById(the_file, Orange_id);
}
