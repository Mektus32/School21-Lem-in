/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 14:07:00 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/14 14:07:02 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_tmp_path(t_list_path **path_i, int c_path)
{
	int			i;
	t_list_path	*del;
	t_list_path	*tmp_i;

	if (!path_i || !*path_i)
		return ;
	i = 0;
	while (i < c_path)
	{
		tmp_i = *path_i + i;
		tmp_i = tmp_i->next;
		while (tmp_i)
		{
			del = tmp_i;
			tmp_i = tmp_i->next;
			free(del);
			del = NULL;
		}
		i++;
	}
	free(*path_i);
	*path_i = NULL;
}

void	ft_free_list_i(t_list_i **head)
{
	t_list_i	*list;
	t_list_i	*del;

	if (!head)
		return ;
	if (!*head)
		return ;
	list = *head;
	del = NULL;
	while (list)
	{
		del = list;
		list = list->next;
		if (del)
			free(del);
		del = NULL;
	}
	free(list);
	list = NULL;
	*head = list;
}

void	ft_free_list_down(t_list_down **head)
{
	t_list_down	*del;
	t_list_down	*list;
	t_list_i	*del_i;

	if (!head || !*head)
		return ;
	list = *head;
	while (list)
	{
		del = list;
		if (del->next)
		{
			del_i = del->next;
			ft_free_list_i(&del_i);
			del_i = NULL;
		}
		list = list->down;
		free(del);
		del = NULL;
	}
	free(list);
	list = NULL;
	*head = list;
}

void	ft_free_first_in_two_path(t_list_down **first)
{
	t_list_down	*list;
	t_list_down	*del_d;

	if (!first || !*first || !(*first)->down)
		return ;
	list = (*first);
	if (list->down)
	{
		del_d = list->down;
		ft_free_list_down(&del_d);
		del_d = NULL;
	}
	else
		del_d = NULL;
	*first = (*first)->right;
	free(list);
}

void	ft_free_list_room(t_room **head)
{
	t_room	*list;
	t_room	*del;

	if (!head)
		return ;
	if (!*head)
		return ;
	list = *head;
	while (list)
	{
		del = list;
		list = list->next;
		free(del->name);
		del->name = NULL;
		free(del);
		del = NULL;
	}
	*head = NULL;
}
