#include "green_red_light.h"

void	create_imgs(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img.back = mlx_new_image(game->mlx, 1280, 720);
	game->img.plant1 = mlx_new_image(game->mlx, 250, 720);
	game->img.plant2 = mlx_new_image(game->mlx, 250, 720);
	game->img.plant3 = mlx_new_image(game->mlx, 250, 720);
	game->img.bottom = mlx_new_image(game->mlx, 1280, 100);
	game->img.ninja1 = mlx_new_image(game->mlx, 460, 460);
	game->img.ninja2 = mlx_new_image(game->mlx, 460, 460);
	game->img.ninja3 = mlx_new_image(game->mlx, 460, 460);
	game->img.ninja4 = mlx_new_image(game->mlx, 460, 460);
	game->img.back = mlx_xpm_file_to_image(game->mlx, "img/back.xpm", &img_width, &img_height);
	game->img.plant1 = mlx_xpm_file_to_image(game->mlx, "img/plant1.xpm", &img_width, &img_height);
	game->img.plant2 = mlx_xpm_file_to_image(game->mlx, "img/plant1.xpm", &img_width, &img_height);
	game->img.plant3 = mlx_xpm_file_to_image(game->mlx, "img/plant1.xpm", &img_width, &img_height);
	game->img.bottom = mlx_xpm_file_to_image(game->mlx, "img/bottom.xpm", &img_width, &img_height);
	game->img.ninja1 = mlx_xpm_file_to_image(game->mlx, "img/ninja1.xpm", &img_width, &img_height);
	game->img.ninja2 = mlx_xpm_file_to_image(game->mlx, "img/ninja2.xpm", &img_width, &img_height);
	game->img.ninja3 = mlx_xpm_file_to_image(game->mlx, "img/ninja3.xpm", &img_width, &img_height);
	game->img.ninja4 = mlx_xpm_file_to_image(game->mlx, "img/ninja4.xpm", &img_width, &img_height);
}

void	create_digits(t_game *game)
{
	int	img_width;
	int	img_height;

	game->digits.zero = mlx_new_image(game->mlx, 50, 50);
	game->digits.one = mlx_new_image(game->mlx, 50, 50);
	game->digits.two = mlx_new_image(game->mlx, 50, 50);
	game->digits.three = mlx_new_image(game->mlx, 50, 50);
	game->digits.four = mlx_new_image(game->mlx, 50, 50);
	game->digits.five = mlx_new_image(game->mlx, 50, 50);
	game->digits.six = mlx_new_image(game->mlx, 50, 50);
	game->digits.seven = mlx_new_image(game->mlx, 50, 50);
	game->digits.eight = mlx_new_image(game->mlx, 50, 50);
	game->digits.nine = mlx_new_image(game->mlx, 50, 50);
	game->digits.zero = mlx_xpm_file_to_image(game->mlx, "img/0.xpm", &img_width, &img_height);
	game->digits.one = mlx_xpm_file_to_image(game->mlx, "img/1.xpm", &img_width, &img_height);
	game->digits.two = mlx_xpm_file_to_image(game->mlx, "img/2.xpm", &img_width, &img_height);
	game->digits.three = mlx_xpm_file_to_image(game->mlx, "img/3.xpm", &img_width, &img_height);
	game->digits.four = mlx_xpm_file_to_image(game->mlx, "img/4.xpm", &img_width, &img_height);
	game->digits.five = mlx_xpm_file_to_image(game->mlx, "img/5.xpm", &img_width, &img_height);
	game->digits.six = mlx_xpm_file_to_image(game->mlx, "img/6.xpm", &img_width, &img_height);
	game->digits.seven = mlx_xpm_file_to_image(game->mlx, "img/7.xpm", &img_width, &img_height);
	game->digits.eight = mlx_xpm_file_to_image(game->mlx, "img/8.xpm", &img_width, &img_height);
	game->digits.nine = mlx_xpm_file_to_image(game->mlx, "img/9.xpm", &img_width, &img_height);
}

