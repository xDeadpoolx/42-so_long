/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:33:55 by ewurstei          #+#    #+#             */
/*   Updated: 2022/07/19 14:20:08 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_moves(t_data *img)
{
	img->moves = img->moves + 1;
	mlx_clear_window(img->mlx, img->mlx_win);
	init_level(img);
	printf("%d\n", img->moves);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->player,
		img->player_x * 64, img->player_y * 64 + 50);
	if (img->enemy > 0)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->enemy,
			img->enemy_x * 64, img->enemy_y * 64 + 50);
}

void	go_up(t_data *img)
{
	if (img->map[img->player_y - 1][img->player_x] != '1')
	{
		if (img->map[img->player_y - 1][img->player_x] == 'C')
		{
			img->map[img->player_y - 1][img->player_x] = '0';
			img->collectibles++;
		}
		if (img->map[img->player_y - 1][img->player_x] == 'E')
		{
			if (img->collectibles == img->total_c)
				endgame(img);
		}
		img->player_y = img->player_y - 1;
		if (img->enemy > 0)
			enemy_go_down(img);
		print_moves(img);
	}	
}

void	go_down(t_data *img)
{
	if (img->map[img->player_y + 1][img->player_x] != '1')
	{
		if (img->map[img->player_y + 1][img->player_x] == 'C')
		{
			img->map[img->player_y + 1][img->player_x] = '0';
			img->collectibles++;
		}
		if (img->map[img->player_y + 1][img->player_x] == 'E')
		{
			if (img->collectibles == img->total_c)
				endgame(img);
		}
		img->player_y = img->player_y + 1;
		if (img->enemy > 0)
				enemy_go_up(img);
		print_moves(img);
	}	
}

void	go_left(t_data *img)
{
	int	img_width;
	int	img_height;

	if (img->map[img->player_y][img->player_x - 1] != '1')
	{
		if (img->map[img->player_y][img->player_x - 1] == 'C')
		{
			img->map[img->player_y][img->player_x - 1] = '0';
			img->collectibles++;
		}
		if (img->map[img->player_y][img->player_x - 1] == 'E')
		{
			if (img->collectibles == img->total_c)
				endgame(img);
		}
		img->player_x = img->player_x - 1;
		img->player = mlx_xpm_file_to_image(img->mlx, "assets/perso_left.xpm",
				&img_width, &img_height);
		if (img->enemy > 0)
				enemy_go_right(img);
		print_moves(img);
	}	
}

void	go_right(t_data *img)
{
	int	img_width;
	int	img_height;

	if (img->map[img->player_y][img->player_x + 1] != '1')
	{
		if (img->map[img->player_y][img->player_x + 1] == 'C')
		{
			img->map[img->player_y][img->player_x + 1] = '0';
			img->collectibles++;
		}
		if (img->map[img->player_y][img->player_x + 1] == 'E')
		{
			if (img->collectibles == img->total_c)
				endgame(img);
		}
		img->player_x = img->player_x + 1;
		img->player = mlx_xpm_file_to_image(img->mlx, "assets/perso_right.xpm",
				&img_width, &img_height);
		if (img->enemy > 0)
				enemy_go_left(img);
		print_moves(img);
	}	
}
