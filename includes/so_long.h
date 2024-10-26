
#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdbool.h>
# include <../mlx_linux/mlx.h>

# ifndef SIZE_IMG
#  define SIZE_IMG 50
# endif

typedef struct s_map
{
	char	*line;
	char	**map;
	int		position;
	int		exit;
	int		collectible;
	int		cols;
	int		rows;
	int		player_x;
	int		player_y;
	bool	**visited;
	bool	*exit_found;
	bool	*valid;
}	t_map;

typedef struct s_list
{
	void	*mlx;
	void	*win;
	void	*player;
	void	*wall;
	void	*coll;
	void	*exit;
	void	*start;
	void	*grass;
}				t_list;

typedef struct s_data
{
	t_map	*map;
	t_list	*mlx;
}	t_data;
// so_long
int		main(int argc, char **argv);
int		handle_key(int keycode, t_data *data);
void	draw_map(t_data *data);


// map_generator
int		map_generator(const char *link, t_map *map);
int		map_check_up(int fd, t_map *map);
int		check_all_line(int fd, t_map *map);
int		check_each_char(t_map *map);
int		find_a_way(t_map *map);

// map_generator_utils
void	dfs(t_map *map, int x, int y);
int		set_visited(t_map *map);
int		check_up_first_last(char *line);
int		is_rectangular_walls(t_map *map, int current_len);
int		map_clone(t_map *map);

// ft_utils
void	ft_free_matrix(void **matrix, int size);
void	render_img(t_data *data);
int		ft_close_window(t_data *data);

// ft_move_actions
void	ft_move_player(t_data *data, int x, int y);
#endif
