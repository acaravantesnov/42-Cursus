#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_putstr(const char *str);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_putnbr_base(unsigned int nbr, char *base);
int	ft_putnbr_base2(unsigned long nbr, char *base);
int	ft_pointer(unsigned long n);
int	ft_printfext(int i, int ret, const char *input, va_list(ap));

#endif