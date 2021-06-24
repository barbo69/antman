##
## EPITECH PROJECT, 2020
## B-CPE-110-LYN-1-1-pushswap-amoz.pay
## File description:
## Makefile
##

TARGET		=	antman #ADD HERE TARGET NAME

SRCFILES	=	main.c\
				antppm_control.c\
				antppm_compression.c\
				open_file.c	\
				occurences_control.c	\
				conversion_to_bin.c\
				create_dict_v2.c\
				dict_dependencies.c\
				convert_char.c#ADD HERE SRC FILES NAME WITHOUT DIR NAME


CFLAGS		=	-I ../includes

CFLAGS		+=	-Wall -Wextra -g3

LDFLAGS		=	-L ../lib -lmy

TESTFILES	=	#ADD HERE UNIT TESTS FILES NAME

SRCDIR		=	src/

SRC		=	$(foreach file, $(SRCFILES), $(addprefix $(SRCDIR), $(file)))

OBJFILES	=	$(SRCFILES:.c=.o)

OBJDIR		=	obj/

OBJ		=	$(foreach file, $(OBJFILES), $(addprefix $(OBJDIR), $(file)))

TESTDIR		=	unit_tests/

TEST		=	$(foreach file, $(TESTFILES), $(addprefix $(TESTDIR), $(file)))

TESTNAME	=	crtests

CC		=	gcc


all: $(TARGET)
	@echo "\e[32m\e[1mBuild Successful\e[0m"

$(TARGET): bins
	@echo "\e[34m\e[1mBuilding AntMan\n\e[0m"
	@$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS)
lib:
	@echo "\e[34m\e[1mBuilding Lib\n\e[0m"
	@make -C ../lib/my
	@echo "\e[32m\e[1mLib build Successful\e[0m\n"

bins: lib
	@echo "\e[34m\e[1mBuilding Antman Binaries\n\e[0m"
	@$(CC) -c $(SRC) $(CFLAGS)
	@mv $(OBJFILES) $(OBJDIR)
	@echo "\e[32m\e[1mBinary build Successful\e[0m\n"

clean:
	@rm -f $(OBJ) $(OBJ)
	@make clean -C ../lib/my

fclean:
	@rm -f $(OBJ)
	@rm -f $(TARGET)
	@rm -f $(TESTNAME)
	@make fclean -C ../lib/my

re:	fclean all

$(TESTNAME):	lib
	@$(CC) -o $(TESTNAME) $(SRC_ANT) $(TEST) $(CFLAGS) $(LDFLAGS) --coverage -lcriterion
	./$(TESTNAME)

.PHONY:	all lib bins clean fclean re debug
