#include "green_red_light.h"

int stop_game_check_result(int keycode, t_stop_game *vars)
{
    int res;
    res  = 1;
    if (keycode != 49)
        res = 0;
    if (vars->curr_fit_position > vars->offset_to_triger_zone + vars->triger_zone_len ||
		vars->curr_fit_position < vars->offset_to_triger_zone)
	{
        lose_game();
        res = -1;
	}
    else
		start_random_nimigame();
    return res;
}

void stop_game_render_new_frame(t_game *game, t_stop_game *vars)
{
	//printf("Fuck\n");
	int i;
    i = vars->offset_to_triger_zone;
    mlx_put_image_to_window(game->mlx, game->mlx_win, vars->stop_game_window_img, 220, 60);
    mlx_put_image_to_window(game->mlx, game->mlx_win, vars->stop_game_fit_img, 220 + vars->curr_fit_position, 60);
    while (i < vars->triger_zone_len)
    {
        mlx_put_image_to_window(game->mlx, game->mlx_win, vars->stop_game_target_img, 220 + i, 610);
        i += 50;
    }
}

void    init_t_stop_game(t_stop_game* vars, t_game *game)
{
    int         img_width;
    int         img_height;
    srand(time(NULL));
    vars->offset_to_triger_zone = 300 - rand() % 150;
    vars->stop_game_window_img = mlx_new_image(game->mlx, 800, 600);
    vars->stop_game_target_img = mlx_new_image(game->mlx, 50, 50);
    vars->stop_game_fit_img = mlx_new_image(game->mlx, 100, 100);
    vars->stop_game_fon_img = mlx_new_image(game->mlx, 100, 100);
    vars->stop_game_window_img = mlx_xpm_file_to_image(game->mlx, "img/stop_game_window.xpm", &img_width, &img_height);
    vars->stop_game_target_img = mlx_xpm_file_to_image(game->mlx, "img/stop_game_target.xpm", &img_width, &img_height);
    vars->stop_game_fit_img = mlx_xpm_file_to_image(game->mlx, "img/stop_game_fit.xpm", &img_width, &img_height);
    vars->stop_game_fon_img = mlx_xpm_file_to_image(game->mlx, "img/stop_game_fon.xpm", &img_width, &img_height);
}

void    stop_game(int step_counter, int curr_position, int round_time, t_game *game)
{
    t_stop_game vars;
    //int         res;
    //int         offset_to_triger_zone;
    int         i;
    (void)curr_position;
    i = 0;
    vars.triger_zone_len = (round_time * 4 - step_counter) * 100 / 300; // (roundTime * ~ maxNumOfStrokPerSecond - stepCounter) * (%) / absoluteBarLen
    init_t_stop_game(&vars, game);
    while (i++ < 300)
    {
        usleep(100);
        vars.curr_fit_position = i;
        stop_game_render_new_frame(game, &vars);
    }
    lose_game();
    mlx_hook(game->mlx_win, 2, 1L<<0, stop_game_check_result, &vars);
}

void lose_game(void)
{
    printf("loose\n");
    exit(1);
}

void start_random_nimigame(void)
{
    printf("win\n");
    exit(1);
}

/*int main()
{
    int     step_counter = 10;
    int     curr_position = 20;
    int     round_time = 5;
    stop_game(step_counter, curr_position, round_time);
    return (0);
}
*/
