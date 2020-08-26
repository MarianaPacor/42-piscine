/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skyscrapers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpacor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 23:25:13 by mpacor            #+#    #+#             */
/*   Updated: 2019/12/01 23:40:07 by mpacor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "struct_possib.h"

int		ft_check_size_of_l(int couple);

/*
** Testa se parâmetros passados estão dentro de casais possíveis **
*/
int ft_test_couple(char arg[])
{
	int i;
	int n;
	char a;
	char b;
	int couple;
	int count_test;

	i = 0;
	count_test = 0;
	while (i <= 22)
	{
		a = arg[i];
		b = arg[i + 8];
		couple = ((a - '0') * 10) + (b - '0');
		int list[] = {41, 32, 31, 23, 22, 21, 14, 13, 12};

		n = 0;
		while (n < 9)
		{
			if (couple == list[n])
				count_test++;
			n++;
		}
		i = i + 2;
		if (i == 8)
			i = i + 8;
	}
	if (count_test != 8)
		return (-1);
	else
		return (0);
}

/*
** Imprime a matriz caso chegue na solução correta **
*/
void ft_print_matrix(int *matrix_sky)
{
	int i;
	char c;

	i = 0;
	while (i < 16)
	{
		c = matrix_sky[i] + '0';
		write(1, &c, 1);
		if (i == 3 || i == 7 || i == 11 || i == 15)
			write(1, "\n", 1);
		i++;
	}
	free (matrix_sky);
	exit(1);
}

/*
** Checa se as colunas estão somando 10 **
*/
void	ft_test_seq2(int *matrix_sky, t_possib *list, int col_couples[])
{

	int coupleop;
	int i;
	int pos_list;
	int n;
	int option;
	int col_count;
	int check_ok;

	n = 0;
	check_ok = 0;
	while (n < 4)
	{
		int col_compara[] = {matrix_sky[0 + n], matrix_sky[4 + n], matrix_sky[8 + n], matrix_sky[12 + n]};		
		option = 1;
		while (option <= ft_check_size_of_l(col_couples[n]))
		{
			coupleop = (col_couples[n] * 10) + option;
			i = 0;
			while (i <= 23)
			{
				if (list[i].coupleop == coupleop)
				{
					pos_list = 0;
					col_count = 0;
					while (pos_list < 4)
					{
						if(col_compara[pos_list] == list[i].poss[pos_list])
							col_count++;
						pos_list++;
					}
					if (col_count == 4)
						check_ok++;
				}
				i++;
			}
			option++;
		}
		n++;
	}
	if (check_ok == 4)
		ft_print_matrix(matrix_sky);
	return;
}

/*
** Preenche as linhas com as opções de cada casa para testarmos a nova matriz **
*/
void ft_add_seq(int couple, int option, int line, int *matrix_sky, t_possib *list, int col_couples[])
{
	int coupleop;
	int i;
	int n;
	int pos_m;

	coupleop = (couple * 10) + option;
	i = 0;
	n = 0;

	while (i <= 23)
	{
		if (list[i].coupleop == coupleop)
		{
			while (n < 4)
			{
				pos_m = ((line - 1) * 4) + n;
				matrix_sky[pos_m] = list[i].poss[n];
				n++;
			}
			ft_test_seq2(matrix_sky, list, col_couples);
			return;
		}
		i++;
	}
}

/*
** Checa o número de opções que o casal pode ter **
*/
int ft_check_size_of_l(int couple)
{
	if (couple == 41 || couple == 14)
		return (1);
	else if (couple == 32 || couple == 31 || couple == 23 || couple == 13)
		return (3);
	else if (couple == 22)
		return (6);
	else if (couple == 21 || couple == 12)
		return (2);
	else
		return (0);
}

