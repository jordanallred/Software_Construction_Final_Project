#include "Manager.h"

void Manager::addStaff() {
    string usernameIn, passwordIn, answer;
    bool adminIn = false;
    do {
        cout << "\n\tEnter the new staff member's username: ";
        cin >> usernameIn;
        if (usernameIn.empty()) {
            cout << "Please enter a valid username.\n";
        }
    } while (usernameIn.empty());

    do {
        cout << "\tEnter the new staff member's password: ";
        cin >> passwordIn;
        if (passwordIn.empty()) {
            cout << "Please enter a valid password.\n";
        }
    } while (passwordIn.empty());
    cout << "\tIs the new staff member an admin? (yes/no): ";
    cin >> answer;
    if (answer == "yes") {
        adminIn = true;
    }

    Staff newMember;
    newMember.username = usernameIn;
    newMember.password = passwordIn;
    newMember.admin = adminIn;

    staffMembers.push_back(newMember);
    Staff::write("staffinfo.txt");
}

void Manager::deleteStaff() {
    string usernameIn;
    bool deleted = false;
    do {
        cout << "\n\tEnter the username of the staff member to be deleted: ";
        cin >> usernameIn;
        if (!authenticate(usernameIn)) { // checking to see if staff member exists
            cout << "\t\tStaff member does not exist.\n";
        }
        if (usernameIn == "admin") {
            cout << "\t\tCannot delete system admin.\n";
        }
    } while (!authenticate(usernameIn));

    for (int i = 0; i < staffMembers.size(); i++) {
        if (usernameIn == staffMembers[i].username) {
            deleted = true;
        }
        if (deleted) {
            if (i < staffMembers.size() - 1) {
                staffMembers[i] = staffMembers[i + 1];
            }
            if (i == staffMembers.size() - 1) {
                staffMembers[i].username = "";
                staffMembers[i].password = "";
                staffMembers[i].admin = NULL;
                staffMembers.resize(staffMembers.size() - 1);
            }
        }
    }
    Staff::write("staffinfo.txt");
}

void Manager::displayStaff() {
    cout << "STAFF MEMBERS\n";
    for (int i = 0; i < staffMembers.size(); i++) {
        cout << i + 1 << ".\t";
        cout << "Username: " << staffMembers[i].username << "\n\t";
        if (staffMembers[i].admin) {
            cout << "Role: System Administrator\n\n";
        }
        else {
            cout << "Role: Branch Staff\n\n";
        }
    }
}