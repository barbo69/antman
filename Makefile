##
## EPITECH PROJECT, 2020
## B-CPE-110-LYN-1-1-pushswap-amoz.pay
## File description:
## Makefile
##

all:
	make -C antman
	make -C giantman

clean:
	make clean -C antman
	make clean -C giantman

fclean:
	make fclean -C antman
	make fclean -C giantman

re:	fclean all

.PHONY:	all clean fclean re
