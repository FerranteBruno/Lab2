#include <iostream>
#include "string.h"
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "user.h"


const char *FILE_USERS = "data/user.dat";

User read_user(int pos){
    User reg;
    FILE *p = fopen(FILE_USERS, "rb");
    if (p == NULL){
        reg.ID = 0;
        return reg;
    }
    fseek(p, pos * sizeof(User), SEEK_SET);
    fread(&reg, sizeof(User), 1, p);
    fclose(p);
    return reg;
}

int quantity_of_users(){
    FILE *p = fopen(FILE_USERS, "rb");
    if (p == NULL){
        return 0;
    }
    int bytes, cant;
    fseek(p, 0, SEEK_END); // SEEK_SET --> 0 , SEEK_CUR --> 1 , SEEK_END --> 2
    bytes = ftell(p);
    fclose(p);
    cant = bytes / sizeof(User);
    return cant;
}

void show_user(User reg){

    if(reg.status == 0){
    return;
    }
    else{
    cout << "Código             : " << reg.ID << endl;
    cout << "Apellidos          : " << reg.lastname<< endl;
    cout << "Nombres            : " << reg.name << endl;
    cout << "Nacimiento         : ";
    show_date(reg.birth);
    cout << "Altura             : " << reg.height << endl;
    cout << "Peso               : " << reg.weight << endl;
    cout << "Perfil de actividad: " << reg.activity << endl;
    cout << "Apto Medico        : " << reg.medicalFit << endl;
    cout << "Alta               : " << reg.status<<endl;
    }
}
int search_user(int searched_id){
    User reg;
    FILE *f;
    int pos=0;
    f = fopen(FILE_USERS, "rb");
    if (f == NULL){
        return -2;
    }
    while(fread(&reg, sizeof(User), 1, f)){
        if (searched_id == reg.ID){
            fclose(f);
            return pos;
        }
        pos++;
    }
    fclose(f);
    return -1;
}
User call_user(){
    cls();
    title("Alta de usuario");
    gotoxy(1, 3);
    User reg;
        delline(3);
        gotoxy(1, 3);

        reg.ID = quantity_of_users()+1;

    cin.ignore();
    //validacion de Nombre y apellido
    cout << "Nombres  : ";
    cin.getline(reg.name, 50);
    while(*reg.name == '\0'){
        cout<<"Ingrese nombre nuevamente :";
        cin.getline(reg.name, 50);
    }
    cout << "Apellidos: ";
    cin.getline(reg.lastname, 50);
    while(*reg.lastname == '\0'){
        cout<<"Ingrese apellido nuevamente :";
        cin.getline(reg.lastname, 50);
    }

    int flag = 0;
    int flag_age = 0;

    while(flag == 0){


    cout << "Ingrese fecha de nacimiento: " << endl;
    cout << "Dia: ";
    cin >> reg.birth.day;
    cout << "Mes: ";
    cin >> reg.birth.month;
    cout << "Anio: ";
    cin >> reg.birth.year;

    call_date(reg.birth, flag, flag_age);

    }

    if(flag_age != 1){

    reg.status = 0;

    cout << "Alta invalida! El usuario no tiene la edad requerida";

    return reg;

    }

    cout << "Altura: ";
    cin >> reg.height;

    while(reg.height < 0){
        cout<<"Ingrese altura nuevamente :";
        cin>>reg.height;
    }

    cout << "Peso: ";
    cin >> reg.weight;
    while(reg.weight < 0){
        cout<<"Ingrese peso nuevamente :";
        cin>>reg.weight;
    }

    cout << "Actividad (A,B,C): ";
    cin >> reg.activity;
    while (reg.activity != 'A' && reg.activity != 'B' && reg.activity != 'C' && reg.activity != 'a' && reg.activity != 'b' && reg.activity != 'c'){
        cout << endl <<  "Actividad Incorrecta!\n Ingrese nueva actividad: "  << endl;
        cin >> reg.activity;
    }

    int MF = 0;
    cout << "Apto Medico (1 Aprobado, 0 desaprobado): ";
    cin >>MF;
    while ((MF != 0) && (MF != 1)){
        cout << endl <<  "Ingrese de nuevo\n Apto Medico (1 Aprobado, 0 desaprobado): " << endl;
        cin >> MF;
    }

    reg.medicalFit = MF;

    reg.status = true;

    return reg;
    }

