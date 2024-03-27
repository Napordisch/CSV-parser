#include "CSVdb.h"
#include <iostream>

CSVdb::CSVdb(unsigned int columns, std::string filename) {
  filename_ = filename;
  columns_ = columns;
  Read();
}
CSVdb::~CSVdb() {
  for (unsigned int i = 0; i < rows_; ++i) {
    delete[] table_[i];
  }
}

void CSVdb::ReadRow(std::ifstream &the_file, unsigned int row) {
  for (unsigned int i = 0; i < columns_ - 1; ++i) {
    std::getline(the_file, table_[row][i], ',');
  }
  std::getline(the_file, table_[row][columns_ - 1]);
}

void CSVdb::Read() {
  std::ifstream the_file(filename_);
  while (!the_file.eof()) {
    AddRow();
    ReadRow(the_file, rows_ - 1);
  }
  the_file.close();
}

void CSVdb::AddRow() {
  std::string *new_row = new std::string[columns_];
  table_.push_back(new_row);
  rows_++;
}

void CSVdb::Display() {
  for (unsigned int i = 0; i < rows_; ++i) {
    for (unsigned int j = 0; j < columns_; ++j) {
      std::cout << table_[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

std::string CSVdb::GetItem(unsigned int row, unsigned int column) {
  return table_[row][column];
}
