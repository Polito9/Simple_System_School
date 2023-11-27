#include <iostream>
#include "Proveedor.h"
#include "Comprador.h"
#include "SaverMannager.h"
#include "Producto.h"
#include <string> 
#include <vector>
#include <map>
using namespace std;

int main() {
    string pathProveedor = "C:\\Users\\crdie\\Documents\\1Semestre_ITESM\\Pensamiento Computacional Orientado a Objetos\\Scripts\\situacionProblema\\source\\Proveedor.csv";
    string pathComprador = "C:\\Users\\crdie\\Documents\\1Semestre_ITESM\\Pensamiento Computacional Orientado a Objetos\\Scripts\\situacionProblema\\source\\Comprador.csv";
    string pathProducto = "C:\\Users\\crdie\\Documents\\1Semestre_ITESM\\Pensamiento Computacional Orientado a Objetos\\Scripts\\situacionProblema\\source\\Productos.csv";
    string pathCompra_Product = "C:\\Users\\crdie\\Documents\\1Semestre_ITESM\\Pensamiento Computacional Orientado a Objetos\\Scripts\\situacionProblema\\source\\Comprador-Productos.csv";
    string aux_exit;
    //Mapa para los path
    map<string, string> mapaPath;
    mapaPath["C"] = pathComprador;
    mapaPath["P"] = pathProveedor;
    
    //Mapa para las categorias
    map<string, string> mapCategorias;
    mapCategorias["ELEC"] = "Electronica";
    mapCategorias["MODA"] = "Moda";
    mapCategorias["HOGA"] = "Hogar y Cocina";
    mapCategorias["LIBR"] = "Libros y medios";
    mapCategorias["DEPO"] = "Deportes y Aire Libre";
    mapCategorias["HERR"] = "Herramientas y mejoras para el Hogar";
    mapCategorias["SALU"] = "Salud y Belleza";
    mapCategorias["JUGJ"] = "Juguetes y juegos";
    mapCategorias["AUTO"] = "Automotriz";
    mapCategorias["MASC"] = "Mascotas";
    mapCategorias["PAPE"] = "Papeleria";
    SaverMannager saver = SaverMannager(pathProveedor);
    //Designing the interaction with the user
    string opt = "";
    cout<<"-------Bienvenido al Sitema de Compras Amaxion-------"<<endl;
    while (true){
        cout<<"Ingresa el codigo de acuerdo a quien seas: "<<endl<<"C->Comprador"<<endl<<"P->Proveedor"<<endl;
        cin>>opt;
        if (mapaPath.find(opt) != mapaPath.end())
        {
            break;
        }
        else{
            cout<<"Codigo no valido, intentalo nuevamente"<<endl;
        }
    }
    
    //-------------LOGIN-----------------------------------------------------------
    string login_path = mapaPath[opt];
    //asking username and password
    string actual_user = "";
    string actual_pass = "";
    string user_opt = "";
    string interal_opt = "";
    while (true){
        cout<<"Ingresa tu usuario: ";
        cin>>actual_user;
        cout<<"Ingresa tu contrasenia: ";
        cin>>actual_pass;

        bool enter =  saver.validateCredentials(actual_user, actual_pass, login_path);
        if (enter){
            while (true){
                //MENUS
                cout<<endl<<"BIENVENIDO"<<endl;
                if (opt == "C"){ //Menú comprador
                    saver.setPath(pathComprador);
                    Comprador comprador = saver.searchComprador(actual_user);
                    while (true){
                        cout<<endl<<"----MENU COMPRADOR----"<<endl;
                        cout<<"(1) Comprar"<<endl;
                        cout<<"(2) Historial de compra"<<endl;
                        cout<<"(3) Actualizar dinero"<<endl;
                        cout<<"Selecciona un numero de acuerdo a la opcion a usar: "<<endl;
                        cin>>interal_opt;
                        cin.ignore();

                        if(interal_opt =="1"){//Comprar
                            string opt_cat = "";
                            while (true){
                                for (auto const &pair: mapCategorias) {
                                    cout <<pair.first << ": " << pair.second << "\n";
                                }
                                cout<<"Digita la abreviacion de la categoria a comprar: ";
                                cin>>opt_cat;
                                if (mapCategorias.find(opt_cat) != mapCategorias.end()){ //Se encuentra
                                    break;
                                }else{
                                    cout<<"No existe esa categoria, intentalo de nuevo"<<endl<<endl;
                                }
                            }
                            cout<<"Productos registrados de la categoria "<<mapCategorias[opt_cat]<<":"<<endl<<endl;
                            saver.setPath(pathProducto);
                            
                            vector<string> id_s_categoria = saver.printProductsByCategoria(opt_cat);
                            int length = id_s_categoria.size();
                            //Validando que el id ingresado exista en la categoria
                            bool pass = true;
                            while (pass){
                                cout<<"Ingresa el ID del producto a comprar: ";
                                cin>>opt_cat;
                                for(int i = 0;i<length;i++){
                                    //cout<<"info: "<<id_s_categoria[i]<<", "<<opt_cat<<endl;
                                    if (id_s_categoria[i] == opt_cat){
                                        pass = false;
                                    }
                                }
                                if(pass){
                                    cout<<"El id ingresado no es de la categoria escogida"<<endl;
                                }
                            }
                            //Buscar el producto en productos.csv
                            Producto producto_compra = saver.searchProducto(opt_cat, actual_user, true);
                            //Validar si tiene suficiente dinero
                            if(comprador.getDinero()>=producto_compra.getPrecio()){
                                if(producto_compra.getStock()>0){
                                    //Se resta el valor de dinero del comprador
                                    comprador.setDinero(comprador.getDinero()-producto_compra.getPrecio());
                                    //Se agregan los id a comprador-producto
                                    saver.setPath(pathCompra_Product);
                                    saver.recordCompra(opt_cat, actual_user);
                                    //Se actualiza el valor de dinero en comprador.csv
                                    saver.setPath(pathComprador);
                                    saver.editComprador(comprador);
                                    //Se actualiza el valor de stock en Productos.csv
                                    producto_compra.setStock(producto_compra.getStock()-1);
                                    saver.setPath(pathProducto);
                                    saver.editProducto(producto_compra);
                                    cout<<"Producto comprado!"<<endl;
                                }
                                else{
                                    cout<<"Ya no hay mas existencias de ese producto"<<endl;
                                }
                            }else{
                                cout<<"No cuentas con suficiente dinero para esta compra ):"<<endl;
                                cout<<"Tu saldo es de: "<<comprador.getDinero()<<endl;
                                cout<<"El producto cuesta: "<<producto_compra.getPrecio()<<endl;
                            }
                            break;
                        }else if(interal_opt == "2"){//Mostrar historial de compra
                            saver.setPath(pathCompra_Product);
                            saver.printProductsByComprador(actual_user);
                            break;
                        }else if(interal_opt =="3"){//Actualizar dinero
                            float dinero = 0.0f;
                            cout<<"Tu saldo es de: "<<comprador.getDinero()<<endl;
                            cout<<"Ingresa tu nuevo saldo: "<<endl;
                            cin>>dinero;
                            comprador.setDinero(dinero);
                            saver.setPath(pathComprador);
                            saver.editComprador(comprador);
                            break;
                        }else{
                            cout<<"No valido, intentalo de nuevo"<<endl;
                        }
                    }
                    
                }else if (opt == "P"){ // Menú de proveedor
                    saver.setPath(pathProveedor);
                    Proveedor proveedor = saver.searchProveedor(actual_user);
                    while (true){
                        cout<<endl<<"----MENU PROVEEDOR----"<<endl;
                        cout<<"(1) Registrar Producto"<<endl;
                        cout<<"(2) Editar producto"<<endl;
                        cout<<"(3) Ver lsita de mis productos"<<endl;
                        cout<<"(4) Mostrar siglas de categorias"<<endl;
                        cout<<"Selecciona un numero de acuerdo a la opcion a usar: ";
                        cin>>interal_opt;
                        cin.ignore();
                        if(interal_opt == "1"){
                            saver.setPath(pathProducto);
                            vector<string> id_s = saver.getIds_productos();
                            int length = id_s.size();
                            float precio;
                            int stock;
                            string producto_arr[7];
                            string string_values[]= {"Id: ", "Nombre: ", "Siglas de categoria: ", "Marca: ", "Otros detalles: ", "Stock: ", "Precio: "};
                            while (true){
                                cout<<"Presiona enter para continuar"<<endl;
                                cin.ignore();
                                cout<<"----REGISTRO DE NUEVO PRODUCTO----"<<endl;
                                //Validando el id repetido
                                bool continu = true;
                                while(continu){
                                    cout<<string_values[0];
                                    getline(cin, producto_arr[0]);
                                    for(int i = 0;i<length;i++){
                                        if(id_s.at(i) == producto_arr[0]){//Si se encuentra
                                            cout<<"Id existente, intenta otro diferente"<<endl;
                                            continu = true;
                                            break;
                                        }
                                        continu = false;
                                    }
                                }
                                
                                //Continuando con los demás elementos
                                for(int i = 1;i<7;i++){
                                    cout<<string_values[i];
                                    getline(cin, producto_arr[i]);
                                    if(i == 2){
                                        while(true){
                                            if (mapCategorias.find(producto_arr[i]) != mapCategorias.end()){ //Se encuentra
                                                break;
                                            }else{
                                                cout<<"Categoria no existente, intentalo de nuevo"<<endl;
                                                cout<<string_values[i];
                                                getline(cin, producto_arr[i]);
                                            }
                                        }
                                        
                                    }
                                }
                                try
                                {
                                    Producto producto = Producto(producto_arr[0], producto_arr[1], producto_arr[2], producto_arr[3], producto_arr[4], stoi(producto_arr[5]), stof(producto_arr[6]), actual_user);
                                    //Saving on the file
                                    saver.recordProducto(producto);
                                    cout<<"Producto guardado correctamente!";
                                }
                                catch(const std::exception& e)
                                {
                                    cout<<"Ingresaste algun valor incorrectamente"<<endl;
                                }
                                cout<<"Deseas registrar otro producto? (S/N): ";
                                cin>>interal_opt;

                                if (interal_opt != "S"){
                                    break;
                                }
                            }
                            break;
                        }else if (interal_opt == "2"){//Editar productos
                            //Preguntar id
                            string id_prod;
                            cout<<"Ingresa el Id del producto a editar: ";
                            cin>>id_prod;
                            saver.setPath(pathProducto);
                            //Buscar en productos.csv y devolver un objeto con las características
                            Producto producto = saver.searchProducto(id_prod, actual_user, false);
                            if (producto.getNombre() == "default"){
                                cout<<"No puedes acceder a ese producto"<<endl;
                            }
                            else{
                                string opt_editar;
                                string new_value;
                                //Elegir atributo a editar
                                while (true){
                                    cout<<"(1): Nombre"<<endl;
                                    cout<<"(2): Categoria"<<endl;
                                    cout<<"(3): Marca"<<endl;
                                    cout<<"(4): Otros detalles"<<endl;
                                    cout<<"(5): Stock"<<endl;
                                    cout<<"(6): Precio"<<endl;
                                    cout<<"Digita el numero de atributo a editar: ";
                                    cin>>opt_editar;
                                    //Editar el objeto en ifs
                                    if (opt_editar == "1"){
                                        cout<<"Digita el nuevo nombre: ";
                                        cin.ignore();
                                        getline(cin, new_value);
                                        producto.setNombre(new_value);
                                    }else if(opt_editar == "2"){//Arreglar bug
                                        while(true){
                                            cout<<"Digita la nueva categoria: ";
                                            cin>>new_value;
                                            cout<<"new: "<<new_value<<endl;
                                            if (mapCategorias.find(new_value) != mapCategorias.end()){ //Se encuentra
                                                break;
                                            }else{
                                                cout<<"Categoria no existente, intentalo de nuevo"<<endl;
                                            }
                                        }
                                        producto.setCategoria(new_value);
                                    }else if(opt_editar == "3"){
                                        cout<<"Digita la nueva marca: ";
                                        cin.ignore();
                                        getline(cin, new_value);
                                        producto.setMarca(new_value);
                                    }else if(opt_editar == "4"){
                                        cout<<"Digita los nuevos detalles: ";
                                        cin.ignore();
                                        getline(cin, new_value);
                                        producto.setOtros_detalles(new_value);
                                    }else if(opt_editar == "5"){
                                        cout<<"Digita el nuevo stock: ";
                                        cin.ignore();
                                        getline(cin, new_value);
                                        try
                                        {
                                            int stock = stoi(new_value);
                                            producto.setStock(stock);
                                        }
                                        catch(const std::exception& e)
                                        {
                                            cerr <<"Valor no valido"<<e.what() << '\n';
                                        }
                                    }else if(opt_editar == "6"){
                                        cout<<"Digita el nuevo precio: ";
                                        cin.ignore();
                                        getline(cin, new_value);
                                        try
                                        {
                                            float precio = stof(new_value);
                                            producto.setPrecio(precio);
                                        }
                                        catch(const std::exception& e)
                                        {
                                            cerr <<"Valor no valido"<<e.what() << '\n';
                                        }
                                    }else{
                                        cout<<"Codigo no valido, intentalo de nuevo"<<endl;
                                    }
                                    //Continuar editando?
                                    cout<<"Continuar editando? (S/N): ";
                                    cin>>opt_editar;
                                    if(opt_editar !="S"){
                                        break;
                                    }
                                }

                            saver.setPath(pathProducto);
                            saver.editProducto(producto);
                            }
                            break;
                        }else if (interal_opt == "3"){//Mostrar productos
                            saver.setPath(pathProducto);
                            saver.printProductsByProveedor(actual_user);
                            break;
                        }else if(interal_opt == "4"){
                            for (auto const &pair: mapCategorias) {
                                cout <<pair.first << "--> " << pair.second << "\n";
                            }
                            break;
                        }
                        else{
                            cout<<"No valido, intentalo de nuevo"<<endl;    
                        }
                    }
                }
                cout<<endl<<"Deseas realizar otra operacion? (S/N): ";
                cin>>user_opt;
                if (user_opt != "S"){
                    break;
                }
            }
        }else{
            cout<<endl<<"Datos incorrectos :("<<endl;
        }
        break;
    }
    cout<<"Gracias por usar Amaxion!"<<endl<<"Hasta luego!";
    
    cin>>aux_exit;//Para que no cierre el programa al mostrar el último mensaje
    return 0;
}