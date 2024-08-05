# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpellegr <mpellegr@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 09:17:47 by mpellegr          #+#    #+#              #
#    Updated: 2024/05/07 10:29:05 by mpellegr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
		  ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		  ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		  ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c

BONUS_SOURCES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
				ft_lstmap_bonus.c


OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar rcs

RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

.bonus: $(BONUS_OBJECTS) $(OBJECTS)
	$(AR) $(NAME) $(BONUS_OBJECTS)
	@touch .bonus;

bonus: .bonus

%.o: %.c
	$(CC) $(CFLAGS) -c -I. $< -o $@

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)
	@$(RM) .bonus

fclean: clean
	$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re bonus
