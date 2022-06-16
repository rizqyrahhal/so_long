/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:55:07 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/16 15:49:49 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long_bonus.h"

int key_hook(int key_code, t_game *game)
{
    if (key_code == KEY_ESC)
        exit(EXIT_SUCCESS);
    if (key_code == KEY_W && game->counter_enemy == 0)
        move_w(game);
    if (key_code == KEY_A && game->counter_enemy == 0)
        move_a(game);
    if (key_code == KEY_S && game->counter_enemy == 0)
        move_s(game);
    if (key_code == KEY_D && game->counter_enemy == 0)
        move_d(game);
    return (0);
}
