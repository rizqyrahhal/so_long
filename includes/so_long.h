/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:08:21 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/13 16:43:26 by rarahhal         ###   ########.fr       */
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

# define IMAGE_WALL     "./images/1.xpm"
# define IMAGE_SPACE    "./images/0.xpm"
# define IMAGE_COLL     "./images/C.xpm"
# define IMAGE_EXIT     "./images/E.xpm"
# define IMAGE_PLAYER   "./images/P.xpm"

typedef struct s_game
{
    // t_imge  *image;
    void    *mlx;
    void    *win;
    int     height;
    int     width;
    char    *map_len;
    int     all_coll;
    int     coll_cnt;
    int     walk_cnt;
}   t_game;

typedef struct s_imge
{
    void    *img_player;
    void    *img_exit;
    void    *img_coll;
    void    *img_space;
    void    *img_wall;
    int     img_height;
    int     img_width;
}   t_imge;

typedef struct s_param
{
    int x;
    int y;
}   t_param;

size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);


#endif
