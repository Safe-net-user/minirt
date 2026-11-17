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
OS					:= $(shell uname)
IS_CLANG			:= $(shell $(CC) -dM -E - </dev/null | grep -q '__clang__' && echo clang)
IS_GCC				:= $(shell $(CC) -dM -E - </dev/null | grep -q '__GNUC__' && echo gcc)

# ------------------- DIRECTORIES ----------------- #

# MAIN DIRECTORIES
HDR					:= include
SRC					:= src
OBJ					:= obj
DEP					:= dep
ASM					:= asm
LIB					:= lib
MAP					:= map
TEST				:= test
EXM					:= example

# SOURCE SUB-DIRECTORIES
CORE				:= core
ENTITY				:= entity
PARSER				:= parser
MATHS				:= maths
PHYSIC				:= physic
SHAPE				:= shape
WINDOW				:= window

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

LIBFT_A				:= $(LIB)/$(LIBFT)/$(LFT)
LIBMLX_A			:= $(LIB)/$(LIBMLX)/$(LMLX)

# ------------------- COMPILER -------------------- #
ifeq ($(IS_CLANG),clang)
    COMPILER := clang
else
ifeq ($(IS_GCC),gcc)
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

ifeq ($(filter debug debug_memory release,$(MODE)),)
	$(error Invalid MODE: $(MODE))
endif
ifeq ($(MODE),debug)
	CFLAGS += -g -O1
else ifeq ($(MODE),debug_memory)
	CFLAGS += -g -O1 -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer
else ifeq ($(MODE),release)
	CFLAGS += -O3 -march=native
endif

CPPFLAGS		:= -I$(HDR) -I$(SRC) -I$(LIB)/$(LIBFT)/include -I$(LIB)/$(LIBMLX)
LDFLAGS			:= -L$(LIB)/$(LIBFT) -L$(LIB)/$(LIBMLX)
LDLIBS			:= -lm -lft -lmlx -lXext -lX11

# --------------------- FILES --------------------- #
SOURCES			:= \
$(SRC)/main.c \
$(SRC)/$(CORE)/raytracer.c \
$(SRC)/$(CORE)/world.c \
$(SRC)/$(ENTITY)/camera.c \
$(SRC)/$(PARSER)/parser.c \
$(SRC)/$(PARSER)/parse_blanks.c \
$(SRC)/$(PARSER)/parse_amb_lighting.c \
$(SRC)/$(PARSER)/parse_camera.c \
$(SRC)/$(PARSER)/parse_cylinder.c \
$(SRC)/$(PARSER)/parse_light.c \
$(SRC)/$(PARSER)/parse_plane.c \
$(SRC)/$(PARSER)/parse_sphere.c \
$(SRC)/$(PARSER)/parser_set.c \
$(SRC)/$(PARSER)/parser_utils.c \
$(SRC)/$(MATHS)/transformations.c \
$(SRC)/$(MATHS)/matrix3.c \
$(SRC)/$(MATHS)/matrix4.c \
$(SRC)/$(PHYSIC)/intersection.c \
$(SRC)/$(PHYSIC)/ray.c \
$(SRC)/$(PHYSIC)/light.c \
$(SRC)/$(SHAPE)/cylinder.c \
$(SRC)/$(SHAPE)/free_shape.c \
$(SRC)/$(SHAPE)/init_shape.c \
$(SRC)/$(SHAPE)/plane.c \
$(SRC)/$(SHAPE)/sphere.c \
$(SRC)/$(SHAPE)/color.c \
$(SRC)/$(WINDOW)/window_utils.c \

# -------------------- OBJECTS -------------------- #
OBJECTS			:= $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

# ---------------------- ASM ---------------------- #
ASSEMBLEUR		:= $(patsubst $(SRC)/%.c, $(ASM)/%.s, $(SOURCES))

# ---------------------- DEPS --------------------- #
DEPENDENCES		:= $(patsubst $(OBJ)/%.o, $(DEP)/%.d, $(OBJECTS))

# --------------------- RULES --------------------- #
all: $(NAME)

$(NAME): $(LIBFT_A) $(LIBMLX_A) $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

$(LIBFT_A):
	make -C $(LIB)/$(LIBFT)

$(LIBMLX_A):
	make -C $(LIB)/$(LIBMLX)

$(OBJ)/%.o: $(SRC)/%.c
	$(MKDIRP) $(dir $@)
	$(MKDIRP) $(dir $(DEP)/$*.d)
	$(CC) $(CPPFLAGS) -MMD -MP -MF $(DEP)/$*.d -MT $@ $(CFLAGS) -c $< -o $@

$(ASM)/%.s: $(SRC)/%.c
	$(MKDIRP) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -S $< -o $@

-include $(DEPENDENCES)

clean:
	$(RMRF) $(OBJ)
	$(RMRF) $(DEP)
	@make clean -C $(LIB)/$(LIBFT)
	@make clean -C $(LIB)/$(LIBMLX)

fclean: clean
	$(RMF) $(NAME)
	@make fclean -C $(LIB)/$(LIBFT)

re: fclean all

.PHONY: all re clean fclean