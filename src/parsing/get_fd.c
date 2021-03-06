/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <mkayumba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 17:09:54 by user42            #+#    #+#             */
/*   Updated: 2020/08/09 14:27:32 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_file_descriptor(t_info *info, char *name_file)
{
	if ((info->fd = open(name_file, O_RDONLY)) < 0)
	{
		ft_putstr_fd("Error\nfailure open file\n", STDOUT);
		return (ERROR);
	}
	return (SUCCESS);
}
