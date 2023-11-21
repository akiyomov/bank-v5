//
// Created by asadbek on 23. 11. 21.
//

#ifndef BANK05_SAVINGACCOUNT_H
#define BANK05_SAVINGACCOUNT_H

#include "Account.h"

class SavingAccount: public Account {
public:
    SavingAccount(int ID, int balance, const char *cname);
    void Deposit(int money) override;
};

#endif //BANK05_SAVINGACCOUNT_H
