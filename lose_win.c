#include "green_red_light.h"

void    print_win(t_game *game)
{
    game->end_or_start = 1;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.win, 0, 0);
}

void    print_lose(t_game *game)
{
    game->end_or_start = 1;
	printf("\007");
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.lose, 0, 0);
}
