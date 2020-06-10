#include "cub3d.h"

static		int check_first_line(int fd)
{
	char	*line;

	if (get_next_line(fd, &line) == ERROR)
	{
		ft_putstr_fd("Error\nmread failed\n", STDOUT);
		return (ERROR);
	}
	if (line[0] != '\0')
	{
		free(line);
		ft_putstr_fd("Error\nFirst line have to begin empty line\n", STDOUT);
		return (ERROR);
	}
	free(line);
	return (SUCCESS);
}
int			put_map_in_list(t_list **begin, int fd)
{
	int		return_gnl;
	t_list	*node;
	char	*line;

	if (check_first_line(fd) == ERROR)
		return (ERROR);
	return_gnl = 1;
	while (return_gnl)
	{
		if ((return_gnl = get_next_line(fd, &line)) == ERROR)
		{
			ft_putstr_fd("Error\nmread failed\n", STDOUT);
			return(freeAll(ERROR));
		}
		if (!(node = ft_lstnew(line)))
		{
			ft_putstr_fd("Error\nmalloc failed for create node\n", STDOUT);
			return(freeAll(ERROR));
		}
		ft_lstadd_back(begin, node);
	}
	return (SUCCESS);
}
