#include "../cub3d.h"


int function_open_map(char *file_name, t_pars *ithems)
{
    ithems->fd = open(file_name, O_RDONLY);
    ithems->buf = malloc(2);
    if (ithems->fd == -1)
        return (putstring("File Not Found"), -1);
    ithems->read_buf = read(ithems->fd, ithems->buf, 1);
    ithems->buf[ithems->read_buf] = '\0';
    ithems->map = string_turn(ithems->map, ithems->buf);
    while (ithems->read_buf > 0)
    {
        ithems->read_buf = read(ithems->fd, ithems->buf, 1);
        ithems->buf[ithems->read_buf] = '\0';
        ithems->map = string_turn(ithems->map, ithems->buf);
    }
    if (ithems->read_buf == -1)
    {
        printf("Error Accured While Reading From file... !\n");
        exit(1);
    }
    return (1);
}
