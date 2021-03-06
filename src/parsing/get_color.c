/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <mkayumba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:02:35 by user42            #+#    #+#             */
/*   Updated: 2020/08/09 14:30:08 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	char	*utile_get_value_color(char *line, int column)
{
	line += skip_number(line);
	line += skip_space(line);
	if (column < 2 && *line == ',')
		line += 1;
	else
	{
		line += skip_space(line);
		if (*line)
		{
			ft_putstr_fd("Error\nthere are trouble with color\n", STDOUT);
			return (0);
		}
	}
	return (line);
}

static char		*get_value_color(int *ptr, char *line, int column)
{
	if (!*line)
	{
		ft_putstr_fd("Error\nwrong format for color\n", STDOUT);
		return (0);
	}
	line += skip_space(line);
	if (ft_isdigit(*line))
	{
		*ptr = atoi(line);
		if ((*ptr & 255) != *ptr)
		{
			ft_putstr_fd("Error\ncolor number must be less than 255\n", STDOUT);
			return (0);
		}
	}
	else
	{
		ft_putstr_fd("Error\nwrong character for color\n", STDOUT);
		return (0);
	}
	return ((line = utile_get_value_color(line, column)));
}

int				get_color(t_list **begin, char *name, int *num_color)
{
	char		*line;
	t_list		*node;
	int			color[3];

	if (!(node = get_node(begin, name, 2)))
	{
		ft_putstr_fd("Error\nnot find color or format is wrong\n", STDOUT);
		return (ERROR);
	}
	line = node->content;
	line += 1;
	if (*line != ' ')
	{
		ft_putstr_fd("Error\ncolor first character must be spaces\n", STDOUT);
		return (ERROR);
	}
	if (!(line = get_value_color(&color[0], line, 0)))
		return (ERROR);
	if (!(line = get_value_color(&color[1], line, 1)))
		return (ERROR);
	if (!(line = get_value_color(&color[2], line, 2)))
		return (ERROR);
	*num_color = (((color[0]) << 16) + ((color[1]) << 8) + (color[2]));
	ft_list_remove_one_if(begin, node->content, &ft_strcmp, &free_content_node);
	return (SUCCESS);
}
