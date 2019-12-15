/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:41:14 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/15 19:08:18 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include 	"Part1.hpp"

typedef	struct	s_mlx
{
	void		*mlx;
	void		*window;
}				t_mlx;


int		hook_keydown(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

void mlx(Part1 one)
{
	t_mlx	mlx;

	char *m_win = new char[8];
	strcpy(m_win, "gkrellm");

	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, 2000, 1200, m_win);


	mlx_loop(mlx.mlx);
}
