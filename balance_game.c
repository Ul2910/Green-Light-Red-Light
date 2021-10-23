#include "green_red_light.h"
//1280x720

// stop game -
// window - 600x374
// fit - 220x200
// ground - 75x75
// grass 600x75


// balance game - 20 ~sec
// window 600x374
// border 520x240
// up down 100x50
// left right 50x100

void init_t_balance_game(t_game *game)
{
    int         img_width;
    int         img_height;
    int         i;
    
    i = 0;
    game->balance_game.window_img = mlx_new_image(game->mlx, 600, 374);
    game->balance_game.up_img = mlx_new_image(game->mlx, 100, 50);
    game->balance_game.down_img = mlx_new_image(game->mlx, 100, 50);
    game->balance_game.left_img = mlx_new_image(game->mlx, 50, 100);
    game->balance_game.right_img = mlx_new_image(game->mlx, 50, 100);
    game->balance_game.border_img = mlx_new_image(game->mlx, 520, 240);
    game->balance_game.window_img = mlx_xpm_file_to_image(game->mlx, "xpm/mini_window2_back.xpm", &img_width, &img_height);
    game->balance_game.up_img = mlx_xpm_file_to_image(game->mlx, "xpm/filler_red.xpm", &img_width, &img_height);
    game->balance_game.down_img = mlx_xpm_file_to_image(game->mlx, "xpm/filler_green.xpm", &img_width, &img_height);
    game->balance_game.left_img = mlx_xpm_file_to_image(game->mlx, "xpm/filler_yellow.xpm", &img_width, &img_height);
    game->balance_game.right_img = mlx_xpm_file_to_image(game->mlx, "xpm/filler_pink.xpm", &img_width, &img_height);
    game->balance_game.border_img = mlx_xpm_file_to_image(game->mlx, "xpm/mini_window2.xpm", &img_width, &img_height);
    game->balance_game.timer = 0;
    game->balance_game.index = 0;
    game->balance_game.check_index = 0;
    game->balance_game.result = 0;
    game->balance_game.lock = true;
    while(i < 12)
    {
        game->balance_game.win_arr[i] = rand() % 8;
        i++;
    }
}
// up - 0, right - 1, down - 2, left - 3
// up - 4, right - 4, down - 6, left - 7
void render_target(int i, t_game *game)
{
    int x_coord[8] = {450, 570, 450, 380, 730, 850, 730, 660};
    int y_coord[8] = {204, 274, 394, 274, 204, 274, 394, 274};
    void* spr[8] = {game->balance_game.up_img, game->balance_game.right_img, game->balance_game.down_img, game->balance_game.left_img,
                    game->balance_game.up_img, game->balance_game.right_img, game->balance_game.down_img, game->balance_game.left_img};
    mlx_put_image_to_window(game->mlx, game->mlx_win, spr[i], x_coord[i], y_coord[i]);
}

void balance_game(t_game *game)
{
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->stop_game.stop_game_window_img, 340, 173);
    if (game->balance_game.timer > 1000 && game->balance_game.timer < 1750)
        render_target(game->balance_game.win_arr[game->balance_game.index], game);
    else if (game->balance_game.timer > 1750 && game->balance_game.timer < 2500)
        render_target(game->balance_game.win_arr[game->balance_game.index + 1], game);
    else if (game->balance_game.timer > 2500 && game->balance_game.timer < 3250)
        render_target(game->balance_game.win_arr[game->balance_game.index + 2], game);
    else if (game->balance_game.timer > 3250 && game->balance_game.timer < 4000)
        render_target(game->balance_game.win_arr[game->balance_game.index + 3], game);
    else if (game->balance_game.timer > 4000 && game->balance_game.timer < 7000) {
        game->balance_game.lock = false;
        game->balance_game.index += 4;
    }
    else if (game->balance_game.timer >= 7000) {
        game->balance_game.lock = true;
        game->balance_game.timer = 0;
    }
    game->balance_game.timer++;
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->balance_game.border_img, 380, 240); 
}

int balance_game_check_result(int key, t_game *game)
{
    int arr[8] = {0, 0, 0, 0, 126, 124, 125, 123};
    int i;

    i = 0;
    while(key != arr[i])
        i++;
    if (i == game->balance_game.win_arr[game->balance_game.check_index])
        game->balance_game.result++;
    game->balance_game.check_index++;
    if (game->balance_game.check_index > 11 && game->balance_game.result > 9)
        game->mini_only = 0;
    return game->balance_game.result;
}