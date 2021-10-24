#include "green_red_light.h"

void	create_imgs(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img.back = mlx_new_image(game->mlx, 1280, 720);
	game->img.start = mlx_new_image(game->mlx, 1280, 720);
	game->img.win = mlx_new_image(game->mlx, 1280, 720);
	game->img.lose = mlx_new_image(game->mlx, 1280, 720);
	game->img.plant1 = mlx_new_image(game->mlx, 250, 670);
	game->img.plant2 = mlx_new_image(game->mlx, 250, 670);
	game->img.plant3 = mlx_new_image(game->mlx, 250, 670);
	game->img.bottom = mlx_new_image(game->mlx, 1280, 100);
	game->img.ninja1 = mlx_new_image(game->mlx, 460, 460);
	game->img.ninja2 = mlx_new_image(game->mlx, 460, 460);
	game->img.ninja3 = mlx_new_image(game->mlx, 460, 460);
	game->img.ninja4 = mlx_new_image(game->mlx, 460, 460);
	game->img.ruby_red = mlx_new_image(game->mlx, 200, 200);
	game->img.ruby_red1 = mlx_new_image(game->mlx, 200, 200);
	game->img.ruby_red2 = mlx_new_image(game->mlx, 200, 200);
	game->img.ruby_green_big = mlx_new_image(game->mlx, 200, 200);
	game->img.ruby_green1_big = mlx_new_image(game->mlx, 200, 200);
	game->img.ruby_green2_big = mlx_new_image(game->mlx, 200, 200);
	game->img.ruby_green = mlx_new_image(game->mlx, 100, 100);
	game->img.ruby_green1 = mlx_new_image(game->mlx, 100, 100);
	game->img.ruby_green2 = mlx_new_image(game->mlx, 100, 100);
	game->img.back = mlx_xpm_file_to_image(game->mlx, "xpm/back.xpm", &img_width, &img_height);
	game->img.start = mlx_xpm_file_to_image(game->mlx, "xpm/start.xpm", &img_width, &img_height);
	game->img.win = mlx_xpm_file_to_image(game->mlx, "xpm/win.xpm", &img_width, &img_height);
	game->img.lose = mlx_xpm_file_to_image(game->mlx, "xpm/lose.xpm", &img_width, &img_height);
	game->img.plant1 = mlx_xpm_file_to_image(game->mlx, "xpm/plant1.xpm", &img_width, &img_height);
	game->img.plant2 = mlx_xpm_file_to_image(game->mlx, "xpm/plant2.xpm", &img_width, &img_height);
	game->img.plant3 = mlx_xpm_file_to_image(game->mlx, "xpm/plant3.xpm", &img_width, &img_height);
	game->img.bottom = mlx_xpm_file_to_image(game->mlx, "xpm/bottom.xpm", &img_width, &img_height);
	game->img.ninja1 = mlx_xpm_file_to_image(game->mlx, "xpm/ninja1.xpm", &img_width, &img_height);
	game->img.ninja2 = mlx_xpm_file_to_image(game->mlx, "xpm/ninja2.xpm", &img_width, &img_height);
	game->img.ninja3 = mlx_xpm_file_to_image(game->mlx, "xpm/ninja3.xpm", &img_width, &img_height);
	game->img.ninja4 = mlx_xpm_file_to_image(game->mlx, "xpm/ninja4.xpm", &img_width, &img_height);
	game->img.ruby_red = mlx_xpm_file_to_image(game->mlx, "xpm/ruby_red.xpm", &img_width, &img_height);
	game->img.ruby_red1 = mlx_xpm_file_to_image(game->mlx, "xpm/ruby_red1.xpm", &img_width, &img_height);
	game->img.ruby_red2 = mlx_xpm_file_to_image(game->mlx, "xpm/ruby_red2.xpm", &img_width, &img_height);
	game->img.ruby_green_big = mlx_xpm_file_to_image(game->mlx, "xpm/ruby_green_big.xpm", &img_width, &img_height);
	game->img.ruby_green1_big = mlx_xpm_file_to_image(game->mlx, "xpm/ruby_green1_big.xpm", &img_width, &img_height);
	game->img.ruby_green2_big = mlx_xpm_file_to_image(game->mlx, "xpm/ruby_green2_big.xpm", &img_width, &img_height);
	game->img.ruby_green = mlx_xpm_file_to_image(game->mlx, "xpm/ruby_green.xpm", &img_width, &img_height);
	game->img.ruby_green1 = mlx_xpm_file_to_image(game->mlx, "xpm/ruby_green1.xpm", &img_width, &img_height);
	game->img.ruby_green2 = mlx_xpm_file_to_image(game->mlx, "xpm/ruby_green2.xpm", &img_width, &img_height);
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
	game->digits.m_left = mlx_new_image(game->mlx, 150, 50);
	game->digits.t_left = mlx_new_image(game->mlx, 150, 50);
	game->digits.zero = mlx_xpm_file_to_image(game->mlx, "xpm/0.xpm", &img_width, &img_height);
	game->digits.one = mlx_xpm_file_to_image(game->mlx, "xpm/1.xpm", &img_width, &img_height);
	game->digits.two = mlx_xpm_file_to_image(game->mlx, "xpm/2.xpm", &img_width, &img_height);
	game->digits.three = mlx_xpm_file_to_image(game->mlx, "xpm/3.xpm", &img_width, &img_height);
	game->digits.four = mlx_xpm_file_to_image(game->mlx, "xpm/4.xpm", &img_width, &img_height);
	game->digits.five = mlx_xpm_file_to_image(game->mlx, "xpm/5.xpm", &img_width, &img_height);
	game->digits.six = mlx_xpm_file_to_image(game->mlx, "xpm/6.xpm", &img_width, &img_height);
	game->digits.seven = mlx_xpm_file_to_image(game->mlx, "xpm/7.xpm", &img_width, &img_height);
	game->digits.eight = mlx_xpm_file_to_image(game->mlx, "xpm/8.xpm", &img_width, &img_height);
	game->digits.nine = mlx_xpm_file_to_image(game->mlx, "xpm/9.xpm", &img_width, &img_height);
	game->digits.m_left = mlx_xpm_file_to_image(game->mlx, "xpm/m_left.xpm", &img_width, &img_height);
	game->digits.t_left = mlx_xpm_file_to_image(game->mlx, "xpm/t_left.xpm", &img_width, &img_height);
}
