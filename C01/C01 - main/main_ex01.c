#include <stdio.h>

void	ft_ultimate_ft(int *********nbr);

int		main()
{
	int a;
	int *nbr;
	int **nbr2;
	int ***nbr3;
	int ****nbr4;
	int *****nbr5;
	int ******nbr6;
	int *******nbr7;
	int ********nbr8;

	a = 25;
	nbr = &a;
	nbr2 = &nbr;
	nbr3 = &nbr2;
	nbr4 = &nbr3;
	nbr5 = &nbr4;
	nbr6 = &nbr5;
	nbr7 = &nbr6;
	nbr8 = &nbr7;
	printf("%d", a);
	ft_ultimate_ft(&nbr8);
	printf("%d", a);
}
