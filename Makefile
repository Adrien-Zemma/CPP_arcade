NAME	= program

CC	= 

RM	= rm -f

SRCS	= 

OBJS	= $(SRCS:.cpp=.o)

CFLAGS = -I
CFLAGS += -W -Wall -Wextra
LDLIBS = 

all: $(NAME)

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

%.o: %.cpp
	@g++ -c -o $@ $(CXXFLAGS) $<
	@echo -e "[\033[0;32m OK \033[0m] built '$@'"

.PHONY: all clean fclean re
