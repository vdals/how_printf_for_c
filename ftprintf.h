/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 12:43:41 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/15 18:38:44 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

# include <stdio.h> //lib for help, delete before project completion

# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define MAGENTA		"\x1b[35m"
# define CYAN			"\x1b[36m"
# define RESET			"\x1b[0m"

# define ABS(i) (((i) < 0) ? -(i) : (i))

# define F_HH			1
# define F_H			2
# define F_L			3
# define F_LL			4
# define F_LD			5

typedef	struct			s_arg
{
	char				*fmt;//это мы парсим
	char				*s;//это для работы со стрингом, тут хранится строка из аргументов
	char				c;//это для работы с чарами
	long int			p;// это для поинтера
	unsigned int		u_i;// это для флагов ouxX
	unsigned char		hha;//
	unsigned short		ha;//
	unsigned long long	lla;//
	unsigned long long	ull;//сюда все кастую, чтобы было меньше функция для вывода
	unsigned long		la;//последня херь для флагов ouxX по факту тут лежат разные размеры для считывания в них va_arg
	int					i;//это для интов и даблов то же самое, что и выше
	char				hhi;//
	short				hi;//
	long long			lli;//
	long long			lls;// сюда все кастую перед выводом, чтобы меньше строк было
	long				li;//тут заканчиваются инты
	int					flg;// тут висит "флаг", где значения дефайнов 1-5 они отвечают за размер наших данных, нужно при проверках и присвоениях
	int					hsh;// тут мы запоминаем встретившийся хэш
	int					num;// тут хранится количество символов для выравнивания или количество 0 на вывод
	int					zero;// тут мы запоминаем, что считали 0
	int					space;// тут мы запоминаем пробел
	int					space2;
	int					move;// тут мы запоминаем пробелы после флагов размера h hh l ll нужно для скипа этих пробелов
	int					plus;// тут запоминаем плюс - для вывода знака инта или дабла (мб и для флота)
	int					minus;// тут запоминаем минус - выравнивание влево
	int					minus2;
	int					wiedth;
	int					point;
	double				f; // ниже все для флотов, возможно будет потом изменено
	double				lf;
	long double			ld;
	long double			ldd;
	int					precision;// precision for floats, default is 6
	char				*fstr;//string with our float number
	long double			head;//голова числа
	long double			tail;//хвост числа
	int					l1;
	int					l2;
	long				i_h;
}						t_arg;

int		ft_printf(const char *format, ...); // тут мы копируем строку пришедшую, запускаем ва_арг для считывания бесконечных аргументов и запускаем парсинг
char	*ft_strdup(const char *src);// libc func
int		ft_strncmp(const char *s1, const char *s2, size_t n);// libc func, but we don't use it, we can del it
int		ft_pow(int x, unsigned int y);// функция возведения в степень
int		ft_atoi(const char *str);// typical atoi
size_t	ft_strlen(const char *s);// length of sting
int		get_flag(t_arg *r, va_list ap, int ret); //here we check size (hh h l ll or simple) and then with static functions we cast in our t_arg structure different info
int		ft_shorter_i(t_arg *r, va_list ap, int ret);// тут мы кидаем флаги и запихиваем разные инты в нашу структуру для последующего вывода
int		ft_print_base(t_arg *r, int sum);// тут мы смотрим, что нам нужно выводить и кидаем это на вывод в шортеры
int		pars(t_arg *r, va_list ap);// бегаем по строке до процента, после чего отправляем в функцию decide
int		ft_putchar(char c);//libc func
int		ft_print_symb(t_arg *r, va_list ap);// тут лежат наши вывода текстов
int		ft_print_symb2(t_arg *r, va_list ap);// тоже самое что и выше и также некоторой простой херни по типу флага поинтера
int		ft_putstr(const char *ptr);// libc func
void	print_base(unsigned long long num, unsigned long long base);// выводим наши числа oux pointer
void	print_base_i(long long num, long long base); // выводим инты и даблы
void	print_base_high(unsigned long long num, unsigned long long base);// выводим X
int		length_of_num(unsigned long long int i, int base);// длина числа
int		length_of_num_i(long long int i, int base);// длина инта или дабла
int		ft_print_hash(t_arg *r);//рисуем результат флага хэш
int		shorter_u_i(t_arg *r, int base, int sum); // тут мы кастим все в один тип и выводим в зависимости от флага
int		shorter_u_i_high(t_arg *r, int base, int sum);// то же самое, что и выше, но только для типа Х
int		shorter_i(t_arg *r, int base, int sum);// для интов то же самое
int		ft_check_hash(t_arg *r);// проверяем хэши
int		ft_check_zero(t_arg *r);//проверяем нули
int		ft_check_num(t_arg *r);//проверяем количество символов для форматирования
int		ft_check_space(t_arg *r);//проверяем пробелы
int		ft_check_plus(t_arg *r);//чекаем плюсы
int		ft_check_minus(t_arg *r);// чекаем минусы
int		ft_check_star(va_list ap, t_arg *r);// чекаем звездочку для будущей точности нужно
int		ft_size_print(t_arg *r, int length);// тут мы форматируем вывод при смещениях из-за пробелов и нулей на экране направо
int		ft_size_print2(t_arg *r, int length);// то же чт ои выше функция направо
int		ft_size_print_minus(t_arg *r, int length);// для рисования форматирования слева

void	ft_check_wiedth(t_arg *r);
int		ft_putstr2(const char *str, int size);
int		ft_putstr3(const char *str, int size);
int		ft_shorter_f(t_arg *r, va_list ap, int ret); // разработка для флотов, в стадии тестирования
int		shorter_f(t_arg *r, int sum);
char	*ft_ltoa(int length, t_arg *r);
//int		min_short_float(t_arg *r, int sum);

int		check_hash_help(t_arg *r);

#endif
