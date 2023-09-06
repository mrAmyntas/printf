/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_testmain.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: basz <basz@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 21:21:51 by basz          #+#    #+#                 */
/*   Updated: 2022/11/11 15:42:52 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"

// int		main(void)
// {
// 	int	ret;
// 	int ret2;

// 	printf("-------------------------------\n");
// 	ret = ft_printf("%*.*d hoi\n", 13, 10, 1234);
// 	printf("-------------------------------\n");
// 	ret2 = printf("%*.*d hoi\n", 13, 10, 1234);
// 	printf("-------------------------------\n");
// 	printf("ret value mine:%d\n", ret);
// 	printf("ret value real:%d\n", ret2);
// 	return (0);
// }


int main(void)
{
  int printed_chars = 0;
  int my_printed_chars = 0;


    printed_chars = printf("%u\n", -2);
    my_printed_chars = ft_printf("%u\n", -2);

  printf("\n(number of printed chars with system printf: %i)\n", printed_chars);
  printf("(number of printed chars with my ft_printf:  %d)\n", my_printed_chars);
  return (0);
}