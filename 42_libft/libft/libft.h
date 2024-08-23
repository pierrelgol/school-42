/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierreollivier <plgol.perso@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:48:54 by pierreollivie     #+#    #+#             */
/*   Updated: 2023/07/07 17:49:01 by pierreollivie    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdint.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*content;
}					t_list;

# define PI 3.14159265358979323846
# define EPSILON 0.00001
# define E 2.71828182845904523536
# define STEPS 8

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				**ft_split(char const *s, char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);

/* ------------------------------ BONUS PART ------------------------------ */

int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *node);
void				ft_lstadd_back(t_list **lst, t_list *node);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/* ------------------------------------------------------------------------ */
/* -------------------------------- MATH_H -------------------------------- */

long				ft_abs(long n);
long				ft_pow(long n, long pow);
long				ft_log2n(long n);
long				ft_log10n(long n);
long				ft_fact(long n);
float				ft_absf(float n);
float				ft_powf(float n, int pow);
float				ft_factf(float n);
float				ft_sin(float n);
float				ft_cos(float n);
float				ft_tan(float n);
float				ft_asin(float n);
float				ft_atocs(float n);
float				ft_atan(float n);
float				ft_atan2(float y, float x);
double				ft_sqrt(double n);

/* ------------------------------------------------------------------------ */

void	ft_sort(void *data, size_t nel, size_t width, int (*compare)(const void *, const void *));

#endif
