/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:48:15 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/18 12:49:37 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_image(t_game *game, int wid, int hei, void *img)
{
	mlx_put_image_to_window(game->mlx, game->win, img, wid * 64, hei * 64);
}

void	setting_img(t_game game)
{
	int	hei;
	int	wid;

	hei = -1;
	while (++hei < game.height)
	{
		wid = -1;
		while (++wid < game.width)
		{
			if (game.map_len[hei * game.width + wid] == '1')
				put_image(&game, wid, hei, game.img_wall);
			else if (game.map_len[hei * game.width + wid] == 'C')
				put_image(&game, wid, hei, game.img_coll);
			else if (game.map_len[hei * game.width + wid] == 'P')
				put_image(&game, wid, hei, game.img_player);
			else if (game.map_len[hei * game.width + wid] == 'E')
				put_image(&game, wid, hei, game.img_exit);
			else if (game.map_len[hei * game.width + wid] == '0')
				put_image(&game, wid, hei, game.img_space);
			else if (game.map_len[hei * game.width + wid] == 'N')
				put_image(&game, wid, hei, game.img_enemy);
		}
	}
}
