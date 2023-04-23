/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aotsala <aotsala@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:31:21 by aotsala           #+#    #+#             */
/*   Updated: 2023/04/21 10:05:15 by aotsala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

//-----------------------------------------------------------------------------

int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);

//-----------------------------------------------------------------------------

char	*ft_substr(char const *s, unsigned int start, int len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//-----------------------------------------------------------------------------

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_data
{
	va_list	args;
	int		width;
	int		pnt;
	int		precision;
	int		zero;
	int		dash;
	int		tl;
	int		plus;
	int		percent;
	int		space;
	int		hash;
}	t_data;

//-----------------------------------------------------------------------------

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

//-----------------------------------------------------------------------------
//                            ft_printf additions

int		ft_atoi_base(const char *str, int base);
char	*ft_itoa_hex(int nb);
char	*ft_uitoa(unsigned int nb);
char	*ft_ulitoa_hex(unsigned long long nb);
char	*ft_substr_v2(char *s, int start, int len, int p_null);

int		ft_printf(const char *str, ...);
int		printter(const char *str, t_data *tab);
int		formatter(t_data *tab, const char *str, int i);
void	doer(t_data *tab, const char *str, int i);

void	ft_print_c(t_data *tab);
void	ft_print_s(t_data *tab);
void	ft_print_d(t_data *tab);
void	ft_print_p(t_data *tab);
void	ft_print_u(t_data *tab);
void	ft_print_x(t_data *tab, int upper_yes);

t_data	*initialise_tab(t_data *tab);
char	ft_choose_mps(char c);
int		not_type(char c);
void	ft_print_pr(t_data *tab);
void	ft_print_spaces(int nb);
char	*ft_add_prefix(char	*a);
char	*ft_add_ps(t_data *tab, char *a);
char	*ft_fuck_this_stupid_rule(t_data *tab, char *anew, char *a);
char	*ft_print_null(char *a);

void	ft_print_s2(t_data *tab, char *a, int p_null);
char	*ft_malloc_zero_flag(t_data *tab, char *a);
char	*ft_add_zeros_flag(t_data *tab, char *a, char *anew);
char	*ft_malloc_for_zeros(t_data *tab, char *a);
char	*ft_add_zeros(t_data *tab, char *a, char *anew);
char	*ft_mega_iq_func(t_data *tab, char *a);
char	*ft_zero_flag_p(t_data *tab, char *a);
char	*ft_zero_flag_p_add(t_data *tab, char *a);
char	*ft_zeros_p(t_data *tab, char *a);
char	*ft_to_upper_x(char	*a);

//-----------------------------------------------------------------------------
//								later additions

double	ft_atof(const char *str);

#endif
