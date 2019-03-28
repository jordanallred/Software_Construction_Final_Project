#include "Account.h"
#include <iostream>
#include <fstream>

using namespace std;

vector <Account> Account::accountMembers;


bool Account::authenticate(string nameIn) {
    for (Account accountMember : accountMembers) {
        if (accountMember.user.name == nameIn) {
            return true;
        }
    }
    return false;
}

Account Account::getInfo(string nameIn) {
    for (Account accountMember : accountMembers) {
        if (accountMember.user.name == nameIn) {
            return accountMember;
        }
    }
    return Account();
}

void Account::createAccount() {
    Client::read("clientinfo.txt");
    Account::read("accountinfo.txt");

    string nameIn;
    Account accountIn;

    if (Client::clientMembers[0].name == "") {
        cout << "\nThere are currently no clients.\n";
        return;
    }

    else {
        cout << "\n---Create a new account---\n";

        do {
            cout << "\tEnter the client's name: ";
            cin.ignore();
            getline(cin, nameIn);
            if (!Client::authenticate(nameIn)) {
                cout << "\t\tClient does not exist. Try again.\n";
            }
        } while (!Client::authenticate(nameIn));

        accountIn.user = Client::getInfo(nameIn);
        accountIn.accountNumber = 4340000 + accountMembers.size();

        cout << "\tEnter the client's balance: ";
        cin >> accountIn.balance;

        if (accountMembers[0].user.name == "") {
            accountMembers[0] = accountIn;
        }
        else {
            accountMembers.push_back(accountIn);
        }

        Account::write("accountinfo.txt");
    }
}

void Account::editAccount() {
    Client::read("clientinfo.txt");
    Account::read("accountinfo.txt");

    string nameIn;
    Account *edit = nullptr;
    bool found = false;


    if (accountMembers[0].user.name == "") {
        cout << "\nThere are currently no accounts.\n";
        return;
    }

    else {
        cout << "\n---Edit an existing account---\n";
        do {
            cout << "\tEnter the client's name: ";
            cin.ignore();
            getline(cin, nameIn);
            if (!authenticate(nameIn)) {
                cout << "\t\tAccount does not exist. Try again.\n";
            }
        } while (!authenticate(nameIn));

        for (auto &accountMember : accountMembers) {
            if (accountMember.user.name == nameIn) {
                edit = &accountMember;
            }
        }
        int input, amount;
        cout << "\tWhat would you like to do?\n"
                "\t\t1. Deposit\n"
                "\t\t2. Withdraw\n"
                "\n\tSelection: ";
        cin >> input;
        switch (input) {
            case 1: {
                cout << "\n\tHow much would you like to deposit? ";
                cin >> amount;
                edit->balance += amount;
                break;
            }
            case 2: {
                cout << "\n\tHow much would you like to withdraw? ";
                cin >> amount;
                edit->balance -= amount;
                break;
            }
            default: {
                break;
            }
        }
        Account::write("accountinfo.txt");
    }
}

void Account::read(string fileName) {
    ifstream file;
    string name;
    file.open(fileName);

    while (!file.eof()) { //populating the vector of account objects
        Account add;
        getline(file, name, ',');
        add.user = Client::getInfo(name);
        file >> add.accountNumber;
        string garbage;
        getline(file, garbage, ',');
        file >> add.balance;
        getline(file, garbage);
        accountMembers.push_back(add);
    }

    file.close();
}

void Account::write(string fileName) {
    ofstream file;
    file.open(fileName);

    for (int i = 0; i < accountMembers.size(); i++) {
        if (i > 0) {
            file << "\n";
        }
        file << accountMembers[i].user.name + ',';
        file << accountMembers[i].accountNumber;
        file << ',';
        file << accountMembers[i].balance;
    }
    file.close();
}

