#include <stdio.h>

void ft_sort_int_tab(int *tab, int size);

int		main()
{
	int i;

	int a[6] = {6, 2, 4, 3, 5, 1};
	for(i = 0; i < 6; i++)
	{
	printf("%d, ", a[i]);
	}
	printf("\n");
	ft_sort_int_tab(a, 6);
	for(i = 0; i < 6; i++)
	{
	printf(": %d, ", a[i]);
	}	
}
