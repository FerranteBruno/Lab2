#include <iostream>
#include "botella_class.h"
#include <stdlib.h>
using namespace std;

///Constructor de botellas LaraCola
    Botella::Botella(float Cap, float Ocu, bool Tap){
        cout << "Nueva Botella creada." << endl;
        Capacidad = Cap;
        if(Tap == 1){
        }
        else{
        Tapada = true;
            Tapada = false;
        }
        Ocupacion = Ocu;
        system("pause");
    }



    float Botella::Llenar(float Cap){



        if(Tapada == true){
            cout << "La botella no puede ser llenada ya que esta tapada" <<  endl;

        }
        else {
            if(Cap < Capacidad ){

                Ocupacion += Cap;

                cout << "Se agrego " << Cap << " cm2 a la botella" << endl;
                system("pause");
                system("cls");
                }
                else
                {
                    Ocupación = Capacida;
                    cout << "La botella no puede ser llenada mas de su capacidad maxima,\nla cual es: " << Capacidad <<  endl;
                    cout << "Se agrego " << Capacidad << " cm2 a la botella" << endl;
                }

        }


    }

    void Botella::Vaciar(){

        if(Tapada == true){
            cout << "La botella no puede ser vaciada ya que esta tapada" <<  endl;

        }
        else{
        Ocupacion= 0;

        cout << "Se vacio la botella" << endl;
        cout << "Actualmente tiene " << Ocupacion << " cm2." << endl;
        }
    }

    void Botella::estado(){

        ///Tapada en letras
        if (Tapada == true){
            cout << "Tapada?: SI" << endl;
            }
            else {
            cout << "Tapada?: NO"<< endl;
            }

            cout << "Capacidad de la botella: " << Capacidad << endl;
            cout << "Ocupacion actual: " << Ocupacion << endl;
            cout << "Disponible para cargar: " << Capacidad - Ocupacion << endl;


    }

    bool Botella::Tapar(int auxTap3){

            cout << "Enroscando..." << endl;
            Tapada = true;
        return true;

    }

    bool Botella::Destapar(int auxTap3){

            cout << "Desenroscando..." << endl;
            Tapada = false;
        return true;

    }



    /*Botella::~Botella(){

        cout << "Estallo la botella" << endl;
    }*/


