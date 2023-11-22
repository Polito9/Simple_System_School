#ifndef SAVERMANNAGER_H
#define SAVERMANNAGER_H
#include <string> 
#include "Proveedor.h"
#include "Comprador.h"

class SaverMannager{
    private:
        std::string path;
    public:
        SaverMannager();
        SaverMannager(std::string path);

        void setPath(std::string path);
        std::string getPath();
        bool recordProveedor(Proveedor proveedor);
        bool recordComprador(Comprador comprador);
        //bool recordAdministrador(Administrador administrador);

        Proveedor searchProveedor(std::string provedor);
        Comprador searchComprador(std::string comprador);
        bool validateCredentials(std::string username, std::string password, std::string path);
};

#endif