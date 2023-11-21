//
// Created by asadbek on 23. 11. 21.
//

#ifndef BANK05_ACCOUNT_H
#define BANK05_ACCOUNT_H


class Account {
private:
    int m_accID;
    char * m_cusName;
protected:
    int m_balance;
public:
    Account(int ID, int balance, const char *cname);

    ~Account();
    int GetAccID() const;
    virtual void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;
    friend class AccountHandler;
};


#endif //BANK05_ACCOUNT_H
