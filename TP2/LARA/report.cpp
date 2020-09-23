#include <iostream>
#include "string.h"
using namespace std;
#include "ui.h"
#include "rlutil.h"
using namespace rlutil;
#include "trainings.h"
#include "user.h"
#include "report.h"

void set0(float *v, int t){
    for(int i=0;i<t; i++){
        v[i] = 0;
    }
}

void report1(){
    cls();

    float *average;

    average = (float *) malloc(sizeof(Trainings) * quantity_of_trainings());
    if (avg == NULL){
        return;
    }
    set0(average, quantity_of_trainings());

    cout << "PROMEDIO DE ENTRENAMIENTOS: "<< endl;

    proAverage(avg(average));



    free(average);
}


float avg(float *average){

    int cant = quantity_of_trainings();
    float avg;
    for(int i=0; i<cant; i++){
        Trainings aux = read_training(i);

        if(aux.t_status == 1){
            *average+=aux.timemin;
        }
    }
    avg = *average / cant;
    cout << avg;
    return avg;
}

void proAverage(float average){
    cls();
    title("VERIFICACION DE PROMEDIO");
    gotoxy(1, 5);
    int  pos, cant;
    int auxID;
    cant = quantity_of_trainings();

    cout << "Cantidad de entrenamientos totales: "<< endl;
    cout << cant;

    msj("LISTADO DE ENTRENAMIENTOS x ID");
            for(int i=0; i<cant+1;i++){
                Trainings reg = read_training(i);
                    float timeaux = reg.timemin;

                    /*cout<<timeaux<<endl;
                    cout<<average<<endl;
                    anykey();*/

                    if(timeaux > average){

                    cout<<timeaux<<endl;

                    auxID = reg.ID;


                   // cout << "Tiempo de entrenamiento: " << reg.timemin<<endl;

                    show_training(reg);
        }
    }
}

void report2(){
    cls();

    int pos, ID;


    User *vUser;
    Trainings *vTrainings;

    vUser = (User *) malloc(sizeof(User) * quantity_of_users());
    if (avg == NULL){

        return;
    }
    vTrainings = (Trainings *) malloc(sizeof(Trainings) * quantity_of_trainings());
    if (avg == NULL){
        return;
        free(vUser);
    }

    User reg;
    int total = 0;
    cout << "Ingrese código de usuario: ";
    cin >> ID;

    pos = search_user(ID);

    if (pos >= 0){
    cout << "El usuario elegido es: " << endl;
        read_user(pos);
        cout << "Nombres: "<< reg.name <<endl;
        cout << "Apellido: "<< reg.lastname <<endl;
        cout << endl;
    }
    else{
        msj("Código de usuario invalido", 15, 3);
        cout << endl;
    }

    int cant =  quantity_of_trainings();

                for(int i = 0; i<cant; i++){
                Trainings reg = read_training(i);
                    if ((reg.userID == pos+1) && (reg.t_status = true)){
                        total++;
                }
            }
            cout << "Total de entrenamientos: " << total;

    anykey();

    free(vTrainings);
    free(vUser);
}



