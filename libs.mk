LIBS_DIR	=	src/libs/
LIBS_COMPIL_DIR	=	lib/
LIBS_FLAGS	=	-I./inc/libs -W -Wall -Wextra

ALLEGRO_SRCS	=	$(LIBS_DIR)liballegro.cpp
ALLEGRO_OBJS	=	$(ALLEGRO_SRCS:.cpp=.o)
ALLEGRO_NAME	=	liballegro.so

NCURSE_SRCS	=	$(LIBS_DIR)libncurse.cpp
NCURSE_OBJS	=	$(NCURSE_SRCS:.cpp=.o)
NCURSE_NAME	=	libncurse.so

SFML_SRCS	=	$(LIBS_DIR)libsfml.cpp
SFML_OBJS	=	$(SFML_SRCS:.cpp=.o)
SFML_NAME	=	libsfml.so

allegro: $(ALLEGRO_OBJS)
	@$(CXX) -shared -o $(LIBS_COMPIL_DIR)$(ALLEGRO_NAME) $(ALLEGRO_OBJS)
	@echo -e "[LIB][ALLEGRO][\033[0;32m OK \033[0m] built"

ncurse: $(NCURSE_OBJS)
	@$(CXX) -shared -o $(LIBS_COMPIL_DIR)$(NCURSE_NAME) $(LIBS_FLAGS) $(NCURSE_OBJS)
	@echo -e "[LIB][NCURSE][\033[0;32m OK \033[0m] built"

sfml: $(SFML_OBJS)
	@$(CXX) -shared -o $(LIBS_COMPIL_DIR)$(SFML_NAME) $(LIBS_FLAGS) $(SFML_OBJS)
	@echo -e "[LIB][SFML][\033[0;32m OK \033[0m] built"