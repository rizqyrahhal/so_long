/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:08:21 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/14 19:34:16 by rarahhal         ###   ########.fr       */
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

# define X_EVENT_KEY_EXIT       17


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
# define IMAGE_PLAYER_MV   "./images/PP.xpm"


typedef struct s_game
{
    void    *img_player;
    void    *img_player_mv;
    void    *img_exit;
    void    *img_coll;
    void    *img_space;
    void    *img_wall;
    int     img_height;
    int     img_width;
    void    *mlx;
    void    *win;
    int     height;
    int     width;
    char    *map_len;
    int     all_coll;
    int     coll_cnt;
    int     walk_cnt;
    int     counter_animation;
}   t_game;


// libft
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);

// helper Function
void    map_read(char   *filename, t_game *game);
void    ft_error(char *error);
void    setting_img(t_game game);
int     key_hook(int key_code, t_game *game);
void    move_w(t_game *game);
void    move_a(t_game *game);
void    move_d(t_game *game);
void    move_s(t_game *game);







#endif
