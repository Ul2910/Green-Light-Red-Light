#ifndef GREEN_RED_LIGHT_H

# define GREEN_RED_LIGHT_H

# include <stdbool.h> // typedef bool
# include <stdlib.h> // exit
# include <stdio.h> // printf
# include <unistd.h> // sleep
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
}
t_stop_game;

typedef struct s_img
{
	void	*back;
	void	*plant1;
	void	*plant2;
	void	*plant3;
	void	*bottom;
	void	*ninja1;
	void	*ninja2;
	void	*ninja3;
	void	*ninja4;
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
	int		time_x;
	int		meters_x;
}
t_digits;

typedef struct s_game
{
    int         meters_left;
    int         tmp_meters;
    bool        is_mini;
    int         time_left;
	void	    *mlx;
	void	    *mlx_win;
	t_img       img;
	t_digits    digits;
	time_t		seconds;
	time_t		finish_time;
	int			prev_key;
	
	int			bottom_x;
	int			plant1_x;
	int			plant2_x;
	int			plant3_x;
	int			mini_only;
	t_stop_game stop_game;
}
t_game;

void	create_imgs(t_game *game);
void	create_digits(t_game *game);
void	print_frame(t_game *game, int time_only);
int     key_hook(int key, t_game *game);
int     win_close(int keycode, t_game *game);
void	fill_struct(t_game *game);
int	    animation_time(t_game *game);
void	print_time(int n, t_game *game);
void	print_meters(int n, t_game *game);
void	digit_chooser(int n, t_game *game, int x);
void    lose_animation(t_game *game);
void    win_animation(t_game *game);


void    stop_game(int step_counter, int curr_position, int round_time, t_game *game);
void    init_t_stop_game(t_game *game);
int		stop_game_render_new_frame(t_game *game);
int		stop_game_check_result(t_game *game);
void	lose_game(void);
void	start_random_minigame(void);

#endif
