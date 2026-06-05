/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 20:44:44 by fpaluku           #+#    #+#             */
/*   Updated: 2026/06/05 10:46:14 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define STRAT_ADAPTIVE 0
# define STRAT_SIMPLE   1
# define STRAT_MEDIUM   2
# define STRAT_COMPLEX  3
# define OP_SA 0
# define OP_SB 1
# define OP_SS 2
# define OP_PA 3
# define OP_PB 4
# define OP_RA 5
# define OP_RB 6
# define OP_RR 7
# define OP_RRA 8
# define OP_RRB 9
# define OP_RRR 10

typedef struct s_options
{
	int		bench;
	int		strategy;
	int		error;
	char	**args;
	int		count;
	int		split;
}	t_options;

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_list;

typedef struct s_wrapper
{
	t_list	*a;
	t_list	*b;
	int		bench;
	int		strategy;
	double	disorder;
	int		total_ops;
	int		ops[11];
}	t_wrapper;

int			valid(int argc, char **argv);
int			is_num(char *str);
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
char		**ft_split(char const *s, char c);
int			is_sep(char ch, char c);
t_wrapper	*stack(char **str);
t_options	parse_args(int argc, char **argv);
void		add_bottom(t_list *list, int n);
void		put_index(t_wrapper *wrapper);
void		n2(t_wrapper *wrapper);
void		medium(t_wrapper *wrapper);
void		rotate_a_to(t_wrapper *wrapper, int pos);
void		rotate_b_to(t_wrapper *wrapper, int pos);
int			lowest(t_list *a);
double		mistakes(t_list *a);
void		pa(t_wrapper *wrapper);
void		pb(t_wrapper *wrapper);
void		sa(t_wrapper *wrapper);
void		sb(t_wrapper *wrapper);
void		ss(t_wrapper *wrapper);
void		ra(t_wrapper *wrapper);
void		rb(t_wrapper *wrapper);
void		rr(t_wrapper *wrapper);
void		rra(t_wrapper *wrapper);
void		rrb(t_wrapper *wrapper);
void		rrr(t_wrapper *wrapper);
void		complex(t_wrapper *wrapper);
int			max_bits(t_list *a);
void		flags(t_wrapper *wrapper);
int			ft_strcmp(char *s1, char *s2);
int			is_sorted(t_list *a);
void		print_op(t_wrapper *wrapper, char *op, int len, int id);
void		print_bench(t_wrapper *wrapper);
void		print_first_counts(t_wrapper *wrapper);
void		print_second_counts(t_wrapper *wrapper);
void		free_wrapper(t_wrapper *wrapper);
void		free_args(t_options opt);

#endif
