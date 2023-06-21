# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 20:25:24 by yejinkim          #+#    #+#              #
#    Updated: 2023/06/21 20:25:51 by yejinkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

SRCS =  main.c 

OBJS = $(SRCS:.c=.o)

all :	$(NAME)

$(NAME) :	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
			
clean   :	
			$(RM) $(OBJS)

fclean  :	clean
			$(RM) $(NAME)

re  :	fclean all

.PHONY  :	all clean fclean re