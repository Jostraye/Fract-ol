# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jostraye <jostraye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 19:04:14 by jostraye          #+#    #+#              #
#    Updated: 2018/01/14 14:48:29 by jostraye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS += -Wall -Werror -Wextra -I
FRMWRK = -framework OpenGL -framework AppKit
LIBS = -lmlx -lft
LX = src/libmlx/
LT = libft/
LTA = libft.a
LXA = libmlx.a
ALLC = *.c
ALLO = *.o

RM = rm -f

MAP1 = src/maps/42.fdf
MAP2 = src/maps/elem-col.fdf
MAP3 = src/maps/mars.fdf
MAP4 = src/maps/t2.fdf

SRCS = main.c \
       fracting.c \
			 images.c \
			 errors.c \
			 colors.c \
			 hooks.c

all: $(LTA) $(LXA) fracting

$(LXA):
	make -C $(LX)

$(LTA):
	make -C $(LT)

fracting:
	gcc $(FLAGS) $(LX) -c $(LT)$(ALLC) $(ALLC)
	gcc $(FLAGS) $(LX) $(ALLO) -L$(LX) -L$(LT) $(LIBS) -o $(NAME) $(FRMWRK)

clean:
	$(RM) $(ALLO) $(LT)$(ALLO) $(LX)$(ALLO)

fclean: clean
	$(RM) $(NAME)

run1:
	./fdf $(MAP1)

run2:
	./fdf $(MAP2)

run3:
	./fdf $(MAP3)

run4:
	./fdf $(MAP4)

re: fclean all
