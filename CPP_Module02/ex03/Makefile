NAME = bsp
ALTNAME = bspAlternative


SRCS_FOLDER = ./srcs/
INCLUDES_FOLDER = ./includes

SRCS = $(SRCS_FOLDER)Point.cpp $(SRCS_FOLDER)Fixed.cpp $(SRCS_FOLDER)main.cpp
ALTSRCS = $(SRCS_FOLDER)Point.cpp $(SRCS_FOLDER)Fixed.cpp $(SRCS_FOLDER)main2.cpp

OBJS = $(SRCS:.cpp=.o)
ALTOBJS = $(ALTSRCS:.cpp=.o)

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g
IFLAGS = -I $(INCLUDES_FOLDER)
RM = rm -f

all: $(NAME) $(ALTNAME)

classic: $(NAME)

alt: $(ALTNAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) 

$(ALTNAME): $(ALTOBJS)
	$(CC) $(CPPFLAGS) $(IFLAGS) -o $(ALTNAME) $(ALTOBJS) 

%.o: %.cpp
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(ALTOBJS)

fclean: clean
	$(RM) $(NAME) $(ALTNAME)

re: fclean all

.PHONY: all clean fclean re
