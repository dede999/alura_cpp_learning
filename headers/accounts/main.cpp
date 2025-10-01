#include "main.hpp"

bool deposit(Account& acc, float value) {
    if (value < 0) return false;

    acc.amount += value;
    return true;
}

bool withdraw(Account &acc, float value) {
    if (value < 0 || value >= acc.amount) return false;

    acc.amount -= value;
    return true;
}

bool transfer(Account &from, Account &to, float value) {
    if (value < 0) return false;

    if (!withdraw(from, value)) return false;

    return deposit(to, value);
}

