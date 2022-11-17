NAME = get_next_line.a
SOURCES = get_next_line.c get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $@ $?

%.c : %.o get_next_line.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean re fclean all