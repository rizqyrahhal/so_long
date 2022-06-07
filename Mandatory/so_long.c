/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:10:45 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/07 12:06:11 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"
# include "../includes/get_next_line.h"

void    param_init(t_param *param)
{
    param->x = 3;
    param->y = 4;
}

int key_press(int keycode, t_param *param)
{
    // static int  a;
    
    // a = 0;
    if (keycode == KEY_W)
        param->y++;
    else if (keycode == KEY_S)
        param->y--;
    else if (keycode == KEY_A)
        param->x--;
    else if (keycode == KEY_D)
        param->x++;
    else if (keycode == KEY_ESC)
        exit (0);
    printf("x: %d, y: %d\n", param->x, param->y);
    return (0);
}

void    map_read(char   *filename, t_game *game)
{
    int     fd;
    char    *line;
    
    fd = open(filename, O_RDONLY);
    line = get_next_line(fd);
    game->hei = 0;
    game->wid = ft_strlen(line);
    game->str_line = ft_strdup(line);
    free(line);
    while(line)
    {
        game->hei++;
        line = get_next_line(fd);
        if(line)
            game->str_line = ft_strjoin(game->str_line ,line);
        free(line);
    }
    close(fd);
}

int main(int argc, char *argv[])
{
    t_long  solong;
    t_imge  image;
    t_param param;
    t_game  game;

    // param_init(&param);
    solong.mlx = mlx_init();
    solong.win = mlx_new_window(solong.mlx, 500, 250, "My_so_long 1337");
    image.img1 = mlx_xpm_file_to_image(solong.mlx, "./images/P.xpm", &image.img_wigth, &image.img_height);
    image.img2 = mlx_xpm_file_to_image(solong.mlx, "./images/E.xpm", &image.img_wigth, &image.img_height);
    image.img3 = mlx_xpm_file_to_image(solong.mlx, "./images/C.xpm", &image.img_wigth, &image.img_height);
    image.img4 = mlx_xpm_file_to_image(solong.mlx, "./images/0.xpm", &image.img_wigth, &image.img_height);
    image.img5 = mlx_xpm_file_to_image(solong.mlx, "./images/1.xpm", &image.img_wigth, &image.img_height);
    mlx_put_image_to_window(solong.mlx, solong.win, image.img1, 0, 0);
    mlx_put_image_to_window(solong.mlx, solong.win, image.img2, 64, 0);
    mlx_put_image_to_window(solong.mlx, solong.win, image.img3, 120, 0);
    mlx_put_image_to_window(solong.mlx, solong.win, image.img4, 0, 64);
    mlx_put_image_to_window(solong.mlx, solong.win, image.img5, 0, 0);
    mlx_hook(solong.win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
    
    map_read(argv[argc - 1], &game);
    
    mlx_loop(solong.mlx);
    return (0);
}





    // Puts a pixel on the screen :
    // mlx_pixel_put(solong.mlx, solong.win, 100, 200, 0xCD);
    // Puts a string on the location (x,y) in the given window:
    // mlx_string_put(solong.mlx, solong.win, 200, 100, 0xCD, "My_so_long 1337");