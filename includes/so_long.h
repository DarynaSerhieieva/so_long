
#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdbool.h>

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
	void	*player;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*start;
	void	*backgraund;
}				t_list;

// map_generator
// t_map	map_generator(const char *link);
int	map_generator(const char *link, t_map *map);
int		main(int argc, char **argv);
int		is_rectangular(t_map *map, int current_len);
int		map_clone(t_map *map);
int		set_visited(t_map *map);
int		check_up_first_last(char *line);
void	dfs(t_map *map, int x, int y);

#endif
