
#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdbool.h>

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
	int		w;
	int		h;
	int		size;
	void	*player;
	void	*wall;
	void	*coll;
	void	*exit;
	void	*start;
	void	*grass;
	char	**map;
}				t_list;
// so_long
int		main(int argc, char **argv);

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
int		ft_close_window(t_list *mlx);

#endif
