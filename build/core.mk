ARCADE_DIR	=	src/

ARCADE_SRCS	=	src/main.cpp \
			src/arcade.cpp

ARCADE_OBJS	=	$(ARCADE_SRCS:.cpp=.o)

core: $(ARCADE_OBJS)
	@$(CXX) -o $(ARCADE_NAME) $(CXXFLAGS) $(ARCADE_OBJS)
	@echo -e "[ARCADE][\033[0;32m OK \033[0m] built"