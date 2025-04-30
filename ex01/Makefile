NAME = phonebook

SRCS_FOLDER = ./srcs/
SRCS = $(SRCS_FOLDER)PhoneBook.cpp $(SRCS_FOLDER)Contact.cpp $(SRCS_FOLDER)main.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
