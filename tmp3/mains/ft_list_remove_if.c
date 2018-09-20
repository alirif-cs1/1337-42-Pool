/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoulhafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 06:29:45 by zoulhafi          #+#    #+#             */
/*   Updated: 2018/09/19 13:04:35 by zoulhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_remove(t_list *begin_list, t_list *previous_list)
{
	if (previous_list != NULL)
		previous_list->next = begin_list->next;
	free(begin_list);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	*cpy;

	if (begin_list[0] != NULL)
	{
		cpy = begin_list[0];
		tmp = NULL;
		while (cpy->next != NULL)
		{
			if ((*cmp)(cpy->data, data_ref) == 0)
			{
				if (tmp == NULL)
					begin_list[0] = cpy->next;
				ft_remove(cpy, tmp);
			}
			else
				tmp = cpy;
			cpy = cpy->next;
		}
		if ((*cmp)(cpy->data, data_ref) == 0)
		{
			ft_remove(cpy, tmp);
			if (tmp != NULL)
				tmp->next = NULL;
			else
				begin_list[0] = NULL;
		}
	}
}
