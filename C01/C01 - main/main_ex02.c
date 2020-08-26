#include <stdio.h>

void	ft_swap(int *a, int *b);

int		main()
{
	int a;
	int b;

	a = 10;
	b = 5;
	printf("a: %d\nb: %d\n", a, b);
	ft_swap(&a, &b);
	printf("a: %d\nb: %d\n", a, b);
}
