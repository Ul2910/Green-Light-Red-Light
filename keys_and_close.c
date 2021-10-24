#include "green_red_light.h"

int	key_hook(int key, t_game *game)
{
	if (key == 53)
		win_close(53, game);
	if (game->end_or_start == 2)
	{
		if (key == 49)
		{
			fill_struct(game);
			mlx_loop_hook(game->mlx, animation_time, game);
			game->end_or_start = 0;
		}
		return (0);
	}
	if (game->end_or_start == 1)
	{
		if (key == 49)
		{
			mlx_loop_hook(game->mlx, print_start, game);
			game->end_or_start = 2;
		}
		return (0);
	}
	if (game->mini_only == 1)
	{
		if (key == 49)
			game->stop_game.is_on_ground = true;
	}
	else if (game->mini_only == 2)
	{
		if (game->balance_game.lock == false)
			balance_game_check_result(key, game);
	}
	else if (game->meters_left > 0 && ((key == 123 && game->prev_key == 124)
			|| (key == 124 && game->prev_key == 123)
			|| (key == 123 && game->prev_key == -100)
			|| (key == 124 && game->prev_key == -100)))
	{
		game->prev_key = key;
		game->bottom_x -= 5;
		game->tmp_meters++;
		if (game->tmp_meters % 2 == 0)
		{
			game->plant1_x -= 5;
			game->plant1_1_x -= 5;
		}
		if (game->tmp_meters % 4 == 0)
		{
			game->plant2_x -= 4;
			game->plant2_2_x -= 4;
			game->plant2_2_2_x -= 4;
		}
		if (game->tmp_meters % 6 == 0)
		{
			game->plant3_x -= 1;
			game->plant3_3_x -= 1;
			game->plant3_3_3_x -= 1;
			game->plant3_3_3_3_x -= 1;
		}
		game->meters_left--;
		print_frame(game, 0);
	}
	else
		return (0);
	return (0);
}

int	win_close(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_destroy_image(game->mlx, game->img.back);
		mlx_destroy_image(game->mlx, game->img.start);
		mlx_destroy_image(game->mlx, game->img.win);
		mlx_destroy_image(game->mlx, game->img.lose);
		mlx_destroy_image(game->mlx, game->img.plant1);
		mlx_destroy_image(game->mlx, game->img.plant2);
		mlx_destroy_image(game->mlx, game->img.plant3);
		mlx_destroy_image(game->mlx, game->img.bottom);
		mlx_destroy_image(game->mlx, game->img.ninja1);
		mlx_destroy_image(game->mlx, game->img.ninja2);
		mlx_destroy_image(game->mlx, game->img.ninja3);
		mlx_destroy_image(game->mlx, game->img.ninja4);
		mlx_destroy_image(game->mlx, game->img.ruby_red);
		mlx_destroy_image(game->mlx, game->img.ruby_red1);
		mlx_destroy_image(game->mlx, game->img.ruby_red2);
		mlx_destroy_image(game->mlx, game->img.ruby_green);
		mlx_destroy_image(game->mlx, game->img.ruby_green1);
		mlx_destroy_image(game->mlx, game->img.ruby_green2);
		mlx_destroy_image(game->mlx, game->img.ruby_green_big);
		mlx_destroy_image(game->mlx, game->img.ruby_green1_big);
		mlx_destroy_image(game->mlx, game->img.ruby_green2_big);
		mlx_destroy_image(game->mlx, game->digits.zero);
		mlx_destroy_image(game->mlx, game->digits.one);
		mlx_destroy_image(game->mlx, game->digits.two);
		mlx_destroy_image(game->mlx, game->digits.three);
		mlx_destroy_image(game->mlx, game->digits.four);
		mlx_destroy_image(game->mlx, game->digits.five);
		mlx_destroy_image(game->mlx, game->digits.six);
		mlx_destroy_image(game->mlx, game->digits.seven);
		mlx_destroy_image(game->mlx, game->digits.eight);
		mlx_destroy_image(game->mlx, game->digits.nine);
		mlx_destroy_image(game->mlx, game->stop_game.stop_game_window_img);
		mlx_destroy_image(game->mlx, game->stop_game.stop_game_target_img);
		mlx_destroy_image(game->mlx, game->stop_game.stop_game_fit_img);
		mlx_destroy_image(game->mlx, game->stop_game.rules);
		mlx_destroy_image(game->mlx, game->balance_game.window_img);
		mlx_destroy_image(game->mlx, game->balance_game.up_img);
		mlx_destroy_image(game->mlx, game->balance_game.down_img);
		mlx_destroy_image(game->mlx, game->balance_game.left_img);
		mlx_destroy_image(game->mlx, game->balance_game.right_img);
		mlx_destroy_image(game->mlx, game->balance_game.border_img);
		mlx_destroy_image(game->mlx, game->balance_game.rules);
		mlx_destroy_window(game->mlx, game->mlx_win);
	}
	exit(0);
}
