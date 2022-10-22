# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mhaan <mhaan@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/06 15:58:09 by mhaan         #+#    #+#                  #
#    Updated: 2022/10/22 15:08:31 by mhaan         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
		ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c 

BONUS =	ft_lstadd_front.c ft_lstnew.c

OBS 		= $(SRC:.c=.o)
BOBS		= $(BONUS:.c=.o)
DEPS		= libft.h

ifdef WITH_BONUS
OBJ_FILES = $(OBS) $(BOBS)
else
OBJ_FILES = $(OBS)
endif

CC = gcc
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar -cr $@ $^

%.o: %.c $(DEPS)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	/bin/rm -f $(OBS) $(BOBS)

fclean: clean
	/bin/rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

bonus:
	$(MAKE) WITH_BONUS=1 all

.PHONY = all clean fclean re bonus
