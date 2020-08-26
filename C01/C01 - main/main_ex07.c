#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int		main()
{
	int i;
	int  a[] = {1, 2, 3, 4, 5, 6};
	for(i = 0; i < 6; i++)
	{
		printf("%d, ", a[i]);
	}
	printf("\n");
	ft_rev_int_tab(a, 6);
	for(i = 0; i < 6; i++)
	{
		printf("%d, ", a[i]);
	}
}
