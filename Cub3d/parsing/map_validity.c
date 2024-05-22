#include "../cub3d.h"


int function_open_map(char *file_name, t_pars *ithems)
{
    ithems->fd = open(file_name, O_RDWR | O_CREAT, 0644);
    ithems->buf = malloc(2);
    int index;
    if (ithems->fd == -1)
        return (putstring("File Not Found"), -1);
    index =0 ;
    ithems->read_buf = read(ithems->fd, ithems->buf, 1);
    ithems->buf[ithems->read_buf] = '\0';
    while (ithems->read_buf > 0)
    {
        ithems->read_buf = read(ithems->fd, ithems->buf, 1);
        ithems->buf[ithems->read_buf] = '\0';
        ithems->map = string_turn(ithems->map, ithems->buf);
    }
    printf("[%s]\n", ithems->map);
    return (1);
}
