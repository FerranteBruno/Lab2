#ifndef TRAININGS_H_INCLUDED
#define TRAININGS_H_INCLUDED
#include "date.h"

struct Trainings{
    int ID;
    int userID;
    date trainingDate;
    int t_activity;
    float calories;
    int timemin;
    bool t_status;
};

Trainings call_training();
bool mod_training();
void show_training(Trainings);

Trainings read_training(int);
int quantity_of_trainings();
int search_training(int);
void list_trainings();
bool save_training(Trainings);
bool save_training(Trainings, int);
void list_trainings_by_id();
bool delete_training();
void list_trainings_by_userID();
void check_userID(int, int &);
void check_medicalFit(int, int, int &flag);

#endif // TRAININGS_H_INCLUDED
