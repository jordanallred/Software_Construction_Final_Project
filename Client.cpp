#include "Client.h"
#include <iostream>
#include <fstream>

using namespace std;

vector <Client> Client::clientMembers;


void Client::createClient() {
    Client::read("clientinfo.txt");

    string nameIn, addressIn, employerIn, ssnIn;
    int incomeIn;

    cout << "\n---Create a new client client---\n";
    cout << "\tEnter the client's name: ";
    cin.ignore();
    getline(cin, nameIn);
    cout << "\tEnter the client's address: ";
    getline(cin, addressIn);
    cout << "\tEnter the client's social security number: ";
    getline(cin, ssnIn);
    cout << "\tEnter the client's employer: ";
    getline(cin, employerIn);
    cout << "\tEnter the client's income: ";
    cin >> incomeIn;

    Client newClient;
    newClient.name = nameIn;
    newClient.address = addressIn;
    newClient.ssn = ssnIn;
    newClient.employer = employerIn;
    newClient.income = incomeIn;

    if (clientMembers[0].name == "") {
        clientMembers[0] = newClient;
    }
    else {
        clientMembers.push_back(newClient);
    }

    Client::write("clientinfo.txt");
}

void Client::editClient() {
    Client::read("clientinfo.txt");

    string nameIn;
    Client *edit = nullptr;

    if (clientMembers[0].name == "") {
        cout << "There are currently no clients.";
        return;
    }

    else {
        cout << "\n---Edit an existing client---\n";
        do {
            cout << "\tEnter the client's name: ";
            cin.ignore();
            getline(cin, nameIn);
            if (!authenticate(nameIn)) {
                cout << "\t\tClient does not exist. Try again.\n";
            }
        } while (!authenticate(nameIn));

        for (auto &clientMember : clientMembers) {
            if (clientMember.name == nameIn) {
                edit = &clientMember;
            }
        }

        cout << "\n\tWhich field would you like to edit?\n"
                "\t\t1. Address\n"
                "\t\t2. Social Security Number\n"
                "\t\t3. Employer\n"
                "\t\t4. Income\n"
                "\n\tSelection: ";
        int input;
        cin >> input;
        switch (input) {
            case 1: {
                cout << "\n\tEnter the new address: ";
                cin.ignore();
                getline(cin, edit->address);
                break;
            }
            case 2: {
                cout << "\n\tEnter the new Social Security Number: ";
                cin.ignore();
                getline(cin, edit->ssn);
                break;
            }
            case 3: {
                cout << "\n\tEnter the new employer: ";
                cin.ignore();
                getline(cin, edit->employer);
                break;
            }
            case 4: {
                cout << "\n\tEnter the new income: ";
                cin.ignore();
                cin >> edit->income;
                break;
            }
            default:
                break;
        }
        Client::write("clientinfo.txt");
    }
}

bool Client::authenticate(string nameIn) {
    for (Client clientMember : clientMembers) {
        if (clientMember.name == nameIn) {
            return true;
        }
    }
    return false;
}

Client Client::getInfo(string nameIn) {
    for (Client clientMember : clientMembers) {
        if (clientMember.name == nameIn) {
            return clientMember;
        }
    }
    return Client();
}

void Client::read(string fileName) {
    ifstream file;
    file.open(fileName);

    while (!file.eof()) { //populating the vector of client objects
        Client add;
        getline(file, add.name, ',');
        getline(file, add.address, ',');
        getline(file, add.ssn, ',');
        getline(file, add.employer, ',');
        file >> add.income;
        string garbage;
        getline(file, garbage);
        clientMembers.push_back(add);
    }

    file.close();
}

void Client::write(string fileName) {
    ofstream file;
    file.open(fileName);

    for (int i = 0; i < clientMembers.size(); i++) {
        if (i > 0) {
            file << "\n";
        }
        file << clientMembers[i].name + ',';
        file << clientMembers[i].address + ',';
        file << clientMembers[i].ssn + ',';
        file << clientMembers[i].employer + ',';
        file << clientMembers[i].income;
    }
    file.close();
}
