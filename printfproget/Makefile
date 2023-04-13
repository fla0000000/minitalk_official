FLAGS = -Wextra -Werror -Wall

NAME = printf.a

SRCS = ft_printf.c ft_printf1.c ft_printf2.c ft_atoi.c

OBJS = ${SRCS:.c=.o}

CC = gcc ${FLAGS}
RM = rm -f

.c.o:
	${CC} -g  -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}
	ranlib ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} 
re: fclean all
