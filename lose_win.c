#include "green_red_light.h"

int		print_win(t_game *game)
{
	game->end_or_start = 1;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.win, 0, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->digits.t_left, 1000, 0);
	print_time(game->time_left, game);
	return (0);
}

int		print_lose(t_game *game)
{
	game->stop_game.curr_fit_position = 0;
	game->mini_only = 0;
	game->end_or_start = 1;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.lose, 0, 0);
	return (0);
}
