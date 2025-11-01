/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminel-h <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:18:48 by aminel-h          #+#    #+#             */
/*   Updated: 2025/10/29 15:34:12 by aminel-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

int		check_n(char *s);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*read_line(int fd, char *saved);
char	*extract_line(char *saved);
char	*update_saved(char *saved);
char	*get_next_line(int fd);

#endif
