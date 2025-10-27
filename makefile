# variables
EXEC = bsq

SRC_DIR = src
OBJ_DIR = obj
H_DIR = includes

SOURCE_FILES = helpers.c \
	       cache.c \
	       errors.c \
	       process_map.c \
	       read_input.c \
	       main.c

OBJECT_FILES = $(SOURCE_FILES:%.c=$(OBJ_DIR)/%.o)

CFLAGS += -Wall -Werror -Wextra -I$(H_DIR)

COMPILER = cc

# rules
$(EXEC): $(OBJECT_FILES)
	$(COMPILER) $(CFLAGS) -o $(EXEC) $(OBJECT_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(COMPILER) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(EXEC)
