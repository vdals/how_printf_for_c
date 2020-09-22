# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/28 13:36:39 by ggeri             #+#    #+#              #
#    Updated: 2020/09/20 20:54:20 by ggeri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# program name
NAME = libftprintf.a

# compiling flags
FLAGS = -Wall -Wextra -Werror -c

# functions
FUNC = math_1 ft_print_base ft_get_format ft_shorter \
	ft_hashnco ft_shorter_high ft_shorter_high2 size_print ft_atoi ft_strdup \
	ft_printf print_symb ft_strlen ft_shorter_int ft_get_format_int \
	ft_hashnco2 float ft_shorter_float ft_ltoa ft_putchar ft_shorter_int2 \
	print_symb2 print_symb3 ft_shorter2 ft_shorter3 ft_length_of_num

# functions with .c
FUNC_C = $(patsubst %, %.c, $(FUNC))

# object files
OBJ = $(patsubst %, %.o, $(FUNC))

# header
HEADER = ftprintf.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar rc $(NAME) $?
	ranlib $(NAME)

$(OBJ): %.o: %.c
	gcc $(FLAGS) $? -I $(HEADER)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