bool mod_user(){
    cls();
    title("Modificar Usuario");
    gotoxy(1, 5);
    int ID, pos;
    cout << "ID: ";
    cin >> ID;
    pos = search_user(ID);
    if (pos >= 0){
        cout << endl << "Usuario a modificar: " << endl;
        cout << "---------------------------" << endl;
        User reg = read_user(pos);
        show_user(reg);
        cout << endl;
        cout << "Peso actual: ";
        cin >> reg.weight;

        cout << "Actualizar actividad (A,B,C): ";
        cin >> reg.activity;
        while (reg.activity != 'A' && reg.activity != 'B' && reg.activity != 'C' && reg.activity != 'a' && reg.activity != 'b' && reg.activity != 'c'){
            cout << endl <<  "Actividad Incorrecta!\n Ingrese nueva actividad: "  << endl;
            cin >> reg.activity;
        }

        int MF = 0;
        cout << "Apto Medico (1 Aprobado, 0 desaprobado): ";
        cin >>MF;
        while ((MF != 0) && (MF != 1)){
            cout << endl <<  "Ingrese de nuevo\n Apto Medico (1 Aprobado, 0 desaprobado): " << endl;
            cin >> MF;
        }

        reg.medicalFit = MF;

        if (save_user(reg, pos) == true){
            msj("Usuario guardado correctamente.", APP_FORECOLOR, APP_OKCOLOR);
            return true;
        }
        else{
            msj("El usuario no se guardó correctamente.", APP_FORECOLOR, APP_ERRORCOLOR);
            return true;

        }
    }
    else{
        msj("No existe el usuario", 15, 3);
        return false;
    }
}

void list_user_by_id(){
    cls();
    title("LISTADO DE USUARIO x ID");
    gotoxy(1, 5);
    int ID, pos;
    cout << "Código: ";
    cin >> ID;
    pos = search_user(ID);
    if (pos >= 0){
        show_user(read_user(pos));
    }
    else{
        msj("No existe el usuario", 15, 3);
    }
}
void list_user(){
    cls();
    title("LISTADO DE USUARIOS");
    gotoxy(1, 5);
    int cant =  quantity_of_users();
    for(int i = 0; i<cant; i++){
        User reg = read_user(i);
        show_user(reg);
        cout << endl;
    }
}
bool save_user(User reg){
    bool saved;
    FILE *f;
    f = fopen(FILE_USERS, "ab");
    if (f == NULL){
        return false;
    }
    saved = fwrite(&reg, sizeof(User), 1, f);
    fclose(f);
    return saved;
}
bool save_user(User reg, int pos){
    bool saved;
    FILE *f;
    f = fopen(FILE_USERS, "rb+");
    if (f == NULL){
        return false;
    }
    fseek(f, pos * sizeof(User), SEEK_SET);
    saved = fwrite(&reg, sizeof(User), 1, f);
    fclose(f);
    return saved;
}

bool delete_user(){
    cls();
    title("Eliminar usuario");
    gotoxy(1, 5);
    int ID, pos;
    cout << "ID: ";
    cin >> ID;
    pos = search_user(ID);
    if (pos >= 0){
        cout << endl << "Usuario a Eliminar: " << endl;
        cout << "---------------------------" << endl;
        User reg = read_user(pos);
        show_user(reg);
        char del;
        cout << endl;
        cout << "REALMENTE DESEA ELIMINTAR AL USUARIO?! (s/n)\n";
        cin >> del;

        while (del != 's' && del != 'n' && del != 'S' && del != 'N' ){
            cout << endl <<  "Opción incorrecta, vuelva a elegir (s/n)"  << endl;
            cin >> del;
        }
        if(del=='s' || del=='S'){
            reg.status = 0;

        }

        if (save_user(reg, pos) == true){
            msj("Usuario eliminado correctamente.", APP_FORECOLOR, APP_OKCOLOR);
            return true;
        }
        else{
            msj("El usuario no se eliminó correctamente.", APP_FORECOLOR, APP_ERRORCOLOR);
            return true;

        }
    }
    else{
        msj("No existe el usuario", 15, 3);
        return false;
    }

}
