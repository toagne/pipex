# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 09:17:47 by mpellegr          #+#    #+#              #
#    Updated: 2024/08/20 14:08:35 by mpellegr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = main.c utils.c error_check.c open.c print_errors.c parse_cmd.c create_path.c \
		  pids.c

OBJECTS = $(SOURCES:.c=.o)

BONUS_SOURCES = main_bonus.c utils.c error_check_bonus.c open.c print_errors.c parse_cmd.c \
				create_path.c pids.c here_doc.c get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

NAME = pipex

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

AR = ar rcs

RM = rm -f

LIBFT = ./libft

all: $(NAME)

$(NAME) : $(OBJECTS)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) libft/libft.a -o $(NAME)

.bonus: $(BONUS_OBJECTS)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJECTS) libft/libft.a -o $(NAME)
	@touch .bonus;

bonus: .bonus

clean:
	@make -C ./libft clean
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)
	@$(RM) .bonus

fclean: clean
	@make -C ./libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
