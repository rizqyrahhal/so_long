/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:48:15 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/16 21:59:52 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long_bonus.h"

void    setting_img(t_game game)
{
    int hei;
    int wid;

    hei = 0;
    while (hei < game.height)
    {
        wid = 0;
        while (wid < game.width)
        {
            if (game.map_len[hei * game.width + wid] == '1')
                mlx_put_image_to_window(game.mlx, game.win, game.img_wall, wid * 64, hei * 64);
            else if (game.map_len[hei * game.width + wid] == 'C')
                mlx_put_image_to_window(game.mlx, game.win, game.img_coll, wid * 64, hei * 64);
            else if (game.map_len[hei * game.width + wid] == 'P')
                mlx_put_image_to_window(game.mlx, game.win, game.img_player, wid * 64, hei * 64);
            else if (game.map_len[hei * game.width + wid] == 'E')
               mlx_put_image_to_window(game.mlx, game.win, game.img_exit, wid * 64, hei * 64);
            else if (game.map_len[hei * game.width + wid] == '0')
                mlx_put_image_to_window(game.mlx, game.win, game.img_space, wid * 64, hei * 64);
            else if (game.map_len[hei * game.width + wid] == 'N')
                mlx_put_image_to_window(game.mlx, game.win, game.img_enemy, wid * 64, hei * 64);
            wid++;
        }
        hei++;
    }
}
