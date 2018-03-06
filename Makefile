NAME	= program

LIBSFML = libsfml.so

PACMAN	= pacman.so

CC	= 

RM	= rm -f

SRCS	= 

SRCSSFML= ./src/libs/libsfml.cpp

OBJS	= $(SRCS:.cpp=.o)

CFLAGS = -I./inc
CFLAGS += -W -Wall -Wextra

all: $(NAME)

libs: $(LIBSFML)

$(LIBSFML): 
	 @$(CXX) -shared -o $(LIBSFML) $(CFLAGS) -fPC $(SRCSSFML)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) $(LDLIBS)
clean:
	@echo -e "\033[1;46m clean OK \033[0m"
	@$(RM) $(OBJS)

fclean:
	@echo -e "\033[1;46m fclean OK \033[0m"
	@$(RM) $(OBJS)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
