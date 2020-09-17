#include <iostream>
#include "string.h"
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "trainings.h"
#include "user.h"


const char *FILE_TRAININGS = "data/trainings.dat";

Trainings read_training(int pos){
    Trainings reg;
    FILE *p = fopen(FILE_TRAININGS, "rb");
    if (p == NULL){
        reg.ID = 0;
        return reg;
    }
    fseek(p, pos * sizeof(Trainings), SEEK_SET);
    fread(&reg, sizeof(Trainings), 1, p);
    fclose(p);
    return reg;
}

int quantity_of_trainings(){
    FILE *p = fopen(FILE_TRAININGS, "rb");
    if (p == NULL){
        return 0;
    }
    int bytes, cant;
    fseek(p, 0, SEEK_END); // SEEK_SET --> 0 , SEEK_CUR --> 1 , SEEK_END --> 2
    bytes = ftell(p);
    fclose(p);
    cant = bytes / sizeof(Trainings);
    return cant;
}

void show_training(Trainings reg){

    if(reg.t_status == 0){
    return;
    }
    else{
    cout << "Código                 : " << reg.ID << endl;
    cout << "Código de usuario      : " << reg.userID<< endl;
    cout << "Fecha de entrenamiento : ";
    show_date(reg.trainingDate);
    cout << "Actividad              : " << reg.t_activity << endl;
    cout << "Calorías               : " << reg.calories << endl;
    cout << "Tiempo                 : " << reg.timemin << endl;
    cout << "Entrenamiento vigente  : " << reg.t_status<<endl;
    }
}
int search_training(int searched_id){
    Trainings reg;
    FILE *f;
    int pos=0;
    f = fopen(FILE_TRAININGS, "rb");
    if (f == NULL){
        return -2;
    }
    while(fread(&reg, sizeof(Trainings), 1, f)){
        if (searched_id == reg.ID){
            fclose(f);
            return pos;
        }
        pos++;
    }
    fclose(f);
    return -1;
}
Trainings call_training(){
    cls();
    title("Alta de entrenamiento");
    gotoxy(1, 3);
    Trainings reg;
        delline(3);
        gotoxy(1, 3);

        reg.ID = quantity_of_trainings()+1;

    cin.ignore();
    //validacion de Nombre y apellido
    cout << "ID del usuario : ";
    cin >> reg.userID;

    /*** TODO: Requiere validacion de usuario, nueva funcion
    while(*reg.name == '\0'){
        cout<<"Ingrese nombre nuevamente :";
        cin.getline(reg.name, 50);
    }*/


    ///TODO Verifcar fecha de entrenamiento.
    int flag = 0;
    int flag_age = 0;

    while(flag == 0){


    cout << "Ingrese fecha del entrenamiento: " << endl;
    cout << "Día: ";
    cin >> reg.trainingDate.day;
    cout << "Mes: ";
    cin >> reg.trainingDate.month;
    cout << "Año: ";
    cin >> reg.trainingDate.year;

    call_training_date(reg.trainingDate, flag, flag_today);

    }

    while(flag_today != 1){

    reg.t_status = 0;

    cout << "Fecha invalida! Ingrese una fecha correcta";

    call_training_date(reg.trainingDate, flag, flag_today)

    return reg;

    }
/// TERMINA FECHAS

///TODO VALIDACION DE APTO FISICO
    cout << "Actividad (1,2,3,4,5): ";
    cin >> reg.t_activity;
    while (reg.t_activity != 1 && reg.t_activity != 2 && reg.t_activity  != 3 && reg.t_activity  != 4 && reg.t_activity  != 5){
        cout << endl <<  "Actividad Incorrecta!\n Ingrese nueva actividad: "  << endl;
        cin >> reg.t_activity;
    }

    cout << "Calorias: ";
    cin >>reg.calories;
    /*while ((MF != 0) && (MF != 1)){
        cout << endl <<  "Ingrese de nuevo\n Apto Medico (1 Aprobado, 0 desaprobado): " << endl;
        cin >> MF;
    }*/

    cout << "Tiempo en minutos: ";
    cin >>reg.timemin;

    reg.t_status = true;

    return reg;
    }

