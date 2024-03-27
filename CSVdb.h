#include <fstream>
#include <map>
#include <vector>

#ifndef CSV_DB_H
#define CSV_DB_H

class CSVdb {
public:
  CSVdb(unsigned int columns, std::string filename); // sets amount of columns
  ~CSVdb();
  void ReadRow(std::ifstream &the_file, unsigned int row);
  void Read();
  void Write();
  void Display();

  std::string GetItem(unsigned int row,
                      unsigned int column); // 0-based indexing

private:
  std::string filename_;
  unsigned int columns_ = 0;
  unsigned int rows_ = 0;
  std::vector<std::string *> table_;
  void AddRow();
  void ClearLastEmptyRow();
};

#endif
