/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenox <mkayumba@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:04:41 by lenox             #+#    #+#             */
/*   Updated: 2020/08/09 14:08:27 by lenox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "struct.h"
# include "raycasting.h"
# include "global.h"
# include "const.h"

void		free_list(void *line);
int			free_struct(t_info *info, int code_return);
int			free_all(int code_return);
int			parsing(t_info *info);
int			my_compare(char *s1, char *s2, size_t nbr_char);
int			skip_number(char *str);
int			skip_space(char *str);
int			get_window_size(t_list **begine);
t_list		*get_node(t_list **begin, char *search, int n);
int			get_color(t_list **begin, char *name, int *num_color);
int			get_image_path(t_list **begin, char *name, int n, char **dest);
int			delete_empty_line_map(t_list **begin);
int			put_the_same_number_of_column(t_list **begin);
int			check_file_extension(char *line, char *extension_name);
int			nb_cloumn(t_list *node);
int			check_character_around(char **map, int i, int j);
int			check_character_map(char *orientation);
void		delete_space_in_map(int column);
int			check_that_line_is_wall(char *line);
void		free_content_node(void *line);
void		init_global_variable();
void		load_ptr_textures_in_array(t_texture texture[NUM_TEXTURE]);
void		check_argument(t_info *info, int nb_arg, char **arg_array);
int			nb_line_and_nb_column(t_info *info);
#endif
