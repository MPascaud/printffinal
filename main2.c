
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <kgricour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:35:58 by kgricour          #+#    #+#             */
/*   Updated: 2018/02/19 17:39:20 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
//#include  "srcs/ft_printf.h"
#include <locale.h>

int main(void)
{
		setlocale(LC_ALL, "");
		wchar_t *str = L"1 ☂ 2 € 3 ☯ 4 ∞ 5 ❤ 6 ♫ ";
	//	ft_printf("%5.2s is a string\n", "this");
	//	printf("%5.2s is a string\n", "this");
	//ft_printf("%hx", 4294967296);
	//  printf("%hx", 4294967296);
	//	ft_printf("%D\n", 1234567891011112);
	//	   printf("%D\n", 1234567891011112);
	//  ft_printf("%#x\n", 0);
	//    printf("%#x\n", 0);
	//	ft_printf("%.5x\n", 5427);
	//	   printf("%.5x\n", 5427);
	//   printf("%s");
//ft_printf("%s");
//printf("%hd\n", 444444442);
//ft_printf("%hd\n", 444444442);
//ft_printf("ft\n%03.2d\n", 1); 
//printf("\n%03.2d\n", 1); 
//ft_printf("%0+5d\n", 42);
//printf("%0+5d\n", 42);
//ft_printf("%0-7d\n", -42);
//printf("%0-7d\n", -42);
//ft_printf("%+0.0d\n", 4242);
//printf("%+0.0d\n", 4242);
//ft_printf("%+ d\n", -42);
//printf("%+ d\n", -42);
//printf("%d\n", 'c');
//ft_printf("%d\n", 'c');
//	   ft_printf(" coucou %-+10d %.10d %-05d\n", 5, 7 , 9984455);
//	   printf(" coucou %-+10d %.10d %-05d\n", 5, 7 , 9984455);
//	ft_printf("@moulitest: %.10d\n", -42);
//	   printf("@moulitest: %.10d\n", -42);
//		ft_printf("%03.2d\n", -1);
//		   printf("%03.2d\n", -1);
//ft_printf("ft %07d\n", 1234);
//	printf("pr %07d\n", 1234);
//ft_printf("%+10.7d\n", 4242);//----------------
//printf("%+10.7d\n", 4242);//---------
//	ft_printf("%03.2d\n", 1);
//	   printf("%03.2d\n", 1);
//		   ft_printf("ft%5d\n", -42);//--------
//		      printf("pr%5d\n", -42);//------
  //	ft_printf("%03.2d\n", -1);
//	 printf("%03.2d\n", -1);
/*		   printf("ld = %ld\n", -100000000000);
		ft_printf("ld = %ld\n", -100000000000);
		   printf("z = %zd\n", -100000000000);
		ft_printf("z = %zd\n", -100000000000);
		   printf("j = %jd\n", -100000000000);
		ft_printf("j = %jd\n", -100000000000);
		   printf("h = %hd\n", -100000000000);
		ft_printf("h = %hd\n", -100000000000);
		ft_printf("ft %+05d\n", 7);
		printf("pr %+05d\n", 7);*/
//	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
//	   printf("@moulitest: %#.x %#.0x\n", 0, 0);
//ft_printf("%5.2s\n", "coucou");
 // ft_printf("dfsfdsfsgdsfgd%c  gtrwtrtwrwrt\n", 0);
//		ft_printf("@mouli11test: %5.c %5.0c\n", 0, 0);
//		printf("@moulitest: %5.c %5.0c\n", 0, 0);
		//	ft_printf("%#08x\n", 42);
		//		printf("%#08x\n", 42);
		//	char *str = "coucou";
		//	ft_printf("->%U\n", 30000000000);
		//	ft_printf("%u\n", -1);
		//	   printf("%u\n", -1);
		//	   ft_printf("%.50lx\n", 4294967296);
		//	   printf("%.50lx\n", 4294967296);
		//	ft_printf("%X\n", 10);
		//	ft_printf("%x\n", 10);
		//	ft_printf("%b\n", "coucou");
		//	ft_printf("%o\n", 10);
//			ft_printf("%50S\n", str);
			   printf("%50S\n", str);
		//	ft_printf("%#08x\n", 42);
		//	printf("%#08x\n", 42);
		//	ft_printf("%#.x%#.0x\n", 0, 0);
		//	   printf("%#.x%#.0x\n", 0, 0);
		
	//	   double i = 3.123456789;
		//	ft_printf("coucou %s toi\n");
		//	   printf("coucou %s toi\n");
/*		ft_printf("%C\n", L'☂');
		ft_printf("% Z \n", "test");
		printf("% Z \n", "test");
		ft_printf("%10.  Z\n");
		printf("%10.   Z\n");
		ft_printf("%#.x %#.5x\n", 42, 42);
		ft_printf("ft hexa = %#X\n", 0);// ULLONG_MAX);
		printf("pr hexa = %#X\n", 0);// ULLONG_MAX);
		ft_printf("ft hexa = %#llx\n", 0);
		printf("pr hexa = %#llx\n", 0);
		ft_printf("ft hexa = %x\n", -999999999);
		printf("pr hexa = %x\n", -999999999);
*/
		printf("%C%C", L'☂', '1');
	//	ft_printf("\n");
/*		ft_printf("ft--->%% %5% %%%");
		ft_printf("\n");
		ft_printf("ft--->%-5%");
		ft_printf("\n");
		ft_printf("%s", "this is a string");
		ft_printf("\n");
		ft_printf("%s%s", "this is a string","k");
		ft_printf("\n");
		ft_printf("%s%s ", "this is a string","k");
		ft_printf("\n");
		ft_printf("%s ", "this is a string");
		ft_printf("%s %d%s   %  %%coucou %c %p %hhd toi %i", "salut", 12,"femme", 'c', 16, 777, 12, 1258);
		ft_printf("\n");
		printf("%s %d%s   %  %%coucou %c %p %hhd toi %i", "salut", 12,"femme", 'c', 16, 777, 12, 1258);
		ft_printf("\n");
		ft_printf("%x", 42);
		printf("%s%s", "this is a string","k");
		printf("%s \n", "this is a string");
		printf("%#.x %#.0x", 0, 0);
		long long int nbr = 245884445778;i
		ft_printf("ft_printf %%-5%%=> %-5% <\n");
		printf("   printf %%-5%%=> %-5% <\n");
		ft_printf("ft_printf %%05%%=> %05% <\n");
		printf("   printf %%05%%=> %05% <\n");
		ft_printf("ft_printf %%-05%%=> %05%  <\n");
		printf("   printf %%-05%%=> %05% <\n");
		ft_printf("----------------------------------------------------------------------\n");*/
		/*ft_printf("s: %s, p: %p, d:%d\n", "a string", &nbr, 42);
		printf("s: %s, p: %p, d:%d\n", "a string", &nbr, 42);*/
}
