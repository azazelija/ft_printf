# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fculator <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 19:19:30 by fculator          #+#    #+#              #
#    Updated: 2019/11/09 19:19:32 by fculator         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS_PATH = src

SRCS_FILES = ft_printf.c\
				format_type.c \
				parse_format.c \
				printf_int.c \
				printf_str.c \
				printf_additional_char.c \
				ft_put_space.c \
				precision.c \
				printf_additional_char_str.c \
				reload_width_pointer.c \
				all_for_float.c \
				reload_float.c \

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_FILES))

OBJ_PATH = obj

OBJS = $(addprefix $(OBJ_PATH)/, $(SRCS_FILES:.c=.o))

FLAGS = -Wall -Wextra -Werror

H_PATH = includes

LIB_PATH = libft

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_PATH)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "libftprintf.a created"

$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c $(H_PATH)/ft_printf.h
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) -I $(H_PATH) -I $(LIB_PATH) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH

fclean:
	@rm -f $(NAME)
	@rm -f $(OBJS)
	@rm -rf $(OBJ_PATH)
	@make fclean -C $(LIB_PATH)

re: fclean all
