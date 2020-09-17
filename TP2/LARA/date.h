#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED\

struct date{
  int day, month, year;
};

date call_date(date, int &flag , int &flag_age);
date call_training_date(date, int &flag , int &flag_age);
void show_date(date);
int time_set(date, int &flag_age);
int time_set_training(date reg, int &flag_age);

#endif // DATE_H_INCLUDED
