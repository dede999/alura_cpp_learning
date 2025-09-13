#pragma once
#include <string>
#ifndef MAIN_HPP
#define MAIN_HPP

struct Account {
  std::string holder_name;
  std::string holder_soc_sec_number;
  float amount;
};

bool deposit(Account& acc, float value);
bool withdraw(Account& acc, float value);
bool transfer(Account& from, Account& to, float value);

#endif // !MAIN_HPP
#define MAIN_HPP

