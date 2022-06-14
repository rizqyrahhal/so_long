/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:55:07 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/14 19:49:51 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long_bonus.h"


int key_hook(int key_code, t_game *game)
{
    if (key_code == KEY_ESC)
        exit(EXIT_SUCCESS);
    if (key_code == KEY_W)
        move_w(game);
     if (key_code == KEY_A)
            move_a(game);
     if (key_code == KEY_S)
            move_s(game);
     if (key_code == KEY_D)
            move_d(game);
    return (0);
}
