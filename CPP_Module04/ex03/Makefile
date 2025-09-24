NAME = materia

SRCSF = ./srcs/
INCLUDEF = ./includes

SRCS = $(SRCSF)AMateria.cpp \
       $(SRCSF)Character.cpp \
       $(SRCSF)Cure.cpp \
       $(SRCSF)Ice.cpp \
       $(SRCSF)MateriaSource.cpp \
       $(SRCSF)main.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g
IFLAGS = -I $(INCLUDEF)
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

