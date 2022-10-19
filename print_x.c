#include "main.h"

/**
 * print_hex - Prints a representation of a decimal number on base16 lowercase
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */

int print_x(va_list list)
{
	unsigned int num;
	int len;
	int rem_num;
	char *x_rep;
	char *rev_hex;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 16);
	x_rep = malloc(sizeof(char) * len + 1);
	if (x_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		rem_num = num % 16;
		if (rem_num > 9)
		{
			rem_num = x_check(rem_num, 'x');
			x_rep[len] = rem_num;
		}
		else
			x_rep[len] = rem_num + 48;
		num = num / 16;
	}
	x_rep[len] = '\0';
	rev_x = rev_string(x_rep);
	if (rev_x == NULL)
		return (-1);
	write_base(rev_x);
	free(x_rep);
	free(rev_x);
	return (len);
}
