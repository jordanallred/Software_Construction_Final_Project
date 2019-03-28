#include <iostream>
#include "Staff.h"
#include "Manager.h"

using namespace std;

// Jordan Allred (jra0027@auburn.edu)
// 4/12/2018
// I did not use any external sources for this assignment
// download the accompanying input file (staffinfo.txt, clientinfo.txt, accountinfo.txt)
// add files to working directory

int main() {
    string usernameIn, passwordIn;

    Staff::read("staffinfo.txt");

    cout << "---Login to Access the Teller Terminal System---";
    int input1, input2;
    do {
        cout << "\n\tUsername: ";
        cin >> usernameIn;
        cout << "\tPassword: ";
        cin >> passwordIn;
    } while (!Staff::authenticate(usernameIn, passwordIn)); //repeat until a valid username/password is entered

    Staff user = Staff::getInfo(usernameIn);
    if (user.admin) { //if the user is a system administrator launch the administrator window
        cout << "\n---Welcome to the Teller Terminal System---";
        do {
            cout << "\n\tSelect one of the following options:\n"
                    "\t1. Manage accounts and clients.\n"
                    "\t2. Manage branch staff.\n"
                    "\t3. Change password.\n"
                    "\t4. Cancel.\n"
                    "\nSelection: ";

            cin >> input1;

            switch (input1) {
                case 1: {
                    Staff::manage();
                    break;
                }
                case 2: {
                    do {
                        cout << "\n---Manage branch staff---\n"
                                "\tSelect one of the following options:\n"
                                "\t1. Add a new staff member.\n"
                                "\t2. Delete an existing staff member.\n"
                                "\t3. Display all existing staff members.\n"
                                "\t4. Return to menu.\n"
                                "\nSelection: ";
                        cin >> input2;
                        switch (input2) {
                            case 1: {
                                Manager::addStaff();
                                break;
                            }
                            case 2: {
                                Manager::deleteStaff();
                                break;
                            }
                            case 3: {
                                Manager::displayStaff();
                                break;
                            }
                            case 4: {
                                break;
                            }
                            default: {
                                cout << "Invalid input. Try again.\n";
                                break;
                            }
                        }
                    } while (input2 != 4);
                    break;
                }
                case 3: {
                    user.changePassword();
                    break;
                }
                case 4: {
                    exit(0);
                }
                default: {
                    cout << "Invalid input. Try again.\n";
                    break;
                }
            }
        } while (input1 != 4);
    }
    else { // if the user is a branch staff launch the branch staff window
        cout << "\n---Welcome to the Teller Terminal System---";
        do {
            cout << "\n\tSelect one of the following options:\n"
                    "\t1. Manage accounts and clients.\n"
                    "\t2. Change password.\n"
                    "\t3. Cancel.\n"
                    "\nSelection: ";

            cin >> input1;

            switch (input1) {
                case 1: {
                    Staff::manage();
                    break;
                }
                case 2: {
                    user.changePassword();
                    break;
                }
                case 3: {
                    exit(0);
                }

                default: {
                    cout << "Invalid input. Try again.\n";
                    break;
                }
            }

        } while (input1 != 3);
    }
    return 0;
}