/*
** Envia as sequências para serem checadas se conjuntamente estão conversando entre si **
*/
void ft_line_test(int col_couples[], int line_couples[], t_possib *seq_list)
{
	int i;
	int j;
	int n;
	int z;
	int *matrix_sky;

	matrix_sky = (int *)malloc(16 * sizeof(int));

	z = 1;
	while (z <= ft_check_size_of_l(line_couples[0]))
	{
		ft_add_seq(line_couples[0], z, 1, matrix_sky, seq_list, col_couples);
		n = 1;
		while (n <= ft_check_size_of_l(line_couples[1]))
		{
			ft_add_seq(line_couples[1], n, 2, matrix_sky, seq_list, col_couples);
			j = 1;
			while (j <= ft_check_size_of_l(line_couples[2]))
			{
				ft_add_seq(line_couples[2], j, 3, matrix_sky, seq_list, col_couples);
				i = 1;
				while (i <= ft_check_size_of_l(line_couples[3]))
				{
					ft_add_seq(line_couples[3], i, 4, matrix_sky, seq_list, col_couples);
					i++;
				}
				j++;
			}
			n++;
		}
		z++;
	}
	write(1, "Error\n", 6);
	free (seq_list);
}

/*
** Atribui os valores dos casais  das linhas e colunas **
*/
void ft_line_loop(char arg[], t_possib *seq_list)
{
	int line_couples[4];
	int col_couples[4];

	col_couples[0] = ((arg[0] - '0') * 10) + (arg[8] - '0');
	col_couples[1] = ((arg[2] - '0') * 10) + (arg[10] - '0');
	col_couples[2] = ((arg[4] - '0') * 10) + (arg[12] - '0');
	col_couples[3] = ((arg[6] - '0') * 10) + (arg[14] - '0');
	line_couples [0] = ((arg[16] - '0') * 10) + (arg[24] - '0');
	line_couples [1] = ((arg[18] - '0') * 10) + (arg[26] - '0');
	line_couples [2] = ((arg[20] - '0') * 10) + (arg[28] - '0');
	line_couples [3] = ((arg[22] - '0') * 10) + (arg[30] - '0');

	ft_line_test(col_couples, line_couples, seq_list);
}

/*
** Adiciona em um tabela todas as possibilidades de sequências para cada casal **
*/
void ft_seq_list1(t_possib *list);
void ft_seq_list2(t_possib *list);
void ft_seq_list3(t_possib *list);
void ft_seq_list4(t_possib *list);
void ft_seq_list5(t_possib *list);

void ft_seq_list(t_possib *list)
{
	list[0].coupleop = 411;
	list[0].poss[0] = 1;
	list[0].poss[1] = 2;
	list[0].poss[2] = 3;
	list[0].poss[3] = 4;

	list[1].coupleop = 321;
	list[1].poss[0] = 1;
	list[1].poss[1] = 2;
	list[1].poss[2] = 4;
	list[1].poss[3] = 3;

	list[2].coupleop = 322;
	list[2].poss[0] = 1;
	list[2].poss[1] = 3;
	list[2].poss[2] = 4;
	list[2].poss[3] = 2;

	list[3].coupleop = 323;
	list[3].poss[0] = 2;
	list[3].poss[1] = 3;
	list[3].poss[2] = 4;
	list[3].poss[3] = 1;
	ft_seq_list1(list);
}

void ft_seq_list1(t_possib *list)
{
	list[4].coupleop = 311;
	list[4].poss[0] = 2;
	list[4].poss[1] = 1;
	list[4].poss[2] = 3;
	list[4].poss[3] = 4;

	list[5].coupleop = 312;
	list[5].poss[0] = 2;
	list[5].poss[1] = 3;
	list[5].poss[2] = 1;
	list[5].poss[3] = 4;

	list[6].coupleop = 313;
	list[6].poss[0] = 1;
	list[6].poss[1] = 3;
	list[6].poss[2] = 2;
	list[6].poss[3] = 4;

	list[7].coupleop = 231;
	list[7].poss[0] = 3;
	list[7].poss[1] = 4;
	list[7].poss[2] = 2;
	list[7].poss[3] = 1;

	list[8].coupleop = 232;
	list[8].poss[0] = 2;
	list[8].poss[1] = 4;
	list[8].poss[2] = 3;
	list[8].poss[3] = 1;
	ft_seq_list2(list);
}

