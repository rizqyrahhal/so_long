/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarahhal <rarahhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:10:45 by rarahhal          #+#    #+#             */
/*   Updated: 2022/06/13 21:16:39 by rarahhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"
# include "../includes/get_next_line.h"

// void    param_init(t_param *param)
// {
//     param->x = 3;
//     param->y = 4;
// }

// int key_press(int keycode, t_param *param)
// {
//     // static int  a;
    
//     // a = 0;
//     if (keycode == KEY_W)
//         param->y++;
//     else if (keycode == KEY_S)
//         param->y--;
//     else if (keycode == KEY_A)
//         param->x--;
//     else if (keycode == KEY_D)
//         param->x++;
//     else if (keycode == KEY_ESC)
//         exit (0);
//     printf("x: %d, y: %d\n", param->x, param->y);
//     return (0);
// }

void    map_read(char   *filename, t_game *game)
{
    int     fd;
    char    *line;

    fd = open(filename, O_RDONLY);
    line = get_next_line(fd);
    game->height = 0;
    game->width = ft_strlen(line);
    game->map_len = ft_strdup(line); 
    free(line);
    while(line)
    {
        game->height++;
        line = get_next_line(fd);
        if(line)
            game->map_len = ft_strjoin(game->map_len ,line);
        free(line);
    }
    free(line);
    close(fd);
}

void    setting_img(t_game game)
{
    int hei;
    int wid;

    hei = 0;
    // printf("height= %d\nwidth = %d\n", game.height, game.width);
    // printf("map_len: %s\n", game.map_len);
    // printf("map_len = %zu\n", ft_strlen(game.map_len));
    while (hei < game.height)
    {
       
        wid = 0;
        while (wid < game.width)
        {
            if (game.map_len[hei * game.width + wid] == '1')
                mlx_put_image_to_window(game.mlx, game.win, game.img_wall, wid * 64, hei * 64);
            else if (game.map_len[hei * game.width + wid] == 'C')
                mlx_put_image_to_window(game.mlx, game.win, game.img_coll, wid * 64, hei * 64);
            else if (game.map_len[hei * game.width + wid] == 'P')
                mlx_put_image_to_window(game.mlx, game.win, game.img_player, wid * 64, hei * 64);
            else if (game.map_len[hei * game.width + wid] == 'E')
               mlx_put_image_to_window(game.mlx, game.win, game.img_exit, wid * 64, hei * 64);
            else if (game.map_len[hei * game.width + wid] == '0')
                mlx_put_image_to_window(game.mlx, game.win, game.img_space, wid * 64, hei * 64);
            wid++;
        }
        hei++;
    }
}

void    move_w(t_game *game)
{
    int i;

    i = -1;
    printf("TTTTTTTTTT\n");
    game->all_coll = 1; // hard code
    game->walk_cnt = 0; // hard code
    while (++i < ft_strlen(game->map_len) && game->map_len[i])   // pour git position of playre
        if (game->map_len[i] == 'P')
            break ;
    printf("cntr to position playre = %d\n", i);
    printf("position: %c\n", game->map_len[i]);
    if (game->map_len[i - game->width] == 'C')
        game->coll_cnt++;
    if (game->map_len[i - game->width] == 'E' && game->all_coll == game->coll_cnt)
        exit (EXIT_SUCCESS);
    else if (game->map_len[i - game->width] != '1' && game->map_len[i - game->width] != 'E')
    {
        game->map_len[i] = '0';
        game->map_len[i - game->width] = 'P';
        game->walk_cnt++;
        printf("walk_cnt = %d\n", game->walk_cnt);
        setting_img(*game);
        
    }
}

int press_key(int key_code, t_game *game)
{
    if (key_code == KEY_ESC)
        exit(EXIT_SUCCESS);
    if (key_code == KEY_W)
        move_w(game);
    //  if (key_code == KEY_A)
    //         move_a(game);
    //  if (key_code == KEY_S)
    //         move_s(game);
    //  if (key_code == KEY_D)
    //         move_d(game);
    return (0);
}

int main(int argc, char *argv[])
{
    t_game  game;
    // t_param param;

    // param_init(&param);

    map_read(argv[argc - 1], &game);
    
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64, "My_so_long 1337");
    game.img_player = mlx_xpm_file_to_image(game.mlx, IMAGE_PLAYER, &game.img_width, &game.img_height);
    game.img_exit = mlx_xpm_file_to_image(game.mlx, IMAGE_EXIT, &game.img_width, &game.img_height);
    game.img_coll = mlx_xpm_file_to_image(game.mlx, IMAGE_COLL, &game.img_width,&game.img_height);
    game.img_space = mlx_xpm_file_to_image(game.mlx, IMAGE_SPACE, &game.img_width,&game.img_height);
    game.img_wall = mlx_xpm_file_to_image(game.mlx, IMAGE_WALL, &game.img_width, &game.img_height);
    setting_img(game);
    mlx_key_hook(game.win, &press_key, &game);
    // mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &press_key, &game);
    mlx_loop(game.mlx);
    return (0);
}





    // Puts a pixel on the screen :
    // mlx_pixel_put(solong.mlx, solong.win, 100, 200, 0xCD);
    // Puts a string on the location (x,y) in the given window:
    // mlx_string_put(solong.mlx, solong.win, 200, 100, 0xCD, "My_so_long 1337");