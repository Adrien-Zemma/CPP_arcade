##
## EPITECH PROJECT, 2018
## arcade
## File description:
##
##


CXX	= g++

RM	= rm -f

ARCADE_NAME	=	arcade

CXXFLAGS = -I./inc
CXXFLAGS += -I./inc/games -I./inc/libs
CXXFLAGS += -W -Wall -Wextra
CXXFLAGS += -ldl
CXXFLAGS += -fpic

include build/core.mk
include build/graphicals.mk
include build/games.mk

all:	core games graphicals

clean:
	@echo -e "\033[1;46m clean OK \033[0m"
	@$(RM) $(NIBBLER_OBJS)
	@$(RM) $(PACMAN_OBJS)

	@$(RM) $(ALLEGRO_OBJS)
	@$(RM) $(NCURSE_OBJS)
	@$(RM) $(SFML_OBJS)

fclean:	clean
	@echo -e "\033[1;46m fclean OK \033[0m"
	@$(RM) $(ARCADE_NAME)

	@$(RM) $(GAME_COMPIL_DIR)$(NIBBLER_NAME)
	@$(RM) $(GAME_COMPIL_DIR)$(PACMAN_NAME)

	@$(RM) $(LIBS_COMPIL_DIR)$(ALLEGRO_NAME)
	@$(RM) $(LIBS_COMPIL_DIR)$(NCURSE_NAME)
	@$(RM) $(LIBS_COMPIL_DIR)$(SFML_NAME)

re: fclean all

#%.o: %.cpp
#	@$(CXX) -c -o $@ $(CXXFLAGS) $< 

.PHONY:	all games graphicals core clean fclean re
