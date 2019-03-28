#include <string>
#include <vector>

using namespace std;

#ifndef PROJECT_2_CLIENT_H
#define PROJECT_2_CLIENT_H


class Client {
public:
    string name;
public:
    string  address, employer, ssn;
    int income;
    static vector <Client> clientMembers;
    static void createClient();
    static void editClient();
    static bool authenticate(string nameIn);
    static Client getInfo(string nameIn);
    static void read(string fileName);
    static void write(string fileName);
};


#endif //PROJECT_2_CLIENT_H
