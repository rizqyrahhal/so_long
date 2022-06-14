/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:42:12 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/14 15:12:15 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"
# include "../includes/get_next_line.h"

void    check_first_line(char *line)
{
    int i;

    i = -1;
    while (++i < ft_strlen(line) && line[i])
        if (line[i] != '1')
            ft_error("Map must be closed/surrounded by walls.\n");
}

void    check_inside_map(char *line)
{
    if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
            ft_error("Map must be closed/surrounded by walls.\n");
}

void    check_last_line(t_game *game)
{
    int i;

    i = ft_strlen(game->map_len) - game->width;
    while (i++ < ft_strlen(game->map_len) && game->map_len[i])
        if (game->map_len[i] != '1')
            ft_error("Map must be closed/surrounded by walls.\n");
}

void    check_map(t_game *game)
{
    int i;
    int exit;
    int collect;
    int start_position;

    i = -1;
    exit = 0;
    collect = 0;
    start_position = 0;
    if (game->height * game->width != ft_strlen(game->map_len))
        ft_error("Map must be rectanguler.\n");
    while (++i < ft_strlen(game->map_len) && game->map_len[i])
    {
        if (game->map_len[i] == 'E')
            exit++;
        if (game->map_len[i] == 'C')
            collect++;
        if (game->map_len[i] == 'P')
            start_position++;
    }
    if (exit == 0 || collect == 0 || start_position == 0)
        ft_error("Map not respects the above rules.\n");
}

void    map_read(char *filename, t_game *game)
{
    int     fd;
    char    *line;

    fd = open(filename, O_RDONLY);
    if (fd <= 0)
        ft_error("error in opening file\n");
    line = get_next_line(fd);
    game->height = 0;
    game->width = ft_strlen(line);
    game->map_len = ft_strdup(line);
    check_first_line(line);
    free(line);
    while (line)
    {
        game->height++;
        line = get_next_line(fd);
        if (line)
        {
            check_inside_map(line);
            game->map_len = ft_strjoin(game->map_len, line);
            free(line);
        }
    }
    check_last_line(game);
    close(fd);
    check_map(game);
}
