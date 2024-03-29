/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:36:57 by ojessi            #+#    #+#             */
/*   Updated: 2019/07/15 14:36:58 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizualizer.h"

int		expose(void *param)
{
	t_ob	*ob;

	ob = param;
	(void)ob;
	exit(0);
	return (0);
}

int		keyboard(int key, t_ob *ob)
{
	if (key == 53)
		exit(0);
	(key == 124 && ob->speed < 30 && ob->stop) ? ob->speed++ : 0;
	(key == 123 && ob->speed > 1 && ob->stop) ? ob->speed-- : 0;
	if (key == 49)
		ob->stop = (ob->stop + 1) % 2;
	if (key == 15)
		ft_init_arr(ob);
	return (0);
}

int		draw(t_ob *ob)
{
	t_turn	*cur;
	int		i;
	int		k;

	cur = ob->cur;
	i = -1;
	k = 0;
	while (cur && cur->matr[++i])
		if (ob->arr[ft_atoi(cur->matr[i] + 1) - 1].x ==
		ft_get_x_room(ob->rooms, ft_strchr(cur->matr[i], '-') + 1) &&
		ob->arr[ft_atoi(cur->matr[i] + 1) - 1].y == ft_get_y_room(ob->rooms,
		ft_strchr(cur->matr[i], '-') + 1))
			k++;
	if (k == i)
		ob->cur = ft_move_turn_next(ob->cur, 1);
	if (ob->stop)
		ft_draw_turn(ob);
	return (0);
}

void	key_hook(t_ob *ob)
{
	mlx_hook(ob->win_ptr, 3, 0, keyboard, ob);
	mlx_loop_hook(ob->mlx_ptr, draw, ob);
	mlx_hook(ob->win_ptr, 17, 0, expose, ob);
}
