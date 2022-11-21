NAME = get_next_line.a
SOURCES = get_next_line.c get_next_line_utils.c
SBONUS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJECTS = $(SOURCES:.c=.o)
SOBJECT = $(SBONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) $(SOBJECT)
	ar -rc $@ $?

%.c : %.o get_next_line.h
	$(CC) $(CFLAGS) -c $<

bonus : $(SOBJECT)
	ar -rc $(NAME) $(SOBJECT)

clean:
	rm -f $(OBJECTS) $(SOBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean re fclean all