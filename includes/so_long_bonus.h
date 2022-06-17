/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:08:21 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/17 12:21:01 by rarahhal         ###   ########.fr       */
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

# define IMAGE_WALL     "./images/image_bonus/1.xpm"
# define IMAGE_SPACE    "./images/image_bonus/0.xpm"
# define IMAGE_COLL     "./images/image_bonus/C.xpm"
# define IMAGE_EXIT     "./images/image_bonus/E.xpm"
# define IMAGE_PLAYER   "./images/image_bonus/P.xpm"
# define IMAGE_ANIMATION   "./images/image_bonus/A.xpm"
# define IMAGE_ENEMY   "./images/image_bonus/I.xpm"


typedef struct s_game
{
    void    *img_player;
    void    *img_exit;
    void    *img_coll;
    void    *img_space;
    void    *img_wall;
    void    *img_animation;
    void    *img_enemy;
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
    int     touch_enemy;
    int     counter_enemy;
    int     enemy;
    
}   t_game;


// libft
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);

// helper Function
void    map_read(char   *filename, t_game *game);
void    ft_error(char *error);
void    setting_img(t_game game);
int     key_hook(int key_code, t_game *game);
void    move_w(t_game *game);
void    move_a(t_game *game);
void    move_d(t_game *game);
void    move_s(t_game *game);
int     ft_animation(t_game *game);
void    move_enemy(t_game *game);










#endif
