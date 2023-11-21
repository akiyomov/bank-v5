//
// Created by asadbek on 23. 11. 21.
//

#include "HighCreditAccount.h"
#include <iostream>

using namespace std;

HighCreditAccount::HighCreditAccount(int ID, int balance, const char* cname,int rate) : SavingAccount(ID, balance, cname) { }

void HighCreditAccount::Deposit(int money){
    if (money > 0) {
        m_balance += money + (money * m_rate / 100);
        cout << "Completed Successfully, added money: $" << money << " All balance:$ " << m_balance << endl;
    }
    else {
        cout << "Invalid amount" << endl;
    }
}

