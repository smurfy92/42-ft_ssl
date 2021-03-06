/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 11:08:41 by jtranchi          #+#    #+#             */
/*   Updated: 2018/08/28 18:20:42 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# define F(b, c, d) ((b & c) | (~b & d))
# define G(b, c, d) ((b & d) | (c & ~d))
# define H(b, c, d) (b ^ c ^ d)
# define I(b, c, d) (c ^ (b | ~d))
# define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))
# define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
# define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define SHR(x, n) ((x) >> n)
# define ROTR(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
# define A(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
# define B(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
# define C(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ SHR(x, 3))
# define D(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ SHR(x, 10))
# define HASH (const char*[3]){"md5", "sha256", NULL}
# define DEBUG 1
# define BUFFER 1024
# include <stdint.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include <errno.h>
# include <string.h>

typedef struct		s_mem
{
	unsigned char	*data;
	unsigned int	h[8];
	int				len;
}					t_mem;

typedef struct		s_arg
{
	char			*str;
	int				is_string;
	struct s_arg	*next;
}					t_arg;

typedef struct		s_opt
{
	int				hash;
	struct s_arg	*arg;
	int				p;
	int				q;
	int				r;
	int				s;
}					t_opt;

typedef struct		s_i
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	e;
	unsigned int	f;
	unsigned int	g;
	unsigned int	h;
	unsigned int	t;
	unsigned int	t2;
}					t_i;

typedef t_mem		*(*t_padding)(t_mem *mem);
typedef void		(*t_hash)(t_mem *mem);
typedef void		(*t_print)(t_mem *mem);

void				ft_free_mem(t_mem *mem);
t_mem				*ft_memjoin(t_mem *dest, t_mem *src);
t_mem				*read_fd(int fd);
void				write_fd(int fd, t_mem *mem);
int					print_usage(char *str);
void				print_output(t_mem *mem);
void				print_output_sha256(t_mem *mem);
void				write_file_error(char *file, t_opt *opt);
void				write_prefix(t_opt *opt, t_arg *arg);
void				write_suffix(t_arg *arg);
t_opt				*add_arg(t_opt *opt, char *str);
t_opt				*check_options(t_opt *opt, char *str);
t_opt				*check_opt(t_opt *opt, char **argv);
t_mem				*padding(t_mem *mem);
void				md5_process(t_i *m, uint32_t *w, int i);
void				hash_md5(t_mem *mem);
t_mem				*padding_sha256(t_mem *mem);
void				hash_sha256(t_mem *mem);
void				init_mem(t_mem *mem);
uint64_t			swap_uint64(uint64_t val);
#endif
