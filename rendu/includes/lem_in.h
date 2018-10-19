/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:35:05 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/19 02:36:26 by efouille         ###   ########.fr       */
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
# define E_EMPTY_LINE_ROOM -4
# define E_DUPLICATE_ROOM -4
# define E_WRONG_ROOM_NAME -5
# define E_WRONG_LINE -6

typedef struct		s_tube
{
	char			*connection;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_room
{
	struct s_room	**links;
	struct s_room	*next;
	struct s_tube	*tubes;
	char			*name;
	int				start;
	int				end;
}					t_room;

typedef struct		s_paths
{
	struct s_paths	*next;
	struct s_room	**a_path;
	int				size;
	int				id;
}					t_paths;

typedef struct		s_info
{
	t_paths			*first_path;
	t_room			*room;
	t_stack			*mark;
	char			*file;
	char			*buff;
	char			**split;
	int				ants;
	int				start;
	int				end;
	int				error_no_exit;
	int				nb_paths;

}					t_info;

//TEMPORY MAIN//
void				clean(t_info *info);

/*
** algo.c
*/
int 				find_path(t_info *info, t_room *start, t_stack**path);
/*
** tools_algo.c
*/
t_room				*get_room(t_info *info, char *s);
t_room				*get_starting_room(t_info *info);
int					ft_count_links(t_room *room);
/*
** node_path.c
*/
void				print_paths(t_paths *begin_node);
void				add_path(t_paths **begin_node, int id);
t_paths				*create_path(int id);
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
void				ft_throw_error_coc(int error, t_info *info);
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
