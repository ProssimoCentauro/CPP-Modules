NAME = check_triangle
ALTNAME = check_triangle_alternative
BSP = bsp


SRCS_FOLDER = ./srcs/
INCLUDES_FOLDER = ./includes

SRCS = $(SRCS_FOLDER)Point.cpp $(SRCS_FOLDER)Fixed.cpp $(SRCS_FOLDER)main.cpp
ALTSRCS = $(SRCS_FOLDER)Point.cpp $(SRCS_FOLDER)Fixed.cpp $(SRCS_FOLDER)main2.cpp
BSPSRCS = $(SRCS_FOLDER)Point.cpp $(SRCS_FOLDER)Fixed.cpp $(SRCS_FOLDER)main3.cpp

OBJS = $(SRCS:.cpp=.o)
ALTOBJS = $(ALTSRCS:.cpp=.o)
BSPOBJS = $(ALTSRCS:.cpp=.o)

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g
IFLAGS = -I $(INCLUDES_FOLDER)
RM = rm -f

all: $(NAME) $(ALTNAME) $(BSP)

classic: $(NAME)

alt: $(ALTNAME)

bsp: $(ALTNAME2)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) 

$(ALTNAME): $(ALTOBJS)
	$(CC) $(CPPFLAGS) $(IFLAGS) -o $(ALTNAME) $(ALTOBJS) 

$(BSP): $(ALTOBJS)
	$(CC) $(CPPFLAGS) $(IFLAGS) -o $(BSP) $(BSPOBJS) 

%.o: %.cpp
	$(CC) $(CPPFLAGS) $(IFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(ALTOBJS) $(BSPOBJS)

fclean: clean
	$(RM) $(NAME) $(ALTNAME) $(BSP)

re: fclean all

.PHONY: all clean fclean re
