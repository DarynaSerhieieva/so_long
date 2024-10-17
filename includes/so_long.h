
#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>

typedef struct s_map
{
	char	*line;
	char	*last_line;
	int		pos;
	int		exit;
	int		coll;
	int		first_len;
	int		current_len;
}	t_map;

typedef struct s_list
{
	void	*mlx;
	void	*win;
}				t_list;

int	map_render(const char *map);
int	main(int argc, char **argv);

#endif
