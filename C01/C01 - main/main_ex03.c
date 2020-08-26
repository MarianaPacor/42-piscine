#include <stdio.h>
void 	ft_div_mod(int a, int b, int *div, int *mod);

int		main()
{
	int a;
	int b;
	ft_div_mod(10, 5, &a, &b);
	printf("Div: %d\nMod: %d", a, b);
}
