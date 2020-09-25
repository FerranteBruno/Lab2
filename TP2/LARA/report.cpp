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

void cal_total(float *vec){
    int cant = quantity_of_trainings(), pos;
    for(int i=0; i<cant; i++){
        Trainings reg = read_training(i);
        pos = search_user(reg.userID);
        if (reg.t_status = true){
        vec[pos] += reg.calories;
        }
    }
}

void report22(){
    cls();

    int pos, ID;

    float *vCalories;
    User *vec;


    vCalories = (float *) malloc(sizeof(Trainings) * quantity_of_trainings());
    if (vCalories == NULL){
        return;
        free(vCalories);
    }

    vec = (User *) malloc(sizeof(User) * quantity_of_users());
    if (vec == NULL){
        return;
        free(vCalories);
        free(vec);
    }
    set0(vCalories, quantity_of_trainings());

    if (read_user2(vec, quantity_of_users()) == quantity_of_users()){
        cal_total(vCalories);
        most(vec, vCalories, quantity_of_users());

    int i=0, c=0;
        cout << left;
        while(c<1){

            if (vec[i].status == true){
                c++;
                if (c == 1){
                    setColor(BLUE);
                }
                cout << "Puesto #" << c << endl;
                cout << vec[i].lastname << endl;
                cout << vec[i].name << endl;
                cout << vCalories[i] << endl;
                cout << endl;
            }
            i++;
        }
    }
    else{
        msj("Hubo un error al reportar.", APP_FORECOLOR, APP_ERRORCOLOR);
    }



    cal_total(vCalories);
            cout << "Total de calorias: " << *vCalories;

    anykey();

    free(vCalories);
}


void most(User *vec, float *vCalories, int cant){

    int i, j, posmax;
    User aux1;
    float aux2;

    for(i=0; i<cant-1; i++){
        posmax = i;

        for(j=i+1; j<cant; j++){
            if (vCalories[j] > vCalories[posmax]){
                posmax = j;
            }
        }
        aux1 = vec[i];
        aux2 = vCalories[i];
        vec[i] = vec[posmax];
        vCalories[i] = vCalories[posmax];
        vec[posmax] = aux1;
        vCalories[posmax] = aux2;
    }
}

