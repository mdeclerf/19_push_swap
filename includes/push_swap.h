/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeclerf <mdeclerf@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:08:31 by mdeclerf          #+#    #+#             */
/*   Updated: 2021/07/12 10:52:33 by mdeclerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# define BUFFER_SIZE 1

typedef struct s_list
{
	int				content;
	int				index;
	char			*binary;
	struct s_list	*next;
}	t_list;

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
}	t_stacks;

/*
** libft.c
*/
int				ft_putstr(char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_strlen(char *str);

/*
** ft_atoi.c
*/
long long int	ft_atoi(char *str);
int				ft_atoi_int( char *str);

/*
** errors.c
*/
int				check_double(char **argv);
int				check_digit(char **argv, int i);
int				ft_error(int argc, char **argv);

/*
** list_utils.c
*/
t_list			*ft_lstnew_index(int number, int i);
int				ft_lstsize(t_list *lst);
t_list			*ft_beforelstlast(t_list *lst);
t_list			*ft_lstlast(t_list *lst);

/*
** list_utils_bis.c
*/
t_list			*ft_lstadd_front(t_list *lst, t_list *new);
t_list			*ft_lstadd_back(t_list *lst, t_list *new);

/*
** struct_init_free.c
*/
t_stacks		*stacks_init(char **argv);
void			free_list(t_list *list);
void			free_stacks(t_stacks *stacks);

/*
** stacks_utils.c
*/
int				ft_order(t_stacks *stacks);
int				ft_order_list(t_list *list);
int				iteration_smallest(t_list *temp_b, int s);
int				index_smallest(t_stacks *stacks);

/*
** swap.c
*/
t_list			*ft_sa_sb(t_list *lst);
t_stacks		*ft_swap(t_stacks *stacks, char *arg);
t_stacks		*ft_swap_mute(t_stacks *stacks, char *arg);

/*
** push.c
*/
t_stacks		*ft_pa(t_stacks *stacks);
t_stacks		*ft_pb(t_stacks *stacks);
t_stacks		*ft_pa_mute(t_stacks *stacks);
t_stacks		*ft_pb_mute(t_stacks *stacks);

/*
** rotate.c
*/
t_list			*ft_ra_rb(t_list *list);
t_stacks		*ft_rotate(t_stacks *stacks, char *str);
t_stacks		*ft_rotate_mute(t_stacks *stacks, char *str);

/*
** rotateR.c
*/
t_list			*ft_rra_rrb(t_list *lst);
t_stacks		*ft_rotateR(t_stacks *stacks, char *arg);
t_stacks		*ft_rotateR_mute(t_stacks *stacks, char *arg);

/*
** two_three.c
*/
t_stacks		*two(t_stacks *stacks);
t_stacks		*three(t_stacks *stacks);
t_stacks		*three_bis(t_stacks *stacks);

/*
** four_five.c
*/
t_stacks		*four_five(t_stacks *stacks);

/*
** sort_big.c
*/
void			ft_lstiter(t_list *lst, int i);
t_stacks		*indexing(char **argv);
t_stacks		*association(t_stacks *stacks, t_stacks *copy);
t_stacks		*sort_big(t_stacks *stacks, int argc, int zero);

/*
** sort_big_mute_sort.c
*/
t_stacks		*three_mute(t_stacks *stacks);
t_stacks		*three_bis_mute(t_stacks *stacks);
t_stacks		*sort_mute_loop(t_stacks *copy);
t_stacks		*sort_mute(t_stacks *copy);

/*
** sort_big_binary.c
*/
int				binary_len(int number);
int				zero_count(int argc);
char			*ft_binary_convert(int number, int zero, t_stacks *stacks);
t_stacks		*binary(t_stacks *stacks, int zero);

/*
** checker.c
*/
t_stacks		*ft_operations(char *line, t_stacks *stacks);
int				instruction_loop(t_stacks *stacks, char *line);
int				ft_instruction_check(char *line);

/*
** get_next_line.c
*/
char			*ft_strjoin(char *s1, char *buf);
char			*get_next_line(char *line);

#endif
