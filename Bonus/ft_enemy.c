/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:35:07 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/18 15:28:10 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	setting_enemy(t_game *game)
{
	int	hei;
	int	wid;

	hei = -1;
	while (++hei < game->height)
	{
		wid = -1;
		while (++wid < game->width)
		{
			if (game->map_len[hei * game->width + wid] == 'N')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_enemy, wid * 64, hei * 64);
			else if (game->map_len[hei * game->width + wid] == '0')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_space, wid * 64, hei * 64);
		}
	}
}

void	move_enemy(t_game *game)
{
	int	i;

	i = git_position(game, 'N');
	if (game->map_len[i - game->width] != '1'
		&& game->map_len[i - game->width] != 'C'
		&& game->map_len[i - game->width] != 'E')
		w(game, i);
	else if (*game->map_len)
		s(game);
	if (*game->map_len)
		a(game);
	else if (*game->map_len)
		d(game);
}
