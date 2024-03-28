#include "Clients.h"

Client::Client(std::string firstname, std::string last_name) {
  // id = GenerateID();
  name = firstname;
  surname = last_name;
}

Client::~Client() {
  if (address != nullptr) {
    delete address;
    address = nullptr;
  }
}

int Client::GetID() { return id; }
std::string Client::GetName() { return name; }
std::string Client::GetSurname() { return surname; }
Address Client::GetAddress() { return *address; }
bool Client::IsTrusted() { return trusted; }

void Client::AddAddress(std::string city, std::string street,
                        unsigned int house_number, unsigned int zip_code) {
  address = new Address;
  address->city = city;
  address->street = street;
  address->house_number = house_number;
  address->zip_code = zip_code;

  if (passport != 0) {
    trusted = true;
  }
}

void Client::AddPassport(unsigned int passport_number) {
  passport = passport_number;
  if (address != nullptr) {
    trusted = true;
  }
}

unsigned int Client::GetPassport() { return passport; }
