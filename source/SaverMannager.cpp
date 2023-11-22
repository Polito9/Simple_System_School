#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "SaverMannager.h"
#include "Proveedor.h"
#include "Comprador.h"


SaverMannager::SaverMannager(){
    path = "C:\\Users\\crdie\\Documents\\1Semestre_ITESM\\Pensamiento Computacional Orientado a Objetos\\Scripts\\situacionProblema\\source\\data\\Comprador.csv";
}

SaverMannager::SaverMannager(std::string path){
    this->path = path;
}

bool SaverMannager::recordProveedor(Proveedor proveedor){
    try
    {
        std::ofstream file;
        file.open(path, std::ios_base::app);
        file<<proveedor.getUsername()<<","<<proveedor.getPassword()<<","<<proveedor.getLast_name()<<","<<proveedor.getName()<<","<<proveedor.getRole()<<","<<proveedor.getUbicacion_sucursal()<<","<<proveedor.getTelefono()<<std::endl;
        file.close();
        return true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

bool SaverMannager::recordComprador(Comprador comprador){
    try
    {
        std::ofstream file;
        file.open(path, std::ios_base::app);
        file<<comprador.getUsername()<<","<<comprador.getPassword()<<","<<comprador.getLast_name()<<","<<comprador.getName()<<","<<comprador.getRole()<<","<<comprador.getDireccion()<<","<<comprador.getTel1()<<","<<comprador.getTel2()<<","<<std::to_string(comprador.getDinero())<<std::endl;
        file.close();
        return true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

void SaverMannager::setPath(std::string path){
    this->path = path;
}

std::string SaverMannager::getPath(){
    return path;
}

Proveedor SaverMannager::searchProveedor(std:: string proveedor){
    std::ifstream inputFile;
    inputFile.open(path);
    std::string line = "";

    while(getline(inputFile, line)){

        std::string data[7];

        std::string tempString;

        std::stringstream inputString(line);

        getline(inputString, data[0], ',');

        if (data[0] == proveedor){
            getline(inputString, data[1], ',');
            getline(inputString, data[2], ',');
            getline(inputString, data[3], ',');
            getline(inputString, data[4], ',');
            getline(inputString, data[5], ',');
            getline(inputString, data[6], '\n');
            Proveedor proveedor_obj = Proveedor(data[0], data[4], data[2], data[3], data[1], data[5], data[6]);
            return proveedor_obj;
        }
        line = "";
    }
    inputFile.close();
}


Comprador SaverMannager::searchComprador(std:: string comprador){
    std::ifstream inputFile;
    inputFile.open(path);
    std::string line = "";

    while(getline(inputFile, line)){

        std::string data[9];
        std::string money;
        std::string tempString;

        std::stringstream inputString(line);

        getline(inputString, data[0], ',');

        if (data[0] == comprador){
            getline(inputString, data[1], ',');
            getline(inputString, data[2], ',');
            getline(inputString, data[3], ',');
            getline(inputString, data[4], ',');
            getline(inputString, data[5], ',');
            getline(inputString, data[6], ',');
            getline(inputString, data[7], ',');
            getline(inputString, money, '\n');

            try
            {
                float moneyValue = std::stof(money);
                Comprador comprador_obj = Comprador(data[0], data[4], data[2], data[3], data[1], data[5], data[6], data[7], moneyValue);
                return comprador_obj;
            }
            catch(const std::exception& e)
            {
                std::cerr << "Ha ocurrido un error: " << e.what() << std::endl;
            }
            
            
        }
        line = "";
    }
    inputFile.close();
}

bool SaverMannager::validateCredentials(std::string username, std::string password, std::string path){
    std::ifstream inputFile;
    inputFile.open(path);
    std::string line = "";
    std::string user;
    std::string pass;


    while(getline(inputFile, line)){

        std::stringstream inputString(line);


        getline(inputString, user, ',');
        getline(inputString, pass, ',');

        if(user == username && pass == password){
            return true;
        }
    }
    return false;
}