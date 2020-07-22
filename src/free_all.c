#include "../include/cub3d.h"

int		free_struct(t_info *info, int code_return)
{
	close(info->fd);
	if (info->map)
	{
		free(info->map);
		info->map = 0;
	}
	return (code_return);
}

void		freeContentNode(void *line)
{
	if ((char *)line)
	{
		free((char *)line);
		line = 0;
	}
}

static	void	free_sprite()
{
	if (g_sprite.ptr)
	{
		free(g_sprite.path);
		g_sprite.path = 0;
		if (g_sprite.ptr)
		{
			mlx_destroy_image (g_mlx_ptr, g_sprite.ptr);
			g_sprite.ptr = 0;
			free(g_sprite.x);
			free(g_sprite.y);
			free(g_sprite.distance);
			free(g_sprite.buffer);
		}
	}
}

static	void	free_texture()
{
	int	i;

	i = -1;
	if (g_texture[0].texture_ptr)
	{
		while (++i < NUM_TEXTURE)
		{
			free(g_texture[i].path);
			mlx_destroy_image (g_mlx_ptr, g_texture[i].texture_ptr);
		}
	}
}

int		freeAll(int codeReturn)
{
	close(g_info->fd);
	ft_lstclear(&g_info->begin, &freeContentNode);
	free_struct(g_info, codeReturn);
	if (g_win_mlx)
	{
		mlx_clear_window(g_mlx_ptr, g_win_mlx);
		mlx_destroy_window(g_mlx_ptr, g_win_mlx);
		if (g_img_ptr)
			mlx_destroy_image (g_mlx_ptr, g_img_ptr);
		free_texture();
		free_sprite();
	}
	g_mlx_ptr = 0;
	g_win_mlx = 0;
	g_img_ptr = 0;
	g_info->begin = 0;
	return (codeReturn);
}
