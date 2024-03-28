#ifndef ACCOUNTS_H
#define ACCOUNTS_H
#include <ctime>
#include <iostream>

class Account {
 // trustworthiness is an attribute of a client not an account
 protected:
  unsigned int id = 0;
  double balance = 0;

 public:
  unsigned int GetID();
  double GetAmountOfMoney();

  // make sure that amount arguments are positive
  virtual void Put(double amount) = 0;
  virtual void Withdraw(double amount) = 0;

  virtual ~Account() = default;
};

class DebitAccount : public Account {
 public:
  void Put(double amount) override;
  void Withdraw(double amount) override;
};

class DepositAccount : public Account {
 public:
  DepositAccount(time_t first_withdrawal_time);
  void Put(double amount) override;
  void Withdraw(double amount) override;

 private:
  time_t first_withdrawal_time_ = 0;
  void SetTime(time_t first_withdrawal_time);
};

class CreditAccount : public Account {
 public:

  CreditAccount(double charge);

  void Put(double amount) override;

  void Withdraw(double amount) override;

 private:
  double charge_ = 0; // percentes

  void Charge(double amount);
};
#endif