/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opernod <opernod@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:22:30 by lgoderne          #+#    #+#             */
/*   Updated: 2026/02/27 10:58:40 by opernod          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define ERROR -1
# include "../../includes/ps.h"

int		is_args_good(char	**argv);
int		get_len_stack(char	**str, int len_str);
int		*args_to_int(char **str, int strlen);
int		only_one(t_stack *stack);
int		only_num(char *str);
int		free_all(t_stack *stack, int i, char **final_argv, char	*joined);
int		compare_execute(char *line, t_stack *stack);
int		argc_updated(char **new_argv);
void	init_all(t_stack *stack, char **argv, int argc);
void	free_argv(char **new_argv, int argc);
char	*strjoin_all(int size, char **strs, char *sep);

#endif
