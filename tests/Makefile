SRCSDIR	= ../srcs
vpath	%.cpp	$(SRCSDIR)

SRCS	=	type_traits_test.cpp \
			vector_iterator_test.cpp \
			reverse_iterator_test.cpp \
			algorithm_test.cpp \
			vector_test.cpp \
			pair_test.cpp \
			map_test.cpp \
			avl_tree_test.cpp \
			avl_tree_iterator_test.cpp

OBJSDIR	=	objs
OBJS	=	$(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
DEPS    =	$(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.d))

INCLUDE =	-I$(SRCSDIR)

NAME	=	unit_test

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror
CFLAGS	+=	-g -fsanitize=address
CFLAGS	+=	-MMD -MP
CFLAGS	+=	-std=c++11
LINK	=	-lgtest
LINK	+=	-lgtest_main
RM		=	rm -rf

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(LINK) $(INCLUDE) -o $@ $(OBJS)

$(OBJSDIR)/%.o	:	%.cpp
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

-include $(DEPS)

test		:	all
				@echo
				@./$(NAME) || :

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

testlib		:
				c++ -Wall -Wextra -Werror -g -fsanitize=address -std=c++98 \
					-I../srcs -Itestlib -I./ -DTESTLIB \
					-o unit_test testlib/testlib_main.cpp
				@./$(NAME) || :

.PHONY		:	all clean fclean re leak test testlib
