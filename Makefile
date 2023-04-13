NAME_S = server
NAME_C = client
NAME_FT_PF = ./printfproget/printf.a
SRCS = server.c client.c
SERVER = server.c
CLIENT = client.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(%.c)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@make -C ./printfproget
	@$(CC) $(CFLAGS) $(NAME) $(SERVER) $(NAME_FT_PF) -o $(NAME_S)
	@$(CC) $(CFLAGS) $(NAME) $(CLIENT) $(NAME_FT_PF) -o $(NAME_C)

%.c: %.o
	@$(CC) $(CFLAGS) -o $<

clean:
	@rm -f $(OBJS)
	@make clean -C ./printfproget
	
fclean: clean
	@rm -f $(NAME_C) $(NAME_S)
	@make fclean -C ./printfproget
	
re: fclean all

.PHONY: all clean fclean re
