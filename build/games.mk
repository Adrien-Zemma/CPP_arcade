GAME_DIR	=	src/games/
GAME_COMPIL_DIR	=	games/
GAME_FLAGS	=	-fPIC -I./inc/games -W -Wall -Wextra

NIBBLER_SRCS	=	$(GAME_DIR)nibbler.cpp
NIBBLER_OBJS	=	$(NIBBLER_SRCS:.cpp=.o)
NIBBLER_NAME	=	libnibbler.so

PACMAN_SRCS	=	$(GAME_DIR)pacman.cpp
PACMAN_OBJS	=	$(PACMAN_SRCS:.cpp=.o)
PACMAN_NAME	=	libpacman.so

pacman: $(PACMAN_OBJS)
	@$(CXX) -shared -o $(GAME_COMPIL_DIR)$(PACMAN_NAME) $(GAME_FLAGS) $(PACMAN_OBJS)
	@echo -e "[GAMES][PACMAN][\033[0;32m OK \033[0m] built lib"

nibbler: $(NIBBLER_OBJS)
	@$(CXX) -shared -o $(GAME_COMPIL_DIR)$(NIBBLER_NAME) $(GAME_FLAGS) $(NIBBLER_OBJS)
	@echo -e "[GAMES][NIBBLER][\033[0;32m OK \033[0m] built lib"

%.o: %.cpp
	@$(CXX) -c -o $@ $(GAME_FLAGS) $< $(LIBS_FLAGS)