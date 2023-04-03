/*
** EPITECH PROJECT, 2023
** error handler
** File description:
** error handler
*/

#include "../includes/my.h"
#include "../includes/functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

bool_t is_line_valid(char *line)
{
    int nb_count = 0;
    int nb;
    if (line[0] == 'A') nb = 6;
    else {
        if (line[0] == 'T') nb = 3;
        else
            return False;
    }
    for (int i = 0 ; i < my_strlen(line) ; i++) {
        if (BETW(line[i], 48, 58)) {
            i += get_nbr_len(line, nb_count);
            nb_count++;
        }
    }
    return nb_count == nb;
}

bool_t is_script_valid(char *path)
{
    FILE *stream = fopen(path, "r");
    if (!stream) {
        write(2, "Error: File not found.\n", 23);
        return False;
    }
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    while ((nread = getline(&line, &len, stream)) != -1) {
        if (!is_line_valid(line)) {
            fclose(stream);
            write(2, "Error: File not valid.\n", 23);
            return False;
        }
    }
    fclose(stream);
    return True;
}

int help(void)
{
    int fd = open("help.txt", O_RDONLY);
    char buff[158];
    read(fd, buff, 158);
    my_putstr(buff);
    return 0;
}
