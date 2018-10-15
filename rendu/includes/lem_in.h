/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:35:05 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/15 13:09:34 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

# define TRUE 1
# define FALSE 0

# define E_WRONG_ANT_NUMBER -1
# define E_START_BEFORE_ANT -2
# define E_END_BEFORE_ANT -3

typedef struct		s_tube
{
	char			*connection;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_room
{
	char			*name;
	struct s_room	*next;
	t_tube			*tubes;
	int				start;
	int				end;
}					t_room;

typedef struct		s_info
{
	t_room			*room;
	char			*file;
	char			*buff;
	int				ants;
	int				start;
	int				end;
}					t_info;

/*
** parsing.c
*/
void				ft_search_ants(t_info *info);
void				ft_search_links(t_info *info);
void				ft_search_rooms(t_info *info);
/*
** tools_comments.c
*/
int					ft_iscomment(t_info *info);
int					ft_iscommand(t_info *info);
/*
** tools_ants.c
*/
int					ft_isant_number(t_info *info);
/*
** tools_common.c
*/
void				free_charofchar(char **table);
void				ft_saveline(t_info *info);
/*
** tools_rooms.c
*/
int					ft_isroom(t_info *info);
void				ft_setend(t_info *info);
void				ft_setstart(t_info *info);
int					ft_isvalid_room_name(char *s);
int					ft_isnumber(char *s);
/*
** tools_links.c
*/
int					ft_islink(t_info *info);
/*
** errors.c
*/
void				ft_throw_error(int error, t_info *info);
/*
** node.c
*/
t_room				*create_room(char *name);
void				add_room(t_room **begin_node, char *name);
t_tube				*create_tube(char *connection);
void				add_tube(t_tube **begin_node, char *connection);
/*
** run_through.c
*/
int					start_available(t_info *info);
int					end_available(t_info *info);
int					startend_available(t_info *info);
int					check_room_duplicates(t_info *info, char *name);

#endif
