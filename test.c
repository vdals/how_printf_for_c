/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:58:47 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/20 20:44:50 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //lib for help, delete before project completion
#include "ftprintf.h"
#include "ft_printf.c"
#include "print_symb.c"
#include "math_1.c"
#include "ft_print_base.c"
#include "ft_get_format.c"
#include "ft_shorter.c"
#include "ft_shorter_high.c"
#include "ft_hashnco.c"
#include "size_print.c"
#include "ft_strdup.c"
#include "ft_atoi.c"
#include "ft_strlen.c"
#include "ft_shorter_int.c"
#include "ft_get_format_int.c"
#include "ft_hashnco2.c"
#include "float.c"
#include "ft_shorter_float.c"
#include "ft_ltoa.c"
#include "ft_putchar.c"
#include "ft_shorter_high2.c"
#include "ft_shorter_int2.c"
#include "print_symb2.c"
#include "print_symb3.c"
#include "ft_shorter2.c"
#include "ft_shorter3.c"

int			main(void)
{

	char	*ptr0 = (char*)malloc(sizeof(int) * 3);
	int		*ptr1 = (int*)malloc(sizeof(int) * 3);
	int		check = 0;

	int		check1 = 2147483647;

	// check = printf("@moulitest: %.10d\n", -42);
	// printf("%i\n", check);
	// check = ft_printf("@moulitest: %.10d\n", -42);
	// printf("%i\n", check);

	printf(MAGENTA "\n --- TEST#01 --- \n\n" RESET);
	check = printf(CYAN"expected:hello %% %#1% %5 c, %  010  s, %lx, %030p %2% %10s.\n"RESET, 'f', "hello", ptr0, ptr0, NULL);
	printf("check:%i\n", check);
	check = ft_printf(CYAN"reality :hello %% %#1% %5 c, %  010  s, %lx, %030p %2% %10s.\n"RESET, 'f', "hello", ptr0, ptr0, NULL);
	printf(RED "check:%i\n" RESET, check);

	printf(GREEN "\n --- TEST#02 --- \n\n" RESET);
	check = printf("octal:%o decimal:%u hex:%x HEX:%X\n", 2147483647, 2147483647, 2147483647, 2147483647);
	printf("check:%i\n", check);
	check = ft_printf("octal:%o decimal:%u hex:%x HEX:%X\n", 2147483647, 2147483647, 2147483647, 2147483647);
	printf(RED "check:%i\n" RESET, check);


	printf(BLUE "\n --- TEST#03 --- \n\n" RESET);
	check = printf("expected:octal:%o H_octal:%#ho HH_octal:%hho L_octal:%lo LL_octal:%llo &&\
	 decimal:%u H_decimal:%hu HH_decimal:%hhu L_decimal:%lu LL_decimal:%llu &&\
	 hex:%x H_hex:%hx HH_hex:%hhx L_hex:%lx LL_hex:%llx &&\
	 HEX:%X H_HEX:%hx HH_HEX:%hhx L_HEX:%lx LL_HEX:%llx int:%i H_int:%hi \
	 HH_int:%hhi L_int:%li LL_int:%lli  \n", -2147483647, -2147483647, -214, 21474836479\
	 , 21474836479, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647\
	 , 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647\
	 , 2147483647, 2147483647, 2147483647, 2147483647);
	printf("check:%i\n", check);
	check = ft_printf("reality :octal:%o H_octal:%#ho HH_octal:%hho L_octal:%lo LL_octal:%llo &&\
	 decimal:%u H_decimal:%hu HH_decimal:%hhu L_decimal:%lu LL_decimal:%llu &&\
	 hex:%x H_hex:%hx HH_hex:%hhx L_hex:%lx LL_hex:%llx &&\
	 HEX:%X H_HEX:%hx HH_HEX:%hhx L_HEX:%lx LL_HEX:%llx int:%i H_int:%hi \
	 HH_int:%hhi L_int:%li LL_int:%lli  \n", -2147483647, -2147483647, -214, 21474836479\
	 , 21474836479, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647\
	 , 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647\
	 , 2147483647, 2147483647, 2147483647, 2147483647);
	printf(RED "check:%i\n" RESET, check);

	printf(YELLOW "\n --- TEST#04 --- \n\n" RESET);
	check = printf("expected:%#####o && %#hho, %#x, %#X\n", 2147483647, 214, 214748364, 214748364);
	printf("check:%i\n", check);
	check = ft_printf("reality :%#####o && %#hho, %#x, %#X\n", 2147483647, 214, 214748364, 214748364);
	printf(RED "check:%i\n" RESET, check);

	printf(RED "\n --- TEST#05 --- \n\n" RESET);
	check = printf("%#05x_%#011hhx_%#7u_%5%_%04%_%19p_%000029p_%p\n", 214, 214, 214, ptr0, ptr0, ptr1);
	printf("check:%i\n", check);
	check = ft_printf("%#05x_%#011hhx_%#7u_%5%_%04%_%19p_%000029p_%p\n", 214, 214, 214, ptr0, ptr0, ptr1);
	printf(RED"check:%i\n"RESET, check);

	printf(CYAN "\n --- TEST#06 --- \n\n" RESET);
	check = printf("expected:%     u_% #o_% c_%  05c_ % #l X_ %          #hx %       hh%\n", 255, 2147483647, 'p', 'f', 21474839999, 250);
	printf("check:%i\n", check);
	check = ft_printf("expected:%     u_% #o_% c_%  05c_ % #l X_ %          #hx %    hh%\n", 255, 2147483647, 'p', 'f', 21474839999, 250);
	printf(RED"check:%i\n"RESET, check);

	printf(MAGENTA "\n --- TEST#07 --- \n\n" RESET);
	check = printf("%+ 015i_% +hi_%   20 l i\n", check1, check1, check1);
	printf("check:%i\n", check);
	check = ft_printf("%+ 015i_% +hi_%   20 l i\n", check1, check1, check1);
	printf(RED"check:%i\n"RESET, check);

	printf(GREEN "\n --- TEST#08 --- \n\n" RESET);
	check = printf("%+ ll  i_% + *  h     i_%++ 20 l   i_%+09hu\n", 2147483647, 9, 2147483647, 2147483647, 2147483647);
	printf("check:%i\n", check);
	check = ft_printf("%+ ll  i_% + *  h  i_%++ 20 l   i_%+09hu\n", 2147483647, 9, 2147483647, 2147483647, 2147483647);
	printf(RED"check:%i\n"RESET, check);

	printf(GREEN "\n --- TEST#09 --- \n\n" RESET);
	check = printf("%-5i_%-5%_%-4li_%-3%_%-5c_%-7s_%-2s_%#-14x_%-14p\n", 23, 2147483999, 'f', "hello", "hello", 2147483645, ptr0);
	printf("check:%i\n", check);
	check = printf("%-5i_%%_%-6hhi_%-5hhi_%-4h i_%-2 +li_%-6lli\n", 23, 125, 2147483647, 2147483647, 2147483649, 2147483647);
	printf("check:%i\n", check);
	check = ft_printf("%-5i_%%_%-6hhi_%-5hhi_%-4h i_%-2 +li_%-6lli\n", 23, 125, 2147483647, 2147483647, 2147483649, 2147483647);
	printf(RED"check:%i\n"RESET, check);
	check = printf("%-5i_%-5%_%-4li_%-3%_%-5c_%-7s_%-2s_%#-14x_%-14p\n", 23, 2147483999, 'f', "hello", "hello", 2147483645, ptr0);
	printf(RED"check:%i\n"RESET, check);
	printf("%5s_%-10s_\n", "goes over", "world");
	ft_printf("%5s_%-10s_\n", "goes over", "world");

	printf(BLUE "\n --- TEST#10 --- \n\n" RESET);
	check = printf("% #-+015d_% +-  i && % hd_%+hi && % +hhd_%+hhi && %+ld_%+li && %lld_%lli\n", 2147483648, 2147483648, 2147483648, 2147483648, 2147483648, 2147483648, 2147483648, 2147483648, 2147483648, 2147483648);
	printf("check:%i\n", check);
	check = ft_printf("% #-+015d_% +-  i && % hd_%+hi && % +hhd_%+hhi && %+ld_%+li && %lld_%lli\n", 2147483648, 2147483648, 2147483648, 2147483648, 2147483648, 2147483648, 2147483648, 2147483648, 2147483648, 2147483648);
	printf(RED "check:%i\n" RESET, check);

	printf(YELLOW "\n --- TEST#11 --- \n\n" RESET);
	check = printf("%f_%lf_%Lf_\n", 2147483648.145, 2147483648.1, -15.204);
	printf("check:%i\n", check);
	check = ft_printf("%f_%lf_%Lf_\n", 2147483648.145, 2147483648.1, -15.204);
	printf(RED "check:%i\n" RESET, check);

	printf(RED "\n --- TEST#12 --- \n\n" RESET);
	check = printf("_%0.  3c_%2. 02c_%5.-2c_%.0c_%-3.-1s_%2.  0%_%25.-20p_%-25.-20p_%-25.20p_%24.19p_\n", 'a', 'b', 'c', 'd', "hello", ptr0, \
	ptr1, ptr0, ptr1);
	printf("check:%i\n", check);
	check = ft_printf("_%0.  3c_%2. 02c_%5.-2c_%.0c_%-3.-1s_%2.  0%_%25.-20p_%-25.-20p_%-25.20p_%24.19p_\n", 'a', 'b', 'c', 'd', "hello", ptr0, \
	ptr1, ptr0, ptr1);
	printf(RED"check:%i\n"RESET, check);

	printf(CYAN "\n --- TEST#13 --- \n\n" RESET);
	check = printf("1_%-15.-17o_%-#15.17o_%#15.  -18o_%# 13.14o_%#15o_\n", 2147483648, 21474838, 21474875, 2147483648, 2147483648);
	printf("check:%i\n", check);
	check = ft_printf("1_%-15.-17o_%-#15.17o_%#15.  -18o_%# 13.14o_%#15o_\n", 2147483648, 21474838, 21474875, 2147483648, 2147483648);
	printf(RED"check:%i\n\n"RESET, check);
	check = printf("2_%-#15.-17u_%-#15.17u_%#15.-18u_%#13.14u_%15u_\n", 2147483648, 21474838, 21474875, 2147483648, 2147483648);
	printf("check:%i\n", check);
	check = ft_printf("2_%-#15.-17u_%-#15.17u_%#15.-18u_%#13.14u_%15u_\n", 2147483648, 21474838, 21474875, 2147483648, 2147483648);
	printf(RED"check:%i\n\n"RESET, check);
	check = printf("3_%-#15.-17x_%-#15.17x_%#15.-18x_%#13.14x_%15x_\n", 2147483648, 21474838, 21474875, 2147483648, 2147483648);
	printf("check:%i\n", check);
	check = ft_printf("3_%-#15.-17x_%-#15.17x_%#15.-18x_%#13.14x_%15x_\n", 2147483648, 21474838, 21474875, 2147483648, 2147483648);
	printf(RED"check:%i\n\n"RESET, check);
	check = printf("4_%-#15.-17X_%-#15.17X_%#15.-18X_%#13.14X_%15X_\n", 2147483648, 21474838, 21474875, 2147483648, 2147483648);
	printf("check:%i\n", check);
	check = ft_printf("4_%-#15.-17X_%-#15.17X_%#15.-18X_%#13.14X_%15X_\n", 2147483648, 21474838, 21474875, 2147483648, 2147483648);
	printf(RED"check:%i\n\n"RESET, check);

	printf(MAGENTA "\n --- TEST#14 --- \n\n" RESET);
	check = printf("_%+10.4lf_%1.3f_%-10.4f_%-0.0Lf_%10.-4f_%f_%f_%7. -5f_\n", 15.204, 5.5, 15.204, 0.3, 15.204, 3.3, 15.117);
	printf("check:%i\n", check);
	check = ft_printf("_%+10.4lf_%1.3f_%-10.4f_%-0.0Lf_%10.-4f_%f_%f_%7. -5f_\n", 15.204, 5.5, 15.204, 0.3, 15.204, 3.3, 15.117);
	printf(RED"check:%i\n\n"RESET, check);

	printf(GREEN "\n --- TEST#15 --- \n\n" RESET);
	check = printf("_%i_%15.5i_%+-13.20i_%-15.-5i_%15.-5i_%0.0i_%15.-20i_%+30.20i_%+30.20i_\n", 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, -2147483646);
	printf("check:%i\n", check);
	check = ft_printf("_%i_%15.5i_%+-13.20i_%-15.-5i_%15.-5i_%0.0i_%15.-20i_%+30.20i_%+30.20i_\n", 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, -2147483646);
	printf(RED"check:%i\n"RESET, check);

	printf(BLUE "\n --- TEST#16 --- \n\n" RESET);
	check = printf("_% 5.0x_% 5.2x_%#x_% #08x_% 5.2o_%#o_%#08o_\n", 5427, 5427, 0, 42, 5424, 2, 42);
	printf("check:%i\n", check);
	check = ft_printf("_% 5.0x_% 5.2x_%#x_% #08x_% 5.2o_%#o_%#08o_\n", 5427, 5427, 0, 42, 5424, 2, 42);
	printf(RED"check:%i\n"RESET, check);
	check = printf("_% 5.0X_% 5.2X_%#X_% #08X_% 5.2X_%#X_%#08X_\n", 5427, 5427, 0, 42, 5424, 2, 42);
	printf("check:%i\n", check);
	check = ft_printf("_% 5.0X_% 5.2X_%#X_% #08X_% 5.2X_%#X_%#08X_\n", 5427, 5427, 0, 42, 5424, 2, 42);
	printf(RED"check:%i\n"RESET, check);

	printf(YELLOW "\n --- TEST#17 --- \n\n" RESET);
	check = printf("_%7. -5f_% 7.5f_%7. 5f_\n", 15.117, 15.117, 15.117);
	printf("check:%i\n", check);
	check = ft_printf("_%7. -5f_% 7.5f_%7. 5f_\n", 15.117, 15.117, 15.117);
	printf(RED"check:%i\n"RESET, check);
	check = printf("_%#8x_\n", 42);
	printf("check:%i\n", check);
	check = ft_printf("_%#8x_\n", 42);
	printf(RED"check:%i\n"RESET, check);
	check = printf("_%#8X_\n", 42);
	printf("check:%i\n", check);
	check = ft_printf("_%#8X_\n", 42);
	printf(RED"check:%i\n"RESET, check);
	check = printf("_%#8o_\n", 42);
	printf("check:%i\n", check);
	check = ft_printf("_%#8o_\n", 42);
	printf(RED"check:%i\n"RESET, check);
	check = printf("_%#.x_%#.0x_\n", 0, 0);
	printf("check:%i\n", check);
	check = ft_printf("_%#.x_%#.0x_\n", 0, 0);
	printf(RED"check:%i\n"RESET, check);
	check = printf("_%#.o_%#.0o_\n", 0, 0);
	printf("check:%i\n", check);
 	check = ft_printf("_%#.o_%#.0o_\n", 0, 0);
	printf(RED"check:%i\n"RESET, check);
	check = printf("_%.X_%.0X_\n", 0, 0);
	printf("check:%i\n", check);
 	check = ft_printf("_%.X_%.0X_\n", 0, 0);
	printf(RED"check:%i\n"RESET, check);
	check = printf("@moulitest:%#5.x_%#5.0x_\n", 1, 0);
	printf("check:%i\n", check);
	check = ft_printf("@moulitest:%#5.x_%#5.0x_\n", 1, 0);
	printf(RED"check:%i\n"RESET, check);
	check = printf("@moulitest:%#5.X_%#5.0X_\n", 1, 0);
	printf("check:%i\n", check);
	check = ft_printf("@moulitest:%#5.X_%#5.0X_\n", 1, 0);
	printf(RED"check:%i\n"RESET, check);
	check = printf("@moulitest:%.d_%.0d_\n", 0, 0);
	printf("check:%i\n", check);
	check = ft_printf("@moulitest:%.d_%.0d_\n", 0, 0);
	printf(RED"check:%i\n"RESET, check);
	check = printf("_%.o_%.0o_\n", 0, 0);
	printf("check:%i\n", check);
	check = ft_printf("_%.o_%.0o_\n", 0, 0);
	printf(RED"check:%i\n"RESET, check);
	ft_printf("_%-10.5o_\n", 2500);
	printf("_%-10.5o_\n", 2500);
	check = printf("%.2s is a string\n", "this");
	printf("check:%i\n", check);
	check = ft_printf("%.2s is a string\n", "this");
	printf(RED"check:%i\n"RESET, check);
	check = printf("%.2s is a string\n", "");
	printf("check:%i\n", check);
	check = ft_printf("%.2s is a string\n", "");
	printf(RED"check:%i\n"RESET, check);
	check = printf("%5.2s is a string\n", "");
	printf("check:%i\n", check);
	check = ft_printf("%5.2s is a string\n", "");
	printf(RED"check:%i\n"RESET, check);
	check = printf("%-.2s is a string\n", "");
	printf("check:%i\n", check);
	check = ft_printf("%-.2s is a string\n", "");
	printf(RED"check:%i\n"RESET, check);
	check = printf("%-5.2s is a string\n", "");
	printf("check:%i\n", check);
	check = ft_printf("%-5.2s is a string\n", "");
	printf(RED"check:%i\n"RESET, check);
	// check = printf("%.2c", NULL);
	// printf("check:%i\n", check);
	// check = ft_printf("%.2c", NULL);
	// printf(RED"check:%i\n"RESET, check);
	check = printf("\0");
	printf("check:%i\n", check);
	check = ft_printf("\0");
	printf(RED"check:%i\n"RESET, check);
	check = printf("%23lld\n", -9223372036854775808);
	printf("check:%i\n", check);
	check = ft_printf("%23lld\n", -9223372036854775808);
	printf(RED"check:%i\n"RESET, check);
	check = printf("%#o\n", 0);
	printf("check:%i\n", check);
	check = ft_printf("%#o\n", 0);
	printf(RED"check:%i\n"RESET, check);
	check = printf("%.5c\n", 42);
	printf("check:%i\n", check);
	check = ft_printf("%.5c\n", 42);
	printf(RED"check:%i\n"RESET, check);
	check = printf("%.5p, %.p\n", 0, 0);
	printf("check:%i\n", check);
	check = ft_printf("%.5p, %.p\n", 0, 0);
	printf(RED"check:%i\n"RESET, check);
	check = printf("%9.2p\n", 1234);
	printf("check:%i\n", check);
	check = ft_printf("%9.2p\n", 1234);
	printf(RED"check:%i\n"RESET, check);
	check = printf("%#.o\n", 42);
	printf("check:%i\n", check);
	check = ft_printf("%#.o\n", 42);
	printf(RED"check:%i\n"RESET, check);
	check = printf("%05.*d_\n", -15, 42);
	printf("check:%i\n", check);
	check = ft_printf("%05.*d_\n", -15, 42);
	printf(RED"check:%i\n"RESET, check);
	check = printf("%05.-15d\n", 42);
	printf("check:%i\n", check);
	check = ft_printf("%05.-15d\n", 42);
	printf(RED"check:%i\n"RESET, check);
	check = printf("{%*d}\n", -5, 42);
	printf("check:%i\n", check);
	check = ft_printf("{%*d}\n", -5, 42);
	printf(RED"check:%i\n"RESET, check);

	check = printf("{%.*s}\n", -5, "42");
	printf("check:%i\n", check);
	check = ft_printf("{%.*s}\n", -5, "42");
	printf(RED"check:%i\n"RESET, check);

	printf("%.4X\n", 42);
	ft_printf("%.4X\n", 42);
	printf("%#15.4x\n", 42);
	ft_printf("%#15.4x\n", 42);
	check = printf("{%*d}\n", -5, 42);
	printf("check:%i\n", check);
	check = ft_printf("{%*d}\n", -5, 42);
	printf(RED"check:%i\n"RESET, check);
	check = printf("{%*d}\n", -5, 42);
	printf("check:%i\n", check);
	check = ft_printf("{%*d}\n", -5, 42);
	printf(RED"check:%i\n"RESET, check);

	check = printf("%-10.8s", NULL);
	printf("check:%i\n", check);
	check = ft_printf("%-10.8s", NULL);
	printf(RED"check:%i\n"RESET, check);

	check = printf("%-5.0x_\n", 0);
	printf("check:%i\n", check);
	check = ft_printf("%-5.0x_\n", 0);
	printf(RED"check:%i\n"RESET, check);
	// check = printf("%-5.0X_\n", 0);
	// printf("check:%i\n", check);
	// check = ft_printf("%-5.0X_\n", 0);
	// printf(RED"check:%i\n"RESET, check);
	check = printf("%.*s_\n", -3, "hello");
	printf("check:%i\n", check);
	check = ft_printf("%.*s_\n", -3, "hello");
	printf(RED"check:%i\n"RESET, check);
	check = printf("%.*p_\n", -3, 0);
	printf("check:%i\n", check);
	check = ft_printf("%.*p_\n", -3, 0);
	printf(RED"check:%i\n"RESET, check);


	// 868/4219 -> 870/4219 -> 902/4219 -> 1078/4219 -> 1090/4219 -> 1287/4219 ->1596/4219 -> 1744/4219 in pft checker
	ft_printf("% Z%s\n", "test");
  	ft_printf("%jx\n", 1582);
	free(ptr0);
	free(ptr1);
	return (0);
}
