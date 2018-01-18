/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 20:28:14 by jostraye          #+#    #+#             */
/*   Updated: 2018/01/14 16:17:58 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <complex.h>
# include <pthread.h>
# include "mlx.h"
# define SIZE 1000
# define WIN_H 1000
# define WIN_W 1000
# define CLR 0x333d3f
# define TH_NB 16

typedef struct		s_env
{
	int				argument;
	double			zoom_param;
	double			x_offset;
	double			y_offset;
	int				max_it;
	double			a;
	double			b;
	double complex	z;
	double complex	z1;
	double complex	z2;
	void			*mlx;
	void			*win;
	void			*img;
	double			xj;
	double			yj;
	double			i;
	double			j;
	double			x;
	double			y;
	int				clr_set;
	pthread_t		pth[TH_NB];
	double			thread_int;
	int				key_code;
	int				*data;
	int				bpp;
	int				ls;
	int				endian;
}					t_env;

typedef struct		s_thread
{
	t_env			*env;
	int				id;
}					t_thread;

t_env				*reset_environment(t_env *e);
t_env				*initialize_win(t_env *e);
void				*create_image(void *e);
void				user_interface_texts(t_env *e);
double				moove_around(int key_code, t_env *e);
void				point_iteration(t_env *e);
void				mlx_draw(t_env *e, int x, int y, int clr);
int					expose_hook(t_env *e);
int					mouse_click_hook(int k, int x, int y, t_env *e);
int					mouse_pos(int x, int y, t_env *e);
int					keyboard_hooks(int key_code, t_env *e);
void				print_error(int err);
int					error_condition(char *a);
void				send_image_to_window(t_env *e);
t_env				*initialize_image(t_env *e);
int					herbal_palette(double r);
int					space_palette(double r);
int					plastic_palette(double r);
int					attribute_color(double distance, int clr_set);
void				mobl_fract(t_env *e);
void				stat_fract(t_env *e);

#endif
