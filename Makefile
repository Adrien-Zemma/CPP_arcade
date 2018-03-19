##
## EPITECH PROJECT, 2018
## arcade
## File description:
##
##


CXX	= g++

RM	= rm -f

ARCADE_NAME	=	arcade

CXXFLAGS = -I./inc -I./inc/games -I./inc/libs
CXXFLAGS += -W -Wall -Wextra -L
CXXFLAGS += -ldl
CXXFLAGS += -lsfml -lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS += -fPIC
CXXFLAGS += -lncurses



all:	core games graphicals

include build/core.mk
include build/graphicals.mk
include build/games.mk

clean:
	@echo -e "\033[1;46m clean OK \033[0m"
	@$(RM) $(NIBBLER_OBJS)
	@echo -e "\033[31m	$(NIBBLER_OBJS) \033[0m"
	@$(RM) $(PACMAN_OBJS)
	@echo -e "\033[31m	$(PACMAN_OBJS) \033[0m"

	@$(RM) $(ALLEGRO_OBJS)
	@echo -e "\033[31m	$(ALLEGRO_OBJS) \033[0m"
	@$(RM) $(NCURSE_OBJS)
	@echo -e "\033[31m	$(NCURSE_OBJS) \033[0m"
	@$(RM) $(SFML_OBJS)
	@echo -e "\033[31m	$(SFML_OBJS) \033[0m"

fclean:	clean
	@echo -e "\033[1;46m fclean OK \033[0m"
	@$(RM) $(ARCADE_NAME)
	@echo -e "\033[31m	$(ARCADE_NAME) \033[0m"

	@$(RM) $(GAME_COMPIL_DIR)$(NIBBLER_NAME)
	@echo -e "\033[31m	$(GAME_COMPIL_DIR)$(NIBBLER_NAME) \033[0m"
	@$(RM) $(GAME_COMPIL_DIR)$(PACMAN_NAME)
	@echo -e "\033[31m	$(GAME_COMPIL_DIR)$(PACMAN_NAME) \033[0m"

	@$(RM) $(LIBS_COMPIL_DIR)$(ALLEGRO_NAME)
	@echo -e "\033[31m	$(LIBS_COMPIL_DIR)$(ALLEGRO_NAME) \033[0m"
	@$(RM) $(LIBS_COMPIL_DIR)$(NCURSE_NAME)
	@echo -e "\033[31m	$(LIBS_COMPIL_DIR)$(NCURSE_NAME) \033[0m"
	@$(RM) $(LIBS_COMPIL_DIR)$(SFML_NAME)
	@echo -e "\033[31m	$(LIBS_COMPIL_DIR)$(SFML_NAME) \033[0m"

re: fclean all

#%.o: %.cpp
#	@$(CXX) -c -o $@ $(CXXFLAGS) $< 

.PHONY:	all games graphicals core clean fclean re
