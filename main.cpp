#include <iostream>
#include <cstring>
#include "Account.h"
#include "AccountHandler.h"
using namespace std;

enum class bank { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, DELETE_ACCOUNT, SHOW_ACCOUNT_INFO,EXIT };

int main() {
    AccountHandler manager;
    int choice;
    bool run = true;

    while(run){
        manager.ShowMenu();
        cin >> choice;
        cout << endl;

        switch(bank(choice)){
            case bank::MAKE:
                manager.MakeAccount();
                break;
            case bank::DEPOSIT:
                manager.DepositMoney();
                break;
            case bank::WITHDRAW:
                manager.WithdrawMoney();
                break;
            case bank::INQUIRE:
                manager.ShowAllAccInfo();
                break;
            case bank::DELETE_ACCOUNT:
                manager.DeleteAccount();
                break;
            case bank::SHOW_ACCOUNT_INFO:
                manager.ShowAccountInfo();
                break;
            case bank::EXIT:
                run = false;
                break;
            default:
                cout << "Illegal selection.." << endl << endl;
        }
    }
    return 0;
}
