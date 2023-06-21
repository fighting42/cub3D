# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yejinkim <yejinkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 20:25:24 by yejinkim          #+#    #+#              #
#    Updated: 2023/06/21 21:47:16 by yejinkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -L ./mlx -lmlx -framework OpenGL -framework Appkit

SRCS =  main.c 

OBJS = $(SRCS:.c=.o)

LDIR	=	libft

LIBFT 	=	$(LDIR)/libft.a


%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@

all 	:	
			make -C $(LDIR) 
			make $(NAME)

$(NAME) :	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(MLXFLAGS)
			
clean   :	
			make -C $(LDIR) clean
			$(RM) $(OBJS)

fclean  :	clean
			$(RM) $(LIBFT) $(NAME) 

re  :	fclean all

.PHONY  :	all clean fclean re