#include "green_red_light.h"

int	main(void)
{
	t_game	game;

	fill_struct(&game);
	
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 1280, 720, "Green Light - Red Light");
	create_imgs(&game);
	create_digits(&game);
	init_t_stop_game(&game);
	print_frame(&game, 0);
	mlx_loop_hook(game.mlx, animation_time, &game);
	mlx_key_hook(game.mlx_win, key_hook, &game);
	mlx_hook(game.mlx_win, 17, 1L << 5, win_close, &game);
	mlx_loop(game.mlx);
}

void	print_frame(t_game *game, int time_only)
{
	static int step = 1;
	if (game->bottom_x == -1280)
		game->bottom_x = 0;
	if (game->plant1_x == -250)
		game->plant1_x = 1280;
	if (game->plant2_x == -250)
		game->plant2_x = 1280;
	if (game->plant3_x == -250)
		game->plant3_x = 1280;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.back, 0, 0);
	
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.plant3, game->plant3_x, 450);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.plant2, game->plant2_x, 250);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.plant1, game->plant1_x, 50);
	

	if (step == 1)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ninja1, 410, 260);
	else if (step == 2)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ninja2, 410, 260);
	else if (step == 3)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ninja3, 410, 260);
	else if (step == 4)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ninja4, 410, 260);
		
	if (time_only == 0)
		step++;
	if (step > 4)
		step = 1;
	
	
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.bottom, game->bottom_x, 625);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.bottom, game->bottom_x + 1280, 625);
	print_time(game->time_left, game);
	print_meters(game->meters_left, game);
	game->digits.time_x = 1130;
	game->digits.meters_x = 200;
	if (game->mini_only == 1) {
		game->stop_game.triger_zone_len = 800 / 100 * (100 - game->tmp_meters * 100 / 2 * 15);
		stop_game(21, 21, 5, game);
	}

}
