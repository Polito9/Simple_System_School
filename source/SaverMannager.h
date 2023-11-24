#ifndef SAVERMANNAGER_H
#define SAVERMANNAGER_H
#include <string> 
#include <vector>
#include "Proveedor.h"
#include "Comprador.h"
#include "Producto.h"
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
        bool recordProducto(Producto producto);

        std::vector<std::string> getIds_productos();

        Proveedor searchProveedor(std::string provedor);
        Comprador searchComprador(std::string comprador);
        void printProductsByProveedor(std::string user_proveedor);
        bool validateCredentials(std::string username, std::string password, std::string path);
};

#endif