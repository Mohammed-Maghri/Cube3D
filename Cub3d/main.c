#include "cub3d.h"

void leacks_it()
{
    system("leaks Cub3d");
}

int main()
{
    t_pars *map;
    map = gb(sizeof(t_pars), 1);
    map->map = NULL;
    map->buf = NULL;
    function_open_map("maps/map.cub", map);
    printf("(%d)\n", count_how_may(map->map, '\n'));
    char **this ;
    this = moveto_array(map->map);
    int index ;
    index = 0;
    while (this[index])
    {
        printf("---> %s \n\n", this[index]);
        index++ ;
    }

    gb(0, -1);
}