#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	**ft_split(char *str, char **charset, int end_str, int **len_w);

static int	ft_strncmp(char *s1, char *s2, int n)
{
	int i;

	i = 0;
//	while ((s1[i] || s2[i]))
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			i++;
	}
	return (0);
}

static int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			i++;
	}
	return (0);
}

int	tab_len(char **tab)
{
	if (!tab[0])
		return (0);
	return (1 + tab_len(tab + 1));
}

void	ft_check_test()
{
	int fd_results;
	int	fd_tests;
	char buffer_results[900000];
	char buffer_tests[900000];
	int size_results;
	int	size_tests;
	int nb_test;
	char *charset_test[] = {"testing \t", 0};
	char *charset_res[] = {"printf    :\t","ft_printf :\t", 0};
	char **res;
	char	**test;
	int compteur_ok;
	int	compteur_undefined;
	int index;
	int *len_w_res;
	int *len_w_test;

	nb_test = 3062;

	fd_results = open("results", O_RDONLY);
	fd_tests = open("tests1", O_RDONLY);

	size_results = read(fd_results, buffer_results, 900000);
	size_tests = read(fd_tests, buffer_tests, 900000);

	res = ft_split(buffer_results, charset_res, size_results, &len_w_res);
	test = ft_split(buffer_tests, charset_test, size_tests, &len_w_test);


	compteur_ok = 0;
	index = 0;
	compteur_undefined = 0;

	while (res[index] && res[index + 1])
	{
		if (!ft_strncmp(res[index], res[index + 1], len_w_res[index]))
			compteur_ok++;
		else if (!ft_strcmp("undefined\n", res[index + 1]))
			compteur_undefined++;
		else
		{
			printf("\nindex : %d\n", index);
			printf("(beta) test effectué -->\t%s\n", test[(index - 1) / 2]);
			printf("printf    :\t%sft_printf :\t%s\n", res[index], res[index + 1]);
		}
		index += 2;
	}

	printf("\n-------  Résultat -------\n");
	printf("\ncompteur_ok = %d\n", compteur_ok);
	printf("compteur_undefined = %d\n", compteur_undefined);
	printf("\nTotal ok : %d / %d\n\n", compteur_undefined + compteur_ok, index / 2);
}

int main()
{
	ft_check_test();
}

/*

gcc -Wall -Wextra test_bis.c -g3 libftprintf.a && ./a.out all > results

gcc -Wall -Wextra -Werror check_test.c split_test.c && ./a.out

*/