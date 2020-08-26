#include <unistd.h>
#include <string.h>
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int	main(void)
{
	char src[40];
	char dest1[40];
	char dest2[40];
	char dest3[40];
	int i;
	
//  função string copy da biblioteca C, usada para inserir uma string na variável char src[40]
//  declarada acima. A função é prototipada assim --> strcpy(destin, source);
	strcpy(src, "Mariana");

//usando o destino como source para ser copiado para dest1 na função string n copy que delimita o tamanho do destino
	ft_strncpy(dest1, src, 7);
	ft_putstr("size = 7 : ");
	for (i = 0; i < 7; i++)
		ft_putchar(*(dest1 + i));
	ft_putchar('\n');

	ft_strncpy(dest2, src, 5);
	ft_putstr("size = 5 : ");
	for (i = 0 ; i < 5; i++)
		ft_putchar(*(dest2 + i));
	ft_putchar('\n');

	ft_strncpy(dest3, src, 10);
	ft_putstr("size = 10 : ");
	for (i = 0 ; i < 10; i++)
		ft_putchar(*(dest3 + i));
	ft_putchar('\n');

	return(0);
}
