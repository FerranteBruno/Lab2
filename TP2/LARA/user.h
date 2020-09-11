#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include "date.h"

struct User{
    int ID;
    char name[50];
    char lastname[50];
    date birth;
    float height;
    float weight;
    char activity;
    bool medicalFit;
    bool status;
};

User call_user();
bool mod_user();
void show_user(User);

User read_user(int);
int quantity_of_users();
int search_user(int);
void list_user();
bool save_user(User);
bool save_user(User, int);
void list_user_by_id();
bool delete_user();


#endif // USER_H_INCLUDED
