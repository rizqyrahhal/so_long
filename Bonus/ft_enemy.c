/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:35:07 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/16 22:39:54 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long_bonus.h"

int git_hie(t_game *game, int position)
{

}

int git_wid(t_game *game, int position)
{
    
}

void    move_enemy(t_game *game)
{
    int i;

    i = -1;
    while (++i < ft_strlen(game->map_len) && game->map_len[i])   // git position of enemy
        if (game->map_len[i] == 'N')
            break ;
    if (game->map_len[i - game->width] != '1' && game->map_len[i - game->width] != 'C')
    {
        // if (game->map_len[i - game->width] == 'P')
        //     exit(EXIT_FAILURE);
        game->map_len[i] = '0';
        game->map_len[i - game->width] = 'N';
        mlx_put_image_to_window(game->mlx, game->win, game->img_space, 1 * 64, 3 * 64);
        mlx_put_image_to_window(game->mlx, game->win, game->img_enemy, 3 * 64, 1 * 64);
        // setting_img(*game);
    }
    // i = -1;
    // while (++i < ft_strlen(game->map_len) && game->map_len[i])   // git position of enemy
    //     if (game->map_len[i] == 'N')
    //         break ;
    // if (game->map_len[i + game->width] != '1' && game->map_len[i + game->width] != 'C')
    // {
    //     game->map_len[i] = '0';
    //     game->map_len[i + game->width] = 'N';
    //     mlx_put_image_to_window(game->mlx, game->win, game->img_space, 4 * 64, 2 * 64);
    //     mlx_put_image_to_window(game->mlx, game->win, game->img_enemy, 4 * 64, 2 * 64);
    //     // setting_img(*game);
    // }
    // printf("%d\n", i);
}