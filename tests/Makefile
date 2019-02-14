##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile of tests for malloc project
##

CC		=		gcc

CFLAGS		+=		-W -Wall -Wextra -g 

CFLAGS		+=		-I ../include -I ./include

CFLAGS		+=		$(DEBUG)

LDFLAGS		=	

NAME		=		unit-tests

SRCDIR		=		source

SRCS		=		source/basic.c

OBJDIR		=		build

OBJS		=		$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o,  $(SRCS))

all:		$(NAME)
		@echo "Done compiling $(NAME)"
		@echo "Executing tests:"
#		@make --no-print-directory run1
		@make --no-print-directory run2

run1:		$(NAME)
		@echo "---------GLIBC---------"
		@ ./$(NAME)

run2:
		@echo "---------MY---------"
		@ LD_PRELOAD=../libmy_malloc.so ./$(NAME)

$(NAME):	buildrepo $(OBJS)
		@echo "Linking $(NAME)"
		@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
		@echo "->" $<
		@$(CC) -c $< -o $@ $(CFLAGS)

libshow.so:
		$(CC) -o $@ $(CFLAGS) -fPIC -shared source/show.c

buildrepo:
		@$(call build-repo)

clean:
		@echo "Cleaning object files"
		@rm -rf $(OBJDIR)
		@rm -f libshow.so

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
