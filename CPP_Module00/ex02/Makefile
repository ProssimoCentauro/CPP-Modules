NAME = do_tests

SRCS_FOLDER = ./srcs/
INCLUDES_FOLDER = ./includes
SRCS = $(SRCS_FOLDER)Account.cpp $(SRCS_FOLDER)tests.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g
IFLAGS = -I $(INCLUDES_FOLDER)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) 

%.o: %.cpp
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
