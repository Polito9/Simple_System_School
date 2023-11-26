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
        void recordProveedor(Proveedor proveedor);
        void recordComprador(Comprador comprador);
        //bool recordAdministrador(Administrador administrador);
        void recordProducto(Producto producto);
        void recordCompra(std::string id_producto, std::string usarname_compra);
        

        std::vector<std::string> getIds_productos();
        Producto searchProducto(std::string id_producto, std::string user, bool compra);
        Proveedor searchProveedor(std::string provedor);
        Comprador searchComprador(std::string comprador);
        void editProducto(Producto producto);
        void editComprador(Comprador comprador);
        void printProductsByProveedor(std::string user_proveedor);
        std::vector<std::string> printProductsByCategoria(std::string categoria);
        void printProductsByComprador(std::string comprador);
        bool validateCredentials(std::string username, std::string password, std::string path);
};

#endif