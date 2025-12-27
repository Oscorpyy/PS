/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azazel <azazel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:22:30 by azazel            #+#    #+#             */
/*   Updated: 2025/12/27 18:54:49 by azazel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define ERROR -1
# include "../../includes/ps.h"

int	is_args_good(char	**argv);
int	*init_all(t_stack *stack, char **argv, int argc);
int	get_len_stack(char	**str, int len_str);
int	*args_to_int(char **str, int strlen);
int	only_one(t_stack *stack);
int	only_num(char *str);

#endif
