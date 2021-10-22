#include "green_red_light.h"

int stop_game_check_result(t_game *game)
{
    int res;
    res  = 1;
    if (game->stop_game.curr_fit_position + 240 > game->stop_game.offset_to_triger_zone + game->stop_game.triger_zone_len ||
		game->stop_game.curr_fit_position + 240 < game->stop_game.offset_to_triger_zone)
	{
        lose_game();
        res = -1;
	}
    else
		start_random_minigame(game);
    return res;
}

void stop_game(t_game *game)
{
    int i;

    i = 0;
    if (game->stop_game.curr_fit_position > 700)
        lose_game();
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->stop_game.stop_game_window_img, 240, 60);
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->stop_game.stop_game_fit_img, 240 + game->stop_game.curr_fit_position, 60);
    game->stop_game.curr_fit_position += (800 - game->meters_left) / 100 + 1;
    while (i < game->stop_game.triger_zone_len - 50)
    {
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->stop_game.stop_game_target_img, game->stop_game.offset_to_triger_zone + i, 610);
        i += 50;
    }
}

void    init_t_stop_game(t_game *game)
{
    int         img_width;
    int         img_height;
    
    game->stop_game.stop_game_window_img = mlx_new_image(game->mlx, 800, 600);
    game->stop_game.stop_game_target_img = mlx_new_image(game->mlx, 50, 50);
    game->stop_game.stop_game_fit_img = mlx_new_image(game->mlx, 100, 100);
    game->stop_game.stop_game_fon_img = mlx_new_image(game->mlx, 100, 100);
    game->stop_game.stop_game_window_img = mlx_xpm_file_to_image(game->mlx, "img/stop_game_window.xpm", &img_width, &img_height);
    game->stop_game.stop_game_target_img = mlx_xpm_file_to_image(game->mlx, "img/stop_game_target.xpm", &img_width, &img_height);
    game->stop_game.stop_game_fit_img = mlx_xpm_file_to_image(game->mlx, "img/stop_game_fit.xpm", &img_width, &img_height);
    game->stop_game.stop_game_fon_img = mlx_xpm_file_to_image(game->mlx, "img/stop_game_fon.xpm", &img_width, &img_height);
    game->stop_game.curr_fit_position = 0;
}
       //                 tmp_meters      meters_left

void lose_game(void)
{
    printf("loose\n");
    exit(1);
}

void start_random_minigame(t_game *game)
{
    printf("win\n");
    game->mini_only = 0;
    game->tmp_meters = 0;
}