void ft_seq_list2(t_possib *list)
{
	list[9].coupleop = 233;
	list[9].poss[0] = 1;
	list[9].poss[1] = 4;
	list[9].poss[2] = 3;
	list[9].poss[3] = 2;

	list[10].coupleop = 221;
	list[10].poss[0] = 1;
	list[10].poss[1] = 4;
	list[10].poss[2] = 2;
	list[10].poss[3] = 3;

	list[11].coupleop = 222;
	list[11].poss[0] = 2;
	list[11].poss[1] = 4;
	list[11].poss[2] = 1;
	list[11].poss[3] = 3;

	list[12].coupleop = 223;
	list[12].poss[0] = 3;
	list[12].poss[1] = 4;
	list[12].poss[2] = 1;
	list[12].poss[3] = 2;

	list[13].coupleop = 224;
	list[13].poss[0] = 2;
	list[13].poss[1] = 1;
	list[13].poss[2] = 4;
	list[13].poss[3] = 3;
	ft_seq_list3(list);
}

void ft_seq_list3(t_possib *list)
{
	list[14].coupleop = 225;
	list[14].poss[0] = 3;
	list[14].poss[1] = 1;
	list[14].poss[2] = 4;
	list[14].poss[3] = 2;

	list[15].coupleop = 226;
	list[15].poss[0] = 3;
	list[15].poss[1] = 2;
	list[15].poss[2] = 4;
	list[15].poss[3] = 1;

	list[16].coupleop = 211;
	list[16].poss[0] = 3;
	list[16].poss[1] = 1;
	list[16].poss[2] = 2;
	list[16].poss[3] = 4;

	list[17].coupleop = 212;
	list[17].poss[0] = 3;
	list[17].poss[1] = 2;
	list[17].poss[2] = 1;
	list[17].poss[3] = 4;
	ft_seq_list4(list);
}

void ft_seq_list4(t_possib *list)
{
	list[18].coupleop = 141;
	list[18].poss[0] = 4;
	list[18].poss[1] = 3;
	list[18].poss[2] = 2;
	list[18].poss[3] = 1;

	list[19].coupleop = 131;
	list[19].poss[0] = 4;
	list[19].poss[1] = 3;
	list[19].poss[2] = 1;
	list[19].poss[3] = 2;

	list[20].coupleop = 132;
	list[20].poss[0] = 4;
	list[20].poss[1] = 1;
	list[20].poss[2] = 3;
	list[20].poss[3] = 2;

	list[21].coupleop = 133;
	list[21].poss[0] = 4;
	list[21].poss[1] = 2;
	list[21].poss[2] = 3;
	list[21].poss[3] = 1;
	ft_seq_list5(list);
}

void ft_seq_list5(t_possib *list)
{
	list[22].coupleop = 121;
	list[22].poss[0] = 4;
	list[22].poss[1] = 2;
	list[22].poss[2] = 1;
	list[22].poss[3] = 3;

	list[23].coupleop = 122;
	list[23].poss[0] = 4;
	list[23].poss[1] = 1;
	list[23].poss[2] = 2;
	list[23].poss[3] = 3;
}

int main(int argc, char *argv[])
{
	t_possib *seq_list;

	if (argc != 2)
		write(1, "Error\n", 6);
	seq_list = (t_possib *)malloc(24 * sizeof(t_possib));
	ft_seq_list(seq_list);
	if (ft_test_couple(argv[1]) != -1)
	{
		ft_line_loop(argv[1], seq_list);
	}
	else
		write(1, "Error\n", 6);
}

