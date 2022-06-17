/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:33:07 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/17 12:21:42 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long_bonus.h"


int ft_animation(t_game *game)
{
    char *wlk;

    if (game->touch_enemy == 0)
        move_enemy(game);
    // movement
    wlk = ft_itoa(game->walk_cnt);
    if (game->touch_enemy == 0)
    {
        mlx_put_image_to_window(game->mlx, game->win, game->img_space, 50, 0);
        mlx_string_put(game->mlx, game->win, 90, 20, 0x0000FF00, wlk);
    }
    //  animation
    if (game->counter_animation <= 15 && game->touch_enemy == 0)
    {
        mlx_put_image_to_window(game->mlx, game->win, game->img_space, 0, 0);
        mlx_put_image_to_window(game->mlx, game->win, game->img_player, 0, 0);
    }
    if (game->counter_animation >= 15 && game->touch_enemy == 0)
    {
        mlx_put_image_to_window(game->mlx, game->win, game->img_space, 0, 0);
        mlx_put_image_to_window(game->mlx, game->win, game->img_animation, 0, 0);
    }
    if (game->counter_animation == 30)
        game->counter_animation = 0;
    game->counter_animation++;
    
    return (0);
}