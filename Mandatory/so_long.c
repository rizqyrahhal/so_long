/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:10:45 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/14 11:32:17 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void    collect_number(t_game *game)
{
    int i;
    
    i = -1;
    while (++i < ft_strlen(game->map_len) && game->map_len[i])
        if (game->map_len[i] == 'C')
            game->all_coll++;
}
int main(int argc, char *argv[])
{
    t_game  game;

    map_read(argv[argc - 1], &game);
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64, "My_so_long 1337");
    game.img_player = mlx_xpm_file_to_image(game.mlx, IMAGE_PLAYER, &game.img_width, &game.img_height);
    game.img_exit = mlx_xpm_file_to_image(game.mlx, IMAGE_EXIT, &game.img_width, &game.img_height);
    game.img_coll = mlx_xpm_file_to_image(game.mlx, IMAGE_COLL, &game.img_width,&game.img_height);
    game.img_space = mlx_xpm_file_to_image(game.mlx, IMAGE_SPACE, &game.img_width,&game.img_height);
    game.img_wall = mlx_xpm_file_to_image(game.mlx, IMAGE_WALL, &game.img_width, &game.img_height);
    setting_img(game);
    collect_number(&game);
    printf("#######all_col = %d\n", game.all_coll);
    mlx_key_hook(game.win, key_hook, &game);
    // mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &press_key, &game);
    // mlx_mouse_hook(game.win, mouse_hook, &game);
    mlx_loop(game.mlx);
    return (0);
}





    // Puts a pixel on the screen :
    // mlx_pixel_put(solong.mlx, solong.win, 100, 200, 0xCD);
    // Puts a string on the location (x,y) in the given window:
    // mlx_string_put(solong.mlx, solong.win, 200, 100, 0xCD, "My_so_long 1337");