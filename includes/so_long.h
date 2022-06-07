/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:08:21 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/07 12:00:31 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

# define X_EVENT_KEY_PRESS      2
# define X_EVENT_KEY_RELEASE    3

# define KEY_ESC    53
# define KEY_W      13
# define KEY_A      0
# define KEY_S      1
# define KEY_D      2

typedef struct s_long
{
    void    *mlx;
    void    *win;
}   t_long;

typedef struct s_param
{
    int x;
    int y;
}   t_param;

typedef struct s_imge
{
    void    *img1;
    void    *img2;
    void    *img3;
    void    *img4;
    void    *img5;
    int     img_wigth;
    int     img_height;
}   t_imge;

typedef struct s_game
{
    int     hei;
    int     wid;
    char    *str_line;
}   t_game;

size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);


#endif
