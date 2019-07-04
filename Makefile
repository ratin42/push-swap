# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Raphael <Raphael@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:46:26 by ratin             #+#    #+#              #
#    Updated: 2019/07/04 06:01:12 by Raphael          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker

SRC_PATH1		:=	src/push_swap
SRC_PATH2		:=	src/checker
OBJ_PATH		:=	obj
INC_PATH		:=	include
LIB_PATH		:=	libft

SRC_NAME1		:=	sort_pile.c \
					sort_work.c \
					mid_sort_replace.c \

SRC_NAME2		:=	parse.c \
					free.c \
					pile_list.c \
					debug.c \
					swap.c \
					push.c \
					rotate.c \
					reverse_rotate.c \
					move_gestion.c \


INC_NAME		:=	push_swap.h
LIB				:=	$(LIB_PATH)/libft.a
LIB_LINK		:=	-L $(LIB_PATH) -lft
OBJ1			:=	$(addprefix $(OBJ_PATH)/,$(SRC_NAME1:.c=.o))
OBJ2			:=	$(addprefix $(OBJ_PATH)/,$(SRC_NAME2:.c=.o))
INCS			:=	-I $(LIB_PATH)/$(INC_DIR) -I $(INC_DIR)
CC				:=	gcc
CFLAGS			:=	-Wall -Wextra -Werror
C_GREEN			:=	"\033[32m"
C_BLUE			:=	"\033[36m"
C_BASE			:=	"\033[00m"
PRINTF=test $(VERBOSE)$(TRAVIS) || printf


all: obj $(LIB) $(NAME1) $(NAME2)

$(LIB):
	@make -C $(LIB_PATH)
	@ @$(PRINTF) "Libft:	"
	@ @$(PRINTF) "\x1b[32m✔\x1b[0m\n\n"

$(NAME1): $(OBJ1) $(OBJ2) obj/push_swap.o
	@$(CC) $(CFLAGS) obj/push_swap.o $(OBJ1) $(OBJ2) $(LIB) -o $@

$(NAME2): $(OBJ2) obj/checker.o
	@ @echo $(C_GREEN)"----" $(C_BASE)
	@$(CC) $(CFLAGS) obj/checker.o $(OBJ2) $(LIB) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH1)/%.c $(INC_PATH)/*
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH)/
	@ @echo "file =" $(C_BLUE){ $< } $(C_BASE)

$(OBJ_PATH)/%.o: $(SRC_PATH2)/%.c $(INC_PATH)/*
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH)/
	@ @echo "file =" $(C_BLUE){ $< } $(C_BASE)

obj:
	@mkdir -p obj

clean:
	@rm -rf $(OBJ) $(LIB_PATH)/*.o
	@rm -rf obj

fclean: clean
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@make -C $(LIB_PATH) fclean

re: fclean all

.PHONY: all fclean clean re norme
