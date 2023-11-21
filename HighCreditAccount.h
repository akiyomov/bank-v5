//
// Created by asadbek on 23. 11. 21.
//

#ifndef BANK05_HIGHCREDITACCOUNT_H
#define BANK05_HIGHCREDITACCOUNT_H

#include "SavingAccount.h"

class HighCreditAccount : public SavingAccount{
protected:
    int m_rate = 7;
public:
    HighCreditAccount(int ID, int balance, const char *cname, int rate = 7 );
    void Deposit (int money) override;
};


#endif //BANK05_HIGHCREDITACCOUNT_H
