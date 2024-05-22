#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


// For Parsing 
typedef struct parsing 
{
    int index;
    int increment ;
    char *map;
    int  fd ;
    int read_buf;
    char *buf;
    char **array;
} t_pars;


// Garbege Collector
int count_lenght(void **array);
void optins(void **array);
void *gb(int size, int flag);
void **garbege_array_fill(void **array, void *add);
// -----------------

char **moveto_array(char *string);
int count_how_may(char *string, char srach_for);
char *string_turn(char *string, char *copy);
void putstring(char *string);
void paste(char string);
int function_open_map(char *file_name, t_pars *ithems);

//--------------

//For Raycasting
//--------------
#endif 