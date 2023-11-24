#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string> 

class Producto{
    private:
        std::string id;
        std::string nombre;
        std::string categoria;
        std::string marca;
        std::string otros_detalles;
        int stock;
        float precio;
        std::string user_proveedor;
    
    public:
        Producto();
        Producto(std::string id, std:: string nombre, std:: string categoria, std:: string marca, std:: string otros_detalles, int stock, float precio, std::string user_proveedor);
        
        void setId(std:: string id);
        void setNombre(std:: string nombre);
        void setCategoria(std:: string categoria);
        void setMarca(std:: string marca);
        void setOtros_detalles(std:: string otros_detalles);
        void setStock(int stock);
        void setPrecio(float precio);

        std::string getId();
        std::string getNombre();
        std::string getCategoria();
        std::string getMarca();
        std::string getOtros_detalles();
        int getStock();
        float getPrecio();
        std::string getUser_proveedor();
};      



#endif