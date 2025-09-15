# TARGET = my_shell
# OBJ = main.c input_parser.c helpers.c
# CFLAGS = -Wall -Wextra -Werror
# CC = gcc


# all:
# 	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
# clean:
# 	rm- f *-o
# fclean: clean
# 	rm -f $(TARGET)
# re: fclean all


## OPTIMIZED CODE 0.1
# # Variables
# TARGET = my_shell
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# SRC = main.c input_parser.c helpers.c
# OBJ = $(SRC:.c=.o)

# # Default rule
# all: $(TARGET)

# # Linking step: build executable from object files
# $(TARGET): $(OBJ)
# 	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# # Compilation step: build .o files from .c files
# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Cleanup rules
# clean:
# 	rm -f $(OBJ)

# fclean: clean
# 	rm -f $(TARGET)

# re: fclean all





## OPTIMIZED CODE 0.2
# # Variables
# TARGET = my_shell
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# SRC = main.c input_parser.c helpers.c
# OBJDIR = obj
# OBJ = $(patsubst %.c,$(OBJDIR)/%.o,$(SRC))

# # Default rule
# all: $(TARGET)

# # Linking step
# $(TARGET): $(OBJ)
# 	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# # Compilation step (ensure obj/ exists)
# $(OBJDIR)/%.o: %.c | $(OBJDIR)
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Rule to create obj/ directory if it doesn’t exist
# $(OBJDIR):
# 	if not exist "$(OBJDIR)" mkdir "$(OBJDIR)"

# # Cleanup rules
# clean:
# 	rm -f $(OBJDIR)/*.o

# fclean: clean
# 	rm -f $(TARGET)
# 	rm -rf $(OBJDIR)

# re: fclean all





## OPTIMIZED CODE 0.3
# Project settings
TARGET = my_shell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Folders
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Default rule
all: $(BIN_DIR)/$(TARGET)

# Linking
$(BIN_DIR)/$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

# Compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create folders if missing
$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(BIN_DIR):
	mkdir $(BIN_DIR)

# target: dependencies
# @ is used for silence mode (stop echo)
run: all
	@.\bin\$(TARGET).exe	

# Cleanup
clean:
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	rm -f $(BIN_DIR)/$(TARGET)
	rm -rf $(OBJ_DIR) $(BIN_DIR)

re: fclean all