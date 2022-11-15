NAME = philo_bonus

HEADER_DIR = includes/
SRC_DIR = srcs/
LIB_DIR = libs/

HEADERS = philo_bonus.h

SRCS  = cleaner_bonus.c\
        logger.c\
        main_bonus.c\
        validations_bonus.c\
        initializer_bonus.c\
        processes_bonus.c\
        philo_life_bonus.c\

HEADER	=	$(addprefix $(HEADER_DIR), $(HEADERS))
SANIT_THREAD = gcc -fsanitize=thread $(CFLAGS)
SRC		=	$(addprefix $(SRC_DIR), $(SRCS))

LIBFT	= ./libs/libft/libft.a

OBJ 	= $(SRC:.c=.o)

CC		= gcc

CFLAGS	= -g -Wall -Werror -Wextra -pthread

RM		= rm -rf

all: $(NAME)

bonus: all

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
