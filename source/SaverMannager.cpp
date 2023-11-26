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

void SaverMannager::recordProveedor(Proveedor proveedor){
    try
    {
        std::ofstream file;
        file.open(path, std::ios_base::app);
        file<<proveedor.getUsername()<<","<<proveedor.getPassword()<<","<<proveedor.getLast_name()<<","<<proveedor.getName()<<","<<proveedor.getRole()<<","<<proveedor.getUbicacion_sucursal()<<","<<proveedor.getTelefono()<<std::endl;
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void SaverMannager::recordComprador(Comprador comprador){
    try
    {
        std::ofstream file;
        file.open(path, std::ios_base::app);
        file<<comprador.getUsername()<<","<<comprador.getPassword()<<","<<comprador.getLast_name()<<","<<comprador.getName()<<","<<comprador.getRole()<<","<<comprador.getDireccion()<<","<<comprador.getTel1()<<","<<comprador.getTel2()<<","<<std::to_string(comprador.getDinero())<<std::endl;
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void SaverMannager::recordProducto(Producto producto){
    try
    {
        std::ofstream file;
        file.open(path, std::ios_base::app);
        file<<producto.getId()<<","<<producto.getNombre()<<","<<producto.getCategoria()<<","<<producto.getMarca()<<","<<producto.getOtros_detalles()<<","<<producto.getStock()<<","<<producto.getPrecio()<<","<<producto.getUser_proveedor()<<std::endl;
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
void SaverMannager::recordCompra(std::string id_producto, std::string username_compra){
    try
    {
        std::ofstream file;
        file.open(path, std::ios_base::app);
        file<<username_compra<<","<<id_producto<<"\n";
        file.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
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
            inputFile.close();
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
                Comprador comprador_obj = Comprador(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], moneyValue);
                inputFile.close();
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

Producto SaverMannager::searchProducto(std:: string id_producto, std::string username, bool compra){
    std::ifstream inputFile;
    inputFile.open(path);
    std::string line = "";
    std::string data[6];
    std::string stock_s;
    std::string precio_s;
    while(getline(inputFile, line)){
        std::stringstream inputString(line);
        getline(inputString, data[0], ',');

        if (data[0] == id_producto){
            for(int i = 1;i<5;i++){
                getline(inputString, data[i], ',');
            }
            getline(inputString, stock_s, ',');
            getline(inputString, precio_s, ',');
            getline(inputString, data[5], '\n');
            if(data[5] != username && !compra){
                break;
            }
            try
            {
                int stock = std::stoi(stock_s);
                float precio = std::stof(precio_s);
                Producto producto = Producto(data[0], data[1], data[2], data[3], data[4], stock, precio, data[5]);
                inputFile.close();
                return producto;
            }
            catch(const std::exception& e)
            {
                std::cerr << "Ha ocurrido un error: " << e.what() << std::endl;
            }
        }
        line = "";
    }
    Producto producto = Producto();
    inputFile.close();
    return producto;
}

void SaverMannager::editProducto(Producto producto){
    std::ifstream inputFile;
    inputFile.open(path);
    std::ofstream outputFile("nuevo_archivo.csv");
    std::string value;
    std::string line = "";
    while(getline(inputFile, line)){
        std::stringstream inputString(line);
        getline(inputString, value, ',');
        if(value != producto.getId()){
            outputFile<<value<<",";
            for(int i = 0;i<6;i++){
                getline(inputString, value, ',');
                outputFile<<value<<",";
            }
            getline(inputString, value, ',');
            outputFile<<value<<"\n";
        }
    }
    std::string values[] = {producto.getId(), producto.getNombre(), producto.getCategoria(), producto.getMarca(), producto.getOtros_detalles()};
    // Escribir las columnas del objeto en el nuevo archivo
    for (int i = 0; i < 5; i++) {
        outputFile << values[i];
        outputFile << ",";
    }
    outputFile<<std::to_string(producto.getStock())<<",";
    outputFile<<std::to_string(producto.getPrecio())<<",";
    outputFile<<producto.getUser_proveedor()<<"\n";
    inputFile.close();
    outputFile.close();

    // Opcional: reemplazar el archivo original con el nuevo
    std::remove("Productos.csv");
    std::rename("nuevo_archivo.csv", "Productos.csv");
}

void SaverMannager::editComprador(Comprador comprador){
    std::ifstream inputFile;
    inputFile.open(path);
    std::ofstream outputFile("nuevo_archivo.csv");
    std::string value;
    std::string line = "";
    while(getline(inputFile, line)){
        std::stringstream inputString(line);
        getline(inputString, value, ',');
        if(value != comprador.getUsername()){
            outputFile<<value<<",";
            for(int i = 0;i<7;i++){
                getline(inputString, value, ',');
                outputFile<<value<<",";
            }
            getline(inputString, value, '\n');
            outputFile<<value<<"\n";
        }
    }
    std::string values[] = {comprador.getUsername(), comprador.getPassword(), comprador.getLast_name(), comprador.getName(), comprador.getRole(), comprador.getDireccion(), comprador.getTel1(), comprador.getTel2()};
    // Escribir las columnas del objeto en el nuevo archivo
    for (int i = 0; i < 8; i++) {
        outputFile << values[i];
        outputFile << ",";
    }
    outputFile<<std::to_string(comprador.getDinero())<<"\n";
    inputFile.close();
    outputFile.close();

    // Opcional: reemplazar el archivo original con el nuevo
    std::remove("Comprador.csv");
    std::rename("nuevo_archivo.csv", "Comprador.csv");
}

void SaverMannager::printProductsByProveedor(std:: string user_proveedor){
    std::ifstream inputFile;
    std::string strings_names []= {"Id:", "Nombre: ", "Categioria: ", "Marca: ", "Otros detalles: "};
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
            std::cout<<std::endl;
            for(int i = 0;i<5;i++){
                std::cout<<strings_names[i]<<data[i]<<std::endl;
            }
            std::cout<<"Stock: "<<stock_s<<std::endl;
            std::cout<<"Precio: "<<precio_s<<std::endl<<std::endl;
        }
    }
    inputFile.close();
}

std::vector<std::string> SaverMannager::printProductsByCategoria(std::string categoria){
    std::ifstream inputFile;
    std::string strings_names []= {"Id:", "Nombre: ", "Categioria: ", "Marca: ", "Otros detalles: "};
    inputFile.open(path);
    std::string line = "";
    std::string data[5];
    std::string stock_s;
    std::string precio_s;
    std::vector<std::string> id_s;
    int stock;
    float precio;
    while(getline(inputFile, line)){
        std::stringstream inputString(line);
        for(int i = 0;i<5;i++){
            getline(inputString, data[i], ',');
        }
        if (data[2] == categoria){
            id_s.push_back(data[0]);
            getline(inputString, stock_s, ',');
            getline(inputString, precio_s, ',');
            precio = std::stof(precio_s);;
            std::cout<<std::endl;
            for(int i = 0;i<5;i++){
                std::cout<<strings_names[i]<<data[i]<<std::endl;
            }
            std::cout<<"Precio: "<<precio_s<<std::endl<<std::endl;
        }        
    }
    return id_s;
    inputFile.close();
}
void SaverMannager::printProductsByComprador(std::string comprador){
    std::ifstream inputFile;
    inputFile.open(path);
    std::string line = "";
    std::string data;
    std::cout<<"-----Historial de compra-----"<<std::endl;
    while(getline(inputFile, line)){
        std::stringstream inputString(line);
        getline(inputString, data, ',');
        ///std::cout<<"Info: "<<data<<","<<comprador<<std::endl;
        if(data == comprador){
            setPath("C:\\Users\\crdie\\Documents\\1Semestre_ITESM\\Pensamiento Computacional Orientado a Objetos\\Scripts\\situacionProblema\\source\\Productos.csv");
            getline(inputString, data, '\n');
            Producto producto_com = searchProducto(data, data, true);
            std::string strings_compra[] = {"Nombre: ", "Categoria: ", "Marca: ", "Otros detalles: ", "Precio: "};
            std::string strings_values[] = {producto_com.getNombre(), producto_com.getCategoria(), producto_com.getMarca(),producto_com.getOtros_detalles(), std::to_string(producto_com.getPrecio())};
            //Imprimir el producto
            std::cout<<std::endl;
            for(int i = 0;i<5;i++){
                std::cout<<strings_compra[i]<<strings_values[i]<<std::endl;
            }
        }
    }
    inputFile.close();
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
    inputFile.close();
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
            inputFile.close();
            return true;
        }
    }
    return false;
}