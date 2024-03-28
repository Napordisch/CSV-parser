#include "Accounts.h"

unsigned int Account::GetID() { return id; }
double Account::GetAmountOfMoney() { return balance; }

// Debit
void DebitAccount::Put(double amount) { balance += amount; }

void DebitAccount::Withdraw(double amount) {
  if (amount > balance) {
    std::cout << "Debit account cannot have negative balance."
              << "\n";
    return;
  }
  balance -= amount;
}

// Deposit
void DepositAccount::SetTime(time_t first_withdrawal_time) {
  first_withdrawal_time_ = first_withdrawal_time;
}

DepositAccount::DepositAccount(time_t first_withdrawal_time) {
  SetTime(first_withdrawal_time);
}

void DepositAccount::Put(double amount) { balance += amount; }

void DepositAccount::Withdraw(double amount) {
  if (amount > balance) {
    std::cout << "Deposit account cannot have negative balance."
              << "\n";
    return;
  }
  if (time(NULL) >= first_withdrawal_time_) {
    balance -= amount;
  } else {
    std::cout << "First withdrawal time is not yet reached."
              << "\n";
  }
}

// Credit
CreditAccount::CreditAccount(double charge) { charge_ = charge; }

void CreditAccount::Put(double amount) {
  Charge(amount);
  balance += amount;
}

void CreditAccount::Withdraw(double amount) {
  Charge(amount);
  balance -= amount;
}

void CreditAccount::Charge(double amount) {
  if (balance < 0) {
    balance -= amount * (charge_ / 100);
  }
}
