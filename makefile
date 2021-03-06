#VARIABLES

NAME = so_long

CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
#CFLAGSTEST = -o
RM = rm -f
#AR = ar rcs
MLXDIR = includes/mlx/
LIBFT = libft.a
LDIR = includes/libft/

#COLORS
LRED = \033[91m
LGREEN = \033[92m
LYELLOW = \033[93
LMAGENTA = \033[95m
LCYAN = \033[96m
DEF_COLOR = \033[0;39m

#SOURCES
SRC = so_long.c newgame.c init_assets.c init_player.c player_moves.c draw_map.c \
		check_map.c init_enemy.c enemy_moves.c
#SRCBON = 

OBJ = $(SRC:.c=.o)
#OBJBON = $(SRCBON:.c=.o)

.c.o :
#Pour MacOs
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
#Pour Linux
#	$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@

#$(V).SILENT:

all:	$(LDIR)/$(LIBFT) $(NAME)

$(NAME):	$(OBJ) $(SRC)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LDIR)$(LIBFT)
	@echo "$(LGREEN)MLX  pour MACOs ready !$(DEF_COLOR)"
#	$(CC) $(CFLAGS) $(OBJ) -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME) $(LDIR)$(LIBFT)
#	@echo "$(LGREEN)MLX  pour Linux ready !$(DEF_COLOR)"
#	$(AR) $(NAME) $(OBJ)
	@echo "$(LGREEN)Compilation complete !$(DEF_COLOR)"

$(LDIR)/$(LIBFT):
	make -C $(LDIR)
	@echo "$(LGREEN)LIBFT done... !$(DEF_COLOR)"

clean:
	$(RM) $(OBJ)
	$(RM) $(LDIR)*.o
	@echo "$(LCYAN)Objects files cleaned !$(DEF_COLOR)"

fclean:	clean
	$(RM) $(LDIR)$(LIBFT)
	$(RM) $(NAME)
	$(RM) *.o
	@echo "$(LCYAN)Executables files cleaned !$(DEF_COLOR)"

re:	fclean all