#include <iostream>
using namespace std;
#include "MenuPrincipal.h"
#include "botella_class.h"



void mainMenu(){

    float auxCap = 0, auxOcu = 0, auxOcu2 = 0;
    int auxTap2 = 0;
    bool auxTap = 0;
    bool auxTap3 = 0;
    bool auxCap2 = 0;

    cout << "Primero que nada... Como es tu botella ?" << endl;
    cout << "Desea darle una capacidad? 1-SI, 0-NO(por defecto 100): " << endl;
    cin >> auxCap2;
    while(auxCap2 != 1 && auxCap2 != 0){
        cout << "Opcion ingresada incorrecta, vuelva a seleccionar. Tapada? 1 = SI, 0 = NO : " << endl;
        cin >> auxCap2;
    }
    if(auxCap2 == 1){
        cout << "Capacidad?             : " << endl;
        cin >> auxCap;
    }
    else
    {
        auxCap = 100;
    }

    cout << "Ocupacion actual?      : " << endl;
    cin >> auxOcu2;
    while(auxOcu2 > auxCap){
        cout << "No puedes ingresar mas liquido del que soporta el recipiente, vuelva a ingresar" << endl;
        cin >> auxOcu2;
    }
    auxOcu = auxOcu2;

    cout << "Tapada? 1 = SI, 0 = NO : " << endl;
    cin >> auxTap2;

    while(auxTap2 != 1 && auxTap2 != 0){
        cout << "Opcion ingresada incorrecta, vuelva a seleccionar. Tapada? 1 = SI, 0 = NO : " << endl;
        cin >> auxTap2;
    }
    auxTap = auxTap2;

    Botella LaraCola(auxCap, auxOcu, auxTap);
    int ra = -1;

    int carga=0;
    int band = 0;
    while(band == 0){
            system("cls");

            cout << "Bienvenido a LaraCola, la actividad mas cocacolera de la historia!,\naqui podras hacer magia con liquidos y recipientes embotellados" << endl;
            cout << "1 - Agregar contenido a la botella " << endl;
            cout << "2 - Vaciar contenido de la botella " << endl;
            cout << "3 - Hacer estallar la botella " << endl;
            cout << "4 - Destapar la botella " << endl;
            cout << "5 - Tapar la botella " << endl;
            cout << "9 - Salir " << endl;
            LaraCola.estado();
            cin >> ra;


        switch(ra){


            case 1:

                cout << "Ingrese la cantidad de cm2 para ingresar en la LaraCola" << endl;
                cin >> carga;

                LaraCola.Llenar(carga);
                ra = -1;
                system("pause");
                break;

            case 2:

                cout << "Botella vaciada" << endl;

                LaraCola.Vaciar();
                ra = -1;
                system("pause");
                break;

            case 3:
                cout << "La botella ha estallado" << endl;
                break;

            case 4:
                cout << "Destapar la botella? Destapar 1 = SI, 0 = NO : " << endl;
                    cin >> auxTap3;
                    while(auxTap3 != 1 && auxTap3 != 0){
                        cout << "Opcion ingresada incorrecta, vuelva a seleccionar. Destapar? 1 = SI, 0 = NO : " << endl;
                        cin >> auxTap3;
                    }
                    LaraCola.Destapar(auxTap3);
                    if(auxTap3 == true){
                    cout << "Botella Destapada satisfactoriamente." << endl;
                }
                else{
                    cout << "No se pudo destapar la botella" << endl;
                }

                system("pause");
                break;

            case 5:
                cout << "Tapar la botella? Tapar 1 = SI, 0 = NO :" << endl;
                cin >> auxTap3;
                    while(auxTap3 != 1 && auxTap3 != 0){
                        cout << "Opcion ingresada incorrecta, vuelva a seleccionar. Tapar? 1 = SI, 0 = NO : " << endl;
                        cin >> auxTap3;
                    }
                    LaraCola.Tapar(auxTap3);

                if(auxTap3 == true){
                    cout << "Botella Tapada satisfactoriamente." << endl;
                }
                else{
                    cout << "No se pudo tapar la botella" << endl;
                }
                system("pause");
                break;

            case 9:

                cout << "Gracias por usar sistemas LaraCola!" << endl;
                band = 9;
                system("pause");
                break;
            ra = -1;
            system("pause");
            system("cls");
        }
        ra = -1;


    }
return;
}








