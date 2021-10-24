#include "green_red_light.h"

int	main(void)
{
	t_game	game;

	fill_struct(&game);
	srand(time(NULL));
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 1280, 720, "Green Light - Red Light");
	create_imgs(&game);
	create_digits(&game);
	init_t_stop_game(&game);
	init_t_balance_game(&game);
	mlx_loop_hook(game.mlx, print_start, &game);
	mlx_key_hook(game.mlx_win, key_hook, &game);
	mlx_hook(game.mlx_win, 17, 1L << 5, win_close, &game);
	mlx_loop(game.mlx);
}

void	print_frame(t_game *game, int time_only)
{
	static int step = 1;
	static int ruby_counter = 0;
	
	if (game->bottom_x == -1280)
		game->bottom_x = 0;
	if (game->plant1_x == -250)
		game->plant1_x = 1280;
	if (game->plant2_x == -250)
		game->plant2_x = 1280;
	if (game->plant3_x == -250)
		game->plant3_x = 1280;
	if (game->plant1_1_x == -250)
		game->plant1_1_x = 1280;
	if (game->plant2_2_x == -250)
		game->plant2_2_x = 1280;
	if (game->plant2_2_2_x == -250)
		game->plant2_2_2_x = 1280;
	if (game->plant3_3_x == -250)
		game->plant3_3_x = 1280;
	if (game->plant3_3_3_x == -250)
		game->plant3_3_3_x = 1280;
	if (game->plant3_3_3_3_x == -250)
		game->plant3_3_3_3_x = 1280;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.back, 0, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.plant3, game->plant3_x, 50);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.plant3, game->plant3_3_x, 50);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.plant3, game->plant3_3_3_x, 50);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.plant3, game->plant3_3_3_3_x, 50);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.plant2, game->plant2_x, 50);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.plant2, game->plant2_2_x, 50);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.plant2, game->plant2_2_2_x, 50);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.plant1, game->plant1_x, 50);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.plant1, game->plant1_1_x, 50);
	if (ruby_counter < 20)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ruby_green, game->ruby_x, game->ruby_y);
	else if (ruby_counter >= 20 && ruby_counter < 40)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ruby_green1, game->ruby_x, game->ruby_y);
	else if (ruby_counter >= 40 && ruby_counter < 60)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ruby_green2, game->ruby_x, game->ruby_y);
	ruby_counter++;
	if (ruby_counter > 59)
		ruby_counter = 0;
	if (step == 1)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ninja1, 410, 220);
		game->ruby_x = 787;
		game->ruby_y = 303;
	}
	else if (step == 2)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ninja2, 410, 220);
		game->ruby_x = 791;
		game->ruby_y = 293;
	}
	else if (step == 3)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ninja3, 410, 220);
		game->ruby_x = 792;
		game->ruby_y = 292;
	}
	else if (step == 4)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ninja4, 410, 220);
		game->ruby_x = 792;
		game->ruby_y = 304;
	}
	if (time_only == 0)
		step++;
	if (step > 4)
		step = 1;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.bottom, game->bottom_x, 625);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.bottom, game->bottom_x + 1280, 625);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->digits.m_left, 0, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->digits.t_left, 1000, 0);
	print_time(game->time_left, game);
	print_meters(game->meters_left, game);
	game->digits.time_x = 1130;
	game->digits.meters_x = 150;
	if (game->mini_only == 1)
		stop_game(game);
	else if (game->mini_only == 2)
		balance_game(game);
}


int	print_start(t_game *game)
{
	static int iter = 0;
	
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.start, 0, 0);
	if (iter < 10)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ruby_green_big, 1080, 130);
	else if (iter >= 10 && iter < 20)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ruby_green1_big, 1080, 130);
	else if (iter >= 20 && iter < 30)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ruby_green2_big, 1080, 130);
	else if (iter >= 30 && iter < 40)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ruby_green1_big, 1080, 130);
	else if (iter >= 40 && iter < 50)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ruby_green_big, 1080, 130);
	else if (iter >= 50 && iter < 60)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ruby_red, 1080, 130);
	else if (iter >= 60 && iter < 70)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ruby_red1, 1080, 130);
	else if (iter >= 70 && iter < 80)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ruby_red2, 1080, 130);
	else if (iter >= 80 && iter < 90)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ruby_red1, 1080, 130);
	else if (iter >= 90 && iter < 100)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ruby_red, 1080, 130);
	iter++;
	if (iter > 100)
		iter = 0;
	return 0;
}
