/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:33:07 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/19 15:58:57 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_animation(t_game *game)
{
	if (game->touch_enemy == 0 && game->counter_animation == 15)
		move_enemy(game);
	game->wlk = ft_itoa(game->walk_cnt);
	if (game->touch_enemy == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_space, 1 * 64, 0);
		mlx_string_put(game->mlx, game->win, 85, 20, 0x0000FF00, game->wlk);
	}
	free(game->wlk);
	if (game->counter_animation <= 15 && game->touch_enemy == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_space, 0, 0);
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, 0, 0);
	}
	if (game->counter_animation >= 15 && game->touch_enemy == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_space, 0, 0);
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_animation, 0, 0);
	}
	if (game->counter_animation == 30)
		game->counter_animation = 0;
	game->counter_animation++;
	return (0);
}
