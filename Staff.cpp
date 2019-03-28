#include "Staff.h"
#include "Account.h"
#include <fstream>

using namespace std;

vector <Staff> Staff::staffMembers;

bool Staff::authenticate(string usernameIn, string passwordIn) {
    for (Staff &staffMember : staffMembers) {
        if (usernameIn == staffMember.username && passwordIn == staffMember.password) {
            return true;
        }
    }
    return false;
}

bool Staff::authenticate(string usernameIn) {
    for (Staff &staffMember : staffMembers) {
        if (usernameIn == staffMember.username) {
            return true;
        }
    }
    return false;
}

Staff Staff::getInfo(string usernameIn) {
    for (Staff &staffMember : staffMembers) {
        if (usernameIn == staffMember.username) {
            return staffMember;
        }
    }
    return Staff();
}

void Staff::manage() {
    int input;
    do {
        cout << "\n---Manage clients and accounts---\n"
                "\tSelect one of the following options:\n"
                "\t1. Create a new client.\n"
                "\t2. Edit an existing client.\n"
                "\t3. Create a new account.\n"
                "\t4. Edit an existing account.\n"
                "\t5. Return to menu.\n"
                "\nSelection: ";
        cin >> input;
        switch (input) {
            case 1: {
                Client::createClient();
                break;
            }
            case 2: {
                Client::editClient();
                break;
            }
            case 3: {
                Account::createAccount();
                break;
            }
            case 4: {
                Account::editAccount();
                break;
            }
            case 5: {
                break;
            }
            default: {
                cout << "Invalid input. Try again.\n";
                break;
            }
        }
    } while (input != 5);
}

void Staff::changePassword() {
    string oldPassword, newPassword, confirmPassword;
    cout << "\n---Change password---";
    do {
        cout << "\n\tEnter current password: ";
        cin >> oldPassword;
        if (oldPassword != password) {
            cout << "\t\tIncorrect password. Try again.\n";
        }
    } while (oldPassword != password);

    do {
        cout << "\n\tEnter your new password: ";
        cin >> newPassword;
        cout << "\tConfirm your new password: ";
        cin >> confirmPassword;
        if (newPassword != confirmPassword) {
            cout << "The passwords do not match. Try again.";
        }
    } while (newPassword != confirmPassword);

    for (auto &staffMember : staffMembers) {
        if (staffMember.username == username) {
            staffMember.password = newPassword;
        }
    }
    Staff::write("staffinfo.txt");
}

void Staff::read(string fileName) {
    bool adminIn;
    ifstream file;
    file.open(fileName);

    while (!file.eof()) { //populating the vector of staff objects
        Staff add;
        getline(file, add.username, ',');
        getline(file, add.password, ',');
        file >> adminIn;
        if (adminIn == 1) {
            add.admin = true;
        }
        else if (adminIn == 0) {
            add.admin = false;
        }
        string garbage;
        getline(file, garbage);
        staffMembers.push_back(add);
    }

    file.close();
}

void Staff::write(string fileName) {
    ofstream file;
    file.open(fileName);

    for (int i = 0; i < staffMembers.size(); i++) {
        if (i > 0) {
            file << "\n";
        }
        file << staffMembers[i].username + ',';
        file << staffMembers[i].password + ',';
        if (staffMembers[i].admin) {
            file << "1";
        }
        else {
            file << "0";

        }
    }
    file.close();
}

