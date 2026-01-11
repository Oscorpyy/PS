/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:22:30 by lgoderne          #+#    #+#             */
/*   Updated: 2026/01/06 15:08:06 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define ERROR -1
# include "../../includes/ps.h"

int		is_args_good(char	**argv);
int		*init_all(t_stack *stack, char **argv, int argc);
int		get_len_stack(char	**str, int len_str);
int		*args_to_int(char **str, int strlen);
int		only_one(t_stack *stack);
int		only_num(char *str);
int		compare_execute(char *line, t_stack *stack);
char	**new_argv(char **argv, int *argc);
void	free_argv(char **new_argv, int argc);

#endif
