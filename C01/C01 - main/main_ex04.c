#include <stdio.h>
void	ft_ultimate_div_mod(int *a, int *b);

int		main()
{
	int a;
	int b;

	ft_ultimate_div_mod(&a, &b);
	printf("*div: %d\n*mod: %d", a, b);
}
