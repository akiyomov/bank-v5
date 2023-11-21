//
// Created by asadbek on 23. 11. 21.
//
#include "Account.h"
#ifndef BANK05_ACCOUNTHANDLER_H
#define BANK05_ACCOUNTHANDLER_H

const int MAX_ACC_NUM = 100;
const int NAME_LEN = 30;

class AccountHandler{
private:
    Account* accArr[MAX_ACC_NUM]{};
    int accNum;
    int GetAccIdx(int id) const;
public:
    AccountHandler() : accNum(0) {
        for (int i = 0; i < MAX_ACC_NUM; ++i) {
            accArr[i] = nullptr;
        }
    }
    ~AccountHandler() {
        for (int i = 0; i < accNum; ++i) {
            delete accArr[i];
        }
    }
    int getAccNum() const { return accNum; }
    void ShowMenu() ;
    void MakeAccount();
    void MakeSavingAccount();
    void MakeHighCreditAccount();
    void DepositMoney() const;
    void WithdrawMoney() const;
    void ShowAccountInfo() const;
    void ShowAllAccInfo() const;
    void DeleteAccount();
};


#endif //BANK05_ACCOUNTHANDLER_H
