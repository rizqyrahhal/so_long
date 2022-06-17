/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:35:07 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/17 12:36:55 by rarahhal         ###   ########.fr       */
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
    // int hie;
    // int wid;
    
    game->enemy = 0;
    if (game->enemy <= 30)
    {
    i = git_position(game);
    if (game->map_len[i - game->width] != '1' && game->map_len[i - game->width] != 'C')
    {
        if (game->map_len[i - game->width] == 'P')
            exit(EXIT_FAILURE);
        game->map_len[i] = '0';
        game->map_len[i - game->width] = 'N';
        setting_enemy(game);
    }
    
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
    
    if (game->enemy >= 30)
    {
    i = git_position(game);
    if (game->map_len[i - 1] != '1' && game->map_len[i - 1] != 'C')
    {
        if (game->map_len[i - 1] == 'P')
            exit(EXIT_FAILURE);
        game->map_len[i] = '0';
        game->map_len[i - 1] = 'N';
        setting_enemy(game);
    }
    i = git_position(game);
    if (game->map_len[i + 1] != '1' && game->map_len[i + 1] != 'C')
    {
        if (game->map_len[i + 1] == 'P')
            exit(EXIT_FAILURE);
        game->map_len[i] = '0';
        game->map_len[i + 1] = 'N';
        setting_enemy(game);
    }
    }
    if (game->enemy == 60)
        game->enemy = 0;
    game->enemy++;
    // printf("%d\n", i);
}