#include "green_red_light.h"

void	fill_struct(t_game *game)
{
	game->prev_key = -100;
	game->meters_left = 800;
	game->tmp_meters = 0;
	game->is_mini = false;
	game->time_left = 120;
	game->digits.time_x = 1130;
	game->digits.meters_x = 150;
	game->seconds = time(NULL);
	game->finish_time = game->seconds + 120;
	game->mini_only = 0;
	
	game->bottom_x = 0;
	game->plant1_x = 0;
	game->plant2_x = 300;
	game->plant3_x = 700;
	game->ruby_x = 787;
	game->ruby_y = 303;

}
