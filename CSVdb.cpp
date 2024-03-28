#include "CSVdb.h"
#include <fstream>
#include <iostream>

// public:
CSVdb::CSVdb(unsigned int columns, std::string filename) {
  filename_ = filename;
  columns_ = columns;
  Read();
}

CSVdb::CSVdb(unsigned int columns) { columns_ = columns; }

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
  ClearLastEmptyRow();
}

void CSVdb::Display() {
  for (unsigned int i = 0; i < rows_; ++i) {
    for (unsigned int j = 0; j < columns_; ++j) {
      std::cout << "[";
      std::cout << table_[i][j] << "]" << '\t';
    }
    std::cout << '\n';
  }
}

std::string CSVdb::GetItem(unsigned int row, unsigned int column) {
  return table_[row][column];
}

void CSVdb::Reset() {
  table_.clear();
  rows_ = 0;
}

void CSVdb::CreateRow(std::vector<std::string> row_data) {
  AddRow();
  FillRow(rows_ - 1, row_data);
}

// private:
void CSVdb::AddRow() {
  std::string *new_row = new std::string[columns_];
  table_.push_back(new_row);
  rows_++;
}

void CSVdb::ClearLastEmptyRow() {
  bool empty = true;
  for (unsigned int i = 0; i < columns_; ++i) {
    if (table_[rows_ - 1][i] != "") {
      empty = false;
      return;
    }
  }
  if (empty) {
    delete[] table_[rows_ - 1];
    table_.pop_back();
    rows_--;
  }
}
void CSVdb::FillRow(unsigned int row, std::vector<std::string> row_data) {
  for (unsigned int i = 0; i < columns_; ++i) {
    table_[row][i] = row_data[i];
  }
}
