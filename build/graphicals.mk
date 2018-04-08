LIBS_DIR	=	src/libs/
LIBS_COMPIL_DIR	=	lib/

NCURSE_SRCS	=	$(LIBS_DIR)libncurses.cpp
NCURSE_OBJS	=	$(NCURSE_SRCS:.cpp=.o)
NCURSE_NAME	=	$(LIBS_COMPIL_DIR)lib_arcade_ncurse.so
NCURSE_FLAGS	=	-lncurses

SFML_SRCS	=	$(LIBS_DIR)libsfml.cpp
SFML_OBJS	=	$(SFML_SRCS:.cpp=.o)
SFML_NAME	=	$(LIBS_COMPIL_DIR)lib_arcade_sfml.so
SFML_FLAGS	=	-L./lib/sfml/ -lsfml-window -lsfml-graphics  -lsfml-audio

LDFLAGS		=	-shared

graphicals:	sfml ncurse 

sfml: $(SFML_OBJS)
	@$(CXX) $(LDFLAGS) $(CXXFLAGS) $(SFML_FLAGS) -o $(SFML_NAME) $(SFML_OBJS)
	@echo -e "[LIB][SFML][\033[0;32m OK \033[0m] built"

ncurse: $(NCURSE_OBJS)
	@$(CXX) $(LDFLAGS) $(CXXFLAGS) $(NCURSE_FLAGS) -o $(NCURSE_NAME) $(NCURSE_OBJS)
	@echo -e "[LIB][NCURSE][\033[0;32m OK \033[0m] built"
