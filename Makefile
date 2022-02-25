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
PURPLE	= \033[1;35m
RED	= \033[1;31m
CYAN	= \033[1;36m
NC	= \033[0m

C_FILE = $(shell find . -type f -name '*.c')


OUTPUT = a.out

NORM	= norminette -R CheckForbiddenSourceHeader
GCC 	= gcc -Wall -Wextra -Werror

all:
	@clear
	@echo "${RED}------------------------- Source -------------------------\n"
	@echo "function file: ${C_FILE}\n"
	@echo "${CYAN}\n----------------------- GCC OUTPUT -----------------------\n"
	@${GCC} ${C_FILE} -o ${OUTPUT}
	@echo "OUTPUT FILE: ${OUTPUT}"
	@echo ""
	@./${OUTPUT}
	@rm ${OUTPUT}
	@echo "\n----------------------------------------------------------${NC}\n"
