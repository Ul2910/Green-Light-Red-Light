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
    game->balance_game.up_img = mlx_new_image(game->mlx, 48, 48);
    game->balance_game.down_img = mlx_new_image(game->mlx, 48, 48);
    game->balance_game.left_img = mlx_new_image(game->mlx, 48, 48);
    game->balance_game.right_img = mlx_new_image(game->mlx, 48, 48);
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
    int x_coord[8] = {631, 673, 630, 588, 784, 827, 785, 742};
    int y_coord[8] = {247, 288, 330, 290, 342, 382, 425, 384};
    void* spr[8] = {game->balance_game.up_img, game->balance_game.right_img, game->balance_game.down_img, game->balance_game.left_img,
                    game->balance_game.up_img, game->balance_game.right_img, game->balance_game.down_img, game->balance_game.left_img};
    mlx_put_image_to_window(game->mlx, game->mlx_win, spr[i], x_coord[i], y_coord[i]);
}

void balance_game(t_game *game)
{
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->stop_game.stop_game_window_img, 340, 173);
    if (game->balance_game.timer > 50 && game->balance_game.timer < 80)
        render_target(game->balance_game.win_arr[game->balance_game.index], game);
    else if (game->balance_game.timer > 85 && game->balance_game.timer < 115)
        render_target(game->balance_game.win_arr[game->balance_game.index + 1], game);
    else if (game->balance_game.timer > 120 && game->balance_game.timer < 150)
        render_target(game->balance_game.win_arr[game->balance_game.index + 2], game);
    else if (game->balance_game.timer > 155 && game->balance_game.timer < 180)
        render_target(game->balance_game.win_arr[game->balance_game.index + 3], game);
    else if (game->balance_game.timer > 180 && game->balance_game.timer < 310)
        game->balance_game.lock = false;
    else if (game->balance_game.timer >= 310) {
        game->balance_game.lock = true;
        game->balance_game.timer = -100;
        game->balance_game.index += 4;
        if (game->balance_game.index > 11)
            exit_minigame(game);
    }
    game->balance_game.timer++;
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->balance_game.border_img, 340, 173); 
}

void exit_minigame(t_game *game)
{
    if (game->balance_game.index > 11 && game->balance_game.result > 9)
        game->mini_only = 0;
    else if (game->balance_game.index > 11 && game->balance_game.result < 10)
        lose_game();
}

int balance_game_check_result(int key, t_game *game)
{
    int arr[8] = {13, 2, 1, 0, 126, 124, 125, 123};
    int i;

    i = 0;
    while(key != arr[i])
        i++;
    if (i == game->balance_game.win_arr[game->balance_game.check_index])
        game->balance_game.result++;
    game->balance_game.check_index++;
    exit_minigame(game);
    return game->balance_game.result;
}