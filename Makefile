CXX	= g++

RM	= rm -f

CXXFLAGS = -I./inc
CXXFLAGS += -W -Wall -Wextra

include build/games.mk
include build/graphicals.mk
include build/arcade.mk


all:	core games graphicals

core:	arcade

games:	pacman nibbler 

graphicals:	sfml allegro ncurse

clean:
	@echo -e "\033[1;46m clean OK \033[0m"
	@$(RM) $(NIBBLER_OBJS)
	@$(RM) $(PACMAN_OBJS)

	@$(RM) $(ALLEGRO_OBJS)
	@$(RM) $(NCURSE_OBJS)
	@$(RM) $(SFML_OBJS)

fclean:	clean
	@echo -e "\033[1;46m fclean OK \033[0m"
	@$(RM) $(GAME_COMPIL_DIR)$(NIBBLER_NAME)
	@$(RM) $(GAME_COMPIL_DIR)$(PACMAN_NAME)

	@$(RM) $(LIBS_COMPIL_DIR)$(ALLEGRO_NAME)
	@$(RM) $(LIBS_COMPIL_DIR)$(NCURSE_NAME)
	@$(RM) $(LIBS_COMPIL_DIR)$(SFML_NAME)

re: fclean all

.PHONY:	all games graphicals core clean fclean re
