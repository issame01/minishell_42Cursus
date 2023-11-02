/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idryab <idryab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:28:20 by osabir            #+#    #+#             */
/*   Updated: 2023/08/09 16:25:21 by idryab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include "./../minishell.h"

size_t				ft_strlen(const char *s);
char				*ft_strrchr(const char *s, int c);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
long long			ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strjoin(char *s1, char *s2);
char				*ft_charjoin(char *s1, char c);
size_t				ft_strlcat(char *dst, char *src, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *hay, const char *need, size_t len);
char				*ft_strtrim(char *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
char				*ft_strstr(const char *hay, const char *need);
int					ft_strcmp(const char *s1, const char *s2);
int					ft__doller(int c);
int					ft_cmp_to_str(const char *s1, const char *s2);

#endif
