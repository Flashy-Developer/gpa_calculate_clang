# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptippaya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 21:14:06 by ptippaya          #+#    #+#              #
#    Updated: 2022/01/31 10:41:54 by ptippaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_NOT_MAIN = $(shell find . -type f -name 'ft_*.c')
C_MAIN = $(shell find . -type f -name 'main.c')
C_TEST = $(shell find . -type f -name 'test.c')

OUTPUT = a.out

NORM	= norminette -R CheckForbiddenSourceHeader
GCC 	= gcc -Wall -Wextra -Werror

$(OUTPUT): all

all:
	@clear
	@printf '\x1b[38;5;198m------------------------- Source -------------------------\n\n\e[0m'
	@echo "function file: ${C_MAIN} ${C_NOT_MAIN}\n"
	@printf '\x1b[38;5;128m----------------------- GCC OUTPUT -----------------------\n\n\e[0m'
	@${GCC} ${C_MAIN} ${C_NOT_MAIN} -o ${OUTPUT}
	@echo "OUTPUT FILE: ${OUTPUT}"
	@echo ""
	@./${OUTPUT}

test:
	@clear
	@printf '\x1b[38;5;198m------------------------- Source -------------------------\n\n\e[0m'
	@echo "function file: ${C_TEST} ${C_NOT_MAIN}\n"
	@printf '\x1b[38;5;128m----------------------- GCC OUTPUT -----------------------\n\n\e[0m'
	@${GCC} ${C_TEST} ${C_NOT_MAIN} -o ${OUTPUT}
	@echo "OUTPUT FILE: ${OUTPUT}"
	@echo ""
	@./${OUTPUT}

clear:
	@rm $(shell find . -type f -name '*.out') $(shell find . -type f -name '*.txt') $(shell find . -type f -name '*.exe')
