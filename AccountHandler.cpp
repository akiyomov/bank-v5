//
// Created by asadbek on 23. 11. 21.
//

#include "AccountHandler.h"
#include<iostream>
#include "SavingAccount.h"
#include "HighCreditAccount.h"

using namespace std;

void AccountHandler::ShowMenu() {
    cout << "-----Menu-----" << endl;
    cout << "1. Make Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Show All Accounts" << endl;
    cout << "5. Delete Account" << endl;
    cout << "6. Show Account Info" << endl;
    cout << "7. Exit" << endl;
    cout << "Select: ";
}

void AccountHandler::MakeAccount(){
    if (accNum >= MAX_ACC_NUM) {
        cout << "Account limit reached." << endl;
        return;
    }
    int type;
    cout << "[Select Account Type: ]" << std::endl;
    cout << "1. Saving Account\n2. High Credit Account" <<endl;
    cin >> type;

    switch (type) {
        case 1:
            MakeSavingAccount();
            break;
        case 2:
            MakeHighCreditAccount();
            break;
        default:
            std::cout << "Enter only 1 and 2!!!" << std::endl;
            break;
    }
}

void AccountHandler::DepositMoney() const{
    int money;
    int id;
    cout << "[Deposit]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Deposit amount: ";
    cin >> money;

    for(int i = 0; i< accNum; i++){
        if (accArr[i]->GetAccID() == id){
            accArr[i]->Deposit(money);
            cout << "Deposit successful" << endl << endl;
            return;
        }
    }
    cout << "Invalid account ID" << endl << endl;
}

void AccountHandler::WithdrawMoney() const {
    int money;
    int id;
    bool accountFound = false;

    cout << "[Withdraw]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Withdraw amount: ";
    cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (accArr[i]->GetAccID() == id) {
            int val = accArr[i]->Withdraw(money);
            accountFound = true;
            break;
        }
    }

    if (!accountFound) {
        cout << "Invalid account ID" << endl << endl;
    }
}

int AccountHandler::GetAccIdx(int id) const{
    for(int i = 0; i< accNum; i++){
        if(accArr[i]->GetAccID() == id){
            return i;
        }
    }
    return -1;
}

void AccountHandler::DeleteAccount(){
    int id;
    cout << "[Delete Account]" << endl;
    cout << "Account ID: ";
    cin >> id;

    int idx = GetAccIdx(id);
    if(idx == -1){
        cout << "Invalid account ID" << endl << endl;
        return;
    }

    delete accArr[idx];
    int i = idx;
    for(; i< accNum-1; i++){
        accArr[i] = accArr[i+1];
    }
    accNum--;
    cout << "Account deleted" << endl << endl;
}

void AccountHandler::ShowAccountInfo() const {
    int id;
    cout << "[Show Account Info]" << endl;
    cout << "Account ID: ";
    cin >> id;

    int idx = GetAccIdx(id);
    if(idx == -1){
        cout << "Invalid account ID" << endl << endl;
        return;
    }

    accArr[idx]->ShowAccInfo();
    cout << endl;
}

void AccountHandler::ShowAllAccInfo() const{
    for(int i = 0; i< accNum; i++){
        accArr[i]->ShowAccInfo();
    }
}

void AccountHandler::MakeSavingAccount() {
    int id, balance;
    char name[NAME_LEN];
    std::cout << "Enter id: " << std::endl;
    std::cin >> id;
    std::cout << "Enter name: ";
    std::cin>>name;
    std::cout << "Deposit balance: $";
    std::cin >> balance;

    SavingAccount *savingAcc;
    savingAcc = new SavingAccount(id, balance, name);
    accArr[accNum++] = savingAcc;
    std::cout << "Saving Account created " << std::endl;

}

void AccountHandler::MakeHighCreditAccount() {
    int id, balance, rate;
    char name[NAME_LEN];
    std::cout << "Enter id: " << std::endl;
    std::cin >> id;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Deposit balance: $";
    std::cin >> balance;
    std::cout << "Enter rate: ";
    std::cin >> rate;

    HighCreditAccount *highCreditAcc;

    highCreditAcc = new HighCreditAccount(id, balance, name, rate);

    accArr[accNum++] = highCreditAcc;
    std::cout << "High Credit Account created " << std::endl;

}
