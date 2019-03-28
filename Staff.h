#include <iostream>
#include <vector>
#include "Client.h"

using namespace std;

#ifndef PROJECT_2_STAFF_H
#define PROJECT_2_STAFF_H


class Staff {
public:
    string username, password;
    bool admin;
    static bool authenticate(string usernameIn, string passwordIn);
    static bool authenticate(string usernameIn);
    static Staff getInfo( string   usernameIn);
    static vector<Staff> staffMembers;
    static void manage();
    void changePassword();
    static void read(string fileName);
    static void write(string fileName);
};


#endif //PROJECT_2_STAFF_H
