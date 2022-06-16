/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:10:45 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/16 19:53:06 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long_bonus.h"

void    collect_number(t_game *game)
{
    int i;
    
    i = -1;
    while (++i < ft_strlen(game->map_len) && game->map_len[i])
        if (game->map_len[i] == 'C')
            game->all_coll++;
}

int exit_game(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
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
        mlx_put_image_to_window(game->mlx, game->win, game->img_space, 4 * 64, 2 * 64);
        mlx_put_image_to_window(game->mlx, game->win, game->img_enemy, 4 * 64, 2 * 64);
        // setting_img(*game);
    }
    i = -1;
    while (++i < ft_strlen(game->map_len) && game->map_len[i])   // git position of enemy
        if (game->map_len[i] == 'N')
            break ;
    if (game->map_len[i + game->width] != '1' && game->map_len[i + game->width] != 'C')
    {
        game->map_len[i] = '0';
        game->map_len[i + game->width] = 'N';
        mlx_put_image_to_window(game->mlx, game->win, game->img_space, 4 * 64, 2 * 64);
        mlx_put_image_to_window(game->mlx, game->win, game->img_enemy, 4 * 64, 2 * 64);
        // setting_img(*game);
    }
    // printf("%d\n", i);
}

int ft_animation(t_game *game)
{
    char *wlk;

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

    if (game->touch_enemy == 0)
        move_enemy(game);
    return (0);
}



int main(int argc, char *argv[])
{
    t_game  game;

    if (argc != 2)
        ft_error("Missing map!\n");
    map_read(argv[argc - 1], &game);
    game.mlx = mlx_init();
    game.counter_animation = 0;
    // game.counter_enemy = 0;
    game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64, "My_so_long 1337");
    game.img_player = mlx_xpm_file_to_image(game.mlx, IMAGE_PLAYER, &game.img_width, &game.img_height);
    game.img_exit = mlx_xpm_file_to_image(game.mlx, IMAGE_EXIT, &game.img_width, &game.img_height);
    game.img_coll = mlx_xpm_file_to_image(game.mlx, IMAGE_COLL, &game.img_width, &game.img_height);
    game.img_space = mlx_xpm_file_to_image(game.mlx, IMAGE_SPACE, &game.img_width, &game.img_height);
    game.img_wall = mlx_xpm_file_to_image(game.mlx, IMAGE_WALL, &game.img_width, &game.img_height);
    game.img_animation = mlx_xpm_file_to_image(game.mlx, IMAGE_ANIMATION, &game.img_width, &game.img_height);
    game.img_enemy = mlx_xpm_file_to_image(game.mlx, IMAGE_ENEMY, &game.img_width, &game.img_height);
    setting_img(game);
    collect_number(&game);
    mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, exit_game, &game);
    mlx_loop_hook(game.mlx, ft_animation, &game);
    mlx_key_hook(game.win, key_hook, &game);
    mlx_loop(game.mlx);
    return (0);
}
