#include "green_red_light.h"

int	key_hook(int key, t_game *game)
{
	//printf("%i\n", key);
	if (key == 53)
		win_close(53, game);
	else if ((key == 123 && game->prev_key == 124) ||
			 (key == 124 && game->prev_key == 123) ||
			 (key == 123 && game->prev_key == -100) ||
			 (key == 124 && game->prev_key == -100))
	{
		game->prev_key = key;
		if (game->is_mini == false && game->meters_left > 0) {
			game->bottom_x -= 5;
			game->tmp_meters++;
			if (game->tmp_meters % 2 == 0)
				game->plant1_x -= 5;
			if (game->tmp_meters % 4 == 0)
				game->plant2_x -= 3;
			if (game->tmp_meters % 6 == 0)
				game->plant3_x -= 2;
			game->meters_left--;
			print_frame(game, 0);
			//print_meters(game->meters_left, game);
		}
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
		mlx_destroy_image(game->mlx, game->img.plant1);
		mlx_destroy_image(game->mlx, game->img.plant2);
		mlx_destroy_image(game->mlx, game->img.plant3);
		mlx_destroy_image(game->mlx, game->img.bottom);
		mlx_destroy_image(game->mlx, game->img.ninja1);
		mlx_destroy_image(game->mlx, game->img.ninja2);
		mlx_destroy_image(game->mlx, game->img.ninja3);
		mlx_destroy_image(game->mlx, game->img.ninja4);
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
		mlx_destroy_window(game->mlx, game->mlx_win);
	}
	exit(0);
}
