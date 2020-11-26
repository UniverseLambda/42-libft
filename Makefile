.DEFAULT: all
.PHONY: all clean fclean re libft.a
.SUFFIXES: .c .o

NAME := libft.a

CC ?= cc
AR ?= ar

CFLAGS ?=
CFLAGS := $(CFLAGS) -Wall -Wextra -Werror

OBJS := ft_atoi.o \
		ft_bzero.o \
		ft_calloc.o \
		ft_isalnum.o \
		ft_isalpha.o \
		ft_isascii.o \
		ft_isdigit.o \
		ft_isprint.o \
		ft_itoa.o \
		ft_memccpy.o \
		ft_memchr.o \
		ft_memcmp.o \
		ft_memcpy.o \
		ft_memmove.o \
		ft_memset.o \
		ft_putchar_fd.o \
		ft_putendl_fd.o \
		ft_putnbr_fd.o \
		ft_putstr_fd.o \
		ft_split.o \
		ft_strchr.o \
		ft_strdup.o \
		ft_strjoin.o \
		ft_strlcat.o \
		ft_strlcpy.o \
		ft_strlen.o \
		ft_strmapi.o \
		ft_strncmp.o \
		ft_strnstr.o \
		ft_strrchr.o \
		ft_strtrim.o \
		ft_substr.o \
		ft_tolower.o \
		ft_toupper.o


BONUS_OBJS := ft_lstadd_back.o \
				ft_lstadd_front.o \
				ft_lstclear.o \
				ft_lstdelone.o \
				ft_lstiter.o \
				ft_lstlast.o \
				ft_lstmap.o \
				ft_lstnew.o \
				ft_lstsize.o

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: OBJS := $(OBJS) $(BONUS_OBJS)
bonus: $(BONUS_OBJS) all

test: all
	gcc -o test $(NAME) main.c
	./test
	rm -f test