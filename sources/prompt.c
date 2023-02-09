#include "../includes/minishell.h"

void	add_front(t_list **list, int value, int index)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->value = value;
	new->index = index;
	new->next = *list;
	*list = new;
}

void	add_back(t_list **list, int value, int index)
{
	t_list	*new;
	t_list	*temp;

	temp = *list;
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->value = value;
	new->index = index;
	new->next = NULL;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	del_front(t_list **list)
{
	t_list	*temp;

	temp = *list;
	*list = temp->next;
	free(temp);
}

void	del_back(t_list **list)
{
	t_list	*temp;

	temp = *list;
	while (temp->next->next)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
}

void	free_list(t_list *list)
{
	t_list	*temp;

	while (list)
	{
		temp = list;
		list = temp->next;
		free(temp);
	}
}