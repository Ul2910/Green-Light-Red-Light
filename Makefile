NAME	= green_light-red_light

SRCS	= main.c helpers.c keys_and_close.c create_img_digits.c animation_time_meters.c lose_win.c al.c

OBJS	= ${SRCS:.c=.o}

CFLAGS	= -Wall -Wextra -Werror

MLX_DIR = minilibx_opengl_20191021

%.o: %.c green_red_light.h
	gcc -c ${CFLAGS} -I . $< -o ${<:.c=.o}

${NAME}: ${OBJS} green_red_light.h
	ar rc liblight.a ${OBJS}
	ranlib liblight.a
	make -C ${MLX_DIR}
	cd ..
	gcc ${CFLAGS} ${MLX_DIR}/libmlx.a -lmlx -framework OpenGL -framework AppKit ${OBJS} -L. -llight -o ${NAME}

all:	${NAME}

clean:
	rm -f ${OBJS}
	make -C ${MLX_DIR} clean
	cd ..

fclean:	clean
	rm -f ${NAME} liblight.a

re: fclean all

.PHONY:	all fclean clean re








