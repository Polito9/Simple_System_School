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
        file<<proveedor.getUsername()<<","<<proveedor.getName()<<","<<proveedor.getLast_name()<<","<<proveedor.getPassword()<<","<<proveedor.getRole()<<","<<proveedor.getUbicacion_sucursal()<<","<<proveedor.getTelefono()<<std::endl;
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
        file<<comprador.getUsername()<<","<<comprador.getName()<<","<<comprador.getLast_name()<<","<<comprador.getPassword()<<","<<comprador.getRole()<<","<<comprador.getDireccion()<<","<<comprador.getTel1()<<","<<comprador.getTel2()<<","<<std::to_string(comprador.getDinero())<<std::endl;
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