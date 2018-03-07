CXX	= g++

RM	= rm -f

CFLAGS = -I./inc
CFLAGS += -W -Wall -Wextra



all: games libs

include games.mk
include libs.mk

games: pacman nibbler

libs:	allegro sfml ncurse

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

.PHONY: all games clean fclean re
