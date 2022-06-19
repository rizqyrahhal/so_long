/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ckeck_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:26:28 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/19 15:42:28 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include "../includes/get_next_line.h"

void	ft_check_extention(char *str)
{
	int	n;

	n = ft_strlen(str);
	if (str[n - 4] == '.' && str[n - 3] == 'b'
		&& str[n - 2] == 'e'
		&& str[n - 1] == 'r')
		return ;
	ft_error("CHECK_EXTENTION\n");
}

void	ft_check_file(char *str, t_game *game)
{
	ft_check_extention(str);
	game->fd = open(str, O_RDONLY);
	if (game->fd <= 0)
		ft_error("error in opening file\n");
	game->line = get_next_line_2(game->fd);
	if (!game->line)
		ft_error("Error in map (vide)\n");
	game->map_len = ft_strdup(game->line);
	free(game->line);
	while (game->line)
	{
		game->line = get_next_line_2(game->fd);
		if (game->line)
		{
			game->fr = game->map_len;
			game->map_len = ft_strjoin(game->fr, game->line);
			free(game->fr);
			free(game->line);
		}
	}
	if (game->map_len[ft_strlen(game->map_len) - 1] == '\n')
		ft_error("Map must be rectanguler.\n");
	free(game->map_len);
	close(game->fd);
}
