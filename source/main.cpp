#include <iostream>
#include "Proveedor.h"
#include "Comprador.h"
#include "SaverMannager.h"
#include <string> 
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
    
    cout<<"Ingresa tu usuario: ";
    cin>>actual_user;
    cout<<"Ingresa tu contrasenia: ";
    cin>>actual_pass;

    
    bool enter =  saver.validateCredentials(actual_user, actual_pass, login_path);
    if (enter){
        //MENUS
        cout<<endl<<"BIENVENIDO"<<endl;
        if (opt == "C"){
            saver.setPath(pathComprador);
            Comprador comprador = saver.searchComprador(actual_user);

            cout<<comprador.getDinero()<<endl;
            cout<<comprador.getName()<<endl;
            cout<<comprador.getPassword()<<endl;
            
            cout<<"----MENU----"<<endl;
            cout<<"(1) Comprar"<<endl;
            cout<<"(2) Historial de compra"<<endl;
            cout<<"(3) Actualizar dinero"<<endl;
            cout<<"(4) Editar datos"<<endl;
            cout<<"Selecciona un número de acuerdo a la opción a usar: "<<endl;
        }else if (opt == "P"){
            saver.setPath(pathProveedor);
            Proveedor proveedor = saver.searchProveedor(actual_user);
            cout<<"----MENU----"<<endl;
            cout<<"(1) Registrar Producto"<<endl;
            cout<<"(2) Editar producto"<<endl;
            cout<<"(3) Editar datos"<<endl;
            cout<<"Selecciona un numero de acuerdo a la opcion a usar: "<<endl;
        }
    }else{
        cout<<endl<<"Datos incorrectos :("<<endl;
    }

    

    /*
    Proveedor proveedor = Proveedor("provedorcito2","Pedro", "Perez Piedras", "pass1234", "proveedor", "Pascual Rubio No. 51", "5545875222");
    Comprador comprador = Comprador("compradorcito1","Christian", "Salazar Lopez", "pass12345", "comprador", "Mariano Ortiz No. 54", "5587945120", "5587451200", 100.0f);
    SaverMannager saver = SaverMannager(pathProveedor);
    saver.recordProveedor(proveedor);
    saver.setPath(pathComprador);
    saver.recordComprador(comprador);
    */
    cin>>aa;
    return 0;
}