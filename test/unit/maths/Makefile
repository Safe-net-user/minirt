MAKEFLAGS		+= --no-print-directory

# ------------------- PROJECT ------------------- #
NAME			:= math_tester

# ------------------- COMMANDS ------------------ #
CC				:= cc
MKDIRP			:= mkdir -p
RMF				:= rm -f
RMRF			:= rm -rf

# ------------------ DIRECTORIES ---------------- #
ROOT			:= ../../..
OBJ				:= $(ROOT)/obj
INC				:= $(ROOT)/include

# -------------------- FILES -------------------- #
SRC				:= math_tester.c
TEST_OBJ		:= $(OBJ)/test/math_tester.o

OBJ_FILES		:= \
$(OBJ)/maths/matrix/matrix4.o \
$(OBJ)/maths/matrix/matrix3.o

# --------------------- FLAGS ------------------- #
CFLAGS			:= -Wall -Wextra -Werror
CPPFLAGS		:= -I$(INC)

LDFLAGS			:=
LDLIBS		:= -lm

# --------------------- RULES ------------------- #

all: $(NAME)

$(NAME): $(TEST_OBJ) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(TEST_OBJ) $(OBJ_FILES) $(LDFLAGS) $(LDLIBS) -o $@

$(TEST_OBJ): $(SRC)
	$(MKDIRP) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RMRF) $(dir $(TEST_OBJ))

fclean: clean
	$(RMF) $(NAME)

re: fclean all

.PHONY: all clean fclean re