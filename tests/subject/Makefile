INCLUDESDIR	= ../../includes

SRCS	=	main.cpp

OBJSDIR	=	objs
OBJS	=	$(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
DEPS    =	$(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.d))

INCLUDE =	-I$(INCLUDESDIR)

NAME	=	subject_test

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror
CFLAGS	+=	-g -fsanitize=address
CFLAGS	+=	-MMD -MP
CFLAGS	+=	-std=c++98
RM		=	rm -rf

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(OBJS)

$(OBJSDIR)/%.o	:	%.cpp
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

-include $(DEPS)

test		:	all
				@echo
				@./$(NAME) $(SEED) || :

clean		:
				-$(RM) $(OBJS) $(DEPS)

fclean		:	clean
				-$(RM) $(NAME)

re			:	fclean all

ifeq ($(shell uname),Darwin)
leak		:	CC		=	/usr/local/opt/llvm/bin/clang++
endif
leak		:	CFLAGS	+=	-g -fsanitize=leak
leak		:	re

.PHONY		:	all clean fclean re leak
