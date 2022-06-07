/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:10:45 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/07 13:48:54 by rarahhal         ###   ########.fr       */
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

void    map_read(char   *filename, t_map *map)
{
    int     fd;
    char    *line;
    
    fd = open(filename, O_RDONLY);
    line = get_next_line(fd);
    map->height = 0;
    map->width = ft_strlen(line);
    map->str_line = ft_strdup(line);
    free(line);
    while(line)
    {
        map->height++;
        line = get_next_line(fd);
        if(line)
            map->str_line = ft_strjoin(map->str_line ,line);
        free(line);
    }
    close(fd);
}

void    setting_img(t_long *solong, t_imge *image, t_map *map)
{
    int hei;
    int wid;

    hei = 0;
    while (hei < image->img_height)
    {
        wid = 0;
        while (wid < image->img_width)
        {
            if (map->str_line[hei * image->img_width + wid] == '1')
                mlx_put_image_to_window(solong->mlx, solong->win, image->img_wall, wid * 64, hei * 64);
            else if (map->str_line[hei * image->img_width + wid] == 'C')
                mlx_put_image_to_window(solong->mlx, solong->win, image->img_coll, wid * 64, hei * 64);
            else if (map->str_line[hei * image->img_width + wid] == 'P')
                mlx_put_image_to_window(solong->mlx, solong->win, image->img_player, wid * 64, hei * 64);
            else if (map->str_line[hei * image->img_width + wid] == 'E')
                mlx_put_image_to_window(solong->mlx, solong->win, image->img_exit, wid * 64, hei * 64);
            else
                mlx_put_image_to_window(solong->mlx, solong->win, image->img_space, wid * 64, hei * 64);
            wid++;
        }
        hei++;
    }
}

int main(int argc, char *argv[])
{
    t_long  solong;
    t_imge  image;
    t_param param;
    t_map  map;

    param_init(&param);
    solong.mlx = mlx_init();
    solong.win = mlx_new_window(solong.mlx, 500, 250, "My_so_long 1337");
    map_read(argv[argc - 1], &map);
    image.img_player = mlx_xpm_file_to_image(solong.mlx, IMAGE_PLAYER, &image.img_width, &image.img_height);
    image.img_exit = mlx_xpm_file_to_image(solong.mlx, IMAGE_EXIT, &image.img_width, &image.img_height);
    image.img_coll = mlx_xpm_file_to_image(solong.mlx, IMAGE_COLL, &image.img_width, &image.img_height);
    image.img_space = mlx_xpm_file_to_image(solong.mlx, IMAGE_SPACE, &image.img_width, &image.img_height);
    image.img_wall = mlx_xpm_file_to_image(solong.mlx, IMAGE_WALL, &image.img_width, &image.img_height);
    setting_img(&solong, &image, &map);
    // mlx_put_image_to_window(solong.mlx, solong.win, image.img_player, 0, 0);
    // mlx_put_image_to_window(solong.mlx, solong.win, image.img_exit, 64, 0);
    // mlx_put_image_to_window(solong.mlx, solong.win, image.img_coll, 120, 0);
    // mlx_put_image_to_window(solong.mlx, solong.win, image.img_space, 0, 64);
    // mlx_put_image_to_window(solong.mlx, solong.win, image.img_wall, 0, 0);
    mlx_hook(solong.win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
    
    mlx_loop(solong.mlx);
    return (0);
}





    // Puts a pixel on the screen :
    // mlx_pixel_put(solong.mlx, solong.win, 100, 200, 0xCD);
    // Puts a string on the location (x,y) in the given window:
    // mlx_string_put(solong.mlx, solong.win, 200, 100, 0xCD, "My_so_long 1337");