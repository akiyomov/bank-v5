//
// Created by asadbek on 23. 11. 21.
//

#include "SavingAccount.h"
#include "Account.h"
#include <iostream>

using namespace std;

SavingAccount::SavingAccount(int ID, int balance, const char *cname)
        : Account(ID, balance, cname) {}

void SavingAccount::Deposit(int money) {
    if (money > 0) {
        m_balance += money;
        cout << "Completed Successfully, added money: $" << money << " All balance:$ " << m_balance << std::endl;
    } else {
        std::cout << "Invalid amount" << std::endl;
    }
}