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
C_FILE = *.c
C_FILE_LIB = ../src/encode.c ../src/file.c

OUTPUT = a.exe

GCC 	= gcc -Wall -Wextra -Werror

all:
	@cls
	@echo ------------------------- Source -------------------------
	@echo function file: ${C_FILE}
	@echo ---------------------- GCC COMPLIER ----------------------
	@${GCC} ${C_FILE} ${C_FILE_LIB} -o ${OUTPUT}
	@echo ----------------------- GCC OUTPUT -----------------------
	@echo OUTPUT FILE: ${OUTPUT}
	@./${OUTPUT}
	@echo ----------------------------------------------------------