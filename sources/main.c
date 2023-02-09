#include "../includes/minishell.h"

#include <string.h>

char *ft_replace_env(t_env **head, char *key)
{
	t_env *current = *head;

	while (current)
	{
		if (strcmp(current->key, key) == 0)
			return current->value;
		current = current->next;
	}
	return NULL;
}

char	**ft_expand(t_env **head, char	**cmds)
{
	int	i;
	int	j;


	i = 0;
	while (cmds[i])
	{
		j = 0;
		cmds[i] = ft_strchr(cmds[i], '$');
		if (cmds[i])
		{
			while (cmds[i][j] != ' ' && cmds[i][j])
				j++;
			cmds[i] = ft_replace_env(head, ft_substr(cmds[i], 1, j));
			printf("%s", cmds[i]);
		}
		i++;
	}

	return cmds;
}


int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	char	**salut;

	salut = malloc(sizeof(char *) * 3);
	salut[0] = "salu$tdsfdsf sfdsfd";
	salut[1] = "sfds$USER";
	salut[2] = NULL;

	data = malloc(sizeof(t_data));

	ft_parse_env(&data->head_env, envp);
	char	**test = ft_expand(&data->head_env, salut);

	for (int i = 0; test[i]; i++)
		printf("%s, ", test[i]);
	
}

	//  for (t_env *node = data->head_env; node; node = node->next)
    // printf("%s=%s\n", node->key, node->value);
