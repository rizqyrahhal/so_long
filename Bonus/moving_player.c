/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:52:05 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/17 20:09:51 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long_bonus.h"

void    move_w(t_game *game)
{
    int i;

    i = -1;
    while (++i < ft_strlen(game->map_len) && game->map_len[i])   // git position of playre
        if (game->map_len[i] == 'P')
            break ;
    if (game->map_len[i - game->width] == 'C')
        game->coll_cnt++;
    if (game->map_len[i - game->width] == 'E' && game->all_coll == game->coll_cnt)
    {
        write(1, "done\n", 5);
        exit (EXIT_SUCCESS);
    }
    else if (game->map_len[i - game->width] != '1' && game->map_len[i - game->width] != 'E' && game->map_len[i - game->width] != 'N')
    {
        game->map_len[i] = '0';
        game->map_len[i - game->width] = 'P';
        game->walk_cnt++;
        setting_img(*game);
    }
    if (game->map_len[i - game->width] == 'N')
    {
        game->touch_enemy = 404;
        write(1, "lose\n", 5);
        exit(EXIT_FAILURE);
    }
}

void    move_a(t_game *game)
{
    int i;

    i = -1;
    while (++i < ft_strlen(game->map_len) && game->map_len[i])
        if (game->map_len[i] == 'P')
            break ;
    if (game->map_len[i - 1] == 'C')
        game->coll_cnt++;
    if (game->map_len[i - 1] == 'E' && game->all_coll == game->coll_cnt)
    {
        write(1, "done\n", 5);
        exit (EXIT_SUCCESS);
    }
    else if (game->map_len[i - 1] != '1' && game->map_len[i - 1] != 'E' && game->map_len[i - 1] != 'N')
    {
        game->map_len[i] = '0';
        game->map_len[i - 1] = 'P';
        game->walk_cnt++;
        setting_img(*game);
    }
    if (game->map_len[i - 1] == 'N')
    {
        game->touch_enemy = 404;
        write(1, "lose\n", 5);
        exit(EXIT_FAILURE);
    }
}

void    move_d(t_game *game)
{
    int i;

    i = -1;
    while (++i < ft_strlen(game->map_len) && game->map_len[i])
        if (game->map_len[i] == 'P')
            break ;
    if (game->map_len[i + 1] == 'C')
        game->coll_cnt++;
    if (game->map_len[i + 1] == 'E' && game->all_coll == game->coll_cnt)
    {
        write(1, "done\n", 5);
        exit (EXIT_SUCCESS);
    }
    else if (game->map_len[i + 1] != '1' && game->map_len[i + 1] != 'E' && game->map_len[i + 1] != 'N')
    {
        game->map_len[i] = '0';
        game->map_len[i + 1] = 'P';
        game->walk_cnt++;
        setting_img(*game);
    }
    if (game->map_len[i + 1] == 'N')
    {
        game->touch_enemy = 404;
        write(1, "lose\n", 5);
        exit(EXIT_FAILURE);
    }
}

void    move_s(t_game *game)
{
    int i;

    i = -1;
    while (++i < ft_strlen(game->map_len) && game->map_len[i])
        if (game->map_len[i] == 'P')
            break ;
    if (game->map_len[i + game->width] == 'C')
        game->coll_cnt++;
    if (game->map_len[i + game->width] == 'E' && game->all_coll == game->coll_cnt)
    {
        write(1, "done\n", 5);
        exit (EXIT_SUCCESS);
    }
    else if (game->map_len[i + game->width] != '1' && game->map_len[i + game->width] != 'E' && game->map_len[i + game->width] != 'N')
    {
        game->map_len[i] = '0';
        game->map_len[i + game->width] = 'P';
        game->walk_cnt++;
        setting_img(*game);
    }
    if (game->map_len[i + game->width] == 'N')
    {
        game->touch_enemy = 404;
        write(1, "lose\n", 5);
        exit(EXIT_FAILURE);
    }
}