bool mod_training(){
    cls();
    title("Modificar Entrenamiento");
    gotoxy(1, 5);
    int ID, pos;
    cout << "ID: ";
    cin >> ID;
    pos = search_training(ID);
    if (pos >= 0){
        cout << endl << "Entrenamiento a modificar: " << endl;
        cout << "---------------------------" << endl;
        Trainings reg = read_training(pos);
        show_training(reg);
        cout << endl;
        cout << "Tiempo a modificar: ";
        cin >> reg.timemin;

        cout << "Calorias: ";
        cin >> reg.calories;
        /*while (reg.activity != 'A' && reg.activity != 'B' && reg.activity != 'C' && reg.activity != 'a' && reg.activity != 'b' && reg.activity != 'c'){
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
        */


        if (save_training(reg, pos) == true){
            msj("Entrenamiento guardado correctamente.", APP_FORECOLOR, APP_OKCOLOR);
            return true;
        }
        else{
            msj("El usuario no se guardó correctamente.", APP_FORECOLOR, APP_ERRORCOLOR);
            return true;

        }
    }
    else{
        msj("No existe el entrenamiento", 15, 3);
        return false;
    }
}

void list_trainings_by_id(){
    cls();
    title("LISTADO DE ENTRENAMIENTOS x ID");
    gotoxy(1, 5);
    int ID, pos;
    cout << "Código: ";
    cin >> ID;
    pos = search_training(ID);
    if (pos >= 0){
        show_training(read_training(pos));
    }
    else{
        msj("No existe el Entrenamiento", 15, 3);
    }
}
void list_trainings(){
    cls();
    title("LISTADO DE ENTRENAMIENTOS");
    gotoxy(1, 5);
    int cant =  quantity_of_trainings();
    for(int i = 0; i<cant; i++){
        Trainings reg = read_training(i);
        show_training(reg);
        cout << endl;
    }
}
bool save_training(Trainings reg){
    bool saved;
    FILE *f;
    f = fopen(FILE_TRAININGS, "ab");
    if (f == NULL){
        return false;
    }
    saved = fwrite(&reg, sizeof(Trainings), 1, f);
    fclose(f);
    return saved;
}
bool save_training(Trainings reg, int pos){
    bool saved;
    FILE *f;
    f = fopen(FILE_TRAININGS, "rb+");
    if (f == NULL){
        return false;
    }
    fseek(f, pos * sizeof(Trainings), SEEK_SET);
    saved = fwrite(&reg, sizeof(Trainings), 1, f);
    fclose(f);
    return saved;
}

bool delete_training(){
    cls();
    title("Eliminar entrenamiento");
    gotoxy(1, 5);
    int ID, pos;
    cout << "ID: ";
    cin >> ID;
    pos = search_training(ID);
    if (pos >= 0){
        cout << endl << "Entrenamiento a Eliminar: " << endl;
        cout << "---------------------------" << endl;
        Trainings reg = read_training(pos);
        show_training(reg);
        char del;
        cout << endl;
        cout << "REALMENTE DESEA ELIMINTAR EL ENTRENAMIENTO?! (s/n)\n";
        cin >> del;

        while (del != 's' && del != 'n' && del != 'S' && del != 'N' ){
            cout << endl <<  "Opción incorrecta, vuelva a elegir (s/n)"  << endl;
            cin >> del;
        }
        if(del=='s' || del=='S'){
            reg.t_status = 0;

        }

        if (save_training(reg, pos) == true){
            msj("Entrenamiento eliminado correctamente.", APP_FORECOLOR, APP_OKCOLOR);
            return true;
        }
        else{
            msj("El entrenamiento no se eliminó correctamente.", APP_FORECOLOR, APP_ERRORCOLOR);
            return true;

        }
    }
    else{
        msj("No existe el entrenamiento", 15, 3);
        return false;
    }

}

void list_trainings_by_idUser(){

}



