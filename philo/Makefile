NAME = philo

HEADER_DIR = includes/
SRC_DIR = srcs/
LIB_DIR = libs/

HEADERS = philo.h

SRCS  = main.c\
		validations.c\
		initializer.c\
		philo_life.c\
		threads.c\
		cleaner.c\
		logger.c\

HEADER	=	$(addprefix $(HEADER_DIR), $(SRCS))
SRC		=	$(addprefix $(SRC_DIR), $(SRCS))

LIBFT	= ./libs/libft/libft.a

OBJ 	= $(SRC:.c=.o)

CC		= gcc

SANIT_THREAD = gcc -fsanitize=thread $(CFLAGS)

CFLAGS	= -g -Wall -Werror -Wextra -pthread

RM		= rm -rf

all: $(NAME)

$(NAME): ${LIBFT} ${OBJ}
	${CC} ${CFLAGS} ${OBJ} ${LIBFT} -o ${NAME}

${LIBFT}:
	make -C ./libs/libft

%.o : %.c  ${HEADER}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJ}
	make -C ./libs/libft clean

fclean: clean
	RM ${NAME}
	RM ${LIBFT}

re: fclean all

norme:
	norminette $(HEADER_DIR) $(SRC_DIR) $(SRC_DIR)

sanit_thread : ${LIBFT}
	$(SANIT_THREAD) $(SRC) ${LIBFT} -o $(NAME)

.PHONY:		all clean fclean re norme
