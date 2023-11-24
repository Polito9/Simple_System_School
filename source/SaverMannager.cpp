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

bool SaverMannager::recordProducto(Producto producto){
    try
    {
        std::ofstream file;
        file.open(path, std::ios_base::app);
        file<<producto.getId()<<","<<producto.getNombre()<<","<<producto.getCategoria()<<","<<producto.getMarca()<<","<<producto.getOtros_detalles()<<","<<producto.getStock()<<","<<producto.getPrecio()<<","<<producto.getUser_proveedor()<<std::endl;
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
    std::string data[7];
    while(getline(inputFile, line)){
        std::stringstream inputString(line);
        getline(inputString, data[0], ',');
        if (data[0] == proveedor){
            for(int i = 0;i<6;i++){
                getline(inputString, data[i], ',');

            }
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
    std::string data[9];
    std::string money;
    while(getline(inputFile, line)){
        std::stringstream inputString(line);
        getline(inputString, data[0], ',');

        if (data[0] == comprador){

            for(int i = 1;i<8;i++){
                getline(inputString, data[i], ',');
            }
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

void SaverMannager::printProductsByProveedor(std:: string user_proveedor){
    std::ifstream inputFile;
    std::string strings_names []= {"Id:", "Nombre: ", "Categioria: ", "Marca", "Otros detalles: "};
    inputFile.open(path);
    std::string line = "";
    std::string data[5];
    std::string stock_s;
    std::string precio_s;
    int stock;
    float precio;
    std::string user_prov;
    while(getline(inputFile, line)){
        std::stringstream inputString(line);
        for(int i = 0;i<5;i++){
            getline(inputString, data[i], ',');
        }
        getline(inputString, stock_s, ',');
        getline(inputString, precio_s, ',');
        stock = std::stoi(stock_s);
        precio = std::stof(precio_s);
        getline(inputString, user_prov, '\n');

        if (user_prov == user_proveedor){
            for(int i = 0;i<5;i++){
                std::cout<<strings_names[i]<<data[i]<<std::endl;
            }
            std::cout<<"Stock: "<<stock_s<<std::endl;
            std::cout<<"Precio: "<<precio_s<<std::endl<<std::endl;
        }
    }
}
std::vector<std::string> SaverMannager::getIds_productos(){
    std::ifstream inputFile;
    inputFile.open(path);
    std::string id;
    std::string line = "";
    std::vector<std::string> id_s;

    while(getline(inputFile, line)){
        std::stringstream inputString(line);
        getline(inputString, id, ',');
        id_s.push_back(id);
    }
    return id_s;
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