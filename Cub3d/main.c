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
    if (le_count(store->no) == 0)
        putstring("NO Textures Are Not Available ..! \n");
    if (le_count(store->so) == 0)
        putstring("NO Textures Are Not Available ..! \n");
    if (le_count(store->we) == 0)
        putstring("NO Textures Are Not Available ..! \n");
    if (le_count(store->ea) == 0)
        putstring("NO Textures Are Not Available ..! \n");
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
    check_directions(that, store);
    check_on_element(store);
    gb(0, -1);
}