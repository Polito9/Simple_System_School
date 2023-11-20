#include <iostream>
#include "User.h"
#include <string> 
using namespace std;
int main() {
    string aa;
    User user = User("Juan", "Perez Sosa", "pass1234", "admin");
    user.hi();
    cout<<user.getName();
    cin>>aa;
    return 0;
}