#include <unistd.h>
#include <string.h>
#include <stdio.h>

char    *ft_strcpy(char *dest, char *src);

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
	char dest[100];

//	memset(dest, '\0', sizeof(dest));
//	strcpy(src, "This is tutorialspoint.com");
//	strcpy(dest, src);
//	printf("Final copied string : %s\n", dest);

	memset(dest, '\0', sizeof(dest));
	ft_strcpy(src, "42saoPaulo");
	ft_strcpy(dest, src);
	printf("Final copied string : %s\n", dest);
	return(0);
}
