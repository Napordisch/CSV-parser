#ifndef CLIENTS_H
#define CLIENTS_H

#include <string>

struct Address {
  std::string city;
  std::string street;
  unsigned int house_number;
  unsigned int zip_code;
};

class Client {
public:
  Client(std::string firstname, std::string last_name);
  ~Client();
  int GetID();
  std::string GetName();
  std::string GetSurname();
  Address GetAddress();
  bool IsTrusted();
  void AddAddress(std::string city, std::string street,
                  unsigned int house_number, unsigned int zip_code);
  void AddPassport(unsigned int passport_number);
  unsigned int GetPassport();

protected:
  unsigned int id = 0;
  std::string name;
  std::string surname;
  Address *address = nullptr;
  unsigned int passport = 0;
  bool trusted = false;
};
#endif
