//
// Created by asadbek on 23. 11. 21.
//

#include "Account.h"
#include <cstring>
#include<iostream>

using namespace std;

Account::Account(int ID, int balance, const char *cname) {
    m_accID = ID;
    m_balance = balance;
    m_cusName = new char[strlen(cname)+1];
    strcpy(m_cusName, cname);
}
Account::~Account(){
    delete []m_cusName;
}

int Account::GetAccID() const {
    return m_accID;
}

void Account::Deposit(int money){
    if (money > 0) {
        m_balance += money;
        cout << "Completed Successfully, added money: $" << money << " All balance:$ " << m_balance << std::endl;
    }
    else {
        cout << "Invalid amount" << endl;
    }
}

int Account::Withdraw(int money) {
    if (m_balance < money){
        cout << "Insufficient balance" << endl;
        return -1;
    }
    m_balance -= money;
    return 1;
}

void Account::ShowAccInfo() const {
    cout << "Customer Name: " << m_cusName << endl;
    cout << "Account ID: " << m_accID << endl;
    cout << "Account Balance: " << m_balance << endl;
}

