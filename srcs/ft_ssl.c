/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 11:44:07 by jtranchi          #+#    #+#             */
/*   Updated: 2018/08/09 11:30:18 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"


int32_t g_s[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17,
	22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11, 16, 23,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10, 15, 21,
	6, 10, 15, 21, 6, 10, 15, 21};

int32_t g_k[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

void    print_bits(unsigned char octet)
{
	int z = 128, oct = octet;

	while (z > 0)
	{
		if (oct & z)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		z >>= 1;
	}
	ft_putchar('\n');
}

int		print_usage(char *str)
{
	ft_putstr("usage: ");
	ft_putstr(str);
	ft_putstr(" [hash] [command options] [command arguments]");
	return (-1);
}

char	*padding(char *str)
{
	char *message;
	int newlen;

	newlen = ft_strlen(str) + 1;
	while (newlen % 64 != 56)
		newlen++;


	message = (char *)malloc(sizeof(char) * newlen + 8);
#if (DEBUG == 1)
	printf("size malloced -> %zu\n", newlen);
#endif
	memcpy(message, str, ft_strlen(str));
	message[ft_strlen(str)] = 128;

}

int		main(int argc, char **argv)
{
	char *message;

	int h0 = 0x67452301;
	int h1 = 0xEFCDAB89;
	int h2 = 0x98BADCFE;
	int h3 = 0x10325476;
	if (argc < 2)
		return (print_usage(argv[0]));

	message = ft_padding(argv[1]);
	if (ft_strlen(argv[1]) % 64 !=  56)
	{
		int i = ft_strlen(argv[1]) - 1;
		while (++i <  (ft_strlen(argv[1]) + (56 - ft_strlen(argv[1]) % 64)))
			message[i] = 0;
		int blocs = (ft_strlen(argv[1]) + (64 - ft_strlen(argv[1]) % 64)) / 64;
#if (DEBUG == 1)
		printf("blocs -> %d\n",blocs);
#endif

	}
	return (0);
}