MAKEFLAGS		+= --no-print-directory

# ------------------- PROJECT ------------------- #
NAME			:= parser_tester

# ------------------- COMMANDS ------------------ #
CC				:= cc
MKDIRP			:= mkdir -p
RMF				:= rm -f
RMRF			:= rm -rf

# ------------------ DIRECTORIES ---------------- #
ROOT			:= ../../..
OBJ				:= $(ROOT)/obj
LIB				:= $(ROOT)/lib
INC				:= $(ROOT)/include
TEST_INC		:= include

PARSER			:= parser
LIBFT			:= libft

# -------------------- FILES -------------------- #
SRC				:= parser_tester.c
TEST_OBJ		:= $(OBJ)/test/parser_tester.o

OBJ_FILES		:= \
	$(OBJ)/$(PARSER)/parse_amb_lighting.o \
	$(OBJ)/$(PARSER)/parse_blanks.o \
	$(OBJ)/$(PARSER)/parse_camera.o \
	$(OBJ)/$(PARSER)/parse_cylinder.o \
	$(OBJ)/$(PARSER)/parse_light.o \
	$(OBJ)/$(PARSER)/parse_plane.o \
	$(OBJ)/$(PARSER)/parse_sphere.o \
	$(OBJ)/$(PARSER)/parser.o \
	$(OBJ)/$(PARSER)/parser_set.o \
	$(OBJ)/$(PARSER)/parser_utils.o

LIBFT_A			:= $(LIB)/$(LIBFT)/libft.a

# --------------------- FLAGS ------------------- #
CFLAGS			:= -Wall -Wextra -Werror

CPPFLAGS		:= \
	-I$(INC) \
	-I$(TEST_INC) \
	-I$(LIB)/$(LIBFT)/include

LDFLAGS			:= -L$(LIB)/$(LIBFT)
LDLIBS			:= -lft

# --------------------- RULES ------------------- #
all: $(NAME)

$(NAME): $(TEST_OBJ) $(OBJ_FILES) $(LIBFT_A)
	$(CC) $(CFLAGS) $(TEST_OBJ) $(OBJ_FILES) $(LDFLAGS) $(LDLIBS) -o $@

$(TEST_OBJ): $(SRC)
	$(MKDIRP) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIB)/$(LIBFT)

clean:
	$(RMRF) $(dir $(TEST_OBJ))

fclean: clean
	$(RMF) $(NAME)

re: fclean all

.PHONY: all clean fclean re