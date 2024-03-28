#include "CSVdb.h"
#include <iostream>

int main() {
  CSVdb db(5);
  std::vector<std::string> data{"jija", "kuk", "sus", "mem", "jij"};
  db.CreateRow(data);
  db.Display();

  std::cout << '\n';

  std::vector<std::string> data2{"pupa", "lupa", "zlp", "piska", "jopa"};
  db.CreateRow(data2);
  db.Display();

  std::cout << '\n';

  db.Reset();
  std::vector<std::string> data3{"Apple", "Google", "Microsoft", "Comma",
                                 "Evil Marttians"};
  db.CreateRow(data3);
  db.Display();
}
