#ifndef GREEN_RED_LIGHT_H
# define GREEN_RED_LIGHT_H

# include <stdbool.h> // typedef bool
# include <stdlib.h> // exit
# include <stdio.h> // printf
# include <time.h> // time
# include <mlx.h>

typedef struct s_stop_game
{
    int     offset_to_triger_zone;
    int     triger_zone_len;
    int     curr_fit_position;
    void*   stop_game_window_img;
    void*   stop_game_target_img;
    void*   stop_game_fit_img;
    void*   stop_game_fon_img;
	void*	rules;
	bool	is_on_ground;
	int		timer;
}
t_stop_game;

typedef struct s_balance_game
{
    int     win_arr[12];
    int     timer;
    int     index;
    int     check_index;
    void*   window_img;
    void*   up_img;
    void*   down_img;
    void*   left_img;
    void*   right_img;
	void*	border_img;
	void*	rules;
	bool	lock;
	int		result;
	int		ready;
	int		skip_index;
}
t_balance_game;

typedef struct s_img
{
	void	*back;
	void	*start;
	void	*win;
	void	*lose;
	void	*plant1;
	void	*plant2;
	void	*plant3;
	void	*bottom;
	void	*ninja1;
	void	*ninja2;
	void	*ninja3;
	void	*ninja4;
	void	*ruby_green;
	void	*ruby_green1;
	void	*ruby_green2;
	void	*ruby_red;
	void	*ruby_red1;
	void	*ruby_red2;
	void	*ruby_green_big;
	void	*ruby_green1_big;
	void	*ruby_green2_big;
}
t_img;

typedef struct s_digits
{
	void	*zero;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*nine;
	void	*m_left;
	void	*t_left;
	int		time_x;
	int		meters_x;
}
t_digits;

typedef struct s_game
{
    int         	meters_left;
    int         	tmp_meters;
    int         	time_left;
	void	    	*mlx;
	void	    	*mlx_win;
	t_img       	img;
	t_digits    	digits;
	time_t			seconds;
	time_t			finish_time;
	int				prev_key;
	int				bottom_x;
	int				plant1_x;
	int				plant2_x;
	int				plant3_x;
	int				plant1_1_x;
	int				plant2_2_x;
	int				plant2_2_2_x;
	int				plant3_3_x;
	int				plant3_3_3_x;
	int				plant3_3_3_3_x;
	int				ruby_x;
	int				ruby_y;
	int				mini_only;
	int				end_or_start;
	t_stop_game 	stop_game;
	t_balance_game	balance_game;
	int				minigame_start[3];
}
t_game;

void	create_imgs(t_game *game);
void	create_digits(t_game *game);
void	print_frame(t_game *game, int time_only);
int		print_start(t_game *game);
int     key_hook(int key, t_game *game);
int     win_close(int keycode, t_game *game);
void	fill_struct(t_game *game);
int	    animation_time(t_game *game);
void	print_time(int n, t_game *game);
void	print_meters(int n, t_game *game);
void	digit_chooser(int n, t_game *game, int x);
void    print_lose(t_game *game);
void    print_win(t_game *game);


void    stop_game(t_game *game);
void    init_t_stop_game(t_game *game);
int		stop_game_check_result(t_game *game);
void	balance_game(t_game *game);
void	init_t_balance_game(t_game *game);
int		balance_game_check_result(int key, t_game *game);
void	start_random_minigame(t_game *game);
void	exit_minigame(t_game *game);

#endif
