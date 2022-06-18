/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:10:45 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/18 14:15:39 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	collect_number(t_game *game)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(game->map_len) && game->map_len[i])
		if (game->map_len[i] == 'C')
			game->all_coll++;
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}

void	xpm_to_img(t_game *game)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, IMAGE_PLAYER,
			&game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, IMAGE_EXIT,
			&game->img_width, &game->img_height);
	game->img_coll = mlx_xpm_file_to_image(game->mlx, IMAGE_COLL,
			&game->img_width, &game->img_height);
	game->img_space = mlx_xpm_file_to_image(game->mlx, IMAGE_SPACE,
			&game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, IMAGE_WALL,
			&game->img_width, &game->img_height);
	game->img_animation = mlx_xpm_file_to_image(game->mlx, IMAGE_ANIMATION,
			&game->img_width, &game->img_height);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx, IMAGE_ENEMY,
			&game->img_width, &game->img_height);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		ft_error("Missing map!\n");
	map_read(argv[argc - 1], &game);
	game.mlx = mlx_init();
	game.counter_animation = 0;
	game.win = mlx_new_window(game.mlx, game.width * 64,
			game.height * 64, "My_so_long 1337");
	xpm_to_img(&game);
	collect_number(&game);
	setting_img(game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, exit_game, &game);
	mlx_loop_hook(game.mlx, ft_animation, &game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
