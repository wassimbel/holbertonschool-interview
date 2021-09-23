#include "holberton.h"

/**
 * check_error - checks errors
 * @argc: number of args
 * @argv: double pointer to array of argv
 * Return: returns 0 on success otherwise exits with status 98
 */

int check_error(int argc, char **argv)
{
	size_t k;
	int i, j;
	char *err = "Error\n";

	if (argc != 3)
	{
		for (k = 0; k < strlen(err); k++)
			_putchar(err[k]);
		exit(98);
	}
	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				for (k = 0; k < strlen(err); k++)
					_putchar(err[k]);
				exit(98);
			}
		}
	}
	return (0);
}

/**
 * main - entry point
 * @argc: number of args
 * @argv: double pointer to array of argv
 * Return: returns 0 on success otherwise 1
 */

int main(int argc, char **argv)
{
	int len1, len2, i, j, k, x, carry;
	int *num;

	check_error(argc, argv);
	len1 = strlen(argv[1]);
	len2 = strlen(argv[2]);
	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		printf("0\n");
		return (1);
	}
	num = calloc(len1 + len2, sizeof(*num));
	if (!num)
		return (1);
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		k = argv[1][i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			x = argv[2][j] - '0';
			carry += num[i + j + 1] + (k * x);
			num[j + i + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			num[i + j + 1] += carry;
	}
	k = num[0];
	if (k == 0)
		k = 1;
	for (; k < len1 + len2; k++)
		printf("%d", num[k]);
	printf("\n");
	free(num);
	return (0);
}
