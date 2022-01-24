/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:30:08 by jdavis            #+#    #+#             */
/*   Updated: 2022/01/24 10:28:57 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_piece
{
	int					one_x;
	int					one_y;
	int					two_x;
	int					two_y;
	int					three_x;
	int					three_y;
	int					four_x;
	int					four_y;
}						t_piece;

typedef struct s_dif
{
	int					two_x;
	int					two_y;
	int					three_x;
	int					three_y;
	int					four_x;
	int					four_y;
}						t_dif;

typedef struct s_location
{
	int					s_x;
	int					s_y;
	int					tet_placing;
	int					offset;
	int					height;
	int					total;
	t_piece				*piece;
	t_dif				*dif;
	struct s_location	*next;
}						t_location;

int						ft_tetri_init(char **argv, char **board, int *i);
int						ft_tetri_check(char *line, int fd, char **board, int i);
t_location				*ft_tetri_collect(t_location *stats, char **tetri,
							int total_tetri, int i);
int						ft_find_square(int **square, t_location *stats);
void					ft_square_loop_x(int **square, t_location *stats,
							int *len, t_location *head);
int						ft_print_error(char **board, int i, t_location *stats);
t_location				*ft_statsdel_stats(t_location **stats,
							void (*del)(t_location *), t_location *new);
void					ft_statsdel_content(t_location *stats);
int						ft_free_line(char *line);

#endif
