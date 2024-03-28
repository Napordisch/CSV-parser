#include <fstream>
#include <vector>

#ifndef CSV_DB_H
#define CSV_DB_H

class CSVdb {
public:
  CSVdb(unsigned int columns,
        std::string filename); // columns — amount of columns in the CSV table
  CSVdb(unsigned int columns);
  ~CSVdb();
  void ReadRow(std::ifstream &the_file, unsigned int row);
  void Read(); // from file
  void Write();
  void Display();

  std::string GetItem(unsigned int row,
                      unsigned int column); // 0-based indexing
  void Reset();
  void CreateRow(std::vector<std::string> row_data);

private:
  std::string filename_;
  unsigned int columns_ = 0;
  unsigned int rows_ = 0;
  std::vector<std::string *> table_;
  void AddRow();
  void ClearLastEmptyRow(); // remove last empty row if exists
  void FillRow(unsigned int row, std::vector<std::string> row_data);
};

#endif
