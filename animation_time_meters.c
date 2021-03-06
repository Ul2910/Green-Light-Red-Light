#include "green_red_light.h"

int	animation_time(t_game *game)
{
	if (game->end_or_start == 0)
		game->seconds = time(NULL);
	game->time_left = game->finish_time - game->seconds;
	print_frame(game, 1);
	if (game->tmp_meters > 0 && game->mini_only == 0 && game->time_left == game->minigame_start[2])
	{
		fill_stop_game(game);
		fill_balance_game(game);
		game->stop_game.triger_zone_len = 400 / 100 * (100 - game->tmp_meters * 100 / ((120 - game->time_left) * 22));
		game->stop_game.offset_to_triger_zone = 540 + rand() % (400 - game->stop_game.triger_zone_len);
		game->mini_only = 1;
	}
	if (game->tmp_meters > 0 && game->mini_only == 0
		&& (game->time_left == game->minigame_start[1] || game->time_left == game->minigame_start[0]))
	{
		fill_stop_game(game);
		fill_balance_game(game);
		game->stop_game.triger_zone_len = 400 / 100 * (100 - game->tmp_meters * 100 / ((120 - game->time_left) * 10));
		game->stop_game.offset_to_triger_zone = 540 + rand() % (400 - game->stop_game.triger_zone_len);
		game->mini_only = 1;
	}
	if (game->time_left <= 0 && game->meters_left > 0)
		print_lose(game);
	else if (game->time_left > 0 && game->meters_left <= 0)
		print_win(game);
	return (0);
}

void	print_time(int n, t_game *game)
{
	int	choose_tile;

	if (n >= 10)
	{
		print_time(n / 10, game);
		choose_tile = n % 10;
		digit_chooser(choose_tile, game, game->digits.time_x);
		game->digits.time_x = game->digits.time_x + 50;
	}
	else
	{
		choose_tile = n % 10;
		digit_chooser(choose_tile, game, game->digits.time_x);
		game->digits.time_x = game->digits.time_x + 50;
	}
}

void	print_meters(int n, t_game *game)
{
	int	choose_tile;

	if (n >= 10)
	{
		print_meters(n / 10, game);
		choose_tile = n % 10;
		digit_chooser(choose_tile, game, game->digits.meters_x);
		game->digits.meters_x = game->digits.meters_x + 50;
	}
	else
	{
		choose_tile = n % 10;
		digit_chooser(choose_tile, game, game->digits.meters_x);
		game->digits.meters_x = game->digits.meters_x + 50;
	}
}

void	digit_chooser(int n, t_game *game, int x)
{
	if (n == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->digits.zero, x, 0);
	else if (n == 1)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->digits.one, x, 0);
	else if (n == 2)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->digits.two, x, 0);
	else if (n == 3)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->digits.three, x, 0);
	else if (n == 4)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->digits.four, x, 0);
	else if (n == 5)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->digits.five, x, 0);
	else if (n == 6)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->digits.six, x, 0);
	else if (n == 7)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->digits.seven, x, 0);
	else if (n == 8)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->digits.eight, x, 0);
	else if (n == 9)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->digits.nine, x, 0);
}
