/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:52:05 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/19 13:27:52 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	git_position(t_game *game, char c)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(game->map_len) && game->map_len[i])
		if (game->map_len[i] == c)
			break ;
	return (i);
}

void	move_w(t_game *game)
{
	game->p = git_position(game, 'P');
	if (game->map_len[game->p - game->width] == 'C')
		game->coll_cnt++;
	if (game->map_len[game->p - game->width] == 'E'
		&& game->all_coll == game->coll_cnt)
	{
		game->walk_cnt++;
		write(1, "done\n", 5);
		exit (EXIT_SUCCESS);
	}
	else if (game->map_len[game->p - game->width] != '1'
		&& game->map_len[game->p - game->width] != 'E'
		&& game->map_len[game->p - game->width] != 'N')
	{
		game->map_len[game->p] = '0';
		game->map_len[game->p - game->width] = 'P';
		game->walk_cnt++;
		setting_img(*game);
	}
	if (game->map_len[game->p - game->width] == 'N')
	{
		game->touch_enemy = 404;
		write(1, "lose\n", 5);
		exit(EXIT_FAILURE);
	}
}

void	move_a(t_game *game)
{
	game->p = git_position(game, 'P');
	if (game->map_len[game->p - 1] == 'C')
		game->coll_cnt++;
	if (game->map_len[game->p - 1] == 'E'
		&& game->all_coll == game->coll_cnt)
	{
		game->walk_cnt++;
		write(1, "done\n", 5);
		exit (EXIT_SUCCESS);
	}
	else if (game->map_len[game->p - 1] != '1'
		&& game->map_len[game->p - 1] != 'E'
		&& game->map_len[game->p - 1] != 'N')
	{
		game->map_len[game->p] = '0';
		game->map_len[game->p - 1] = 'P';
		game->walk_cnt++;
		setting_img(*game);
	}
	if (game->map_len[game->p - 1] == 'N')
	{
		game->touch_enemy = 404;
		write(1, "lose\n", 5);
		exit(EXIT_FAILURE);
	}
}

void	move_d(t_game *game)
{
	game->p = git_position(game, 'P');
	if (game->map_len[game->p + 1] == 'C')
		game->coll_cnt++;
	if (game->map_len[game->p + 1] == 'E'
		&& game->all_coll == game->coll_cnt)
	{
		game->walk_cnt++;
		write(1, "done\n", 5);
		exit (EXIT_SUCCESS);
	}
	else if (game->map_len[game->p + 1] != '1'
		&& game->map_len[game->p + 1] != 'E'
		&& game->map_len[game->p + 1] != 'N')
	{
		game->map_len[game->p] = '0';
		game->map_len[game->p + 1] = 'P';
		game->walk_cnt++;
		setting_img(*game);
	}
	if (game->map_len[game->p + 1] == 'N')
	{
		game->touch_enemy = 404;
		write(1, "lose\n", 5);
		exit(EXIT_FAILURE);
	}
}

void	move_s(t_game *game)
{
	game->p = git_position(game, 'P');
	if (game->map_len[game->p + game->width] == 'C')
		game->coll_cnt++;
	if (game->map_len[game->p + game->width] == 'E'
		&& game->all_coll == game->coll_cnt)
	{
		game->walk_cnt++;
		write(1, "done\n", 5);
		exit (EXIT_SUCCESS);
	}
	else if (game->map_len[game->p + game->width] != '1'
		&& game->map_len[game->p + game->width] != 'E'
		&& game->map_len[game->p + game->width] != 'N')
	{
		game->map_len[game->p] = '0';
		game->map_len[game->p + game->width] = 'P';
		game->walk_cnt++;
		setting_img(*game);
	}
	if (game->map_len[game->p + game->width] == 'N')
	{
		game->touch_enemy = 404;
		write(1, "lose\n", 5);
		exit(EXIT_FAILURE);
	}
}
