ARCADE_DIR	=	src/
ARCADE_FLAGS	=	-fPIC -I./inc/ -I./inc/games -I./inc/libs -W -Wall -Wextra

ARCADE_SRCS	=	$(ARCADE_DIR)arcade.cpp \
			$(ARCADE_DIR)main.cpp 

ARCADE_OBJS	=	$(PACMAN_SRCS:.cpp=.o)

ARCADE_NAME	=	arcade

arcade: $(ARCADE_OBJS)
	@$(CXX) -o $(ARCADE_NAME) $(ARCADE_FLAGS) $(ARCADE_OBJS)
	@echo -e "[ARCADE][\033[0;32m OK \033[0m] built"

$(NAME): $(OBJS)
	@$(CXX) $(ARCADE_FLAGS) -o $(NAME) $(OBJS) $(LDLIBS)



%.o: %.cpp
	@$(CXX) -c -o $@ $(ARCADE_FLAGS) $< 