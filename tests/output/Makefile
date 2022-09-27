SRCS	=	main.cpp Fixed.cpp OutputTest.cpp \
			OutputTestVector.cpp

FT_OBJSDIR	=	objs_ft
FT_OBJS		=	$(addprefix $(FT_OBJSDIR)/, $(SRCS:.cpp=.o))
FT_DEPS		=	$(addprefix $(FT_OBJSDIR)/, $(SRCS:.cpp=.d))

STD_OBJSDIR	=	objs_std
STD_OBJS	=	$(addprefix $(STD_OBJSDIR)/, $(SRCS:.cpp=.o))
STD_DEPS	=	$(addprefix $(STD_OBJSDIR)/, $(SRCS:.cpp=.d))

INCLUDESDIR	= ../../includes
INCLUDE =	-I$(INCLUDESDIR)

FT_NAME		=	output_ft
STD_NAME	=	output_std

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror
CFLAGS	+=	-g -fsanitize=address
CFLAGS	+=	-MMD -MP
CFLAGS	+=	-std=c++98
RM		=	rm -rf

all			:	$(FT_NAME) $(STD_NAME)

$(FT_NAME)	:	$(FT_OBJS)
				$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(FT_OBJS)

$(STD_NAME)	:	$(STD_OBJS)
				$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(STD_OBJS)

$(FT_OBJSDIR)/%.o	:	%.cpp
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

$(STD_OBJSDIR)/%.o	:	%.cpp
			@mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

-include $(FT_DEPS) $(STD_DEPS)

test		:	ft_test std_test

ft_test		:	$(FT_NAME)
				@echo
				@./$(FT_NAME) $(SEED) | tee result_ft.txt

std_test	:	CFLAGS += -D NAMESPACE_STD
std_test	:	$(STD_NAME)
				@echo
				@./$(STD_NAME) $(SEED) | tee result_std.txt

clean		:
				-$(RM) $(FT_OBJS) $(FT_DEPS) $(STD_OBJS) $(STD_DEPS)

fclean		:	clean
				-$(RM) $(FT_NAME) $(STD_NAME)

re			:	fclean all

ifeq ($(shell uname),Darwin)
leak		:	CC		=	/usr/local/opt/llvm/bin/clang++
endif
leak		:	CFLAGS	+=	-g -fsanitize=leak
leak		:	re

.PHONY		:	all clean fclean re leak test ft_test std_test
