#include "cub3d.h"

void leacks_it()
{
    system("leaks Cub3d");
}

char **for_main(t_pars *map)
{
    map = gb(sizeof(t_pars), 1);
    map->map = NULL;
    map->buf = NULL;
    function_open_map("maps/map.cub", map);
    return (move_only_content(moveto_array(map->map)));
}
void check_on_element(t_store *store)
{

    if (store->no[0] == '*')
        putstring("NO Textures Are Not Available ..! \n");
    if (store->so[0] == '*')
        putstring("SO Textures Are Not Available ..! \n");
    if (store->we[0] == '*')
        putstring("WE Textures Are Not Available ..! \n");
    if (store->ea[0] == '*')
        putstring("EA Textures Are Not Available ..! \n");
}

void check_tb(t_store *store)
{
    int index;

    index = 0;
    while (index < 3)
    {
        if (store->f[index] == -1)
        {
            putstring("RGB'S Are Not Valid ...!\n");
            exit(1);
        }
        index++ ;
    }
    while (index < 3)
    {
        if (store->c[index] == -1)
        {
            putstring("RGB'S Are Not Valid ...!\n");
            exit(1);
        }
        index++ ;
    }
}
void ini_tila(t_store *store, int flag)
{
    if (flag == 1)
    {
        store->c = gb(sizeof(int) + 3, 1);
        store->f = gb(sizeof(int) + 3, 1);
        store->c[0] = -1;
        store->c[1] = -1;
        store->c[2] = -1;
        store->f[0] = -1;
        store->f[1] = -1;
        store->f[2] = -1;
    }
    if (flag == 0)
        check_tb(store);
}
int main()
{
    t_pars *map;
    t_store *store;
    char **that;

    map = NULL;
    store = NULL;
    atexit(leacks_it);
    that = for_main(map);
    store = gb(sizeof(t_store), 1);
    store->no = copy_move("*");
    store->ea = copy_move("*");
    store->so = copy_move("*");
    store->we = copy_move("*");
    check_directions(that, store);
    check_on_element(store);
    ini_tila(store, 1);
    check_rgb_colors(that, store);
    ini_tila(store, 0);
    gb(0, -1);
}
