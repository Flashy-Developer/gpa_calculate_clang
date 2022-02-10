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

C_NOT_MAIN = $(shell find . -type f -name 'ft_*.c')

OUTPUT = c.out

NORM	= norminette -R CheckForbiddenSourceHeader
GCC 	= gcc -Wall -Wextra -Werror

all:
	@clear
	@echo "${RED}------------------------- Source -------------------------\n"
	@echo "function file: ${C_NOT_MAIN}\n"
	@cat ${C_NOT_MAIN}
	@echo "${PURPLE}\n----------------------- Norminette -----------------------\n"
	@${NORM} ${C_NOT_MAIN}
	@echo "${CYAN}\n----------------------- GCC OUTPUT -----------------------\n"
	@${GCC} ${C_FILE} -o ${OUTPUT}
	@echo "OUTPUT FILE: ${OUTPUT}"
	@echo ""
	@./${OUTPUT}
	@echo "\n----------------------------------------------------------${NC}\n"
norm:
	${NORM} ${SRCS}
