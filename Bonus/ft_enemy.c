/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:35:07 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/17 17:32:33 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long_bonus.h"

void    setting_enemy(t_game *game)
{
    int hei;
    int wid;

    hei = 0;
    while (hei < game->height)
    {
        wid = 0;
        while (wid < game->width)
        {
            if (game->map_len[hei * game->width + wid] == 'N')
                mlx_put_image_to_window(game->mlx, game->win, game->img_enemy, wid * 64, hei * 64);
            else if (game->map_len[hei * game->width + wid] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->img_space, wid * 64, hei * 64);
            wid++;
        }
        hei++;
    }
}

int git_position(t_game *game)
{
    int i;

    i = -1;
    while (++i < ft_strlen(game->map_len) && game->map_len[i])   // git position of enemy
        if (game->map_len[i] == 'N')
            break ;
    return (i);
}

void    move_enemy(t_game *game)
{
    int i;

    i = git_position(game);
    if (game->map_len[i - game->width] != '1' && game->map_len[i - game->width] != 'C' && game->map_len[i - game->width] != 'E')
    {
        if (game->map_len[i - game->width] == 'P')
            exit(EXIT_FAILURE);
        game->map_len[i] = '0';
        game->map_len[i - game->width] = 'N';
        setting_enemy(game);
    }
    
    else if (*game->map_len && game->map_len[i - game->width])
    {
        i = git_position(game);
        if (game->map_len[i + game->width] != '1' && game->map_len[i + game->width] != 'C' && game->map_len[i + game->width] != 'E')
        {
            if (game->map_len[i + game->width] == 'P')
                exit(EXIT_FAILURE);
            game->map_len[i] = '0';
            game->map_len[i + game->width] = 'N';
            setting_enemy(game);
        }
    }

    if (*game->map_len)
    {
        i = git_position(game);
        if (game->map_len[i - 1] != '1' && game->map_len[i - 1] != 'C' && game->map_len[i - 1] != 'E')
        {
            if (game->map_len[i - 1] == 'P')
                exit(EXIT_FAILURE);
            game->map_len[i] = '0';
            game->map_len[i - 1] = 'N';
            setting_enemy(game);
        }
    }
    else if (*game->map_len)
    {
        i = git_position(game);
        if (game->map_len[i + 1] != '1' && game->map_len[i + 1] != 'C' && game->map_len[i + 1] != 'E')
        {
            if (game->map_len[i + 1] == 'P')
                exit(EXIT_FAILURE);
            game->map_len[i] = '0';
            game->map_len[i + 1] = 'N';
            setting_enemy(game);
        }
    }
}