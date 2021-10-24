#include "green_red_light.h"

int stop_game_check_result(t_game *game)
{
    int res;

    res  = 1;
    if (game->stop_game.curr_fit_position + 340 + 110 > game->stop_game.offset_to_triger_zone + game->stop_game.triger_zone_len ||
		game->stop_game.curr_fit_position + 340 + 110 < game->stop_game.offset_to_triger_zone)
	{
        print_lose(game);
        res = -1;
	}
    else
    {
        game->stop_game.curr_fit_position = 0;
		start_random_minigame(game);
    }
    return res;
}

void stop_game(t_game *game)
{
    int i;
    int y_coord;

    i = 0;
    y_coord = 387;
    if (game->stop_game.curr_fit_position > 430)
        print_lose(game);
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->stop_game.stop_game_window_img, 340, 173);
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->balance_game.rules, 340, 36);
    while (i < game->stop_game.triger_zone_len)
    {
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->stop_game.stop_game_target_img, game->stop_game.offset_to_triger_zone + i, 472);
        i += 74;
    }
    if (!game->stop_game.is_on_ground)
    {
        game->stop_game.curr_fit_position += (800 - game->meters_left) / 100 + 1;
        mlx_put_image_to_window(game->mlx, game->mlx_win, game->stop_game.stop_game_fit_img, 340 + game->stop_game.curr_fit_position, 173);
    }
    else
    {
        if (game->stop_game.curr_fit_position + 340 + 110 > game->stop_game.offset_to_triger_zone + game->stop_game.triger_zone_len ||
		    game->stop_game.curr_fit_position + 340 + 110 < game->stop_game.offset_to_triger_zone)
            y_coord -= 40;
        if (game->stop_game.timer++ < 70)
            mlx_put_image_to_window(game->mlx, game->mlx_win, game->stop_game.stop_game_fit_img, game->stop_game.curr_fit_position + 340, y_coord);
        else
            stop_game_check_result(game);
    }
}

void    init_t_stop_game(t_game *game)
{
    int	img_width;
    int	img_height;

	game->stop_game.stop_game_window_img = mlx_new_image(game->mlx, 600, 374);
    game->stop_game.stop_game_target_img = mlx_new_image(game->mlx, 75, 75);
    game->stop_game.stop_game_fit_img = mlx_new_image(game->mlx, 220, 200);
    game->stop_game.rules = mlx_new_image(game->mlx, 600, 100);
    game->stop_game.stop_game_window_img = mlx_xpm_file_to_image(game->mlx, "xpm/mini_window.xpm", &img_width, &img_height);
    game->stop_game.stop_game_target_img = mlx_xpm_file_to_image(game->mlx, "xpm/earth.xpm", &img_width, &img_height);
    game->stop_game.stop_game_fit_img = mlx_xpm_file_to_image(game->mlx, "xpm/leg.xpm", &img_width, &img_height);
    game->stop_game.rules = mlx_xpm_file_to_image(game->mlx, "xpm/mini_info2.xpm", &img_width, &img_height);
    game->stop_game.curr_fit_position = 0;
    game->stop_game.is_on_ground = false;
    game->stop_game.timer = 0;
}

void start_random_minigame(t_game *game)
{
    game->mini_only = 2;
    game->tmp_meters = 0;
    game->stop_game.is_on_ground = false;
    game->stop_game.timer = 0;
}
