#include <iostream>
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "mainMenu.h"
#include "user.h"
#include "trainings.h"

void mainMenu(){
    while(true){
        cls();
        title("MENÚ PRINCIPAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 5);
        cout << "1 - Usuarios" << endl;
        cout << "2 - Entrenamientos" << endl;
        cout << "3 - REPORTES" << endl;
        cout << "4 - CONFIGURACIÓN" << endl;
        cout << "------------------" << endl;
        cout << "0 - Salir del programa" << endl;
        int pos;
        cout << endl << "> ";
        cin >> pos;

        switch(pos){
            case 1:
                menuUsers();
            break;
            case 2:
            menuTrainings();
            break;
            case 3:
            break;
            case 4:
            break;
            case 0:
                return;
            break;
        }
    }
}

void menuUsers(){
    while(true){
        cls();
        title("MENÚ USUARIOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 5);
        cout << "1 - Nuevo usuario" << endl;
        cout << "2 - Modificar usuario" << endl;
        cout << "3 - Listar usuario por ID" << endl;
        cout << "4 - Listar todos los usuarios" << endl;
        cout << "5 - Eliminar usuario" << endl;
        cout << "------------------" << endl;
        cout << "0 - VOLVER" << endl;
        int pos;
        cout << endl << "> ";
        cin >> pos;

        switch(pos){
            case 1:
                User reg;
                reg = call_user();
                if(save_user(reg)){
                    cout << "Usuario registrado.";
                }
                else{
                    cout << "No se pudo registrar el Usuario.";
                }
            break;
            case 2:
                mod_user();
            break;
            case 3:
                list_user_by_id();
            break;
            case 4:
                list_user();
            break;
            case 5:
                delete_user();

            break;
            case 0:
                return;
            break;
        }
        cin.ignore();
        cout<<"Presione cualquier tecla para salir..."<<endl;
        anykey();
    }
}

void menuTrainings(){
    while(true){
        cls();
        title("MENÚ ENTRENAMIENTOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 5);
        cout << "1 - Nuevo entrenamiento" << endl;
        cout << "2 - Modificar entrenamiento" << endl;
        cout << "3 - Listar entrenamientos por ID" << endl;
        cout << "4 - Listar entrenamientos por ID de usuario" << endl;
        cout << "5 - Listar todos los entrenamientos" << endl;
        cout << "------------------" << endl;
        cout << "0 - VOLVER" << endl;
        int pos;
        cout << endl << "> ";
        cin >> pos;

        switch(pos){
            case 1:
                Trainings reg;
                reg = call_training();
                if(save_training(reg)){
                    cout << "Usuario registrado.";
                }
                else{
                    cout << "No se pudo registrar el Usuario.";
                }
            break;
            case 2:
                mod_training();
            break;
            case 3:
                list_trainings_by_id();
            break;
            case 4:
                list_trainings_by_idUser();
            break;
            case 5:
                list_trainings();
            break;
            case 0:
                return;
            break;
        }
        cin.ignore();
        cout<<"Presione cualquier tecla para salir..."<<endl;
        anykey();
    }
}

