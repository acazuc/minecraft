CPP = clang++-3.5

CPPFLAGS = -Wall -Wextra -Werror -Ofast

SRCS_PATH = srcs/

OBJS_PATH = objs/

INCLUDES_PATH = includes/

SRCS_NAME = Main.cpp Window.cpp EventListener.cpp World.cpp Chunk.cpp Block.cpp Player.cpp Texture.cpp

OBJS_NAME = $(SRCS_NAME:.cpp=.opp)

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

NAME = minecraft

LIBRARY = -lsfml-graphics -lsfml-window -lsfml-system -lglut -lGL -lGLU -lGLEW -lz -I/usr/local/lib/ -lpng16 -lpng

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[1;32m"
	@echo "                                      AKEFILEMA                         (c) Tchang     "
	@echo "                                  KEFILEMAKEFILEMAK                                    "
	@echo "                              EFILEMAKEFILEMAKEFILEMAK                                 "
	@echo "                      EFILEMAKEFILEMA           KEFILEMA                               "
	@echo "                   KEFILEMAKEFIL                  EMAKEFI                              "
	@echo "                 LEMAKEFILEMAKEF                   ILEMAK                              "
	@echo "                 EFILEMAKEFILEMAK                   EFILE          COMPILATION         "
	@echo "                 MAKEFILEMAK EFILEM    AKEFILEMAKE  FILEM             DONE             "
	@echo "                 AKEFILEMAKEFILEMAKE FILEMAKEFI  MAK EFIL        CONGRATULATION        "
	@echo "                 EMAKEFILEMAKEFILE  MAKEFILEMAK  ILEMAKEF        ______ _______        "
	@echo "                ILEMA  KEFILEMAKEF  ILEMAKEFI    KEFILEMA             |/               "
	@echo "               KEFILEMAKEFILEMAKEFI LEMAKEFI    AKEFILEMA                              "
	@echo "              KEFILEMAKEFILEMAKEF   ILEMAKEFILEMAKEFILEMA                              "
	@echo "             KEFILEMAKEFILEMAKEFILEMAKEFILEMAKEFI  LEMAK                               "
	@echo "            EFILE          MAKEFILEMAKEFILEMA     KEFILE                               "
	@echo "           MAKEF                      ILEMAKE     FILEMA                               "
	@echo "          KEFILE                                 MAKEFI                                "
	@echo "         LEMAKE                                 FILEMA                                 "
	@echo "        KEFILE                                  MAKEFI                                 "
	@echo "        LEMAK                      EFIL        EMAKEF                                  "
	@echo "        ILEM                      AKEFI LEM   AKEFIL                                   "
	@echo "        EMAK                      EFILEMAKEF  ILEMA                         KEFILEMAK  "
	@echo "       EFILE                      MAKEFILEM  AKEFI                        LEMAKEFILEMA "
	@echo "       KEFIL                     EMAKEFILEM AKEFI                       LEMAKE    FILE "
	@echo "       MAKEF                     ILEMAKEFI  LEMAK                     EFILEMA    KEFIL "
	@echo "       EMAKE                    FILEMAKEF  ILEMAK                   EFILEMA     KEFIL  "
	@echo "       EMAKE                    FILEMAKE   FILEMAKEFILEMAKEFILE   MAKEFIL     EMAKE    "
	@echo "        FILE                   MAKEFILE    MAKEFILEMAKEFILEMAKEFILEMAKE      FILEM     "
	@echo "        AKEF                   ILEMAKE     FILEM   AKEFI   LEMAKEFILE      MAKEFI      "
	@echo "        LEMA                  KEFILEMA      KEF   ILEMAKEFILEMAKEFI      LEMAKE        "
	@echo "        FILEM               AKEFI LEMAK         EFILEMAKEFILEMAKEF     ILEMAKE         "
	@echo "         FILE             MAKEF  ILEMAKE         FILEMAKEFILEMAKEFIL   EMAKEFIL        "
	@echo "         EMAKE            FILEMAKEFILEMA                     KEFILEMA    KEFILEMAK     "
	@echo "          EFILE            MAKEFILEMAKE              FILE       MAKEFI  LEMA KEFIL     "
	@echo "          EMAKEF              ILEM                   AKEF        ILEMAK  EFILEMAK      "
	@echo "           EFILEM                                AKE              FILEM    AKEF        "
	@echo "            ILEMAKEF                            ILEM              AKEFI     LEMA       "
	@echo "               KEFILEM                          AKEF              ILEMAKEFILEMAK       "
	@echo "     EFI        LEMAKEFILE                       MAKE           FILEMAKEFILEMAK        "
	@echo "    EFILEMA    KEFILEMAKEFILEMAK                  EFI         LEMAKEF    I             "
	@echo "    LEMAKEFILEMAKE FILEMAKEFILEMAKEFILEM           AKEF    ILEMAKE                     "
	@echo "    FILE MAKEFILEMAKEFI    LEMAKEFILEMAKEF ILEMAKEFILEMAKEFILEMA                       "
	@echo "     KEFI  LEMAKEFILE         MAKEFILEMAK EFILEMAKEFILEMAKEFI                          "
	@echo "      LEMA   KEFILE         MAKEFILEMAKE FILEM AKEFILEMAKE                             "
	@echo "       FILEMAKEFI           LEMAKEFILEM  AKEF                                          "
	@echo "        ILEMAKE              FILEMAKE   FILE                                           "
	@echo "          MAK                EFILEM    AKEF                                            "
	@echo "                              ILEMAK  EFIL                                             "
	@echo "                               EMAKEFILEM                                              "
	@echo "                                 AKEFILE                                               "
	@echo "                                   MAK                                                 "
	@echo "\033[1;0m"
	@$(CPP) $(CPPFLAGS) -o $(NAME) $^ $(LIBRARY) -I$(INCLUDES_PATH)

$(OBJS_PATH)%.opp: $(SRCS_PATH)%.cpp
	@echo " - Compiling $<"
	@$(CPP) $(CPPFLAGS) -I$(INCLUDES_PATH) -o $@ -c $<

.PHONY: clean fclean re run

clean:
	@echo " - Clearing objects files"
	@rm -f $(OBJS)

fclean: clean
	@echo " - Clearing executable file"
	@rm -f $(NAME)

re: fclean all

run: all
	@echo " - Running"
	@./$(NAME)
