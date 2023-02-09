#ifndef MINISHELL_H
#define MINISHELL_H

#include "../libft/includes/libft.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_data
{
	t_env	*head_env;
}					t_data;


char	**ft_lexer(char const *s, char c);
void	ft_parse_env(t_env **head, char **envp);

#endif