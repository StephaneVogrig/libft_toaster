# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 23:35:34 by svogrig           #+#    #+#              #
#    Updated: 2023/11/15 22:14:43 by svogrig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
# variables libraries                                                          #
#------------------------------------------------------------------------------#

LIBFT_DIR	:=	../
LIBS		:=	ft \
                bsd
LIBS_TARGET	:=	$(LIBFT_DIR)/libft/libft.a

LDFLAGS		:=	$(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS		:=	$(addprefix -l,$(LIBS))

#------------------------------------------------------------------------------#
# variables libft_toaster                                                      #
#------------------------------------------------------------------------------#

NAME        :=  libft_toaster
INCS		:=	include \
				$(LIBFT_DIR)/libft

PART_1_DIR	:=	part_1
SRCS_PART_1	:=	isalpha_tests.c \
				isdigit_tests.c \
				isalnum_tests.c \
				isascii_tests.c \
				isprint_tests.c \
				strlen_tests.c \
				memset_tests.c \
				bzero_tests.c \
				memcpy_tests.c \
				memmove_tests.c \
				strlcpy_tests.c \
				strlcat_tests.c \
				toupper_tests.c \
				tolower_tests.c \
				strchr_tests.c \
				strrchr_tests.c \
				strncmp_tests.c \
				memchr_tests.c \
				memcmp_tests.c \
				strnstr_tests.c	\
				atoi_tests.c \
				calloc_tests.c \
				strdup_tests.c
SRCS_PART_1	:=	$(SRCS_PART_1:%=$(PART_1_DIR)/%)

PART_2_DIR	:=	part_2
SRCS_PART_2	:=	substr_tests.c \
				strjoin_tests.c \
				strtrim_tests.c \
				split_tests.c \
				itoa_tests.c \
				strmapi_tests.c \
				striteri_tests.c \
				putchar_fd_tests.c \
				putstr_fd_tests.c \
				putendl_fd_tests.c \
				putnbr_fd_tests.c
SRCS_PART_2	:=	$(SRCS_PART_2:%=$(PART_2_DIR)/%)

BONUS_DIR	:=	bonus
SRCS_BONUS	:=	lstnew_tests.c \
				lstadd_front_tests.c \
				lstsize_tests.c \
				lstlast_tests.c \
				lstadd_back_tests.c \
				lstdelone_tests.c \
				lstclear_tests.c \
				lstiter_tests.c \
				lstmap_tests.c
SRCS_BONUS	:=	$(SRCS_BONUS:%=$(BONUS_DIR)/%)

SRC_DIR		:=	src
SRC_TESTER	:=	main.c \
				file.c \
				generic_test.c \
				log.c \
				print.c \
				put.c \
				ft_putptr_fd.c \
				perso/ft_putptr_fd_tests.c
				
SRCS		:= 	$(SRC_TESTER) $(SRCS_PART_1) $(SRCS_PART_2) $(SRCS_BONUS)
SRCS		:=	$(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:=	.build
OBJS		:=	$(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:=	$(OBJS:.o=.d)

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror
CPPFLAGS	:=	$(addprefix -I,$(INCS)) -MMD -MP

RM          :=	rm -f
MAKEFLAGS   +=	--no-print-directory
DIR_DUP		=	mkdir -p $(@D)

#------------------------------------------------------------------------------#
# rules                                                                        #
#------------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	$(info created: $(NAME))

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -g -c -o $@ $< 
	$(info created: $@)

-include $(DEPS)

clean:
	$(MAKE) -C $(dir $(LIBS_TARGET)) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(dir $(LIBS_TARGET)) fclean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

run: all
	-./$(NAME)

#------------------------------------------------------------------------------#
# specifications                                                               #
#------------------------------------------------------------------------------#

.PHONY: clean fclean re run
.SILENT:
