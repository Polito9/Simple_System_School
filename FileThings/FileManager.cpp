#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

int main(){
    ifstream inputFile;
    inputFile.open("C:\\Users\\crdie\\Documents\\1Semestre_ITESM\\Pensamiento Computacional Orientado a Objetos\\Scripts\\situacionProblema\\FileThings\\data.csv");
    string line = "";

    while(getline(inputFile, line)){
        string d1;
        string d2;
        string d3;
        string d4;

        string tempString;

        stringstream inputString(line);

        getline(inputString, d1, ',');
        getline(inputString, d2, ',');
        getline(inputString, d3, ',');
        getline(inputString, d4, '\n');
        
        cout<<d1<<endl;
        cout<<d2<<endl;
        cout<<d3<<endl;
        cout<<d4<<endl;

        line = "";
    }
    inputFile.close();

    cout<<"Hi"<<endl;

    return 0;
}