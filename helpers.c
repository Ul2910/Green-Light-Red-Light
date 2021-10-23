#include "green_red_light.h"

void	fill_struct(t_game *game)
{
	game->prev_key = -100;
	game->meters_left = 800;
	game->tmp_meters = 0;
	game->time_left = 120;
	game->digits.time_x = 1130;
	game->digits.meters_x = 150;
	game->seconds = time(NULL);
	game->finish_time = game->seconds + 120;
	game->mini_only = 0;
	game->end_or_start = 2;
	game->bottom_x = 0;
	game->plant1_x = 0;
	game->plant1_1_x = 600;
	game->plant2_x = 300;
	game->plant2_2_x = 700;
	game->plant2_2_2_x = 900;
	game->plant3_x = 100;
	game->plant3_3_x = 400;
	game->plant3_3_3_x = 800;
	game->plant3_3_3_3_x = 1100;
	game->ruby_x = 787;
	game->ruby_y = 303;

}
