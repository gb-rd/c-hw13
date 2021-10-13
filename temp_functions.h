#pragma once

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct measures_t{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
    int crt;
} measures;

int scan_file(measures *st, FILE *data_file, int *current_size);

void get_current_time(int *month, int *year);

void print_data(measures *st);
int print_month_data(measures *st, int my_month, int my_year, int *year_calculate, int year_only);
void print_all(measures *st, int year, int is_current);

void help_function(char *arg);
