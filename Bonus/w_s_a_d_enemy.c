/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_s_a_d_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:26:46 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/18 13:51:39 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	w(t_game *game, int i)
{
	if (game->map_len[i - game->width] == 'P')
		exit(EXIT_FAILURE);
	game->map_len[i] = '0';
	game->map_len[i - game->width] = 'N';
	setting_enemy(game);
}

void	s(t_game *game)
{
	int	i;

	i = git_position(game, 'N');
	if (game->map_len[i + game->width] != '1'
		&& game->map_len[i + game->width] != 'C'
		&& game->map_len[i + game->width] != 'E')
	{
		if (game->map_len[i + game->width] == 'P')
			exit(EXIT_FAILURE);
		game->map_len[i] = '0';
		game->map_len[i + game->width] = 'N';
		setting_enemy(game);
	}
}

void	a(t_game *game)
{
	int	i;

	i = git_position(game, 'N');
	if (game->map_len[i - 1] != '1' && game->map_len[i - 1] != 'C'
		&& game->map_len[i - 1] != 'E')
	{
		if (game->map_len[i - 1] == 'P')
			exit(EXIT_FAILURE);
		game->map_len[i] = '0';
		game->map_len[i - 1] = 'N';
		setting_enemy(game);
	}
}

void	d(t_game *game)
{
	int	i;

	i = git_position(game, 'N');
	if (game->map_len[i + 1] != '1' && game->map_len[i + 1] != 'C'
		&& game->map_len[i + 1] != 'E')
	{
		if (game->map_len[i + 1] == 'P')
			exit(EXIT_FAILURE);
		game->map_len[i] = '0';
		game->map_len[i + 1] = 'N';
		setting_enemy(game);
	}
}
