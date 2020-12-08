.DEFAULT: all
.PHONY: all clean fclean re
.SUFFIXES: .c .o

NAME := libft.a

CC ?= cc
AR ?= ar

CFLAGS ?=
CFLAGS := $(CFLAGS) -Wall -Wextra -Werror -Iinc

OBJS := src/base/ft_atoi.o \
		src/base/ft_bzero.o \
		src/base/ft_calloc.o \
		src/base/ft_isalnum.o \
		src/base/ft_isalpha.o \
		src/base/ft_isascii.o \
		src/base/ft_isdigit.o \
		src/base/ft_isprint.o \
		src/base/ft_itoa.o \
		src/base/ft_memccpy.o \
		src/base/ft_memchr.o \
		src/base/ft_memcmp.o \
		src/base/ft_memcpy.o \
		src/base/ft_memmove.o \
		src/base/ft_memset.o \
		src/base/ft_putchar_fd.o \
		src/base/ft_putendl_fd.o \
		src/base/ft_putnbr_fd.o \
		src/base/ft_putstr_fd.o \
		src/base/ft_split.o \
		src/base/ft_strchr.o \
		src/base/ft_strdup.o \
		src/base/ft_strjoin.o \
		src/base/ft_strlcat.o \
		src/base/ft_strlcpy.o \
		src/base/ft_strlen.o \
		src/base/ft_strmapi.o \
		src/base/ft_strncmp.o \
		src/base/ft_strnstr.o \
		src/base/ft_strrchr.o \
		src/base/ft_strtrim.o \
		src/base/ft_substr.o \
		src/base/ft_tolower.o \
		src/base/ft_toupper.o \
		src/base/ft_lstadd_back.o \
		src/base/ft_lstadd_front.o \
		src/base/ft_lstclear.o \
		src/base/ft_lstdelone.o \
		src/base/ft_lstiter.o \
		src/base/ft_lstlast.o \
		src/base/ft_lstmap.o \
		src/base/ft_lstnew.o \
		src/base/ft_lstsize.o\
		src/ft_printf/ft_nbr_utils.o \
		src/ft_printf/ft_parser.o \
		src/ft_printf/ft_printers_nbr.o \
		src/ft_printf/ft_printers.o \
		src/ft_printf/ft_printf.o

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	gcc -o test $(NAME) main.c
	./test
	rm -f test