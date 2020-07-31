#include "cub3d.h"

void	remove_front(t_list **begin_list, void (*free_fct)(void *))
{
	t_list	*prev;

	prev = *begin_list;
	*begin_list = prev->next;
	(*free_fct)(prev->content);
	prev->content = 0;
	free(prev);
	prev = 0;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*next;

	if (!begin_list || !*begin_list)
		return ;
	if (!(*cmp)((*begin_list)->content, data_ref))
		remove_front(begin_list, free_fct);
	prev = *begin_list;
	next = (*begin_list)->next;
	while (prev)
	{
		if (next && !(*cmp)(next->content, data_ref))
		{
			prev->next = next->next;
			(*free_fct)(next->content);
			free(next);
			next = prev->next;
		}
		prev = prev->next;
		if (next)
		{
			/* printf("next->content : %s\n", (char *)next->content); */
			next = next->next;
		}
	}
	(void)prev;
	(void)next;
}
