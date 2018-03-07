GAME_DIR	=	src/games/
GAME_COMPIL_DIR	=	games/
GAME_FLAGS	=	-I./inc/games -W -Wall -Wextra

NIBBLER_SRCS	=	$(GAME_DIR)nibbler.cpp
NIBBLER_OBJS	=	$(NIBBLER_SRCS:.cpp=.o)
NIBBLER_NAME	=	nibbler.so

PACMAN_SRCS	=	$(GAME_DIR)pacman.cpp
PACMAN_OBJS	=	$(PACMAN_SRCS:.cpp=.o)
PACMAN_NAME	=	pacman.so

%.o: %.cpp
	@$(CXX) -c -o $@ $(CXXFLAGS) $< $(LIBS_FLAGS)

pacman: $(PACMAN_OBJS)
	@$(CXX) -shared -o $(GAME_COMPIL_DIR)$(PACMAN_NAME) $(GAME_FLAGS) $(PACMAN_OBJS)
	@echo -e "[GAMES][PACMAN][\033[0;32m OK \033[0m] built lib"

nibbler: $(NIBBLER_OBJS)
	@$(CXX) -shared -o $(GAME_COMPIL_DIR)$(NIBBLER_NAME) $(GAME_FLAGS) $(NIBBLER_OBJS)
	@echo -e "[GAMES][NIBBLER][\033[0;32m OK \033[0m] built lib"