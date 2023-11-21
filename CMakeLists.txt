cmake_minimum_required(VERSION 3.26)
project(Bank05)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bank05 main.cpp
        Account.cpp
        AccountHandler.cpp
        AccountHandler.h
        SavingAccount.cpp
        SavingAccount.h
        HighCreditAccount.cpp
        HighCreditAccount.h)
