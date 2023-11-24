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
    string pathProveedor = "C:\\Users\\crdie\\Documents\\1Semestre_ITESM\\Pensamiento Computacional Orientado a Objetos\\Scripts\\situacionProblema\\source\\data\\Proveedor.csv";
    string pathComprador = "C:\\Users\\crdie\\Documents\\1Semestre_ITESM\\Pensamiento Computacional Orientado a Objetos\\Scripts\\situacionProblema\\source\\data\\Comprador.csv";
    string pathAdmin = "C:\\Users\\crdie\\Documents\\1Semestre_ITESM\\Pensamiento Computacional Orientado a Objetos\\Scripts\\situacionProblema\\source\\data\\Administrador.csv";
    string pathProducto = "C:\\Users\\crdie\\Documents\\1Semestre_ITESM\\Pensamiento Computacional Orientado a Objetos\\Scripts\\situacionProblema\\source\\data\\Productos.csv";
    string pathCompra_Product = "C:\\Users\\crdie\\Documents\\1Semestre_ITESM\\Pensamiento Computacional Orientado a Objetos\\Scripts\\situacionProblema\\source\\data\\Comprador-Productos.csv";
    string aa;
    map<string, string> mapaPath;
    mapaPath["A"] = pathAdmin;
    mapaPath["C"] = pathComprador;
    mapaPath["P"] = pathProveedor;
    SaverMannager saver = SaverMannager(pathProveedor);
    //Designing the interaction with the user
    string opt = "";
    cout<<"-------Bienvenido al Sitema de Compras Amaxion-------"<<endl;
    while (true){
        cout<<"Ingresa el codigo de acuerdo a quien seas: "<<endl<<"A->Administrador"<<endl<<"C->Comprador"<<endl<<"P->Proveedor"<<endl;
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

                    cout<<comprador.getDinero()<<endl;
                    cout<<comprador.getName()<<endl;
                    cout<<comprador.getPassword()<<endl;
                    
                    cout<<"----MENU----"<<endl;
                    cout<<"(1) Comprar"<<endl;
                    cout<<"(2) Historial de compra"<<endl;
                    cout<<"(3) Actualizar dinero"<<endl;
                    cout<<"Selecciona un numero de acuerdo a la opcion a usar: "<<endl;

                }else if (opt == "P"){ // Menú de proveedor
                    saver.setPath(pathProveedor);
                    Proveedor proveedor = saver.searchProveedor(actual_user);
                    
                    while (true){
                        cout<<endl<<"----MENU----"<<endl;
                        cout<<"(1) Registrar Producto"<<endl;
                        cout<<"(2) Editar producto"<<endl;
                        cout<<"(3) Ver lsita de mis productos"<<endl;
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
                            string string_values[]= {"Id: ", "Nombre: ", "Categoria: ", "Marca: ", "Otros detalles: ", "Stock: ", "Precio: "};
                            while (true){
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
                            break;
                        }else if (interal_opt == "3"){//Mostrar productos
                            saver.setPath(pathProducto);
                            saver.printProductsByProveedor(actual_user);
                            break;
                        }else{
                            cout<<"No valido, intentalo de nuevo"<<endl;       
                        }
                    }
                }
                cout<<"Deseas realizar otra operacion? (S/N): ";
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
    cin>>aa;
    return 0;
}