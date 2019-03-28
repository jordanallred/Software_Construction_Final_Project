#include "Client.h"
#include <vector>

#ifndef PROJECT_2_ACCOUNT_H
#define PROJECT_2_ACCOUNT_H


class Account {
public:
    Client user;
    long unsigned int accountNumber;
    double balance;
    static vector <Account> accountMembers;
    static bool authenticate(string nameIn);
    static Account getInfo(string nameIn);
    static void createAccount();
    static void editAccount();
    static void read(string fileName);
    static void write(string fileName);
};


#endif //PROJECT_2_ACCOUNT_H
