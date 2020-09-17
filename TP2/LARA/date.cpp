#include <iostream>
using namespace std;
#include "date.h"
#include "user.h"
#include "trainings.h"

date call_date(date reg, int &flag, int &flag_age){

        bool bisiesto = false;


        //comprobamos si el año es bisiesto
        if((reg.year%4==0) && (reg.year%100!=100 || reg.year%400==0)){
            bisiesto = true;
            }


        //comprobamos que los datos ingresados esten en un rango valido
        while(reg.day > 0 && reg.day < 32 && reg.month > 0 && reg.month < 13 && reg.year > 1910){
            if(reg.month==1 || reg.month==3 || reg.month==5 || reg.month==7 || reg.month==8 || reg.month==10 || reg.month==12){
               cout << "\nFecha valida\n";
               flag = 1;
               time_set(reg,flag_age);
               return reg;
            }
            else
            {
                if(reg.month==2 && reg.day<30 && bisiesto){

                    cout << "\nFecha valida\n";
                    flag = 1;
                    time_set(reg,flag_age);
                    return reg;
                    }

                else if(reg.month==2 && reg.day<29 && !bisiesto){
                    cout << "\nFecha valida\n";
                    flag = 1;
                    time_set(reg,flag_age);
                    return reg;
                    }

                else if(reg.month!=2 && reg.day<31){
                    cout << "\nFecha valida\n";
                    flag = 1;
                    time_set(reg,flag_age);
                    return reg;
                }
                else{
                cout << "\nFecha no valida\n";
                flag = 0;
                time_set(reg,flag_age);
                return reg;
            }
        }
    }
    cout << "\nFecha no valida\n";
    show_date(reg);
}


void show_date(date reg){
    cout << reg.day << "/" << reg.month << "/" << reg.year << endl;
}

int time_set(date reg, int &flag_age)
{
  time_t tiempo;
  char cad[80];
  struct tm *tmPtr;

  tiempo = time(NULL);
  tmPtr = localtime(&tiempo);

  printf("FECHA ACTUAL \n%d/%d/%d %d:%d:%d", tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year, tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec);
  //strftime(cad, 80, "%A %d de %B de %Y", tmPtr);
  //printf("\n\n%s", cad);

  int auxd, auxm, auxy;
  auxm= tmPtr->tm_mon ;

  auxd = tmPtr->tm_mday - reg.day ;
  auxm = tmPtr->tm_mon+1 - reg.month;
  auxy = 1900+tmPtr->tm_year - reg.year;

    if(auxy <=13){
    if(auxm <=0){

    if (auxd <=0){

    cout<<endl << "No tiene pelito brodi"<< endl;

    flag_age=0;

    return 0;
        }
    cout<<endl << "No tiene pelito brodi"<< endl;
    flag_age=0;
    return 0;
    }

    cout<<endl << "No tiene pelito brodi"<< endl;
    flag_age=0;
    return 0;
    }
   else {
   cout<<endl << "Edad valida, Mayor a 13 años"<< endl;
    flag_age=1;
   }

  return 0;
}

date call_training_date(date reg, int &flag, int &flag_today){

        bool bisiesto = false;


        //comprobamos si el año es bisiesto
        if((reg.year%4==0) && (reg.year%100!=100 || reg.year%400==0)){
            bisiesto = true;
            }


        //comprobamos que los datos ingresados esten en un rango valido
        while(reg.day > 0 && reg.day < 32 && reg.month > 0 && reg.month < 13) {
        if(reg.month==1 || reg.month==3 || reg.month==5 || reg.month==7 || reg.month==8 || reg.month==10 || reg.month==12){

               cout << "\nFecha valida\n";
               flag= 1;
               time_set_training(reg,flag_today);
               return reg;
            }
            else
            {
                if(reg.month==2 && reg.day<30 && bisiesto){

                    cout << "\nFecha valida\n";
                    flag= 1;
                    time_set_training(reg,flag_today);
                    return reg;
                    }

                else if(reg.month==2 && reg.day<29 && !bisiesto){
                    cout << "\nFecha valida\n";
                    flag= 1;
                    time_set_training(reg,flag_today);
                    return reg;
                    }

                else if(reg.month!=2 && reg.day<31){
                    cout << "\nFecha valida\n";
                    flag= 1;
                    time_set_training(reg,flag_today);
                    return reg;
                }
                else{
                cout << "\nFecha no valida\n";
                flag= 0;
                time_set_training(reg,flag_today);
                return reg;
            }
        }
    }
    cout << "\nFecha no valida\n";
    show_date(reg);
}

int time_set_training(date reg, int &flag_today)
{
  time_t tiempo;
  char cad[80];
  struct tm *tmPtr;

  tiempo = time(NULL);
  tmPtr = localtime(&tiempo);

  printf("FECHA ACTUAL \n%d/%d/%d %d:%d:%d", tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year, tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec);
  //strftime(cad, 80, "%A %d de %B de %Y", tmPtr);
  //printf("\n\n%s", cad);

  int auxd, auxm, auxy;
  auxm= tmPtr->tm_mon ;


  auxd = tmPtr->tm_mday - reg.day ;
  auxm = tmPtr->tm_mon+1 - reg.month;
  auxy = 1900+tmPtr->tm_year - reg.year;

   if(auxy < 0) {
    if(auxm < 0){

    if (auxd < 0){

    cout<<endl << "No es por ahi wey"<< endl;

    flag_today=0;

    return 0;
        }
    cout<<endl << "No es por ahi wey"<< endl;
     flag_today=0;
    return 0;
    }

    cout<<endl << "No es por ahi wey"<< endl;
     flag_today=0;
    return 0;
    }
   else {
   cout<<endl << "Es por ahi bro"<< endl;
     flag_today=1;
   }

  return 0;
}
