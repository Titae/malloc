##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile of tests for malloc project
##

CC		=		gcc

CFLAGS		+=		-W -Wall -Wextra -Werror

CFLAGS		+=		-I ../include -I ./include

CFLAGS		+=		$(DEBUG)

LDFLAGS		=		-l criterion -coverage

NAME		=		unit-tests

SRCDIR		=		source

SRCS		=		source/basic.c

OBJDIR		=		build

OBJS		=		$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o,  $(SRCS))

all:		$(NAME)
		@echo "Done compiling $(NAME)"
		@echo "Executing tests:"
		@ LD_PRELOAD=../libmy_malloc.so ./$(NAME)

$(NAME):	buildrepo $(OBJS)
		@echo "Linking $(NAME)"
		@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
		@echo "->" $<
		@$(CC) -c $< -o $@ $(CFLAGS)

buildrepo:
		@$(call build-repo)

clean:
		@echo "Cleaning object files"
		@rm -rf $(OBJDIR)


fclean:		clean
		@echo "Cleaning binary"
		@rm -f $(NAME)

re:		fclean all

define build-repo
	for dir in $(dir $(OBJS));	\
	do				\
		mkdir -p $$dir;		\
	done
endef

.PHONY: all tests_run buildrepo clean fclean re
