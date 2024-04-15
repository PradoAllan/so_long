LIBXFLAGS = -lmlx -lXext -lX11 -lm -lz

NAME = so_long

LIBFTNAME = libft.a

CC = cc

CLANG = clang

FLAGS = -Wall -Wextra -Werror

SOURCES = libftsrc/ft_atoi.c \
	  	libftsrc/ft_atol.c \
		libftsrc/ft_bzero.c \
		libftsrc/ft_calloc.c \
		libftsrc/ft_isalnum.c \
		libftsrc/ft_isalpha.c \
		libftsrc/ft_isascii.c \
		libftsrc/ft_isdigit.c \
		libftsrc/ft_isprint.c \
		libftsrc/ft_itoa.c \
		libftsrc/ft_memchr.c \
		libftsrc/ft_memcmp.c \
		libftsrc/ft_memcpy.c \
		libftsrc/ft_memset.c \
		libftsrc/ft_memmove.c \
		libftsrc/ft_putchar_fd.c \
		libftsrc/ft_putendl_fd.c \
		libftsrc/ft_putnbr_fd.c \
		libftsrc/ft_putstr_fd.c \
		libftsrc/ft_split.c \
		libftsrc/ft_strchr.c \
		libftsrc/ft_strdup.c \
		libftsrc/ft_striteri.c \
		libftsrc/ft_strjoin.c \
		libftsrc/ft_strlcat.c \
		libftsrc/ft_strlcpy.c \
		libftsrc/ft_strlen.c \
		libftsrc/ft_strmapi.c \
		libftsrc/ft_strncmp.c \
		libftsrc/ft_strnstr.c \
		libftsrc/ft_strrchr.c \
		libftsrc/ft_strtrim.c \
		libftsrc/ft_substr.c \
		libftsrc/ft_tolower.c \
		libftsrc/ft_toupper.c \
		libftsrc/ft_lstadd_back.c \
		libftsrc/ft_lstadd_front.c \
		libftsrc/ft_lstclear.c \
		libftsrc/ft_lstdelone.c \
		libftsrc/ft_lstiter.c \
		libftsrc/ft_lstlast.c \
		libftsrc/ft_lstmap.c \
		libftsrc/ft_lstnew.c \
		libftsrc/ft_lstsize.c \
		libftsrc/get_next_line.c \
		libftsrc/get_next_line_utils.c

SO_LONG_SOURCES = so_long.c \
			validations_func.c \
			validations_func2.c \
			utils.c \
			utils2.c \
			display_func.c \
			player_moves.c \
			new_assets.c \
			helper.c

VAL_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

OBJECTS = ${SOURCES:.c=.o}

CC_LINUX = $(CC) $(FLAGS) $(SO_LONG_SOURCES) $(LIBFTNAME) minilibx-linux/libmlx.a -o $(NAME) -lmlx_linux -lXext -lm

CC_MAC = $(CC) $(FLAGS) $(SO_LONG_SOURCES) $(LIBFTNAME) minilibx-mac/libmlx.a -o $(NAME) -framework OpenGL -framework AppKit

.c.o: 
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)	 

all : $(NAME)

$(LIBFTNAME) : $(OBJECTS) 
	ar rcs $(LIBFTNAME) $(OBJECTS)

detected_OS := $(shell uname)
ifeq ($(detected_OS),Linux)
OCFLAGS    = $(CC_LINUX)
else
OCFLAGS    = $(CC_MAC)
endif

$(NAME) : libft
	$(OCFLAGS)

libft : $(LIBFTNAME)

debug : fclean libft
	$(CLANG) -g $(SO_LONG_SOURCES) $(LIBFTNAME) minilibx-linux/libmlx.a -o $(NAME) -Imlx_linux -lXext -lX11 -lm

leak : all
	valgrind $(VAL_FLAGS) ./$(NAME)

clean : 
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(LIBFTNAME) $(NAME) so_long.dSYM

re : fclean all
