# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlamonic <jlamonic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 23:00:12 by jlamonic          #+#    #+#              #
#    Updated: 2022/03/09 23:00:12 by jlamonic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CLIBFLAGS = -lncurses

RM = rm
RMFLAGS = -rf

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

HEADERS = $(addprefix $(INC_DIR)/,) \
	minishell.h \

UTIL_DIR = $(SRC_DIR)/util
UTIL_SRC = $(addprefix $(UTIL_DIR)/,) \
	get_line.c
