MAKEFLAGS			+= --no-print-directory

# ------------------ PROJECT NAME ----------------- #
NAME				:= miniRT

# ---------------------- MODE -------------------- #
MODE				?= release

# ------------------- CONSTANTS ------------------- #
CC					:= cc
MKDIRP				:= mkdir -p
RMF					:= rm -f
RMRF				:= rm -rf

# ------------------- SHELL CMDS ------------------ #
CC_VERSION			:= $(shell $(CC) --version)
OS					:= $(shell uname)

# ------------------- DIRECTORIES ----------------- #

# MAIN DIRECTORIES
HDR					:= include
SRC					:= src
OBJ					:= obj
ASM					:= asm
LIB					:= lib
MAP					:= map
TEST				:= test
EXM					:= example

# SOURCE SUB-DIRECTORIES
CORE				:= core

# LIB SUB-DIRECTORIES
LIBFT				:= libft
ifeq ($(OS), Darwin)
	LIBMLX		:= minilibx_opengl_20121021
else
	LIBMLX		:= minilibx-linux
endif

# ------------------- LIBRARIES ------------------- #
LFT					:= libft.a
LMLX				:= libmlx.a

# ------------------- COMPILER -------------------- #
ifeq ($(findstring clang,$(CC_VERSION)),clang)
    COMPILER := clang
else
ifeq ($(findstring GCC,$(CC_VERSION)),GCC)
    COMPILER := gcc
else
    $(error Unsupported compiler. Use clang or gcc)
endif
endif

# --------------------- FLAGS -------------------- #
CFLAGS			?= -Wall -Werror -Wextra
ifeq ($(COMPILER),clang)
	CFLAGS		= 	-Wall -Werror -Wextra -Wvla -Wpedantic -Wmisleading-indentation -Wshadow -Wnull-dereference
else ifeq ($(COMPILER),gcc)
	CFLAGS		= 	-Wall -Werror -Wextra -Wvla -Wpedantic -Wmisleading-indentation -Wshadow -Wnull-dereference -Wstringop-overflow -Warray-bounds -Wrestrict
endif

ifeq ($(MODE),debug)
	CFLAGS += -g -O1
else ifeq ($(MODE),debug_memory)
	CFLAGS += -g -O1 -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer
else ifeq ($(MODE),release)
	CFLAGS += -O3 -march=native
endif

CPPFLAGS		:= -I$(LIB)/$(LIBFT)/include -I$(LIB)/$(LIBMLX)
LDFLAGS			:= -L/$(LIB)/$(LIBFT)/$(LFT) -L/$(LIB)/$(LIBMLX)/$(LMLX)
LDLIBS			:= -lm -lft -lmlx -lXext -lX11

# --------------------- FILES --------------------- #
SOURCES			:=

# -------------------- OBJECTS -------------------- #
OBJECTS			:= $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

# ---------------------- ASM ---------------------- #
ASSEMBLEUR		:= $(patsubst $(SRC)/%.c, $(ASM)/%.s, $(SOURCES))

# --------------------- RULES --------------------- #
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJECTS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(OBJECTS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(MKDIRP) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $< -o $@

$(ASM)/%.s: $(SRC)/%.c
	$(MKDIRP) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -S $< -o $@

clean:
	$(RMRF) $(OBJ)
	@make clean -C $(LIB)/$(LIBFT)
	@make clean -C $(LIB)/$(LIBMLX)

fclean: clean
	$(RMF) $(NAME)
	@make fclean -C $(LIB)/$(LIBFT)

re: fclean all

.PHONY: all re clean fclean