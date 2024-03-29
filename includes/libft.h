/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 14:12:00 by kkraszew          #+#    #+#             */
/*   Updated: 2019/12/03 18:31:04 by kkraszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <wchar.h>
# include <stddef.h>
# define BUFF_SIZE 8

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_file
{
	int				fd;
	char			*content;
	char			*content_start;
}					t_file;

int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_iswspace(int c);
int					ft_xint(int c);
int					ft_isblank(int c);
int					ft_sqrt(int nb);
int					ft_get_next_line(int fd, char **line);
int					*ft_array_new(size_t size);
int					*ft_array_pop(int *arr, size_t size, unsigned int pos);
int					ft_array_max_value(int *arr, int length);
int					*ft_array_copy(const int *src, int *dst,
									size_t n_src, size_t n_dst);
int					*ft_array_rotate_left(int *arr, size_t size,
											unsigned int tms);
int					*ft_array_rotate_right(int *arr, size_t size,
											unsigned int tms);
int					ft_max(int x, int y);
int					ft_widelen(wchar_t arg);
int					ft_strchr_index(char *s, int c);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
								const char *needle, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_itoa_base(unsigned long long int val,
									int base, int lowcase);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar(char c);
void				ft_putnchar(int len, char c);
void				ft_putstr(const char *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr_free(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstaddfront(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstaddnext(t_list *lst, t_list *elm);
void				ft_lstprint(t_list *alst);
void				ft_print_bits(unsigned char octet);
void				ft_print_hex(size_t n);
void				ft_array_print(int *arr, size_t size, char *encl);
void				ft_puthex(unsigned int n, int *p);
void				ft_putuhex(unsigned int n, int *p);
void				ft_putull(unsigned long long n, int *p);
void				ft_putoct(unsigned int n, int *p);
void				ft_putunbr(unsigned int n, int *p);
void				ft_putadr(unsigned long n, int *p);
void				ft_putlong(long n, int *p);
void				ft_putwstrf(wchar_t *s, int *p);
void				ft_putstrf(char const *s, int *p);
void				ft_putnbrf(int n, int *p);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_numlen(int n);
size_t				ft_numulen(unsigned int n);
size_t				ft_ustrlen(const unsigned char *s);
size_t				ft_ustrnlen(const unsigned char *s, size_t max);
size_t				ft_abs(int n);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstpush(t_list *first, void *item);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
unsigned char		ft_swap_bits(unsigned char octet);
unsigned char		ft_reverse_bits(unsigned char octet);
unsigned char		*ft_strudup(char *s1);
unsigned char		*ft_ustrdup(unsigned char *s1);
int					len_wchar_single(wchar_t c);
int					len_wchar(wchar_t *wstr);
int					nlen_wchar(wchar_t *wstr, size_t len);
void				convert_wchar(unsigned char **new, wchar_t wc, size_t *i);
size_t				len_wuchart(unsigned char *str);
int					ft_maxlen_tab(char **tab, int index);
void				ft_printtab_fd(char **tab, int fd);
void				ft_printtab(char **tab);
unsigned long long	ft_numullen(unsigned long long n);

#endif
