#include <iostream>
#include "Comprador.h"
#include <string> 
using namespace std;
int main() {
    string aa;
    Comprador comprador = Comprador("JuanitoPerez","Juan", "Perez Sosa", "pass1234", "admin", "Pascual Rubio No. 512", "5545875222", "5598786532", 100.0f);
    comprador.hi();
    cout<<comprador.getName()<<endl;
    cout<<comprador.getDireccion()<<endl;
    cin>>aa;
    return 0;
}