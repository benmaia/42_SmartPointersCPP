NAME = smartptr

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98 -g

SRCS = $(SHARED_PTR)

SHARED_PTR = Shared_Ptr/main.cpp
WEAK_PTR = Shared_Ptr
UNIQUE_PTR = Shared_Ptr

OBJS =	$(SRCS:%.c=%.o)

%.o:	%.c
	@#echo "$(YELLOW)[       Compiling pipex ...      ]$(RESET)"	
	#@echo "$(GREEN)[ Creating ${@F} ]$(RESET)"
	@$(CC) $(FLAGS) -c $(^) -I./ -o $(@)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -I./ -o $(@)

clean :
	rm -f smartptr

re: clean all
